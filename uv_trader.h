#ifndef UV_TRADER_H_
#define UV_TRADER_H_

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "TapTradeAPI.h"
#include "TapTradeAPIDataType.h"
#include "TapAPIError.h"
#include "TapAPICommDef.h"
#include <uv.h>
#include <node.h>
#include "wraper_struct.h"
#include <node_object_wrap.h>

extern const TAPICHAR* GetTapTradeAPIVersion();
extern const ITapTradeAPI* CreateTapTradeAPI();
extern bool islog;
extern std::string authCodeStr;
// extern ITapTradeAPI * CreateTapTradeAPI(const TapAPIApplicationInfo *appInfo, TAPIINT32 &iResult);

void logger_cout(const char *content);

std::string to_string(int val);

std::string charto_string(char val);

class uv_trader : public ITapTradeAPINotify {
public:
  uv_trader(void);

  virtual ~uv_trader(void);

  const char *GetAPIVersion();
  int On(const char *eName, int cb_type, void(*callback)(CbRtnField *cbResult));
  void Connect(UVConnectField *pConnectField, void(*callback)(int, void *), int uuid);

  void ReqUserLogin(TapAPITradeLoginAuth *pReqUserLoginField, void(*callback)(int, void *), int uuid);

  void ReqOrderInsert(TapAPINewOrder *pInputOrder, void(*callback)(int, void *), int uuid);

  virtual void TAP_CDECL OnConnect();

  virtual void TAP_CDECL OnAPIReady();

  virtual void TAP_CDECL OnRspLogin(TAPIINT32 errorCode, const TapAPITradeLoginRspInfo *pRspUserLogin);

  virtual void TAP_CDECL OnRtnOrder(const TapAPIOrderInfoNotice *pInputOrder);

	virtual void TAP_CDECL  OnDisconnect(TAPIINT32 reasonCode);
	virtual void TAP_CDECL  OnRspChangePassword(TAPIUINT32 sessionID, TAPIINT32 errorCode);
	virtual void TAP_CDECL  OnRspSetReservedInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, const TAPISTR_50 info);
	virtual void TAP_CDECL  OnRspQryAccount(TAPIUINT32 sessionID, TAPIUINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountInfo *info);
	virtual void TAP_CDECL  OnRspQryFund(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFundData *info);
	virtual void TAP_CDECL  OnRtnFund(const TapAPIFundData *info);
	virtual void TAP_CDECL  OnRspQryExchange(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIExchangeInfo *info);
	virtual void TAP_CDECL  OnRspQryCommodity(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICommodityInfo *info);
	virtual void TAP_CDECL  OnRspQryContract(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPITradeContractInfo *info);
	virtual void TAP_CDECL  OnRtnContract(const TapAPITradeContractInfo *info);
	virtual void TAP_CDECL  OnRspOrderAction(TAPIUINT32 sessionID, TAPIUINT32 errorCode, const TapAPIOrderActionRsp *info);
	virtual void TAP_CDECL  OnRspQryOrder(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info);
	virtual void TAP_CDECL  OnRspQryOrderProcess(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIOrderInfo *info);
	virtual void TAP_CDECL  OnRspQryFill(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIFillInfo *info);
	virtual void TAP_CDECL  OnRtnFill(const TapAPIFillInfo *info);
	virtual void TAP_CDECL  OnRspQryPosition(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIPositionInfo *info);
	virtual void TAP_CDECL  OnRtnPosition(const TapAPIPositionInfo *info);
	virtual void TAP_CDECL  OnRspQryClose(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPICloseInfo *info);
	virtual void TAP_CDECL  OnRtnClose(const TapAPICloseInfo *info);
	virtual void TAP_CDECL  OnRtnPositionProfit(const TapAPIPositionProfitNotice *info);
	virtual void TAP_CDECL  OnRspQryDeepQuote(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIDeepQuoteQryRsp *info);
	virtual void TAP_CDECL  OnRspQryExchangeStateInfo(TAPIUINT32 sessionID,TAPIINT32 errorCode, TAPIYNFLAG isLast,const TapAPIExchangeStateInfo * info);
	virtual void TAP_CDECL  OnRtnExchangeStateInfo(const TapAPIExchangeStateInfoNotice * info);
	virtual void TAP_CDECL  OnRtnReqQuoteNotice(const TapAPIReqQuoteNotice *info); //V9.0.2.0 20150520
	virtual void TAP_CDECL  OnRspUpperChannelInfo(TAPIUINT32 sessionID,TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIUpperChannelInfo * info);
	virtual void TAP_CDECL  OnRspAccountRentInfo(TAPIUINT32 sessionID, TAPIINT32 errorCode, TAPIYNFLAG isLast, const TapAPIAccountRentInfo * info);

private:
  static void _async(uv_work_t *work);

  static void _completed(uv_work_t *work, int);

  static void _on_async(uv_work_t *work);

  static void _on_completed(uv_work_t *work, int);

  void invoke(void *field, int ret, void(*callback)(int, void *), int uuid);

  void on_invoke(int event_type, void *_stru, TAPIINT32 errorCode);

  ITapTradeAPI *m_pApi;
  int iRequestID;
  uv_async_t async_t;
  static std::map<int, CbWrap *> cb_map;
};

#endif
