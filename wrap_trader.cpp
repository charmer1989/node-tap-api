#include <node.h>
#include "wrap_trader.h"
#include <cstring>
#include <nan.h>

Persistent <Function> WrapTrader::constructor;
int WrapTrader::s_uuid;
std::map<std::string, int> WrapTrader::event_map;
std::map<int, Persistent<Function> > WrapTrader::callback_map;
std::map<int, Persistent<Function> > WrapTrader::fun_rtncb_map;


void logger_cout(const char *content) {
  using namespace std;
  if (islog) {
    cout << content << endl;
  }
}

WrapTrader::WrapTrader(void) {
  logger_cout("wrap_trader------>object start init");
  uvTrader = new uv_trader();
  logger_cout("wrap_trader------>object init successed");
}

WrapTrader::~WrapTrader(void) {
  if (uvTrader) {
    delete uvTrader;
  }
  logger_cout("wrap_trader------>object destroyed");
}

void WrapTrader::Init(Isolate *isolate) {
  // Prepare constructor template
  Local <FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
  tpl->SetClassName(String::NewFromUtf8(isolate, "WrapTrader"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  NODE_SET_PROTOTYPE_METHOD(tpl, "getAPIVersion", GetAPIVersion);
  NODE_SET_PROTOTYPE_METHOD(tpl, "connect", Connect);
  NODE_SET_PROTOTYPE_METHOD(tpl, "on", On);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reqUserLogin", ReqUserLogin);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reqOrderInsert", ReqOrderInsert);

  constructor.Reset(isolate, tpl->GetFunction());
}

void WrapTrader::New(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();

  if (event_map.size() == 0)
    initEventMap();

  if (args.IsConstructCall()) {
    // Invoked as constructor: `new MyObject(...)`
    WrapTrader *wTrader = new WrapTrader();
    wTrader->Wrap(args.This());
    args.GetReturnValue().Set(args.This());
  } else {
    // Invoked as plain function `MyObject(...)`, turn into construct call.
    const int argc = 1;
    Local <Value> argv[argc] = {Number::New(isolate, 0)};
    Local <Function> cons = Local<Function>::New(isolate, constructor);
    Local <Context> context = isolate->GetCurrentContext();
    Local <Object> instance = cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(instance);
  }
}

void WrapTrader::NewInstance(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();
  const unsigned argc = 1;
  Local <Value> argv[argc] = {Number::New(isolate, 0)};
  Local <Function> cons = Local<Function>::New(isolate, constructor);
  Local <Context> context = isolate->GetCurrentContext();
  Local <Object> instance = cons->NewInstance(context, argc, argv).ToLocalChecked();
  args.GetReturnValue().Set(instance);
}

void WrapTrader::initEventMap() {
  event_map["connect"] = T_ON_CONNECT;
  event_map["apiReady"] = T_ON_API_READY;
  event_map["disconnected"] = T_ON_DISCONNECTED;
  event_map["rspUserLogin"] = T_ON_RSPUSERLOGIN;
  event_map["rspUserLogout"] = T_ON_RSPUSERLOGOUT;
  event_map["rspInfoconfirm"] = T_ON_RSPINFOCONFIRM;
  event_map["rspInsert"] = T_ON_RSPINSERT;
  event_map["errInsert"] = T_ON_ERRINSERT;
  event_map["rspAction"] = T_ON_RSPACTION;
  event_map["errAction"] = T_ON_ERRACTION;
  event_map["rqOrder"] = T_ON_RQORDER;
  event_map["rtnOrder"] = T_ON_RTNORDER;
  event_map["rqTrade"] = T_ON_RQTRADE;
  event_map["rtnTrade"] = T_ON_RTNTRADE;
  event_map["rqInvestorPosition"] = T_ON_RQINVESTORPOSITION;
  event_map["rqInvestorPositionDetail"] = T_ON_RQINVESTORPOSITIONDETAIL;
  event_map["rqTradingAccount"] = T_ON_RQTRADINGACCOUNT;
  event_map["rqInstrument"] = T_ON_RQINSTRUMENT;
  event_map["rqDdpthmarketData"] = T_ON_RQDEPTHMARKETDATA;
  event_map["rqSettlementInfo"] = T_ON_RQSETTLEMENTINFO;
  event_map["rspError"] = T_ON_RSPERROR;
}

void WrapTrader::GetAPIVersion(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();

  WrapTrader *wTrader = ObjectWrap::Unwrap<WrapTrader>(args.Holder());
  const char *apiVersion = wTrader->uvTrader->GetAPIVersion();
  logger_cout("调用结果:");
  logger_cout(apiVersion);

  args.GetReturnValue().Set(String::NewFromUtf8(isolate, apiVersion));
}

void WrapTrader::On(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();

  if (args[0]->IsUndefined() || args[1]->IsUndefined()) {
    logger_cout("Wrong arguments->event name or function");
    isolate->ThrowException(
                            Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->event name or function")));
    return;
  }

  WrapTrader *obj = ObjectWrap::Unwrap<WrapTrader>(args.Holder());

  Local <String> eventName = args[0]->ToString();
  Local <Function> cb = Local<Function>::Cast(args[1]);

  String::Utf8Value eNameAscii(eventName);

  std::map<std::string, int>::iterator eIt = event_map.find((std::string) * eNameAscii);
  if (eIt == event_map.end()) {
    logger_cout("System has not register this event");
    isolate->ThrowException(
                            Exception::TypeError(String::NewFromUtf8(isolate, "System has no register this event")));
    return;
  }

  std::map < int, Persistent < Function > > ::iterator
    cIt = callback_map.find(eIt->second);
  if (cIt != callback_map.end()) {
    logger_cout("Callback is defined before");
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Callback is defined before")));
    return;
  }

  callback_map[eIt->second].Reset(isolate, cb);
  obj->uvTrader->On(*eNameAscii, eIt->second, FunCallback);
  return args.GetReturnValue().Set(String::NewFromUtf8(isolate, "finish exec on"));
}

void WrapTrader::Connect(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();

  if (args[0]->IsUndefined()) {
    logger_cout("Wrong arguments->front addr");
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->front addr")));
    return;
  }
  if (!args[1]->IsNumber()) {
    logger_cout("Wrong arguments->public or private topic type");
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->public or private topic type")));
    return;
  }
  int uuid = -1;
  WrapTrader *obj = ObjectWrap::Unwrap<WrapTrader>(args.Holder());
  if (!args[2]->IsUndefined() && args[2]->IsFunction()) {
    uuid = ++s_uuid;
    fun_rtncb_map[uuid].Reset(isolate, Local<Function>::Cast(args[2]));
    logger_cout(to_string(uuid).append("|uuid").c_str());
  }

  Local <String> frontIp = args[0]->ToString();
  int frontPort = args[1]->Int32Value();
  String::Utf8Value frontIpUtf8(frontIp);

  UVConnectField pConnectField;
  memset(&pConnectField, 0, sizeof(pConnectField));
  strcpy(pConnectField.front_ip, ((std::string) * frontIpUtf8).c_str());
  pConnectField.front_port = frontPort;
  logger_cout(((std::string) * frontIpUtf8).append("|addrUtf8").c_str());
  logger_cout(to_string(frontPort).append("|frontPort").c_str());

  obj->uvTrader->Connect(&pConnectField, FunRtnCallback, uuid);
  return args.GetReturnValue().Set(String::NewFromUtf8(isolate, "finish exec connect"));
}

void WrapTrader::ReqUserLogin(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();

  std::string log = "wrap_trader ReqUserLogin------>";
  if (args[0]->IsUndefined() || args[1]->IsUndefined() ) {
    std::string _head = std::string(log);
    logger_cout(_head.append(" Wrong arguments").c_str());
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments")));
    return;
  }

  int uuid = -1;
  WrapTrader *obj = ObjectWrap::Unwrap<WrapTrader>(args.Holder());
  if (!args[2]->IsUndefined() && args[2]->IsFunction()) {
    uuid = ++s_uuid;
    fun_rtncb_map[uuid].Reset(isolate, Local<Function>::Cast(args[2]));
    std::string _head = std::string(log);
    logger_cout(_head.append(" uuid is ").append(to_string(uuid)).c_str());
  }

  Local <String> userNo = args[0]->ToString();
  Local <String> pwd = args[1]->ToString();
  String::Utf8Value userNoUtf8(userNo);
  String::Utf8Value pwdUtf8(pwd);

  TapAPITradeLoginAuth req;
  memset(&req, 0, sizeof(req));
  strcpy(req.UserNo, ((std::string) * userNoUtf8).c_str());
  strcpy(req.Password, ((std::string) * pwdUtf8).c_str());
  req.ISModifyPassword = APIYNFLAG_NO;
	req.ISDDA = APIYNFLAG_NO;
  logger_cout(log.append(" ").append((std::string) * userNoUtf8).append("|").append((std::string) * pwdUtf8).c_str());
  obj->uvTrader->ReqUserLogin(&req, FunRtnCallback, uuid);
  return args.GetReturnValue().Set(String::NewFromUtf8(isolate, "finish exec reqUserlogin"));
}

void WrapTrader::ReqOrderInsert(const FunctionCallbackInfo <Value> &args) {
  Isolate *isolate = args.GetIsolate();
  std::string log = "wrap_trader ReqOrderInsert------>";

  if (args[0]->IsUndefined() || !args[0]->IsObject()) {
    std::string _head = std::string(log);
    logger_cout(_head.append(" Wrong arguments").c_str());
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments")));
    return ;
  }
  int uuid = -1;
  WrapTrader *obj = ObjectWrap::Unwrap<WrapTrader>(args.Holder());
  if (!args[1]->IsUndefined() && args[1]->IsFunction()) {
    uuid = ++s_uuid;
    fun_rtncb_map[uuid].Reset(isolate, Local<Function>::Cast(args[1]));
    std::string _head = std::string(log);
    logger_cout(_head.append(" uuid is ").append(to_string(uuid)).c_str());
  }
  Local <Object> jsonObj = args[0]->ToObject();
  Local <Value> accountNo = jsonObj->Get(v8::String::NewFromUtf8(isolate, "accountNo"));
  if (accountNo->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->accountNo")));
    return ;
  }
  String::Utf8Value accountNo_(accountNo->ToString());

  Local <Value> exchangeNo = jsonObj->Get(v8::String::NewFromUtf8(isolate, "exchangeNo"));
  if (exchangeNo->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->exchangeNo")));
    return ;
  }
  String::Utf8Value exchangeNo_(exchangeNo->ToString());

  Local <Value> commodityType = jsonObj->Get(v8::String::NewFromUtf8(isolate, "commodityType"));
  if (commodityType->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->commodityType")));
    return ;
  }
  String::Utf8Value commodityType_(commodityType->ToString());

  Local <Value> commodityNo = jsonObj->Get(v8::String::NewFromUtf8(isolate, "commodityNo"));
  if (commodityNo->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->commodityNo")));
    return ;
  }
  String::Utf8Value commodityNo_(commodityNo->ToString());

  Local <Value> contractNo = jsonObj->Get(v8::String::NewFromUtf8(isolate, "contractNo"));
  if (contractNo->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->contractNo")));
    return ;
  }
  String::Utf8Value contractNo_(contractNo->ToString());

  Local <Value> strikePrice = jsonObj->Get(v8::String::NewFromUtf8(isolate, "strikePrice"));
  if (strikePrice->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->strikePrice")));
    return ;
  }
  String::Utf8Value strikePrice_(strikePrice->ToString());

  Local <Value> callOrPutFlag = jsonObj->Get(v8::String::NewFromUtf8(isolate, "callOrPutFlag"));
  if (callOrPutFlag->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->callOrPutFlag")));
    return ;
  }
  String::Utf8Value callOrPutFlag_(callOrPutFlag->ToString());

  Local <Value> contractNo2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "contractNo2"));
  if (contractNo2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->contractNo2")));
    return ;
  }
  String::Utf8Value contractNo2_(contractNo2->ToString());

  Local <Value> strikePrice2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "strikePrice2"));
  if (strikePrice2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->strikePrice2")));
    return ;
  }
  String::Utf8Value strikePrice2_(strikePrice2->ToString());

  Local <Value> callOrPutFlag2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "callOrPutFlag2"));
  if (callOrPutFlag2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->callOrPutFlag2")));
    return ;
  }
  String::Utf8Value callOrPutFlag2_(callOrPutFlag2->ToString());

  Local <Value> orderType = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderType"));
  if (orderType->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderType")));
    return ;
  }
  String::Utf8Value orderType_(orderType->ToString());

  Local <Value> orderSource = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderSource"));
  if (orderSource->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderSource")));
    return ;
  }
  String::Utf8Value orderSource_(orderSource->ToString());

  Local <Value> timeInForce = jsonObj->Get(v8::String::NewFromUtf8(isolate, "timeInForce"));
  if (timeInForce->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->timeInForce")));
    return ;
  }
  String::Utf8Value timeInForce_(timeInForce->ToString());

  Local <Value> expireTime = jsonObj->Get(v8::String::NewFromUtf8(isolate, "expireTime"));
  if (expireTime->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->expireTime")));
    return ;
  }
  String::Utf8Value expireTime_(expireTime->ToString());

  Local <Value> isRiskOrder = jsonObj->Get(v8::String::NewFromUtf8(isolate, "isRiskOrder"));
  if (isRiskOrder->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->isRiskOrder")));
    return ;
  }
  String::Utf8Value isRiskOrder_(isRiskOrder->ToString());

  Local <Value> orderSide = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderSide"));
  if (orderSide->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderSide")));
    return ;
  }
  String::Utf8Value orderSide_(orderSide->ToString());

  Local <Value> positionEffect = jsonObj->Get(v8::String::NewFromUtf8(isolate, "positionEffect"));
  if (positionEffect->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->positionEffect")));
    return ;
  }
  String::Utf8Value positionEffect_(positionEffect->ToString());

  Local <Value> positionEffect2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "positionEffect2"));
  if (positionEffect2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->positionEffect2")));
    return ;
  }
  String::Utf8Value positionEffect2_(positionEffect2->ToString());

  Local <Value> inquiryNo = jsonObj->Get(v8::String::NewFromUtf8(isolate, "inquiryNo"));
  if (inquiryNo->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->inquiryNo")));
    return ;
  }
  String::Utf8Value inquiryNo_(inquiryNo->ToString());

  Local <Value> hedgeFlag = jsonObj->Get(v8::String::NewFromUtf8(isolate, "hedgeFlag"));
  if (hedgeFlag->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->hedgeFlag")));
    return ;
  }
  String::Utf8Value hedgeFlag_(hedgeFlag->ToString());

  Local <Value> orderPrice = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderPrice"));
  if (orderPrice->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderPrice")));
    return ;
  }
  double orderPrice_ = orderPrice->NumberValue();

  Local <Value> orderPrice2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderPrice2"));
  if (orderPrice2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderPrice2")));
    return ;
  }
  String::Utf8Value orderPrice2_(orderPrice2->ToString());

  Local <Value> stopPrice = jsonObj->Get(v8::String::NewFromUtf8(isolate, "stopPrice"));
  if (stopPrice->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->stopPrice")));
    return ;
  }
  String::Utf8Value stopPrice_(stopPrice->ToString());

  Local <Value> orderQty = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderQty"));
  if (orderQty->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderQty")));
    return ;
  }
  int orderQty_ = orderQty->NumberValue();

  Local <Value> orderMinQty = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderMinQty"));
  if (orderMinQty->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderMinQty")));
    return ;
  }
  String::Utf8Value orderMinQty_(orderMinQty->ToString());

  Local <Value> minClipSize = jsonObj->Get(v8::String::NewFromUtf8(isolate, "minClipSize"));
  if (minClipSize->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->minClipSize")));
    return ;
  }
  String::Utf8Value minClipSize_(minClipSize->ToString());

  Local <Value> maxClipSize = jsonObj->Get(v8::String::NewFromUtf8(isolate, "maxClipSize"));
  if (maxClipSize->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->maxClipSize")));
    return ;
  }
  String::Utf8Value maxClipSize_(maxClipSize->ToString());

  Local <Value> refInt = jsonObj->Get(v8::String::NewFromUtf8(isolate, "refInt"));
  if (refInt->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->refInt")));
    return ;
  }
  String::Utf8Value refInt_(refInt->ToString());

  Local <Value> refString = jsonObj->Get(v8::String::NewFromUtf8(isolate, "refString"));
  if (refString->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->refString")));
    return ;
  }
  String::Utf8Value refString_(refString->ToString());

  Local <Value> tacticsType = jsonObj->Get(v8::String::NewFromUtf8(isolate, "tacticsType"));
  if (tacticsType->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->tacticsType")));
    return ;
  }
  String::Utf8Value tacticsType_(tacticsType->ToString());

  Local <Value> triggerCondition = jsonObj->Get(v8::String::NewFromUtf8(isolate, "triggerCondition"));
  if (triggerCondition->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->triggerCondition")));
    return ;
  }
  String::Utf8Value triggerCondition_(triggerCondition->ToString());

  Local <Value> triggerPriceType = jsonObj->Get(v8::String::NewFromUtf8(isolate, "triggerPriceType"));
  if (triggerPriceType->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->triggerPriceType")));
    return ;
  }
  String::Utf8Value triggerPriceType_(triggerPriceType->ToString());

  Local <Value> addOneIsValid = jsonObj->Get(v8::String::NewFromUtf8(isolate, "addOneIsValid"));
  if (addOneIsValid->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->addOneIsValid")));
    return ;
  }
  String::Utf8Value addOneIsValid_(addOneIsValid->ToString());

  Local <Value> orderQty2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderQty2"));
  if (orderQty2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderQty2")));
    return ;
  }
  String::Utf8Value orderQty2_(orderQty2->ToString());

  Local <Value> hedgeFlag2 = jsonObj->Get(v8::String::NewFromUtf8(isolate, "hedgeFlag2"));
  if (hedgeFlag2->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->hedgeFlag2")));
    return ;
  }
  String::Utf8Value hedgeFlag2_(hedgeFlag2->ToString());

  Local <Value> marketLevel = jsonObj->Get(v8::String::NewFromUtf8(isolate, "marketLevel"));
  if (marketLevel->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->marketLevel")));
    return ;
  }
  double marketLevel_ = marketLevel->NumberValue();

  Local <Value> orderDeleteByDisConnFlag = jsonObj->Get(v8::String::NewFromUtf8(isolate, "orderDeleteByDisConnFlag"));
  if (orderDeleteByDisConnFlag->IsUndefined()) {
    isolate->ThrowException(Exception::TypeError(String::NewFromUtf8(isolate, "Wrong arguments->orderDeleteByDisConnFlag")));
    return ;
  }
  String::Utf8Value orderDeleteByDisConnFlag_(orderDeleteByDisConnFlag->ToString());


  TapAPINewOrder req;
  memset(&req, 0, sizeof(req));
  log.append(" ");

  strcpy(req.AccountNo, ((std::string) * accountNo_).c_str());
	strcpy(req.ExchangeNo, ((std::string) * exchangeNo_).c_str());
	req.CommodityType = TAPI_COMMODITY_TYPE_FUTURES;
	strcpy(req.CommodityNo, ((std::string) * commodityNo_).c_str());
	strcpy(req.ContractNo, ((std::string) * contractNo_).c_str());
	strcpy(req.StrikePrice, "");
	req.CallOrPutFlag = TAPI_CALLPUT_FLAG_NONE;
	strcpy(req.ContractNo2, "");
	strcpy(req.StrikePrice2, "");
	req.CallOrPutFlag2 = TAPI_CALLPUT_FLAG_NONE;
	req.OrderType = TAPI_ORDER_TYPE_LIMIT;
	req.OrderSource = TAPI_ORDER_SOURCE_ESUNNY_API;
	req.TimeInForce = TAPI_ORDER_TIMEINFORCE_FAK;
	strcpy(req.ExpireTime, "");
	req.IsRiskOrder = APIYNFLAG_NO;
	req.OrderSide = TAPI_SIDE_SELL;
	req.PositionEffect = TAPI_PositionEffect_OPEN;
	req.PositionEffect2 = TAPI_PositionEffect_NONE;
	strcpy(req.InquiryNo,"");
	req.HedgeFlag = TAPI_HEDGEFLAG_T;
	req.OrderPrice = orderPrice_;
	req.OrderPrice2;
	req.StopPrice;
	req.OrderQty = orderQty_;
	req.OrderMinQty ;
	req.MinClipSize;
	req.MaxClipSize;
	req.RefInt;
	req.RefString;
	req.TacticsType = TAPI_TACTICS_TYPE_NONE;
	req.TriggerCondition = TAPI_TRIGGER_CONDITION_NONE;
	req.TriggerPriceType = TAPI_TRIGGER_PRICE_NONE;
	req.AddOneIsValid = APIYNFLAG_NO;
	req.OrderQty2;
	req.HedgeFlag2 = TAPI_HEDGEFLAG_NONE;
	req.MarketLevel = TAPI_MARKET_LEVEL_0;
	req.OrderDeleteByDisConnFlag = APIYNFLAG_NO;

  // strcpy(req.AccountNo, ((std::string) * accountNo_).c_str());
  // strcpy(req.ExchangeNo, ((std::string) * exchangeNo_).c_str());
  // strcpy(req.CommodityType, ((std::string) * commodityType_).c_str());
  // strcpy(req.CommodityNo, ((std::string) * commodityNo_).c_str());
  // strcpy(req.ContractNo, ((std::string) * contractNo_).c_str());
  // strcpy(req.StrikePrice, ((std::string) * strikePrice_).c_str());
  // req.CallOrPutFlag = ((std::string) * callOrPutFlag_)[0];
  // strcpy(req.ContractNo2, ((std::string) * contractNo2_).c_str());
  // strcpy(req.StrikePrice2, ((std::string) * strikePrice2_).c_str());
  // req.CallOrPutFlag2 = ((std::string) * callOrPutFlag2_)[0];
  // req.OrderType = ((std::string) * orderType_)[0];
  // req.OrderSource = ((std::string) * orderSource_)[0];
  // req.TimeInForce = ((std::string) * timeInForce_)[0];
  // strcpy(req.ExpireTime, ((std::string) * expireTime_).c_str());
  // req.IsRiskOrder = ((std::string) * isRiskOrder_)[0];
  // req.OrderSide = ((std::string) * orderSide_)[0];
  // req.PositionEffect = ((std::string) * positionEffect_)[0];
  // req.PositionEffect2 = ((std::string) * positionEffect2_)[0];
  // strcpy(req.InquiryNo, ((std::string) * inquiryNo_).c_str());
  // req.HedgeFlag = ((std::string) * hedgeFlag_)[0];
  // req.OrderPrice = ((std::string) * orderPrice_)[0];
  // req.OrderPrice2 = ((std::string) * orderPrice2_)[0];
  // req.StopPrice = ((std::string) * stopPrice_)[0];
  // req.OrderQty = ((std::string) * orderQty_)[0];
  // req.OrderMinQty = ((std::string) * orderMinQty_)[0];
  // req.MinClipSize = ((std::string) * minClipSize_)[0];
  // req.MaxClipSize = ((std::string) * maxClipSize_)[0];
  // req.RefInt = ((std::string) * refInt_)[0];
  // // req.RefString = ((std::string) * refString_)[0];
  // req.RefString;
  // req.TacticsType = ((std::string) * tacticsType_)[0];
  // req.TriggerCondition = ((std::string) * triggerCondition_)[0];
  // req.TriggerPriceType = ((std::string) * triggerPriceType_)[0];
  // req.AddOneIsValid= ((std::string) * addOneIsValid_)[0];
  // req.OrderQty2 = ((std::string) * orderQty2_)[0];
  // req.HedgeFlag2 = ((std::string) * hedgeFlag2_)[0];
  // req.MarketLevel = marketLevel_;
  // req.OrderDeleteByDisConnFlag = ((std::string) * orderDeleteByDisConnFlag_)[0];


  obj->uvTrader->ReqOrderInsert(&req, FunRtnCallback, uuid);
  return ;
}


void WrapTrader::FunCallback(CbRtnField *data) {
  Isolate *isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  std::map<int, Persistent<Function>>::iterator cIt = callback_map.find(data->eFlag);
  if (cIt == callback_map.end())
    return;

  switch (data->eFlag) {
  case T_ON_CONNECT: {
    Local <Value> argv[1] = {Undefined(isolate)};
    Local <Function> fn = Local<Function>::New(isolate, cIt->second);
    fn->Call(isolate->GetCurrentContext()->Global(), 1, argv);
    break;
  }
  case T_ON_API_READY: {
    Local <Value> argv[1] = {Integer::New(isolate, data->nReason)};
    Local <Function> fn = Local<Function>::New(isolate, cIt->second);
    fn->Call(isolate->GetCurrentContext()->Global(), 1, argv);
    break;
  }
  case T_ON_RSPUSERLOGIN: {
    Local <Value> argv[2];
    pkg_cb_userlogin(data, argv);
    Local<Function> fn = Local<Function>::New(isolate, cIt->second);
    fn->Call(isolate->GetCurrentContext()->Global(), 2, argv);
    break;
  }
  case T_ON_RSPINSERT: {
    Local <Value> argv[2];
    pkg_cb_orderinsert(data, argv);
    Local<Function> fn = Local<Function>::New(isolate, cIt->second);
    fn->Call(isolate->GetCurrentContext()->Global(), 2, argv);
    break;
  }
  }
}

void WrapTrader::FunRtnCallback(int result, void *baton) {
  Isolate *isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  LookupCtpApiBaton *tmp = static_cast<LookupCtpApiBaton *>(baton);
  if (tmp->uuid != -1) {
    std::map < int, Persistent < Function > > ::iterator
      it = fun_rtncb_map.find(tmp->uuid);

    const unsigned argc = 2;
    Local <Value> argv[argc] = {Integer::New(isolate, tmp->nResult), Integer::New(isolate, tmp->iRequestID)};

    Local <Function> fn = Local<Function>::New(isolate, it->second);
    fn->Call(isolate->GetCurrentContext()->Global(), argc, argv);
    it->second.Reset();
    fun_rtncb_map.erase(tmp->uuid);
  }
}

void WrapTrader::pkg_cb_userlogin(CbRtnField *data, Local <Value> *cbArray) {
  Isolate *isolate = Isolate::GetCurrent();

  *cbArray = Local<Value>::New(isolate, Number::New(isolate, 0));
  if (data->rtnField) {
    TapAPITradeLoginRspInfo *pRspUserLogin = static_cast<TapAPITradeLoginRspInfo *>(data->rtnField);
    Local <Object> jsonRtn = Object::New(isolate);
    jsonRtn->Set(String::NewFromUtf8(isolate, "UserNo"),
                 String::NewFromUtf8(isolate, pRspUserLogin->UserNo));

    Local<Value> str = Nan::Encode(pRspUserLogin->UserName, strlen(pRspUserLogin->UserName), Nan::Encoding::BUFFER);
    jsonRtn->Set(String::NewFromUtf8(isolate, "UserName"), str);
    jsonRtn->Set(String::NewFromUtf8(isolate, "QuoteTempPassword"), String::NewFromUtf8(isolate, pRspUserLogin->QuoteTempPassword));
    jsonRtn->Set(String::NewFromUtf8(isolate, "ReservedInfo"), String::NewFromUtf8(isolate, pRspUserLogin->ReservedInfo));
    jsonRtn->Set(String::NewFromUtf8(isolate, "LastLoginIP"),
                 String::NewFromUtf8(isolate, pRspUserLogin->LastLoginIP));
    jsonRtn->Set(String::NewFromUtf8(isolate, "LastLoginTime"), String::NewFromUtf8(isolate, pRspUserLogin->LastLoginTime));
    jsonRtn->Set(String::NewFromUtf8(isolate, "TradeDate"), String::NewFromUtf8(isolate, pRspUserLogin->TradeDate));
    jsonRtn->Set(String::NewFromUtf8(isolate, "LastSettleTime"),
                 String::NewFromUtf8(isolate, pRspUserLogin->LastSettleTime));
    jsonRtn->Set(String::NewFromUtf8(isolate, "StartTime"), String::NewFromUtf8(isolate, pRspUserLogin->StartTime));
    jsonRtn->Set(String::NewFromUtf8(isolate, "InitTime"), String::NewFromUtf8(isolate, pRspUserLogin->InitTime));
    *(cbArray+1) = jsonRtn;
  }
  else {
    *(cbArray+1) = Local<Value>::New(isolate, Undefined(isolate));
  }
  return;
}


void WrapTrader::pkg_cb_orderinsert(CbRtnField *data, Local <Value> *cbArray) {
  Isolate *isolate = Isolate::GetCurrent();

  *cbArray = Local<Value>::New(isolate, Number::New(isolate, 0));
  if (data->rtnField) {
    // TapAPITradeLoginRspInfo *pRspUserLogin = static_cast<TapAPITradeLoginRspInfo *>(data->rtnField);
    // Local <Object> jsonRtn = Object::New(isolate);
    // jsonRtn->Set(String::NewFromUtf8(isolate, "UserNo"),
    //              String::NewFromUtf8(isolate, pRspUserLogin->UserNo));

    // Local<Value> str = Nan::Encode(pRspUserLogin->UserName, strlen(pRspUserLogin->UserName), Nan::Encoding::BUFFER);
    // jsonRtn->Set(String::NewFromUtf8(isolate, "UserName"), str);
    // jsonRtn->Set(String::NewFromUtf8(isolate, "QuoteTempPassword"), String::NewFromUtf8(isolate, pRspUserLogin->QuoteTempPassword));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "ReservedInfo"), String::NewFromUtf8(isolate, pRspUserLogin->ReservedInfo));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "LastLoginIP"),
    //              String::NewFromUtf8(isolate, pRspUserLogin->LastLoginIP));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "LastLoginTime"), String::NewFromUtf8(isolate, pRspUserLogin->LastLoginTime));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "TradeDate"), String::NewFromUtf8(isolate, pRspUserLogin->TradeDate));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "LastSettleTime"),
    //              String::NewFromUtf8(isolate, pRspUserLogin->LastSettleTime));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "StartTime"), String::NewFromUtf8(isolate, pRspUserLogin->StartTime));
    // jsonRtn->Set(String::NewFromUtf8(isolate, "InitTime"), String::NewFromUtf8(isolate, pRspUserLogin->InitTime));
    // *(cbArray+1) = jsonRtn;
  }
  else {
    *(cbArray+1) = Local<Value>::New(isolate, Undefined(isolate));
  }
  return;
}

