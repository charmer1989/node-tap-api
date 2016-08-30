#include <uv.h>
#include "uv_trader.h"
#include "TapTradeAPI.h"
#include "TapTradeAPIDataType.h"
#include "TapAPIError.h"
#include "TapAPICommDef.h"
#include <cstring>
#include <sstream>
#include "wraper_struct.h"
#include <string>

std::string to_string(int val){
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::string charto_string(char val){
  std::stringstream ss;
  ss << val;
  return ss.str();
}

std::map<int, CbWrap*> uv_trader::cb_map;

uv_trader::uv_trader(void) {
  iRequestID = 0;
  uv_async_init(uv_default_loop(),&async_t,NULL);
  logger_cout("uv_trader init");
}

uv_trader::~uv_trader(void) {
  uv_close((uv_handle_t*)&async_t,NULL);
}

const char* uv_trader::GetAPIVersion(){
  const TAPICHAR* apiVersion = GetTapTradeAPIVersion();
  return apiVersion;
}

int uv_trader::On(const char* eName,int cb_type, void(*callback)(CbRtnField* cbResult)) {
	std::string log = "uv_trader On------>";
	std::map<int, CbWrap*>::iterator it = cb_map.find(cb_type);
	if (it != cb_map.end()) {
		logger_cout(log.append(" event id").append(to_string(cb_type)).append(" register repeat").c_str());
		return 1;
	}

	CbWrap* cb_wrap = new CbWrap();
	cb_wrap->callback = callback;
	cb_map[cb_type] = cb_wrap;
	logger_cout(log.append(" Event:").append(eName).append(" ID:").append(to_string(cb_type)).append(" register").c_str());
	return 0;
}

void uv_trader::Connect(UVConnectField* pConnectField, void(*callback)(int, void*), int uuid) {
	UVConnectField* _pConnectField = new UVConnectField();
	memcpy(_pConnectField, pConnectField, sizeof(UVConnectField));
  logger_cout("trader Connect this -> invoke");
	this->invoke(_pConnectField, T_CONNECT_RE, callback, uuid);
}

void uv_trader::ReqUserLogin(TapAPITradeLoginAuth *pReqUserLoginField, void(*callback)(int, void*), int uuid) {
	TapAPITradeLoginAuth *_pReqUserLoginField = new TapAPITradeLoginAuth();
	memcpy(_pReqUserLoginField, pReqUserLoginField, sizeof(TapAPITradeLoginAuth));
	this->invoke(_pReqUserLoginField, T_LOGIN_RE, callback, uuid);
}

void uv_trader::ReqOrderInsert(TapAPINewOrder *pInputOrder, void(*callback)(int, void*), int uuid) {
	TapAPINewOrder *_pInputOrder = new TapAPINewOrder();
	memcpy(_pInputOrder, pInputOrder, sizeof(TapAPINewOrder));
	this->invoke(_pInputOrder, T_INSERT_RE, callback, uuid);
}




void uv_trader::OnConnect() {
	std::string log = "uv_trader OnFrontConnected";
  logger_cout(log.c_str());
	CbRtnField* field = new CbRtnField();
	field->eFlag = T_ON_CONNECT;
  field->work.data = field;
	uv_queue_work(uv_default_loop(), &field->work, _on_async, _on_completed);
}

void uv_trader::OnAPIReady() {
	std::string log = "uv_trader OnAPIReady";
  logger_cout(log.c_str());
	CbRtnField* field = new CbRtnField();
	field->eFlag = T_ON_API_READY;
  field->work.data = field;
	uv_queue_work(uv_default_loop(), &field->work, _on_async, _on_completed);
}

void uv_trader::OnRspLogin(TAPIINT32 errorCode, const TapAPITradeLoginRspInfo *pRspUserLogin) {
	TapAPITradeLoginRspInfo* _pRspUserLogin = NULL;
	if (pRspUserLogin) {
		_pRspUserLogin = new TapAPITradeLoginRspInfo();
		memcpy(_pRspUserLogin, pRspUserLogin, sizeof(TapAPITradeLoginRspInfo));
	}
	std::string log = "uv_trader OnRspLogin------>";
	logger_cout(log.append("errorCode:").append(to_string((int)errorCode)).c_str());
	on_invoke(T_ON_RSPUSERLOGIN, _pRspUserLogin, errorCode);
}

void uv_trader::OnRtnOrder(const TapAPIOrderInfoNotice *pInputOrder) {
	TapAPIOrderInfoNotice* _pInputOrder = NULL;
	if (pInputOrder) {
		_pInputOrder = new TapAPIOrderInfoNotice();
		memcpy(_pInputOrder, pInputOrder, sizeof(TapAPIOrderInfoNotice));
	}
	std::string log = "uv_trader OnRtnOrder------>";
	logger_cout(log.c_str());
	on_invoke(T_ON_RSPINSERT, _pInputOrder, 0);
}

void uv_trader::_async(uv_work_t * work) {
	LookupCtpApiBaton* baton = static_cast<LookupCtpApiBaton*>(work->data);
	uv_trader* uv_trader_obj = static_cast<uv_trader*>(baton->uv_trader_obj);
	std::string log = "uv_trader _async------>";
  logger_cout(log.append(to_string(baton->fun)).c_str());
	switch (baton->fun) {
	case T_CONNECT_RE:
    {
      UVConnectField* _pConnectF = static_cast<UVConnectField*>(baton->args);
      TAPIINT32 iResult = TAPIERROR_SUCCEED;
      TapAPIApplicationInfo stAppInfo;
      strcpy(stAppInfo.AuthCode, authCodeStr.c_str());
      strcpy(stAppInfo.KeyOperationLogPath, "\\log");
      uv_trader_obj->m_pApi = CreateTapTradeAPI(&stAppInfo, iResult);
      // if (NULL == uv_trader_obj->m_pApi){
      //   std::cout << "CreateTapTradeAPI fail errorCode：" << iResult <<std::endl ;
      //   return ;
      // }
      uv_trader_obj->m_pApi->SetAPINotify(uv_trader_obj);

      TAPIINT32 iErr = TAPIERROR_SUCCEED;
      iErr =  uv_trader_obj->m_pApi->SetHostAddress(_pConnectF->front_ip, (TAPIUINT16)_pConnectF->front_port);
      // if(TAPIERROR_SUCCEED != iErr) {
      //   std::cout << "SetHostAddress Error:" << iErr <<std::endl;
      //   return;
      // }
      logger_cout(log.append("invoke connect,the result is 0 | szPath is ").append(_pConnectF->front_ip).append("|iResult:").append(to_string(iResult)).c_str());
      break;
    }
	case T_LOGIN_RE:
    {
      TapAPITradeLoginAuth *_pReqUserLoginField = static_cast<TapAPITradeLoginAuth*>(baton->args);
      baton->nResult = uv_trader_obj->m_pApi->Login(_pReqUserLoginField);
      logger_cout(log.append("invoke ReqUserLogin,the result:").append(to_string(baton->nResult)).c_str());
      break;
    }
  case T_INSERT_RE:
    {
      TapAPINewOrder *_pInputOrder = static_cast<TapAPINewOrder*>(baton->args);
      TAPIINT32 iErr = TAPIERROR_SUCCEED;
      logger_cout("ready insert order 3");
      iErr = uv_trader_obj->m_pApi->InsertOrder((TAPIUINT32 *)&baton->iRequestID, _pInputOrder);
      logger_cout("ready insert order 4");
      logger_cout(to_string((int)iErr).c_str());
      logger_cout(log.append("invoke ReqOrderInsert,the result:").append(to_string((int)iErr)).c_str());

      break;
    }
  default:
    {
      logger_cout(log.append("No case event:").append(to_string(baton->fun)).c_str());
      break;
    }
	}
}
///uv_queue_work
void uv_trader::_completed(uv_work_t * work, int) {
	LookupCtpApiBaton* baton = static_cast<LookupCtpApiBaton*>(work->data);
	baton->callback(baton->nResult, baton);
	delete baton->args;
	delete baton;
}

void uv_trader::_on_async(uv_work_t * work){
  //do nothing
}

void uv_trader::_on_completed(uv_work_t * work,int){
	std::string head = "uv_trader _on_completed  ==> ";

	CbRtnField* cbTrnField = static_cast<CbRtnField*>(work->data);
	std::map<int, CbWrap*>::iterator it = cb_map.find(cbTrnField->eFlag);
	if (it != cb_map.end()) {
    logger_cout(head.append("has return").c_str());
		cb_map[cbTrnField->eFlag]->callback(cbTrnField);
	} else {
    logger_cout(head.append("none").c_str());
  }
	if (cbTrnField->rtnField)
		delete cbTrnField->rtnField;
	// if (cbTrnField->errorCode)
	// 	delete cbTrnField->errorCode;
	delete cbTrnField;
}

void uv_trader::invoke(void* field, int ret, void(*callback)(int, void*), int uuid) {
	LookupCtpApiBaton* baton = new LookupCtpApiBaton();
	baton->work.data = baton;
	baton->uv_trader_obj = this;
	baton->callback = callback;
	baton->args = field;
	baton->fun = ret;
	baton->uuid = uuid;

  iRequestID = iRequestID+1;
  baton->iRequestID = iRequestID;
	std::string head = "uv_trader invoke------>uuid:";
	logger_cout(head.append(to_string(uuid)).append(",requestid:").append(to_string(baton->iRequestID)).c_str());
	uv_queue_work(uv_default_loop(), &baton->work, _async, _completed);
}

void uv_trader::on_invoke(int event_type, void* _stru, TAPIINT32 errorCode){
	CbRtnField* field = new CbRtnField();
  field->work.data = field;
	field->eFlag = event_type;
	field->rtnField = _stru;
	field->errorCode = errorCode;
	uv_queue_work(uv_default_loop(), &field->work, _on_async, _on_completed);
}

void uv_trader::OnDisconnect(TAPIINT32 reasonCode){};
void uv_trader::OnRspChangePassword(TAPIUINT32 sessionID, TAPIINT32 errorCode){};
void uv_trader::OnRspSetReservedInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, const TAPISTR_50 info){};
void uv_trader::OnRspQryAccount(TAPIUINT32 sessionID, TAPIUINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountInfo *info){};
void uv_trader::OnRspQryFund(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFundData *info){};
void uv_trader::OnRtnFund(const TapAPIFundData *info){};
void uv_trader::OnRspQryExchange(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIExchangeInfo *info){};
void uv_trader::OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICommodityInfo *info){};
void uv_trader::OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPITradeContractInfo *info){};
void uv_trader::OnRtnContract(const TapAPITradeContractInfo *info){};
void uv_trader::OnRspOrderAction(TAPIUINT32 sessionID, TAPIUINT32 errorCode, const TapAPIOrderActionRsp *info){};
void uv_trader::OnRspQryOrder(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info){};
void uv_trader::OnRspQryOrderProcess(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info){};
void uv_trader::OnRspQryFill(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFillInfo *info){};
void uv_trader::OnRtnFill(const TapAPIFillInfo *info){};
void uv_trader::OnRspQryPosition(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionInfo *info){};
void uv_trader::OnRtnPosition(const TapAPIPositionInfo *info){};
void uv_trader::OnRspQryClose(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICloseInfo *info){};
void uv_trader::OnRtnClose(const TapAPICloseInfo *info){};
void uv_trader::OnRtnPositionProfit(const TapAPIPositionProfitNotice *info){};
void uv_trader::OnRspQryDeepQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIDeepQuoteQryRsp *info){};
void uv_trader::OnRspQryExchangeStateInfo(TAPIUINT32 sessionID,TAPIINT32 errorCode, TAPIYNFLAG isLast,const TapAPIExchangeStateInfo * info){};
void uv_trader::OnRtnExchangeStateInfo(const TapAPIExchangeStateInfoNotice * info){};
void uv_trader::OnRtnReqQuoteNotice(const TapAPIReqQuoteNotice *info){}; //V9.0.2.0 20150520
void uv_trader::OnRspUpperChannelInfo(TAPIUINT32 sessionID,TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIUpperChannelInfo * info){};
void uv_trader::OnRspAccountRentInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountRentInfo * info){};
