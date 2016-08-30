#ifndef TAP_API_ERROR_H
#define TAP_API_ERROR_H

//=============================================================================
/**
 *	\addtogroup G_ERR_INNER_API		TapAPI�ڲ����صĴ����붨�塣
 *	@{
 */
//=============================================================================
//! �ɹ�
const int TAPIERROR_SUCCEED                                            = 0;
//! ���ӷ���ʧ��
const int TAPIERROR_ConnectFail                                        = -1;
//! ��·��֤ʧ��
const int TAPIERROR_LinkAuthFail                                       = -2;
//! ������ַ������
const int TAPIERROR_HostUnavailable                                    = -3;
//! �������ݴ���
const int TAPIERROR_SendDataError                                      = -4;
//! ���Ա�Ų��Ϸ�
const int TAPIERROR_TestIDError                                        = -5;
//! û׼���ò�������
const int TAPIERROR_NotReadyTestNetwork                                = -6;
//! ��ǰ������Ի�û����
const int TAPIERROR_CurTestNotOver                                     = -7;
//! û�ÿ��õĽ���ǰ��
const int TAPIERROR_NOFrontAvailable                                   = -8;
//! ����·��������
const int TAPIERROR_DataPathAvaiable                                   = -9;
//! �ظ���¼
const int TAPIERROR_RepeatLogin                                        = -10;
//! �ڲ�����	
const int TAPIERROR_InnerError                                         = -11;
//! ��һ������û�н���	
const int TAPIERROR_LastReqNotFinish                                   = -12;
//! ��������Ƿ�	
const int TAPIERROR_InputValueError                                    = -13;
//! ��Ȩ�벻�Ϸ�	
const int TAPIERROR_AuthCode_Invalid                                   = -14;
//! ��Ȩ�볬��	
const int TAPIERROR_AuthCode_Expired                                   = -15;
//! ��Ȩ�����Ͳ�ƥ��	
const int TAPIERROR_AuthCode_TypeNotMatch                              = -16;
//! API��û��׼����
const int TAPIERROR_API_NotReady                                       = -17;
//! UDP�˿ڼ���ʧ��
const int TAPIERROR_UDP_LISTEN_FAILED                                  = -18;
//! UDP���ڼ���
const int TAPIERROR_UDP_LISTENING                                      = -19;
//! �ӿ�δʵ��
const int TAPIERROR_NotImplemented                                     = -20;
//! ÿ�ε�½ֻ�������һ��
const int TAPIERROR_CallOneTimeOnly                                    = -21;

/** @}*/


//=============================================================================
/**
 *	\addtogroup G_ERR_INPUT_CHECK		�������������
 *	@{
 */
//=============================================================================
//! ��������ΪNULL
const int TAPIERROR_INPUTERROR_NULL                                    = -10000;
//! ��������:TAPIYNFLAG
const int TAPIERROR_INPUTERROR_TAPIYNFLAG                              = -10001;
//! ��������:TAPILOGLEVEL
const int TAPIERROR_INPUTERROR_TAPILOGLEVEL                            = -10002;
//! ��������:TAPICommodityType
const int TAPIERROR_INPUTERROR_TAPICommodityType                       = -10003;
//! ��������:TAPICallOrPutFlagType
const int TAPIERROR_INPUTERROR_TAPICallOrPutFlagType                   = -10004;
//! ��������:TAPIBucketDateFlag
const int TAPIERROR_INPUTERROR_TAPIBucketDateFlag                      = -11001;
//! ��������:TAPIHisQuoteType
const int TAPIERROR_INPUTERROR_TAPIHisQuoteType                        = -11002;
//! ��������:TAPIAccountType
const int TAPIERROR_INPUTERROR_TAPIAccountType                         = -12001;
//! ��������:TAPIUserTypeType
const int TAPIERROR_INPUTERROR_TAPIUserTypeType                        = -12002;
//! ��������:TAPIAccountState
const int TAPIERROR_INPUTERROR_TAPIAccountState                        = -12003;
//! ��������:TAPIAccountFamilyType
const int TAPIERROR_INPUTERROR_TAPIAccountFamilyType                   = -12004;
//! ��������:TAPIOrderTypeType
const int TAPIERROR_INPUTERROR_TAPIOrderTypeType                       = -12005;
//! ��������:TAPIOrderSourceType
const int TAPIERROR_INPUTERROR_TAPIOrderSourceType                     = -12006;
//! ��������:TAPITimeInForceType
const int TAPIERROR_INPUTERROR_TAPITimeInForceType                     = -12007;
//! ��������:TAPISideType
const int TAPIERROR_INPUTERROR_TAPISideType                            = -12008;
//! ��������:TAPIPositionEffectType
const int TAPIERROR_INPUTERROR_TAPIPositionEffectType                  = -12009;
//! ��������:TAPIHedgeFlagType
const int TAPIERROR_INPUTERROR_TAPIHedgeFlagType                       = -12010;
//! ��������:TAPIOrderStateType
const int TAPIERROR_INPUTERROR_TAPIOrderStateType                      = -12011;
//! ��������:TAPICalculateModeType
const int TAPIERROR_INPUTERROR_TAPICalculateModeType                   = -12012;
//! ��������:TAPIMatchSourceType
const int TAPIERROR_INPUTERROR_TAPIMatchSourceType                     = -12013;
//! ��������:TAPIOpenCloseModeType
const int TAPIERROR_INPUTERROR_TAPIOpenCloseModeType                   = -12014;
//! ��������:TAPIFutureAlgType
const int TAPIERROR_INPUTERROR_TAPIFutureAlgType                       = -12015;
//! ��������:TAPIOptionAlgType
const int TAPIERROR_INPUTERROR_TAPIOptionAlgType                       = -12016;
//! ��������:TAPIBankAccountLWFlagType
const int TAPIERROR_INPUTERROR_TAPIBankAccountLWFlagType               = -12017;
//! ��������:TAPIBankAccountStateType
const int TAPIERROR_INPUTERROR_TAPIBankAccountStateType                = -12018;
//! ��������:TAPIBankAccountSwapStateType
const int TAPIERROR_INPUTERROR_TAPIBankAccountSwapStateType            = -12019;
//! ��������:TAPIBankAccountTransferStateType
const int TAPIERROR_INPUTERROR_TAPIBankAccountTransferStateType        = -12020;
//! ��������:TAPIMarginCalculateModeType
const int TAPIERROR_INPUTERROR_TAPIMarginCalculateModeType             = -12021;
//! ��������:TAPIOptionMarginCalculateModeType
const int TAPIERROR_INPUTERROR_TAPIOptionMarginCalculateModeType       = -12022;
//! ��������:TAPICmbDirectType
const int TAPIERROR_INPUTERROR_TAPICmbDirectType                       = -12023;
//! ��������:TAPIDeliveryModeType
const int TAPIERROR_INPUTERROR_TAPIDeliveryModeType                    = -12024;
//! ��������:TAPIContractTypeType
const int TAPIERROR_INPUTERROR_TAPIContractTypeType                    = -12025;
//! ��������:TAPIPartyTypeType
const int TAPIERROR_INPUTERROR_TAPIPartyTypeType                       = -12026;
//! ��������:TAPIPartyCertificateTypeType
const int TAPIERROR_INPUTERROR_TAPIPartyCertificateTypeType            = -12027;
//! ��������:TAPIMsgReceiverType
const int TAPIERROR_INPUTERROR_TAPIMsgReceiverType                     = -12028;
//! ��������:TAPIMsgTypeType
const int TAPIERROR_INPUTERROR_TAPIMsgTypeType                         = -12029;
//! ��������:TAPIMsgLevelType
const int TAPIERROR_INPUTERROR_TAPIMsgLevelType                        = -12030;
//! ��������:TAPITransferDirectType
const int TAPIERROR_INPUTERROR_TAPITransferDirectType                  = -12031;
//! ��������:TAPITransferStateType
const int TAPIERROR_INPUTERROR_TAPITransferStateType                   = -12032;
//! ��������:TAPITransferTypeType
const int TAPIERROR_INPUTERROR_TAPITransferTypeType                    = -12033;
//! ��������:TAPITransferDeviceIDType
const int TAPIERROR_INPUTERROR_TAPITransferDeviceIDType                = -12034;
//! ��������:TAPITacticsTypeType
const int TAPIERROR_INPUTERROR_TAPITacticsTypeType                     = -12035;
//! ��������:TAPIORDERACT
const int TAPIERROR_INPUTERROR_TAPIORDERACT                            = -12036;
//! ��������:TAPIBillTypeType
const int TAPIERROR_INPUTERROR_TAPIBillTypeType                        = -12037;
//! ��������:TAPIBillFileTypeType
const int TAPIERROR_INPUTERROR_TAPIBillFileTypeType                    = -12038;
//! ��������:TAPIOFFFlagType
const int TAPIERROR_INPUTERROR_TAPIOFFFlagType                         = -12039;
//! ��������:TAPICashAdjustTypeType
const int TAPIERROR_INPUTERROR_TAPICashAdjustTypeType                  = -12040;
//! ��������:TAPITriggerConditionType
const int TAPIERROR_INPUTERROR_TAPITriggerConditionType                = -12041;
//! ��������:TAPITriggerPriceTypeType
const int TAPIERROR_INPUTERROR_TAPITriggerPriceTypeType                = -12042;
//! ��������:TAPITradingStateType 
const int TAPIERROR_INPUTERROR_TAPITradingStateType                    = -12043;
//! ��������:TAPIMarketLevelType 
const int TAPIERROR_INPUTERROR_TAPIMarketLevelType                     = -12044;
//! ��������:TAPIOrderQryTypeType 
const int TAPIERROR_INPUTERROR_TAPIOrderQryTypeType                    = -12045;

//! ��ʷ�����ѯ�������Ϸ�
const int TAPIERROR_INPUTERROR_QryHisQuoteParam                        = -13001;

/** @}*/

//=============================================================================
/**
 *	\addtogroup G_ERR_DISCONNECT_REASON	����Ͽ�������붨��
 *	@{
 */
//=============================================================================
//! �����Ͽ�
const int TAPIERROR_DISCONNECT_CLOSE_INIT                              = 1;
//! �����Ͽ�
const int TAPIERROR_DISCONNECT_CLOSE_PASS                              = 2;
//! ������
const int TAPIERROR_DISCONNECT_READ_ERROR                              = 3;
//! д����
const int TAPIERROR_DISCONNECT_WRITE_ERROR                             = 4;
//! ��������
const int TAPIERROR_DISCONNECT_BUF_FULL                                = 5;
//! �첽��������
const int TAPIERROR_DISCONNECT_IOCP_ERROR                              = 6;
//! �������ݴ���
const int TAPIERROR_DISCONNECT_PARSE_ERROR                             = 7;
//! ���ӳ�ʱ
const int TAPIERROR_DISCONNECT_CONNECT_TIMEOUT                         = 8;
//! ��ʼ��ʧ��
const int TAPIERROR_DISCONNECT_INIT_ERROR                              = 9;
//! �Ѿ�����
const int TAPIERROR_DISCONNECT_HAS_CONNECTED                           = 10;
//! �����߳��ѽ���
const int TAPIERROR_DISCONNECT_HAS_EXIT                                = 11;
//! �������ڽ��У����Ժ�����
const int TAPIERROR_DISCONNECT_TRY_LATER                               = 12;

/** @}*/

//=============================================================================
/**
 *	\addtogroup G_ERR_BUSINESS	ҵ�񷵻صĴ�����붨��
 *	@{
 */
//=============================================================================


//==============================================================================
//! ��¼����ִ�д���
const int TAPIERROR_LOGIN = 10001;
//! ��¼�û�������
const int TAPIERROR_LOGIN_USER = 10002;
//! ��Ҫ���ж�̬��֤
const int TAPIERROR_LOGIN_DDA = 10003;
//! ��¼�û�δ��Ȩ
const int TAPIERROR_LOGIN_LICENSE = 10004;
//! ��¼ģ�鲻��ȷ
const int TAPIERROR_LOGIN_MODULE = 10005;
//! ��Ҫǿ���޸�����
const int TAPIERROR_LOGIN_FORCE = 10006;
//! ��¼״̬��ֹ��½
const int TAPIERROR_LOGIN_STATE = 10007;
//! ��¼���벻��ȷ
const int TAPIERROR_LOGIN_PASS = 10008;
//! û�и�ģ���¼Ȩ��
const int TAPIERROR_LOGIN_RIGHT = 10009;
//! ��¼��������
const int TAPIERROR_LOGIN_COUNT = 10010;
//! ��¼�û����ڷ�������ʶ�¿ɵ�¼�û��б���
const int TAPIERROR_LOGIN_NOTIN_SERVERFLAGUSRES = 10011;
//! ��½�û���������֤����
const int TAPIERROR_LOGIN_TRADEDATE = 10012;
//! ��½�û��������ͻ�
const int TAPIERROR_LOGIN_NO_ACCOUNT = 10013;
//==============================================================================
//! ��¼�û���Ϣ��ѯʧ��
const int TAPIERROR_USERINFO_QRY = 10101;
//! ��¼�û���Ϣ����ʧ��
const int TAPIERROR_USERINFO_ADD = 10102;
//! ��¼�û���Ϣ�޸�ʧ��
const int TAPIERROR_USERINFO_MOD = 10103;
//! ��¼�û���Ϣɾ��ʧ��
const int TAPIERROR_USERINFO_DEL = 10104;
//! ���ڹ�����Ϣ��ɾ��ʧ��
const int TAPIERROR_ACCOUNTNO_IN_USERINFO_DEL = 10105;

//==============================================================================
//! ��¼�û�״̬��ѯʧ��
const int TAPIERROR_USERSTATE_QRY = 10201;
//! ��¼�û�״̬����ʧ��
const int TAPIERROR_USERSTATE_ADD = 10202;
//! ��¼�û�״̬�޸�ʧ��
const int TAPIERROR_USERSTATE_MOD = 10203;
//! ��¼�û�״̬ɾ��ʧ��
const int TAPIERROR_USERSTATE_DEL = 10204;

//==============================================================================
//! �����Ȩ��Ϣ��ѯʧ��
const int TAPIERROR_LICENSEINFO_QRY = 10301;
//! �����Ȩ��Ϣ����ʧ��
const int TAPIERROR_LICENSEINFO_ADD = 10302;
//! �����Ȩ��Ϣ�޸�ʧ��
const int TAPIERROR_LICENSEINFO_MOD = 10303;
//! �����Ȩ��Ϣɾ��ʧ��
const int TAPIERROR_LICENSEINFO_DEL = 10304;
//! ���ڹ�����Ϣ��ɾ��ʧ��
const int TAPIERROR_LICENSEINFO_IN_USERLICENSE_DEL = 10305;

//==============================================================================
//! ��¼�û������Ȩ��ѯʧ��
const int TAPIERROR_USERLICENSE_QRY = 10401;
//! ��¼�û������Ȩ����ʧ��
const int TAPIERROR_USERLICENSE_ADD = 10402;
//! ��¼�û������Ȩɾ��ʧ��
const int TAPIERROR_USERLICENSE_DEL = 10403;

//==============================================================================
//! Ȩ����Ϣ��ѯʧ��
const int TAPIERROR_RIGHTINFO_QRY = 10501;

//==============================================================================
//! ��ɫ��Ϣ��ѯʧ��
const int TAPIERROR_ROLEINFO_QRY = 10601;
//! ��ɫ��Ϣ����ʧ��
const int TAPIERROR_ROLEINFO_ADD = 10602;
//! ��ɫ��Ϣ�޸�ʧ��
const int TAPIERROR_ROLEINFO_MOD = 10603;
//! ��ɫ��Ϣɾ��ʧ��
const int TAPIERROR_ROLEINFO_DEL = 10604;
//! ���ڹ�����Ϣ��ɾ��ʧ��
const int TAPIERROR_ROLENO_IN_USERROLE_DEL = 10605;

//==============================================================================
//! ��ɫ����Ȩ�޲�ѯʧ��
const int TAPIERROR_ROLERIGHT_QRY = 10701;
//! ��ɫ����Ȩ������ʧ��
const int TAPIERROR_ROLERIGHT_ADD = 10702;
//! ��ɫ����Ȩ��ɾ��ʧ��
const int TAPIERROR_ROLERIGHT_DEL = 10703;

//==============================================================================
//! ��¼�û�������ɫ��ѯʧ��
const int TAPIERROR_USERROLE_QRY = 10801;
//! ��¼�û�������ɫ����ʧ��
const int TAPIERROR_USERROLE_ADD = 10802;
//! ��¼�û�������ɫɾ��ʧ��
const int TAPIERROR_USERROLE_DEL = 10803;

//==============================================================================
//! ��¼�û�����Ȩ�޲�ѯʧ��
const int TAPIERROR_USERRIGHT_QRY = 10901;
//! ��¼�û�����Ȩ������ʧ��
const int TAPIERROR_USERRIGHT_ADD = 10902;
//! ��¼�û�����Ȩ��ɾ��ʧ��
const int TAPIERROR_USERRIGHT_DEL = 10903;

//==============================================================================
//! ��¼�û���������Ȩ�޲�ѯʧ��
const int TAPIERROR_USERALLRIGHT_QRY = 11001;
//! ��¼�û���������Ȩ������֪ͨʧ��
const int TAPIERROR_USERALLRIGHT_ADD_NOTICE = 11002;
//! ��¼�û���������Ȩ��ɾ��֪ͨʧ��
const int TAPIERROR_USERALLRIGHT_DEL_NOTICE = 11003;

//==============================================================================
//! �˺ŷ�����Ϣ��ѯʧ��
const int TAPIERROR_ACCOUNTGROUPINFO_QRY = 11101;
//! �˺ŷ�����Ϣ����ʧ��
const int TAPIERROR_ACCOUNTGROUPINFO_ADD = 11102;
//! �˺ŷ�����Ϣ�޸�ʧ��
const int TAPIERROR_ACCOUNTGROUPINFO_MOD = 11103;
//! �˺ŷ�����Ϣɾ��ʧ��
const int TAPIERROR_ACCOUNTGROUPINFO_DEL = 11104;

//==============================================================================
//! �˺ŷ��������ʽ��˺Ų�ѯʧ��
const int TAPIERROR_GROUPACCOUNT_QRY = 11201;
//! �˺ŷ��������ʽ��˺�����ʧ��
const int TAPIERROR_GROUPACCOUNT_ADD = 11202;
//! �˺ŷ��������ʽ��˺�ɾ��ʧ��
const int TAPIERROR_GROUPACCOUNT_DEL = 11203;
//! �˺ŷ��������ʽ��˺�����ʧ�ܣ��÷�������һ���ͻ�ֻ�ܶ�Ӧһ������
const int TAPIERROR_GROUPACCOUNT_ONETOONE = 11204;

//==============================================================================
//! ��¼�û������˺ŷ����ѯʧ��
const int TAPIERROR_USERGROUP_QRY = 11301;
//! ��¼�û������˺ŷ�������ʧ��
const int TAPIERROR_USERGROUP_ADD = 11302;
//! ��¼�û������˺ŷ���ɾ��ʧ��
const int TAPIERROR_USERGROUP_DEL = 11303;

//==============================================================================
//! ��¼�û������ʽ��˺Ų�ѯʧ��
const int TAPIERROR_USERACCOUNT_QRY = 11401;
//! ��¼�û������ʽ��˺�����ʧ��
const int TAPIERROR_USERACCOUNT_ADD = 11402;
//! ��¼�û������ʽ��˺�ɾ��ʧ��
const int TAPIERROR_USERACCOUNT_DEL = 11403;

//==============================================================================
//! ��¼�û����������ʽ��˺Ų�ѯʧ��
const int TAPIERROR_USERALLACCOUNT_QRY = 11501;
//! ��¼�û����������ʽ��˺�����֪ͨʧ��
const int TAPIERROR_USERALLACCOUNT_ADD_NOTICE = 11502;
//! ��¼�û����������ʽ��˺�ɾ��֪ͨʧ��
const int TAPIERROR_USERALLACCOUNT_DEL_NOTICE = 11503;

//==============================================================================
//! ����������Ϣ��ѯʧ��
const int TAPIERROR_PASSWORDTYPEINFO_QRY = 11601;
//! ����������Ϣ��ѯʧ��
const int TAPIERROR_PASSWORDTYPEINFO_MOD = 11602;

//==============================================================================
//! ��¼�û������޸�ʧ��
const int TAPIERROR_USERPASSWORD_MOD = 11701;
//! ��¼�û������޸�ʧ�ܡ���ԭʼ�������
const int TAPIERROR_USERPASSWORD_MOD_SOURCE = 11702;
//! ��¼�û������޸�ʧ�ܡ���������ǰn��������ͬ
const int TAPIERROR_USERPASSWORD_MOD_SAME = 11703;
//! �����벻�������븴�Ӷ�Ҫ��
const int TAPIERROR_USERPASSWORD_MOD_COMPLEXITY = 11704;

//==============================================================================
//! ������Ϣ��ѯʧ��
const int TAPIERROR_LINKINFO_QRY = 11801;
//! ������ϸ��Ϣ��ѯʧ��
const int TAPIERROR_LINKDETAILINFO_QRY = 11802;
//! ������Ϣɾ��ʧ��
const int TAPIERROR_LINKINFO_DEL = 11803;

//==============================================================================
//! ��¼�û�Ԥ����Ϣ�޸�ʧ��
const int TAPIERROR_USERRESERVEDINFO_MOD = 11901;

//==============================================================================
//! ��������ʶ�¿ɵ�¼�û��б��ѯʧ��
const int TAPIERROR_SERVERFLAGUSERS_QRY = 12001;
//! ��������ʶ�¿ɵ�¼�û��б�����ʧ��
const int TAPIERROR_SERVERFLAGUSERS_ADD = 12002;
//! ��������ʶ�¿ɵ�¼�û��б�ɾ��ʧ��
const int TAPIERROR_SERVERFLAGUSERS_DEL = 12003;

//==============================================================================
//! ����������Ϣ��ʧ��
const int TAPIERROR_GROUPPROPERTYINFO_QRY = 12011;
//! ����������Ϣ����ʧ��
const int TAPIERROR_GROUPPROPERTYINFO_ADD = 12012;
//! ����������Ϣ�޸�ʧ��
const int TAPIERROR_GROUPPROPERTYINFO_MOD = 12013;
//! ����������Ϣɾ��ʧ��
const int TAPIERROR_GROUPPROPERTYINFO_DEL = 12014;

//==============================================================================
//! �ڲ�������֤����ʧ��  
const int TAPIERROR_INTERFUTUREBANKPASSWORDAUTH_REQ = 12021;

//==============================================================================
//! �ʽ��˺�������������޸�����ʧ��  
const int TAPIERROR_ACCOUNTPASSWORD_MOD = 12031;
//! �ʽ��˺����������û��޸�����ʧ��  
const int TAPIERROR_ACCOUNTPASSWORDUSER_MOD = 12032;
//! �ʽ��˺����������޸�ԭʼ�������
const int TAPIERROR_ACCOUNTPASSWORD_ERROR = 12033;

//==============================================================================
const int TAPIERROR_LOGININFO_QRY = 12041;

//==============================================================================
//! �û������ѯ����
const int TAPIERROR_USERPASSWORD_QRY = 12051;

//==============================================================================
//! ��̨�汾У�����
const int TAPIERROR_MANAGEVER_VERY = 12061;

//==============================================================================
//! �û���ɫȨ�޷����ѯ
const int TAPIERROR_USERRIGHTSPLITQRY_QRY = 12071;

//==============================================================================
//! �û���Ӧ������ģ���ѯ����
const int TAPIERROR_USERFEETEMPLATE_QRY = 12101;
//! �û���Ӧ������ģ�����Ӵ���
const int TAPIERROR_USERFEETEMPLATE_ADD = 12102;
//! �û���Ӧ������ģ��ɾ������
const int TAPIERROR_USERFEETEMPLATE_DEL = 12103;
//! �û���Ӧ��֤��ģ���ѯ����
const int TAPIERROR_USERMARGINTEMPLATE_QRY = 12104;
//! �û���Ӧ��֤��ģ�����Ӵ���
const int TAPIERROR_USERMARGINTEMPLATE_ADD = 12105;
//! �û���Ӧ��֤��ģ��ɾ������
const int TAPIERROR_USERMARGINTEMPLATE_DEL = 12106;

//==============================================================================
//! �ʽ��˺Ų�����
const int TAPIERROR_ORDERINSERT_ACCOUNT = 60001;
//! �ʽ��˺�״̬����ȷ
const int TAPIERROR_ORDERINSERT_ACCOUNT_STATE = 60002;

//! �µ���Ч�ĺ�Լ
const int TAPIERROR_ORDERINSERT_CONTRACT = 60011;

//! �µ���Լ�޽���·��
const int TAPIERROR_ORDERINSERT_TRADEROUTE = 60021;
//! �ֲ��������������
const int TAPIERROR_ORDERINSERT_POSITIONMAX = 60022;
//! ��ֹ����
const int TAPIERROR_ORDER_NOTRADE = 60023;
//! ֻ��ƽ��
const int TAPIERROR_ORDER_CLOSE = 60024;
//! �µ��ʽ���
const int TAPIERROR_ORDERINSERT_NOTENOUGHFUND = 60031;
//! ��֧�ֵĶ�������
const int TAPIERROR_ORDERINSERT_ORDERTYPE = 60032;
//! ��֧�ֵ�ʱ����Ч����
const int TAPIERROR_ORDERINSERT_TIMEINFORCE = 60033;
//! ��֧�ֵĲ��Ե�����
const int TAPIERROR_ORDERINSERT_NO_TACTICS = 60034;
//! ƽ�������������гֲ���
const int TAPIERROR_ORDERINSERT_POSITION_CANNOT_CLOSE = 60035;
//! �µ��Զ����ʧ��
const int TAPIERROR_ORDERINSERT_AUTOCHECK_FAIL = 60036;
//! LMEδ׼������
const int TAPIERROR_ORDERINSERT_LME_NOTREADY = 60037;
//! ƽ�ַ�ʽ����
const int TAPIERROR_ORDERINSERT_CLOSEMODE = 60038;
//! �µ���Ӧ�ĸ��˺��ʽ���
const int TAPIERROR_ORDERINSERT_PARENTNOTENOUGHFUND = 60039;
//! �������ĺ�Լ��ʽ����
const int TAPIERROR_SWAP_CONTRACT = 60040;

//! ��ǰ�ͻ�����ʹ�ô��˺Ž���
const int TAPIERROR_USERNO_NOTHAS_ACCOUNT = 60051;
//! ����ͨ��״̬������
const int TAPIERROR_UPPERCHANNEL_BROKEN = 60052;
//! ����ͨ��δ��ͨEXIST
const int TAPIERROR_UPPERCHANNEL_NOT_EXIST = 60053;

//! �����޴�ϵͳ��
const int TAPIERROR_ORDERDELETE_NOT_SYSNO = 60061;
//! ��״̬��������
const int TAPIERROR_ORDERDELETE_NOT_STATE = 60062;
//! ��״̬��������
const int TAPIERROR_ORDERACTIVE_NOT_STATE = 60063;

//! ��״̬��ֹ���
const int TAPIERROR_ORDERCHECK_NOT_STATE = 60071;
//! �������ʧ��
const int TAPIERROR_ORDERCHECK_FAIL = 60072;

//! ��״̬������ĵ�
const int TAPIERROR_ORDERMODIFY_NOT_STATE = 60081;
//! �˹���������ĵ�
const int TAPIERROR_ORDERMODIFY_BACK_INPUT = 60082;

//! �����Ѳ�������
const int TAPIERROR_ORDERINSERT_FEE = 60091;
//! ��֤���������
const int TAPIERROR_ORDERINSERT_MARGIN = 60092;

//! �����˺�ֻ�ɲ�ѯ
const int TAPIERROR_ORDER_NO_PERMIT = 60100;

//! �������̲���Ӧ��
const int TAPIERROR_RSPQUOTE_NO_PERMIT = 60101;
//! ��ʹ���ʺ����������̲���Ӧ��
const int TAPIERROR_RSPQUOTE_CHILD_NO_PERMIT = 60102;
//! �µ��Ҳ������ױ���
const int TAPIERROR_TRADENO_NOT_FIND = 60103;
//! �����˺�ֻ�ɿ���
const int TAPIERROR_ORDER_NO_CLOSE = 60104;
//! �����˺�û�����ڹҵ���ѯȨ��
const int TAPIERROR_QRY_QUOTE_NO_PERMIT = 60105;
//! ������Ч������С�ڵ�ǰ������
const int TAPIERROR_EXPIREDATE_NO_PERMIT = 60106;
//! �ñ��벻��������������
const int TAPIERROR_CMB_NO_PERMIT = 60107;
//! �Ǳ�����������µ��˺Ų��������
const int TAPIERROR_ORDERSERVER_NO_PERMIT = 60108;
//! ��Ȩ����Ȩ������������
const int TAPIERROR_POSITION_CANNOT_EXEC_OR_ABANDON = 60109;
//! û�ж������Ȩ��
const int TAPIERROR_ORDERCHECK_NO_PERMIT = 60110;
//! ����������󿪲���
const int TAPIERROR_ORDERMAXOPENVOL_NO_PERMIT = 60111;
//==============================================================================
//! ���ֲ�ѯʧ��
const int TAPIERROR_CURRENCYINFO_QRY = 20101;
//! ���ױ��ֲ�ѯʧ��
const int TAPIERROR_TCURRENCYINFO_QRY = 20102;
//! ��������ʧ��
const int TAPIERROR_CURRENCYINFO_ADD = 20103;
//! ����ɾ��ʧ��
const int TAPIERROR_CURRENCYINFO_DEL = 20104;
//! �����޸�ʧ��
const int TAPIERROR_CURRENCYINFO_MOD = 20105;
//! ���ּ���ɾ��ʧ��
const int TAPIERROR_CURRENCYINFO_CASCADE_DEL = 20106;
//! ���ֻ��ʱ����ʷ��ˮ��ѯʧ��
const int TAPIERROR_CURRENCYCHANGE_INFO_QRY = 20107;
//==============================================================================
//! �ʽ��˺���Ϣ��ѯʧ��
const int TAPIERROR_ACCOUNTINFO_QRY = 20201;
//! �ʽ��˺�ժҪ��ѯʧ��
const int TAPIERROR_ACCOUNTSUMMARY_QRY = 20202;
//! �ʽ��˺���Ϣ����ʧ��
const int TAPIERROR_ACCOUNTINFO_ADD = 20203;
//! �ʽ��˺���Ϣɾ��ʧ��
const int TAPIERROR_ACCOUNTINFO_DEL = 20204;
//! �ʽ��˺���Ϣ�޸�ʧ��
const int TAPIERROR_ACCOUNTINFO_MOD = 20205;
//! ȫ���ʽ��˺���Ϣ��ѯʧ��
const int TAPIERROR_ALLACCOUNTINFO_QRY = 20206;
//==============================================================================
//! �����ͻ���Ϣ��ѯʧ��
const int TAPIERROR_ORGINFO_QRY = 20301;
//! �����ͻ���Ϣ����ʧ��
const int TAPIERROR_ORGINFO_ADD = 20302;
//! �����ͻ���Ϣɾ��ʧ��
const int TAPIERROR_ORGINFO_DEL = 20303;
//! �����ͻ���Ϣ�޸�ʧ��
const int TAPIERROR_ORGINFO_MOD = 20304;

//==============================================================================
//! �ͻ�֤����Ϣ��ѯʧ��
const int TAPIERROR_ACCOUNTCERTIFICATE_QRY = 20401;
//! �ͻ�֤����Ϣ����ʧ��
const int TAPIERROR_ACCOUNTCERTIFICATE_ADD = 20402;
//! �ͻ�֤����Ϣɾ��ʧ��
const int TAPIERROR_ACCOUNTCERTIFICATE_DEL = 20403;
//! �ͻ�֤����Ϣ�޸�ʧ��
const int TAPIERROR_ACCOUNTCERTIFICATE_MOD = 20404;

//==============================================================================
//! �ͻ����ʽ��˺Ų�ѯʧ��
const int TAPIERROR_PARENTACCOUNT_QRY = 20501;
//! �ͻ����ʽ��˺Ų�ѯʧ��(����)
const int TAPIERROR_TPARENTACCOUNT_QRY = 20502;
//! �ͻ����ʽ��˺�����ʧ��
const int TAPIERROR_PARENTACCOUNT_ADD = 20503;
//! �ͻ����ʽ��˺�ɾ��ʧ��
const int TAPIERROR_PARENTACCOUNT_DEL = 20504;
//! �ͻ����ʽ��˺��޸�ʧ��
const int TAPIERROR_PARENTACCOUNT_MOD = 20505;

//==============================================================================
//! ��������Ϣ��ѯʧ��
const int TAPIERROR_EXCHANGEINFO_QRY = 20601;
//! ��������Ϣ����ʧ��
const int TAPIERROR_EXCHANGEINFO_ADD = 20602;
//! ��������Ϣɾ��ʧ��
const int TAPIERROR_EXCHANGEINFO_DEL = 20603;
//! ��������Ϣ�޸�ʧ��
const int TAPIERROR_EXCHANGEINFO_MOD = 20604;

//==============================================================================
//! �ͻ����ױ����ѯʧ��
const int TAPIERROR_TRADENO_QRY = 20701;
//! �ͻ����ױ�������ʧ��
const int TAPIERROR_TRADENO_ADD = 20702;
//! �ͻ����ױ���ɾ��ʧ��
const int TAPIERROR_TRADENO_DEL = 20703;
//! �ͻ����ױ����޸�ʧ��
const int TAPIERROR_TRADENO_MOD = 20704;
//! �ͻ����ױ����˻��Ѵ���
const int TAPIERROR_TRADENO_EXIT = 20705;

//==============================================================================
//! �ͻ�������Ϣ��ѯʧ��			
const int TAPIERROR_ACCOUNTBANKINFO_QRY = 20801;
//! �ͻ�������Ϣ����ʧ��			
const int TAPIERROR_ACCOUNTBANKINFO_ADD = 20802;
//! �ͻ�������Ϣɾ��ʧ��			
const int TAPIERROR_ACCOUNTBANKINFO_DEL = 20803;
//! �ͻ�������Ϣ�޸�ʧ��			
const int TAPIERROR_ACCOUNTBANKINFO_MOD = 20804;

//==============================================================================
//! ��ϵ����Ϣ��ѯʧ��		
const int TAPIERROR_PARTYINFO_QRY = 20901;
//! ��ϵ����Ϣ����ʧ��		
const int TAPIERROR_PARTYINFO_ADD = 20902;
//! ��ϵ����Ϣɾ��ʧ��		
const int TAPIERROR_PARTYINFO_DEL = 20903;
//! ��ϵ����Ϣ�޸�ʧ��		
const int TAPIERROR_PARTYINFO_MOD = 20904;

//==============================================================================
//! ������Ϣ��ѯʧ��
const int TAPIERROR_ATTRIBUTEINFO_QRY = 21001;
//! ������Ϣ����ʧ��
const int TAPIERROR_ATTRIBUTEINFO_ADD = 21002;
//! ������Ϣɾ��ʧ��
const int TAPIERROR_ATTRIBUTEINFO_DEL = 21003;
//! ������Ϣ�޸�ʧ��
const int TAPIERROR_ATTRIBUTEINFO_MOD = 21004;

//==============================================================================
//! �ͻ�������Ϣ��ѯʧ��
const int TAPIERROR_ACCOUNTATTRIBUTE_QRY = 21101;
//! �ͻ�������Ϣ����ʧ��
const int TAPIERROR_ACCOUNTATTRIBUTE_ADD = 21102;
//! �ͻ�������Ϣ�޸�ʧ��
const int TAPIERROR_ACCOUNTATTRIBUTE_MOD = 21103;

//==============================================================================
//! ������Ϣ��ѯʧ��
const int TAPIERROR_UPPERINFO_QRY = 21201;
//! ������Ϣ����ʧ��
const int TAPIERROR_UPPERINFO_ADD = 21202;
//! ������Ϣɾ��ʧ��
const int TAPIERROR_UPPERINFO_DEL = 21203;
//! ������Ϣ�޸�ʧ��
const int TAPIERROR_UPPERINFO_MOD = 21204;
//! ������Ϣ����ɾ��ʧ��
const int TAPIERROR_UPPERINFO_CASCADE_DEL = 21205;

//==============================================================================
//! ����������Ϣ��ѯʧ��
const int TAPIERROR_UPPERBANKINFO_QRY = 21301;
//! ����������Ϣ����ʧ��
const int TAPIERROR_UPPERBANKINFO_ADD = 21302;
//! ����������Ϣɾ��ʧ��
const int TAPIERROR_UPPERBANKINFO_DEL = 21303;
//! ����������Ϣ�޸�ʧ��
const int TAPIERROR_UPPERBANKINFO_MOD = 21304;
//! ����������Ϣ����ɾ��ʧ��
const int TAPIERROR_UPPERBANKINFO_CASCADE_DEL = 21305;

//==============================================================================
//! ����ͨ����Ϣ��ѯʧ��
const int TAPIERROR_UPPERCHANNEL_QRY = 21401;
//! ����ͨ����Ϣ����ʧ��
const int TAPIERROR_UPPERCHANNEL_ADD = 21402;
//! ����ͨ����Ϣɾ��ʧ��
const int TAPIERROR_UPPERCHANNEL_DEL = 21403;
//! ����ͨ����Ϣ�޸�ʧ��
const int TAPIERROR_UPPERCHANNEL_MOD = 21404;
//! ����ͨ����Ϣ����ɾ��ʧ��
const int TAPIERROR_UPPERCHANNEL_CASCADE_DEL = 21405;

//==============================================================================
//! ��������Ϣ��ѯʧ��
const int TAPIERROR_CURRENCYGROUP_QRY = 21501;
//! ��������Ϣ����ʧ��
const int TAPIERROR_CURRENCYGROUP_ADD = 21502;
//! ��������Ϣɾ��ʧ��
const int TAPIERROR_CURRENCYGROUP_DEL = 21503;
//! ��������Ϣ�޸�ʧ��
const int TAPIERROR_CURRENCYGROUP_MOD = 21504;
//! ��������Ϣ���ڱ�����Ϣ����ɾ��ʧ��
const int TAPIERROR_CURRENCYGROUP_CASCADE_DEL = 21505;

//==============================================================================
//! ���б�ʶ��ѯʧ��
const int TAPIERROR_BANKINFO_QRY = 21601;
//! ���б�ʶ����ʧ��
const int TAPIERROR_BANKINFO_ADD = 21602;
//! ���б�ʶɾ��ʧ��
const int TAPIERROR_BANKINFO_DEL = 21603;
//! ���б�ʶ�޸�ʧ��
const int TAPIERROR_BANKINFO_MOD = 21604;
//! ���б�ʶ��Ϣ���ڼ�����ɾ��ʧ��
const int TAPIERROR_BANKINFO_CASCADE_DEL = 21605;

//==============================================================================
//! ��˾������Ϣ��ѯʧ��
const int TAPIERROR_INTERNALBANK_QRY = 21701;
//! ��˾������Ϣ����ʧ��
const int TAPIERROR_INTERNALBANK_ADD = 21702;
//! ��˾������Ϣɾ��ʧ��
const int TAPIERROR_INTERNALBANK_DEL = 21703;
//! ��˾������Ϣ�޸�ʧ��
const int TAPIERROR_INTERNALBANK_MOD = 21704;

//==============================================================================
//! ��һ��ʲ�ѯʧ��
const int TAPIERROR_SWAPRATE_QRY = 21801;
//! ��һ�������ʧ��
const int TAPIERROR_SWAPRATE_ADD = 21802;
//! ��һ���ɾ��ʧ��
const int TAPIERROR_SWAPRATE_DEL = 21803;
//! ��һ����޸�ʧ��
const int TAPIERROR_SWAPRATE_MOD = 21804;

//==============================================================================
//! �ͻ������Ȳ�ѯʧ��
const int TAPIERROR_ACCOUNTSWAPVALUE_QRY = 21901;
//! �ͻ�����������ʧ��
const int TAPIERROR_ACCOUNTSWAPVALUE_ADD = 21902;
//! �ͻ�������ɾ��ʧ��
const int TAPIERROR_ACCOUNTSWAPVALUE_DEL = 21903;
//! �ͻ��������޸�ʧ��
const int TAPIERROR_ACCOUNTSWAPVALUE_MOD = 21904;

//==============================================================================
//! Ʒ����Ϣ��ѯʧ��
const int TAPIERROR_COMMODITYINFO_QRY = 22001;
//! Ʒ����Ϣ��ѯʧ��(����)
const int TAPIERROR_TCOMMODITYINFO_QRY = 22002;
//! Ʒ����Ϣ����ʧ��
const int TAPIERROR_COMMODITYINFO_ADD = 22003;
//! Ʒ����Ϣɾ��ʧ��
const int TAPIERROR_COMMODITYINFO_DEL = 22004;
//! Ʒ����Ϣ�޸�ʧ��
const int TAPIERROR_COMMODITYINFO_MOD = 22005;

//==============================================================================
//! Ʒ�ְ���ѯʧ��
const int TAPIERROR_COMMODITYSECTOR_QRY = 22101;
//! Ʒ�ְ������ʧ��
const int TAPIERROR_COMMODITYSECTOR_ADD = 22102;
//! Ʒ�ְ��ɾ��ʧ��
const int TAPIERROR_COMMODITYSECTOR_DEL = 22103;
//! Ʒ�ְ���޸�ʧ��
const int TAPIERROR_COMMODITYSECTOR_MOD = 22104;
//! Ʒ�ְ������ӳ��Ʒ�ּ���ɾ��ʧ��
const int TAPIERROR_COMMODITYSECTOR_CASCADE_DEL = 22105;
//! ��Ʒ�ְ����������Ʒ�ְ��ɾ��ʧ��
const int TAPIERROR_COMMODITYSECTOR_CHILD_DEL = 22106;

//==============================================================================
//! Ʒ�ְ���ӦƷ�ֲ�ѯʧ��
const int TAPIERROR_SECTORMAPCOMMODITY_QRY = 22201;
//! Ʒ�ְ���ӦƷ������ʧ��
const int TAPIERROR_SECTORMAPCOMMODITY_ADD = 22202;
//! Ʒ�ְ���ӦƷ��ɾ��ʧ��
const int TAPIERROR_SECTORMAPCOMMODITY_DEL = 22203;
//! Ʒ�ְ���ӦƷ���޸�ʧ��
const int TAPIERROR_SECTORMAPCOMMODITY_MOD = 22204;

//==============================================================================
//! Ʒ�����ѯʧ��
const int TAPIERROR_COMMODITYGROUP_QRY = 22301;
//! Ʒ��������ʧ��
const int TAPIERROR_COMMODITYGROUP_ADD = 22302;
//! Ʒ����ɾ��ʧ��
const int TAPIERROR_COMMODITYGROUP_DEL = 22303;
//! Ʒ�����޸�ʧ��
const int TAPIERROR_COMMODITYGROUP_MOD = 22304;
//! Ʒ���鼶��ɾ��ʧ��
const int TAPIERROR_COMMODITYGROUP_CASCADE_DEL = 22305;

//==============================================================================
//! �����ӦƷ�ֲ�ѯʧ��
const int TAPIERROR_GROUPMAPCOMMODITY_QRY = 22401;
//! �����ӦƷ������ʧ��
const int TAPIERROR_GROUPMAPCOMMODITY_ADD = 22402;
//! �����ӦƷ��ɾ��ʧ��
const int TAPIERROR_GROUPMAPCOMMODITY_DEL = 22403;
//! �����ӦƷ���޸�ʧ��
const int TAPIERROR_GROUPMAPCOMMODITY_MOD = 22404;

//==============================================================================
//! ����ʱ��ģ���ѯʧ��
const int TAPIERROR_TRADINGTIMEBUCKET_QRY = 22501;
//! ����ʱ��ģ������ʧ��
const int TAPIERROR_TRADINGTIMEBUCKET_ADD = 22502;
//! ����ʱ��ģ��ɾ��ʧ��
const int TAPIERROR_TRADINGTIMEBUCKET_DEL = 22503;
//! ����ʱ��ģ���޸�ʧ��
const int TAPIERROR_TRADINGTIMEBUCKET_MOD = 22504;

//==============================================================================
//! Ʒ��������Ϣ��ѯʧ��
const int TAPIERROR_COMMODITYQUOTEINFO_QRY = 22601;
//! Ʒ��������Ϣ����ʧ��
const int TAPIERROR_COMMODITYQUOTEINFO_ADD = 22602;
//! Ʒ��������Ϣɾ��ʧ��
const int TAPIERROR_COMMODITYQUOTEINFO_DEL = 22603;
//! Ʒ��������Ϣ�޸�ʧ��
const int TAPIERROR_COMMODITYQUOTEINFO_MOD = 22604;

//==============================================================================
//! Ʒ�ֹ�����Ϣ��ѯʧ��
const int TAPIERROR_COMMODITYRELATEINFO_QRY = 22701;
//! Ʒ�ֹ�����Ϣ����ʧ��
const int TAPIERROR_COMMODITYRELATEINFO_ADD = 22702;
//! Ʒ�ֹ�����Ϣɾ��ʧ��
const int TAPIERROR_COMMODITYRELATEINFO_DEL = 22703;
//! Ʒ�ֹ�����Ϣ�޸�ʧ��
const int TAPIERROR_COMMODITYRELATEINFO_MOD = 22704;

//==============================================================================
//! ��Լ��Ϣ��ѯʧ��
const int TAPIERROR_CONTRACTINFO_QRY = 22801;
//! ��Լ��Ϣ����ʧ��
const int TAPIERROR_CONTRACTINFO_ADD = 22802;
//! ��Լ��Ϣɾ��ʧ��
const int TAPIERROR_CONTRACTINFO_DEL = 22803;
//! ��Լ��Ϣ�޸�ʧ��
const int TAPIERROR_CONTRACTINFO_MOD = 22804;
//! ��Լ��Ϣ���гֲּ���ɾ��ʧ��
const int TAPIERROR_CONTRACTINFO_CASCADE_DEL = 22805;

//! ��Ϻ�Լ��Ϣ��ѯʧ��
const int TAPIERROR_CMBCONTRACTINFO_QRY = 22806;
//! ��Ϻ�Լ��Ϣ����ʧ��
const int TAPIERROR_CMBCONTRACTINFO_ADD = 22807;
//! ��Ϻ�Լ��Ϣɾ��ʧ��
const int TAPIERROR_CMBCONTRACTINFO_DEL = 22808;

//==============================================================================
//! ������Ȩ��Ĳ�ѯʧ��
const int TAPIERROR_SPECIALOPTIONFUTURE_QRY = 22901;
//! ������Ȩ�������ʧ��
const int TAPIERROR_SPECIALOPTIONFUTURE_ADD = 22902;
//! ������Ȩ���ɾ��ʧ��
const int TAPIERROR_SPECIALOPTIONFUTURE_DEL = 22903;
//! ������Ȩ����޸�ʧ��
const int TAPIERROR_SPECIALOPTIONFUTURE_MOD = 22904;

//==============================================================================
//! ����Ʒ�ִ���ӳ���ѯʧ��
const int TAPIERROR_UPPERCOMMODITYMAPPING_QRY = 23001;
//! ����Ʒ�ִ���ӳ������ʧ��
const int TAPIERROR_UPPERCOMMODITYMAPPING_ADD = 23002;
//! ����Ʒ�ִ���ӳ��ɾ��ʧ��
const int TAPIERROR_UPPERCOMMODITYMAPPING_DEL = 23003;
//! ����Ʒ�ִ���ӳ���޸�ʧ��
const int TAPIERROR_UPPERCOMMODITYMAPPING_MOD = 23004;

//==============================================================================
//! �ⲿƷ�ִ���ӳ���ѯʧ��
const int TAPIERROR_OUTSIDECOMMODITYMAPPING_QRY = 23101;
//! �ⲿƷ�ִ���ӳ������ʧ��
const int TAPIERROR_OUTSIDECOMMODITYMAPPING_ADD = 23102;
//! �ⲿƷ�ִ���ӳ��ɾ��ʧ��
const int TAPIERROR_OUTSIDECOMMODITYMAPPING_DEL = 23103;
//! �ⲿƷ�ִ���ӳ���޸�ʧ��
const int TAPIERROR_OUTSIDECOMMODITYMAPPING_MOD = 23104;

//==============================================================================
//! �ⲿ������Դ��ѯʧ��
const int TAPIERROR_OUTSIDEDATASOURCE_QRY = 23201;
//! �ⲿ������Դ����ʧ��
const int TAPIERROR_OUTSIDEDATASOURCE_ADD = 23202;
//! �ⲿ������Դɾ��ʧ��
const int TAPIERROR_OUTSIDEDATASOURCE_DEL = 23203;
//! �ⲿ������Դ�޸�ʧ��
const int TAPIERROR_OUTSIDEDATASOURCE_MOD = 23204;

//==============================================================================
//! ���������Ѳ�ѯʧ��
const int TAPIERROR_UPPERFEE_QRY = 23301;
//! ��������������ʧ��
const int TAPIERROR_UPPERFEE_ADD = 23302;
//! ����������ɾ��ʧ��
const int TAPIERROR_UPPERFEE_DEL = 23303;
//! �����������޸�ʧ��
const int TAPIERROR_UPPERFEE_MOD = 23304;

//==============================================================================
//! ������ģ���ѯʧ��
const int TAPIERROR_TEMPLATEFEE_QRY = 23401;
//! ������ģ������ʧ��
const int TAPIERROR_TEMPLATEFEE_ADD = 23402;
//! ������ģ��ɾ��ʧ��
const int TAPIERROR_TEMPLATEFEE_DEL = 23403;
//! ������ģ���޸�ʧ��
const int TAPIERROR_TEMPLATEFEE_MOD = 23404;
//! ������ģ�弶��ɾ��ʧ��
//! const int TAPIERROR_TEMPLATEFEE_CASCADE_DEL			= 23405;

//==============================================================================
//! �ͻ���Ӧ������ģ���ѯʧ��
const int TAPIERROR_ACCOUNTFEETEMPLATE_QRY = 23501;
//! �ͻ���Ӧ������ģ������ʧ��
const int TAPIERROR_ACCOUNTFEETEMPLATE_ADD = 23502;
//! �ͻ���Ӧ������ģ��ɾ��ʧ��
const int TAPIERROR_ACCOUNTFEETEMPLATE_DEL = 23503;
//! �ͻ���Ӧ������ģ���޸�ʧ��
const int TAPIERROR_ACCOUNTFEETEMPLATE_MOD = 23504;

//==============================================================================
//! �����������ò�ѯʧ��
const int TAPIERROR_UPPEROTHERFEE_QRY = 23601;
//! ����������������ʧ��
const int TAPIERROR_UPPEROTHERFEE_ADD = 23602;
//! ������������ɾ��ʧ��
const int TAPIERROR_UPPEROTHERFEE_DEL = 23603;
//! �������������޸�ʧ��
const int TAPIERROR_UPPEROTHERFEE_MOD = 23604;

//==============================================================================
//! �ͻ��������ò�ѯʧ��
const int TAPIERROR_ACCOUNTOTHERFEE_QRY = 23701;
//! �ͻ�������������ʧ��
const int TAPIERROR_ACCOUNTOTHERFEE_ADD = 23702;
//! �ͻ���������ɾ��ʧ��
const int TAPIERROR_ACCOUNTOTHERFEE_DEL = 23703;
//! �ͻ����������޸�ʧ��
const int TAPIERROR_ACCOUNTOTHERFEE_MOD = 23704;

//==============================================================================
//! ���ֱ�֤���ѯʧ��
const int TAPIERROR_UPPERMARGIN_QRY = 23801;
//! ���ֱ�֤������ʧ��
const int TAPIERROR_UPPERMARGIN_ADD = 23802;
//! ���ֱ�֤��ɾ��ʧ��
const int TAPIERROR_UPPERMARGIN_DEL = 23803;
//! ���ֱ�֤���޸�ʧ��
const int TAPIERROR_UPPERMARGIN_MOD = 23804;

//==============================================================================
//! ���ֱ�֤�������ѯʧ��
const int TAPIERROR_UPPERMARGINADJUST_QRY = 23901;
//! ���ֱ�֤���������ʧ��
const int TAPIERROR_UPPERMARGINADJUST_ADD = 23902;
//! ���ֱ�֤�����ɾ��ʧ��
const int TAPIERROR_UPPERMARGINADJUST_DEL = 23903;
//! ���ֱ�֤������޸�ʧ��
const int TAPIERROR_UPPERMARGINADJUST_MOD = 23904;

//==============================================================================
//! ��֤��ģ���ѯʧ��
const int TAPIERROR_TEMPLATEMARGIN_QRY = 24001;
//! ��֤��ģ������ʧ��
const int TAPIERROR_TEMPLATEMARGIN_ADD = 24002;
//! ��֤��ģ��ɾ��ʧ��
const int TAPIERROR_TEMPLATEMARGIN_DEL = 24003;
//! ��֤��ģ���޸�ʧ��
const int TAPIERROR_TEMPLATEMARGIN_MOD = 24004;

//==============================================================================
//! �ͻ���Ӧ��֤��ģ���ѯʧ��
const int TAPIERROR_ACCOUNTMARGINTEMPLATE_QRY = 24101;
//! �ͻ���Ӧ��֤��ģ������ʧ��
const int TAPIERROR_ACCOUNTMARGINTEMPLATE_ADD = 24102;
//! �ͻ���Ӧ��֤��ģ��ɾ��ʧ��
const int TAPIERROR_ACCOUNTMARGINTEMPLATE_DEL = 24103;
//! �ͻ���Ӧ��֤��ģ���޸�ʧ��
const int TAPIERROR_ACCOUNTMARGINTEMPLATE_MOD = 24104;

//==============================================================================
//! ��֤��ģ�������ѯʧ��
const int TAPIERROR_TEMPLATEMARGINADJUST_QRY = 24201;
//! ��֤��ģ���������ʧ��
const int TAPIERROR_TEMPLATEMARGINADJUST_ADD = 24202;
//! ��֤��ģ�����ɾ��ʧ��
const int TAPIERROR_TEMPLATEMARGINADJUST_DEL = 24203;
//! ��֤��ģ������޸�ʧ��
const int TAPIERROR_TEMPLATEMARGINADJUST_MOD = 24204;

//==============================================================================
//! �ͻ���֤�������Ϣ��ѯʧ��
const int TAPIERROR_ACCOUNTMARGINADJUST_QRY = 24205;
//! �ͻ���֤�������Ϣ����ʧ��
const int TAPIERROR_ACCOUNTMARGINADJUST_ADD = 24206;
//! �ͻ���֤�������Ϣɾ��ʧ��
const int TAPIERROR_ACCOUNTMARGINADJUST_DEL = 24207;
//! �ͻ���֤�������Ϣ�޸�ʧ��
const int TAPIERROR_ACCOUNTMARGINADJUST_MOD = 24208;


//==============================================================================
//! ���ֱ�����ѯʧ��
const int TAPIERROR_LOCKEDPERCENTAGE_QRY = 24301;
//! ���ֱ�������ʧ��
const int TAPIERROR_LOCKEDPERCENTAGE_ADD = 24302;
//! ���ֱ���ɾ��ʧ��
const int TAPIERROR_LOCKEDPERCENTAGE_DEL = 24303;
//! ���ֱ����޸�ʧ��
const int TAPIERROR_LOCKEDPERCENTAGE_MOD = 24304;

//==============================================================================
//! ����Ȩ�޲�ѯʧ��
const int TAPIERROR_TRADINGRIGHT_QRY = 24401;
//! ����Ȩ������ʧ��
const int TAPIERROR_TRADINGRIGHT_ADD = 24402;
//! ����Ȩ��ɾ��ʧ��
const int TAPIERROR_TRADINGRIGHT_DEL = 24403;
//! ����Ȩ���޸�ʧ��
const int TAPIERROR_TRADINGRIGHT_MOD = 24404;

//==============================================================================
//! ����µ�����ѯʧ��
const int TAPIERROR_ONCEMAX_QRY = 24501;
//! ����µ�������ʧ��
const int TAPIERROR_ONCEMAX_ADD = 24502;
//! ����µ���ɾ��ʧ��
const int TAPIERROR_ONCEMAX_DEL = 24503;
//! ����µ����޸�ʧ��
const int TAPIERROR_ONCEMAX_MOD = 24504;

//==============================================================================
//! ���ֲ�����ѯʧ��
const int TAPIERROR_POSITIONMAX_QRY = 24601;
//! ���ֲ�������ʧ��
const int TAPIERROR_POSITIONMAX_ADD = 24602;
//! ���ֲ���ɾ��ʧ��
const int TAPIERROR_POSITIONMAX_DEL = 24603;
//! ���ֲ����޸�ʧ��
const int TAPIERROR_POSITIONMAX_MOD = 24604;

//==============================================================================
//! ����·�ɿ��Ʋ�ѯʧ��
const int TAPIERROR_TRADINGROUTE_QRY = 24701;
//! ����·�ɿ�������ʧ��
const int TAPIERROR_TRADINGROUTE_ADD = 24702;
//! ����·�ɿ���ɾ��ʧ��
const int TAPIERROR_TRADINGROUTE_DEL = 24703;
//! ����·�ɿ����޸�ʧ��
const int TAPIERROR_TRADINGROUTE_MOD = 24704;

//==============================================================================
//! ����·�ɿ��Ʋ�ѯʧ��
const int TAPIERROR_QUOTEROUTE_QRY = 24801;
//! ����·�ɿ�������ʧ��
const int TAPIERROR_QUOTEROUTE_ADD = 24802;
//! ����·�ɿ���ɾ��ʧ��
const int TAPIERROR_QUOTEROUTE_DEL = 24803;
//! ����·�ɿ����޸�ʧ��
const int TAPIERROR_QUOTEROUTE_MOD = 24804;

//==============================================================================
//! ϵͳ������ѯʧ��
const int TAPIERROR_SYSTEMPARAMETER_QRY = 24901;
//! ϵͳ��������ʧ��
const int TAPIERROR_SYSTEMPARAMETER_ADD = 24902;
//! ϵͳ����ɾ��ʧ��
const int TAPIERROR_SYSTEMPARAMETER_DEL = 24903;
//! ϵͳ�����޸�ʧ��
const int TAPIERROR_SYSTEMPARAMETER_MOD = 24904;

//==============================================================================
//! ��Ŀ��Ϣ�����ѯʧ��
const int TAPIERROR_ITEMINFO_QRY = 25001;
//! ��Ŀֵ��Ϣ�����޸�ʧ��
const int TAPIERROR_ITEMVALUEINFO_QRY = 25002;

//==============================================================================
//! ������ģ����Ϣ��ѯʧ��
const int TAPIERROR_TEMPLATEFEEINFO_QRY = 25101;
//! ������ģ����Ϣ����ʧ��
const int TAPIERROR_TEMPLATEFEEINFO_ADD = 25102;
//! ������ģ����Ϣɾ��ʧ��
const int TAPIERROR_TEMPLATEFEEINFO_DEL = 25103;
//! ������ģ����Ϣ�޸�ʧ��
const int TAPIERROR_TEMPLATEFEEINFO_MOD = 25104;
//! ������ģ����Ϣ����ɾ��ʧ��
const int TAPIERROR_TEMPLATEFEEINFO_CASCADE_DEL = 25105;

//==============================================================================
//! ��֤��ģ����Ϣ��ѯʧ��
const int TAPIERROR_TEMPLATEMARGININFO_QRY = 25201;
//! ��֤��ģ����Ϣ����ʧ��
const int TAPIERROR_TEMPLATEMARGININFO_ADD = 25202;
//! ��֤��ģ����Ϣɾ��ʧ��
const int TAPIERROR_TEMPLATEMARGININFO_DEL = 25203;
//! ��֤��ģ����Ϣ�޸�ʧ��
const int TAPIERROR_TEMPLATEMARGININFO_MOD = 25204;
//! ��֤��ģ����Ϣ����ɾ��ʧ��
const int TAPIERROR_TEMPLATEMARGININFO_CASCADE_DEL = 25205;
//! ģ���ͬ����ʧ��
const int TAPIERROR_TEMPLATEPARAMEQUAL_ADD = 25206;
//! ģ���ͬ��ѯʧ��
const int TAPIERROR_TEMPLATEPARAMEQUAL_QRY = 25207;

//==============================================================================
//! ��������������Ϣ��ѯʧ��
const int TAPIERROR_OTHERFEETYPEINFO_QRY = 25301;
//! ��������������Ϣ����ʧ��
const int TAPIERROR_OTHERFEETYPEINFO_ADD = 25302;
//! ��������������Ϣɾ��ʧ��
const int TAPIERROR_OTHERFEETYPEINFO_DEL = 25303;
//! ��������������Ϣ�޸�ʧ��
const int TAPIERROR_OTHERFEETYPEINFO_MOD = 25304;
//! ��������������Ϣ����ɾ��ʧ��
const int TAPIERROR_OTHERFEETYPEINFO_CASCADE_DEL = 25305;

//==============================================================================
//! Ʒ��ί�����Ͳ�ѯʧ��
const int TAPIERROR_COMMODITYORDERTYPE_QRY = 25501;
//! Ʒ��ί����������ʧ��
const int TAPIERROR_COMMODITYORDERTYPE_ADD = 25502;
//! Ʒ��ί������ɾ��ʧ��
const int TAPIERROR_COMMODITYORDERTYPE_DEL = 25503;
//! Ʒ��ί�������޸�ʧ��
const int TAPIERROR_COMMODITYORDERTYPE_MOD = 25504;

//==============================================================================
//! Ʒ��ί��ʱ����Ч�Բ�ѯʧ��
const int TAPIERROR_ORDERTIMEINFORCE_QRY = 25601;
//! Ʒ��ί��ʱ����Ч������ʧ��
const int TAPIERROR_ORDERTIMEINFORCE_ADD = 25602;
//! Ʒ��ί��ʱ����Ч��ɾ��ʧ��
const int TAPIERROR_ORDERTIMEINFORCE_DEL = 25603;
//! Ʒ��ί��ʱ����Ч���޸�ʧ��
const int TAPIERROR_ORDERTIMEINFORCE_MOD = 25604;

//==============================================================================
//! ���Լ�����Ϣ��ѯʧ��
const int TAPIERROR_ATTRIBUTELEVELINFO_QRY = 25701;
//! ���Լ�����Ϣ����ʧ��
const int TAPIERROR_ATTRIBUTELEVELINFO_ADD = 25702;
//! ���Լ�����Ϣɾ��ʧ��
const int TAPIERROR_ATTRIBUTELEVELINFO_DEL = 25703;
//! ���Լ�����Ϣ�޸�ʧ��
const int TAPIERROR_ATTRIBUTELEVELINFO_MOD = 25704;
//! ���Լ�����Ϣ����ɾ��ʧ��
const int TAPIERROR_ATTRIBUTELEVELINFO_CASCADE_DEL = 25705;

//==============================================================================
//! ��������ģ����Ϣ��ѯʧ��
const int TAPIERROR_CALENDARTEMPLATEINFO_QRY = 25801;
//! ��������ģ����Ϣ����ʧ��
const int TAPIERROR_CALENDARTEMPLATEINFO_ADD = 25802;
//! ��������ģ����Ϣɾ��ʧ��
const int TAPIERROR_CALENDARTEMPLATEINFO_DEL = 25803;
//! ��������ģ����Ϣ�޸�ʧ��
const int TAPIERROR_CALENDARTEMPLATEINFO_MOD = 25804;

//==============================================================================
//! Ʒ�ֽ�������ģ���ѯʧ��
const int TAPIERROR_COMMODITYCALENDARTEMPLATE_QRY = 25901;
//! Ʒ�ֽ�������ģ������ʧ��
const int TAPIERROR_COMMODITYCALENDARTEMPLATE_ADD = 25902;
//! Ʒ�ֽ�������ģ��ɾ��ʧ��
const int TAPIERROR_COMMODITYCALENDARTEMPLATE_DEL = 25903;
//! Ʒ�ֽ�������ģ���޸�ʧ��
const int TAPIERROR_COMMODITYCALENDARTEMPLATE_MOD = 25904;

//==============================================================================
//! ʵֵ���ѯʧ��
const int TAPIERROR_ACCOUNTREALVALUE_QRY = 26001;
//! ʵֵ������ʧ��
const int TAPIERROR_ACCOUNTREALVALUE_ADD = 26002;
//! ʵֵ��ɾ��ʧ��
const int TAPIERROR_ACCOUNTREALVALUE_DEL = 26003;
//! ʵֵ���޸�ʧ��
const int TAPIERROR_ACCOUNTREALVALUE_MOD = 26004;

//==============================================================================
//! �Զ�������Ȩ���ʧ��
const int TAPIERROR_TOOPTIONCMB_REQ = 26101;

//==============================================================================
//! ��������ģ����Ϣ������ѯʧ��
const int TAPIERROR_CALENDARTEMPLATEBASE_QRY = 26201;
//! ��������ģ����Ϣ��������ʧ��
const int TAPIERROR_CALENDARTEMPLATEBASE_ADD = 26202;
//! ��������ģ����Ϣ����ɾ��ʧ��
const int TAPIERROR_CALENDARTEMPLATEBASE_DEL = 26203;
//! ��������ģ����Ϣ�����޸�ʧ��
const int TAPIERROR_CALENDARTEMPLATEBASE_MOD = 26204;

//==============================================================================
//! ----------------�˻�֤�����ʹ�����붨��-------------------------------------
//! �˻�֤�����Ͳ�ѯʧ��
const int TAPIERROR_CERTIFICATE_QRY = 26301;

//==============================================================================
//! ��������ʶ��ѯʧ��
const int TAPIERROR_TRADESERVERFLAG_QRY = 26401;
//! ��������ʶ����ʧ��
const int TAPIERROR_TRADESERVERFLAG_ADD = 26402;
//! ��������ʶɾ��ʧ��
const int TAPIERROR_TRADESERVERFLAG_DEL = 26403;
//! ��������ʶ�޸�ʧ��
const int TAPIERROR_TRADESERVERFLAG_MOD = 26404;
//! ��������ʶ����ɾ��ʧ��
const int TAPIERROR_TRADESERVERFLAG_CASCADE_DEL = 26405;

//==============================================================================
//! ��������ʶӳ���ʽ��˺Ŷ�Ӧ�����Ѳ�ѯʧ��
const int TAPIERROR_TRADESERVERFLAG_FEETEMPLATE_QRY = 26501;

//==============================================================================
//! ��������ʶӳ���ʽ��˺Ŷ�Ӧ��֤���ѯʧ��
const int TAPIERROR_TRADESERVERFLAG_MARGINTEMPLATE_QRY = 26601;

//==============================================================================
//! ��������ʶӳ���ʽ��˺Ŷ�Ӧ��������Ϣ��ѯʧ��
const int TAPIERROR_TRADESERVERFLAG_ACCOUNT_FEEINFO_QRY = 26701;

//==============================================================================
//! ��������ʶӳ���ʽ��˺Ŷ�Ӧ��֤����Ϣ��ѯʧ��
const int TAPIERROR_TRADESERVERFLAG_ACCOUNT_MARGININFO_QRY = 26801;

//==============================================================================
//! ������Ϣ��ѯʧ��
const int TAPIERROR_COUNTY_QRY = 26901;

//==============================================================================
//! ʡ����Ϣ��ѯʧ��
const int TAPIERROR_PROVINCE_QRY = 27001;
//==============================================================================
//! ����ǩ��ǩ�˲�ѯʧ��
const int TAPIERROR_BANKLOGINOUT_QRY = 27101;
//! ����ǩ��ǩ������ʧ��
const int TAPIERROR_BANKLOGINOUT_ADD = 27102;

//==============================================================================
//! ������ˮ��ѯʧ��
const int TAPIERROR_TRANSFERFUTUREBANK_QRY = 27201;
//! ������ˮ����ʧ��
const int TAPIERROR_TRANSFERFUTUREBANK_ADD = 27202;

//==============================================================================
//! ����ת�˲�����ѯʧ��
const int TAPIERROR_TRANSFERRENT_QRY = 27301;
//! ����ת�˲�������ʧ��
const int TAPIERROR_TRANSFERRENT_ADD = 27302;
//! ����ת�˲����޸�ʧ��
const int TAPIERROR_TRANSFERRENT_MOD = 27303;
//! ����ת�˲���ɾ��ʧ��
const int TAPIERROR_TRANSFERRENT_DEL = 27304;

//==============================================================================
//! ����ת��ʱ��β�ѯʧ��
const int TAPIERROR_TRANSFERTIME_QRY = 27401;
//! ����ת��ʱ�������ʧ��
const int TAPIERROR_TRANSFERTIME_ADD = 27402;
//! ����ת��ʱ����޸�ʧ��
const int TAPIERROR_TRANSFERTIME_MOD = 27403;
//! ����ת��ʱ���ɾ��ʧ��
const int TAPIERROR_TRANSFERTIME_DEL = 27404;

//==============================================================================
//! ����ת��ǩ��Լ��ʷ��ˮ��ѯʧ��
const int TAPIERROR_BANKSIGNEDINFO_QRY = 27501;
//! ����ת��ǩ��Լ��ʷ��ˮ����ʧ��
const int TAPIERROR_BANKSIGNEDINFO_ADD = 27502;

//==============================================================================
//! ����ʱ��ģ�������ѯʧ��
const int TAPIERROR_TRADINGTIMEBUCKETBASE_QRY = 27601;
//! ����ʱ��ģ���������ʧ��
const int TAPIERROR_TRADINGTIMEBUCKETBASE_ADD = 27602;
//! ����ʱ��ģ�����ɾ��ʧ��
const int TAPIERROR_TRADINGTIMEBUCKETBASE_DEL = 27603;
//! ����ʱ��ģ������޸�ʧ��
const int TAPIERROR_TRADINGTIMEBUCKETBASE_MOD = 27604;
//! ����ʱ��ģ���������ɾ��ʧ��
const int TAPIERROR_TRADINGTIMEBUCKETBASE_CASCADE_DEL = 27605;
//==============================================================================
//! ����������Ϣ��ѯʧ��
const int TAPIERROR_CLASSIFY_QRY = 27701;

//==============================================================================
//! ��֯������Ϣ��ѯʧ��
const int TAPIERROR_ORGANTYPE_QRY = 27801;

//==============================================================================
//! 9.0ϵͳ����������Ϣ��ѯʧ��
const int TAPIERROR_TRADINGCALENDARINFO_QRY = 27901;
//! 9.0ϵͳ����������Ϣ����ʧ��
const int TAPIERROR_TRADINGCALENDARINFO_ADD = 27902;
//! 9.0ϵͳ����������Ϣ�޸�ʧ��
const int TAPIERROR_TRADINGCALENDARINFO_MOD = 27903;
//! 9.0ϵͳ����������Ϣɾ��ʧ��
const int TAPIERROR_TRADINGCALENDARINFO_DEL = 27904;
//! ͨ������������ѯ��ǰ�����պ��ϴν����ղ�ѯʧ��
const int TAPIERROR_TRADING_CLENDAR_SETTLE_TRADE_QRY = 27905;

//==============================================================================
//! ������������ֹ��Ϣ��ѯʧ��
const int TAPIERROR_EXCHANGETRADINGCALENDARINFO_QRY = 28001;
//! ������������ֹ��Ϣ����ʧ��
const int TAPIERROR_EXCHANGETRADINGCALENDARINFO_ADD = 28002;
//! ������������ֹ��Ϣ�޸�ʧ��
const int TAPIERROR_EXCHANGETRADINGCALENDARINFO_MOD = 28003;
//! ������������ֹ��Ϣɾ��ʧ��
const int TAPIERROR_EXCHANGETRADINGCALENDARINFO_DEL = 28004;
//! ���ݽ����ղ�ѯ��������ϸ���ڲ�ѯʧ��
const int TAPIERROR_EXCHANGE_TRADING_DETAILDATE_QRY = 28005;

//==============================================================================
//! ��Լ��ʱ������Ϣ��ѯʧ��
const int TAPIERROR_CONTRACTNEARDELIVERY_QRY = 28101;
//! ��Լ��ʱ������Ϣ����ʧ��
const int TAPIERROR_CONTRACTNEARDELIVERY_ADD = 28102;
//! ��Լ��ʱ������Ϣɾ��ʧ��
const int TAPIERROR_CONTRACTNEARDELIVERY_DEL = 28103;
//==============================================================================
//! �����Ϣ���ѯʧ��
const int TAPIERROR_CHECKTABLEINFO_QRY = 28201;
//! �����Ϣ������ʧ��
const int TAPIERROR_CHECKTABLEINFO_ADD = 28202;
//! �����Ϣ���޸�ʧ��
const int TAPIERROR_CHECKTABLEINFO_MOD = 28203;
//! �����Ϣ��ɾ��ʧ��
const int TAPIERROR_CHECKTABLEINFO_DEL = 28204;
//! �ж��Ƿ�Ϊ��˱��ѯʧ��
const int TAPIERROR_CHECKTABLEBASEINFO_QRY = 28205;
//! �������ɾ����Ϣ���ѯʧ��
const int TAPIERROR_CHECKTABLEDELINFO_QRY = 28206;
//! �������ɾ����Ϣ������ʧ��
const int TAPIERROR_CHECKTABLEDELINFO_ADD = 28207;
//! �������ɾ����Ϣ��ɾ��ʧ��
const int TAPIERROR_CHECKTABLEDELINFO_DEL = 28208;
//! ��˻�����Ϣ������ʧ��
const int TAPIERROR_CHECKTABLEBASEINFO_ADD = 28209;
//! ��˻�����Ϣ���޸�ʧ��
const int TAPIERROR_CHECKTABLEBASEINFO_MOD = 28210;
//! �����Ϣ���޸��������Ϣ
const int TAPIERROR_CHECKTABLEINFO_MOD_CHECKED = 28211;

//==============================================================================
//! ������־��ѯʧ��
const int TAPIERROR_OPERATORLOGINFO_QRY = 28301;
//! ������־����ʧ��
const int TAPIERROR_OPERATORLOGINFO_ADD = 28302;
//! ������־ɾ��ʧ��
const int TAPIERROR_OPERATORLOGINFO_DEL = 28303;

//! ���ղ�����ѯʧ��
const int TAPIERROR_RISKPARAMETER_QRY = 28304;
//! ���ղ����޸�ʧ��
const int TAPIERROR_RISKPARAMETER_MOD = 28305;

//! �������������ѯʧ��
const int TAPIERROR_TRANSFERCOUNTVALUE_QRY = 28306;
//! ����������������ʧ��
const int TAPIERROR_TRANSFERCOUNTVALUE_ADD = 28307;
//==============================================================================
//! ��ֹ�Զ����˶�����ѯʧ��
const int TAPIERROR_BANAUTO_ORDERCHECK_QRY = 28401;
//! ��ֹ�Զ����˶�������ʧ��
const int TAPIERROR_BANAUTO_ORDERCHECK_ADD = 28402;
//! ��ֹ�Զ����˶���ɾ��ʧ��
const int TAPIERROR_BANAUTO_ORDERCHECK_DEL = 28403;
//==============================================================================
//! �ʽ��˺Ŷ�Ӧ�������������Լ������ѯʧ��
const int TAPIERROR_USER_QUOTE_QTY_QRY = 28501;
//! �ʽ��˺Ŷ�Ӧ�������������Լ��������ʧ��
const int TAPIERROR_USER_QUOTE_QTY_ADD = 28502;
//! �ʽ��˺Ŷ�Ӧ�������������Լ�����޸�ʧ��
const int TAPIERROR_USER_QUOTE_QTY_MOD = 28503;
//! �ʽ��˺Ŷ�Ӧ�������������Լ����ɾ��ʧ��
const int TAPIERROR_USER_QUOTE_QTY_DEL = 28504;
//==============================================================================
//! ��Ʒ�ְ���ѯʧ��
const int TAPIERROR_SECTOR_PARENT_QRY = 28601;
//! ��Ʒ�ְ������ʧ��
const int TAPIERROR_SECTOR_PARENT_ADD = 28602;
//! ��Ʒ�ְ���޸�ʧ��
const int TAPIERROR_SECTOR_PARENT_MOD = 28603;
//! ��Ʒ�ְ��ɾ��ʧ��
const int TAPIERROR_SECTOR_PARENT_DEL = 28604;
//==============================================================================
//! ������λ��Ϣ��ѯʧ��
const int TAPIERROR_MEASURE_UNIT_QRY = 28701;
//! ������λ�����ϵ��Ϣ��ѯʧ��
const int TAPIERROR_MEASURE_CONVERSION_QRY = 28702;
//! �Ƽ۵�λ�����ϵ��Ϣ��ѯʧ��
const int TAPIERROR_CHARGE_CONVERSION_QRY = 28703;

//==============================================================================
//! �Ƽ۵�λ��Ϣ��ѯʧ��
const int TAPIERROR_CHARGE_UNIT_QRY = 28801;
//! �Ƽ۵�λ��Ϣ����ʧ��
const int TAPIERROR_CHARGE_UNIT_ADD = 28802;
//! �Ƽ۵�λ��Ϣ�޸�ʧ��
const int TAPIERROR_CHARGE_UNIT_MOD = 28803;
//! �Ƽ�λ��Ϣɾ��ʧ��
const int TAPIERROR_CHARGE_UNIT_DEL = 28804;
//==============================================================================
//! �û��µ�Ƶ�ʲ�ѯʧ��
const int TAPIERROR_USER_ORDER_FREQUENCE_QRY = 28901;
//! �û��µ�Ƶ������ʧ��
const int TAPIERROR_USER_ORDER_FREQUENCE_ADD = 28902;
//! �û��µ�Ƶ���޸�ʧ��
const int TAPIERROR_USER_ORDER_FREQUENCE_MOD = 28903;
//! �û��µ�Ƶ��ɾ��ʧ��
const int TAPIERROR_USER_ORDER_FREQUENCE_DEL = 28904;
//==============================================================================
//! �������Ӳ�ѯʧ��
const int TAPIERROR_DATA_LINKINFO_QRY = 29001;
//! ������������ʧ��
const int TAPIERROR_DATA_LINKINFO_ADD = 29002;
//! ���������޸�ʧ��
const int TAPIERROR_DATA_LINKINFO_MOD = 29003;
//! ��������ɾ��ʧ��
const int TAPIERROR_DATA_LINKINFO_DEL = 29004;
//==============================================================================
//! ֻ��ƽ����ǰ������ѯʧ��
const int TAPIERROR_ONLYCANCLOSEDAYS_QRY = 29101;
//! ֻ��ƽ����ǰ��������ʧ��
const int TAPIERROR_ONLYCANCLOSEDAYS_ADD = 29102;
//! ֻ��ƽ����ǰ����ɾ��ʧ��
const int TAPIERROR_ONLYCANCLOSEDAYS_DEL = 29103;
//! ֻ��ƽ����ǰ�����޸�ʧ��
const int TAPIERROR_ONLYCANCLOSEDAYS_MOD = 29104;

//==============================================================================
//! LME����������Ϣ��ѯʧ��
const int TAPIERROR_LMETRADINGCALENDARINFO_QRY = 29201;
//! LME����������Ϣ����ʧ��
const int TAPIERROR_LMETRADINGCALENDARINFO_ADD = 29202;
//! LME����������Ϣ�޸�ʧ��
const int TAPIERROR_LEMTRADINGCALENDARINFO_MOD = 29203;
//! LME����������Ϣɾ��ʧ��
const int TAPIERROR_LEMTRADINGCALENDARINFO_DEL = 29204;
//! ���ݽ����ղ�ѯLME��ϸ�������ڲ�ѯʧ��
const int TAPIERROR_LEM_TRADING_DETAILDATE_QRY = 29205;
//==============================================================================
//! ����������ģ���ѯʧ��
const int TAPIERROR_TEMPLATE_MINMAX_FEE_QRY = 29301;
//! ����������ģ������ʧ��
const int TAPIERROR_TEMPLATE_MINMAX_FEE_ADD = 29302;
//! ����������ģ��ɾ��ʧ��
const int TAPIERROR_TEMPLATE_MINMAX_FEE_DEL = 29303;
//! ����������ģ���޸�ʧ��
const int TAPIERROR_TEMPLATE_MINMAX_FEE_MOD = 29304;
//! ����������ģ�弶��ɾ��ʧ��
//! const int TAPIERROR_TEMPLATE_MINMAX_FEE_CASCADE_DEL			= 29305;
//==============================================================================
//! �ͻ���Ӧ����������ģ���ѯʧ��
const int TAPIERROR_ACCOUNT_MINMAX_FEETEMPLATE_QRY = 29401;
//! �ͻ���Ӧ����������ģ������ʧ��
const int TAPIERROR_ACCOUNT_MINMAX_FEETEMPLATE_ADD = 29402;
//! �ͻ���Ӧ����������ģ��ɾ��ʧ��
const int TAPIERROR_ACCOUNT_MINMAX_FEETEMPLATE_DEL = 29403;
//! �ͻ���Ӧ����������ģ���޸�ʧ��
const int TAPIERROR_ACCOUNT_MINMAX_FEETEMPLATE_MOD = 29404;
//==============================================================================
//! �ʽ��˻�����һ��ͨ���ϵͳ��ѯʧ��
const int TAPIERROR_ACCOUNT_SEAT_INFO_QRY = 29411;
//! �ʽ��˻�����һ��ͨ���ϵͳ����ʧ��
const int TAPIERROR_ACCOUNT_SEAT_INFO_ADD = 29412;
//! �ʽ��˻�����һ��ͨ���ϵͳɾ��ʧ��
const int TAPIERROR_ACCOUNT_SEAT_INFO_DEL = 29413;
//==============================================================================
//! һ��ͨ�˺���Ϣ��ѯʧ��
const int TAPIERROR_SEAT_INFO_QRY = 29421;
//! һ��ͨ�˺���Ϣ����ʧ��
const int TAPIERROR_SEAT_INFO_ADD = 29422;
//! һ��ͨ�˺���Ϣɾ��ʧ��
const int TAPIERROR_SEAT_INFO_DEL = 29423;
//! һ��ͨ�˺���Ϣ��ϯ�Ѵ�������ʧ��
const int TAPIERROR_SEAT_INFO_MAIN_EXIT_ADD = 29424;
//==============================================================================
//! �ͻ����������Ѳ�ѯʧ��
const int TAPIERROR_ACCOUNTFEE_PARAMETER_QRY = 29431;
//! �ͻ����ձ�֤���ѯʧ��
const int TAPIERROR_ACCOUNTMARGIN_PARAMETER_QRY = 29432;
//! ������ģ�������޸�ʧ��
const int TAPIERROR_TEMPLATEFEE_BATCH_MOD = 29433;
//! ��֤��ģ�������޸�ʧ��
const int TAPIERROR_TEMPLATEMARGIN_BATCH_MOD = 29434;
//==============================================================================
//! ����ڻ����·��ʲ�ѯʧ��
const int TAPIERROR_FOREIGN_EXCHANGE_NEWRATE_QRY = 29441;
//! ����ڻ���ǰ���ʲ�ѯʧ��
const int TAPIERROR_FOREIGN_EXCHANGE_CURRATE_QRY = 29442;
//! ����ڻ������޸�ʧ��
const int TAPIERROR_FOREIGN_EXCHANGE_RATE_MOD = 29443;
//! ����ڻ���������ʧ��
const int TAPIERROR_FOREIGN_EXCHANGE_RATE_ADD = 29444;
//! ����ڻ�����ɾ��ʧ��
const int TAPIERROR_FOREIGN_EXCHANGE_RATE_DEL = 29445;
//==============================================================================
//! �ʼ���Ϣ��ѯʧ��
const int TAPIERROR_MAIL_INFO_QRY = 29451;
//! �ʼ���Ϣ����ʧ��
const int TAPIERROR_MAIL_INFO_ADD = 29452;
//! �ʼ���Ϣ�޸�ʧ��
const int TAPIERROR_MAIL_INFO_MOD = 29453;
//! �ʼ���Ϣɾ��ʧ��
const int TAPIERROR_MAIL_INFO_DEL = 29454;
//==============================================================================
//! ������ʲ�ѯʧ��
const int TAPIERROR_FOREX_RATE_INFO_QRY = 29461;
//! �����������ʧ��
const int TAPIERROR_FOREX_RATE_INFO_ADD = 29462;
//! ��������޸�ʧ��
const int TAPIERROR_FOREX_RATE_INFO_MOD = 29463;
//! �������ɾ��ʧ��
const int TAPIERROR_FOREX_RATE_INFO_DEL = 29464;
//==============================================================================
//! �����ڲ�ѯʧ��
const int TAPIERROR_FOREX_HOLIDAY_QRY = 29471;
//! ����������ʧ��
const int TAPIERROR_FOREX_HOLIDAY_ADD = 29472;
//! �������޸�ʧ��
const int TAPIERROR_FOREX_HOLIDAY_MOD = 29473;
//! ������ɾ��ʧ��
const int TAPIERROR_FOREX_HOLIDAY_DEL = 29474;
//==============================================================================
//! �ͻ�������ѯʧ��
const int TAPIERROR_ACCOUNT_RELATEINFO_QRY = 29481;
//! �ͻ���������ʧ��
const int TAPIERROR_ACCOUNT_RELATEINFO_ADD = 29482;
//! �ͻ������޸�ʧ��
const int TAPIERROR_ACCOUNT_RELATEINFO_MOD = 29483;
//! �ͻ�����ɾ��ʧ��
const int TAPIERROR_ACCOUNT_RELATEINFO_DEL = 29484;
//==============================================================================
//! ֣���������̱��ۼ۲��ѯʧ��
const int TAPIERROR_MARKETERPRICE_QRY = 29491;
//! ֣���������̱��ۼ۲�����ʧ��
const int TAPIERROR_MARKETERPRICE_ADD = 29492;
//! ֣���������̱��ۼ۲��޸�ʧ��
const int TAPIERROR_MARKETERPRICE_MOD = 29493;
//! ֣���������̱��ۼ۲�?h��ʧ��
const int TAPIERROR_MARKETERPRICE_DEL = 29494;
//==============================================================================
//! �������л���Ϣ��ѯʧ��
const int TAPIERROR_SERVERCHANGE_QRY = 29501;
//! �������л���Ϣ����ʧ��
const int TAPIERROR_SERVERCHANGE_ADD = 29502;
//! �������л���Ϣɾ��ʧ��
const int TAPIERROR_SERVERCHANGE_DEL = 29503;
//==============================================================================
//! �ϼ�ϵͳ�ʽ��˺Ź�ϵ��ѯʧ��
const int TAPIERROR_UPPERACCOUNT_QRY = 29511;
//! �ϼ�ϵͳ�ʽ��˺Ź�ϵ����ʧ��
const int TAPIERROR_UPPERACCOUNT_ADD = 29512;
//! �ϼ�ϵͳ�ʽ��˺Ź�ϵɾ��ʧ��
const int TAPIERROR_UPPERACCOUNT_DEL = 29513;

//==============================================================================
//! �ϼ���½��ַ��Ϣ���ѯʧ��
const int TAPIERROR_UPPERLINK_QRY = 29521;
//! �ϼ���½��ַ��Ϣ������ʧ��
const int TAPIERROR_UPPERLINK_ADD = 29522;
//! �ϼ���½��ַ��Ϣ���޸�ʧ��
const int TAPIERROR_UPPERLINK_MOD = 29523;
//! �ϼ���½��ַ��Ϣ��ɾ��ʧ��
const int TAPIERROR_UPPERLINK_DEL = 29524;

//==============================================================================
//! ���ֱ�֤�������޸�����ʧ��
const int TAPIERROR_UPPERMARGINBATCH_MOD = 29531;

//==============================================================================
//! �����������
//==============================================================================
//! ��ʷί�в�ѯ����
const int TAPIERROR_HISORDER_QRY = 40001;
//! ��ʷί�����Ӵ���
const int TAPIERROR_HISORDER_ADD = 40002;
//! ��ʷί���޸Ĵ���
const int TAPIERROR_HISORDER_MOD = 40003;
//! ��ʷί��ɾ��
const int TAPIERROR_HISORDER_DEL = 40004;
//! ���׷�����ί�в�ѯ����
const int TAPIERROR_ORDERFORTRADE_QRY = 40005;

//==============================================================================
//! ��ʷ�ɽ���ѯ����
const int TAPIERROR_HISMATCH_QRY = 40101;
//! ��ʷ�ɽ����Ӵ���
const int TAPIERROR_HISMATCH_ADD = 40102;
//! ��ʷ�ɽ��޸Ĵ���
const int TAPIERROR_HISMATCH_MOD = 40103;
//! ��ʷ�ɽ�ɾ������
const int TAPIERROR_HISMATCH_DEL = 40104;
//! ���׷������ɽ���ѯ����
const int TAPIERROR_MATCHFORTRADE_QRY = 40105;

//==============================================================================
//! ��ʷ�ֲֲ�ѯ����
const int TAPIERROR_HISPOSITION_QRY = 40201;
//! ��ʷ�ֲ����Ӵ���
const int TAPIERROR_HISPOSITION_ADD = 40202;
//! ��ʷ�ֲ��޸Ĵ���
const int TAPIERROR_HISPOSITION_MOD = 40203;
//! ��ʷ�ֲ�ɾ������
const int TAPIERROR_HISPOSITION_DEL = 40204;
//! ���׷������ֲֲ�ѯ����
const int TAPIERROR_POSITIONFORTRADE_QRY = 40205;
//! ��һ�����ղ�ѯ����
const int TAPIERROR_LASTSETTLEDATE_QRY = 40206;
//! ��ʷ�ֲ�ɾ���쳣��������˹����㣨��⵽���˺Ž�����Ϣ����δ�����˹����㣩
const int TAPIERROR_HISPOSITION_DELUNUSUAL = 40207;

//==============================================================================
//! ��ʷƽ�ֲ�ѯ����
const int TAPIERROR_HISCLOSE_QRY = 40301;

//==============================================================================
//! ��ʷδ����ƽ�ֲ�ѯ����
const int TAPIERROR_HISUNEXPCLOSE_QRY = 40401;
//! ��ʷδ����ƽ�����Ӵ���
const int TAPIERROR_HISUNEXPCLOSE_ADD = 40402;
//! ��ʷδ����ƽ���޸Ĵ���
const int TAPIERROR_HISUNEXPCLOSE_MOD = 40403;
//! ��ʷδ����ƽ��ɾ������
const int TAPIERROR_HISUNEXPCLOSE_DEL = 40404;

//==============================================================================
//! ��ʷ�����ѯ����
const int TAPIERROR_HISDELIVERY_QRY = 40501;
//! ��ʷ�������Ӵ���
const int TAPIERROR_HISDELIVERY_ADD = 40502;
//! ��ʷ�����޸Ĵ���
const int TAPIERROR_HISDELIVERY_MOD = 40503;
//! ��ʷ����ɾ������
const int TAPIERROR_HISDELIVERY_DEL = 40504;

//==============================================================================
//! ����۲�ѯ����
const int TAPIERROR_SETTLEPRICE_QRY = 40601;
//! ��������Ӵ���
const int TAPIERROR_SETTLEPRICE_ADD = 40602;
//! ������޸Ĵ���
const int TAPIERROR_SETTLEPRICE_MOD = 40603;
//! �����ɾ������
const int TAPIERROR_SETTLEPRICE_DEL = 40604;

//==============================================================================
//! ��Ч��Լ���ɴ���
const int TAPIERROR_VALIDCONTRACT_GEN = 40701;

//==============================================================================
//! �Ʋֲ�ѯ����
const int TAPIERROR_POSITIONMOVE_QRY = 40801;
//! �Ʋ����Ӵ���
const int TAPIERROR_POSITIONMOVE_ADD = 40802;
//! �Ʋ�ɾ������
const int TAPIERROR_POSITIONMOVE_DEL = 40803;

//==============================================================================
//! �ͻ�������ѯ����
const int TAPIERROR_ACCOUNTCASHINOUT_QRY = 40901;
//! �ͻ���������Ӵ���
const int TAPIERROR_ACCOUNTCASHINOUT_ADD = 40902;
//! �ͻ����������֪ͨ����
const int TAPIERROR_ACCOUNTCASHINOUTADD_NOTICE = 40903;

//==============================================================================
//! �ͻ��ʽ������ѯ����
const int TAPIERROR_ACCOUNTCASHADJUST_QRY = 41001;
//! �ͻ��ʽ�������Ӵ���
const int TAPIERROR_ACCOUNTCASHADJUST_ADD = 41002;
//! �ͻ��ʽ��������֪ͨ����
const int TAPIERROR_ACCOUNTCASHADJUSTADD_NOTICE = 41003;

//==============================================================================
//! �ͻ��ʽ��Ҳ�ѯ����
const int TAPIERROR_ACCOUNTCASHSWAP_QRY = 41201;
//! �ͻ��ʽ������Ӵ���
const int TAPIERROR_ACCOUNTCASHSWAP_ADD = 41202;
//! �ͻ��ʽ�������֪ͨ����
const int TAPIERROR_ACCOUNTCASHSWAPADD_NOTICE = 41203;

//==============================================================================
//! �ͻ�ת����Ϣ��ѯ����
const int TAPIERROR_TRANSFERINFO_QRY = 41301;
//! �ͻ�ת����Ϣ���Ӵ���
const int TAPIERROR_TRANSFERINFO_ADD = 41302;
//! �ͻ�ת������֪ͨ����
const int TAPIERROR_ATRANSFERINFOADD_NOTICE = 41303;

//==============================================================================
//! Span��֤���ѯ����
const int TAPIERROR_SPANMARGIN_QRY = 41401;
//! Span��֤�����Ӵ���
const int TAPIERROR_SPANMARGIN_ADD = 41402;
//! Span��֤���޸Ĵ���
const int TAPIERROR_SPANMARGIN_MOD = 41403;
//! Span��֤���޸Ĵ���
const int TAPIERROR_SPANMARGIN_DEL = 41404;

//==============================================================================
//! �ͻ��ʽ��ѯʧ��
const int TAPIERROR_ACCOUNTFUND_QRY = 41501;
//! ���ײ�ѯ�ͻ��ʽ�ʧ��
const int TAPIERROR_ACCOUNTFUNDFORTRADE_QRY = 41502;
//! �ͻ��ʽ�����ʧ��
const int TAPIERROR_ACCOUNTFUND_ADD = 41503;
//! �ͻ��ʽ�ɾ��ʧ��
const int TAPIERROR_ACCOUNTFUND_DEL = 41504;

//==============================================================================
//! �ͻ������ʽ��ѯ����
const int TAPIERROR_ACCOUNTFROZENFUND_QRY = 41601;
//! �ͻ������ʽ����Ӵ���
const int TAPIERROR_ACCOUNTFROZENFUND_ADD = 41602;
//! �ͻ������ʽ�����֪ͨ����
const int TAPIERROR_ACCOUNTFROZENADD_NOTICE = 41603;
//! �ͻ������ʽ��޸Ĵ���
const int TAPIERROR_ACCOUNTFROZENFUND_MOD = 41604;
//! �ͻ������ʽ��޸�֪ͨ����
const int TAPIERROR_ACCOUNTFROZENMOD_NOTICE = 41605;

//==============================================================================
//! ���ֳ�����ѯ����
const int TAPIERROR_UPPERCASHINOUT_QRY = 41701;
//! ���ֳ�������Ӵ���
const int TAPIERROR_UPPERCASHINOUT_ADD = 41702;
//! ���ֳ�����޸Ĵ���
const int TAPIERROR_UPPERCASHINOUT_MOD = 41703;
//! ���ֳ����ɾ������
const int TAPIERROR_UPPERCASHINOUT_DEL = 41704;

//==============================================================================
//! �����ʽ������ѯ����
const int TAPIERROR_UPPERCASHADJUST_QRY = 41801;
//! �����ʽ�������Ӵ���
const int TAPIERROR_UPPERCASHADJUST_ADD = 41802;
//! �����ʽ�����޸Ĵ���
const int TAPIERROR_UPPERCASHADJUST_MOD = 41803;
//! �����ʽ����ɾ������
const int TAPIERROR_UPPERCASHADJUST_DEL = 41804;

//==============================================================================
//! �����ʽ��ѯ����
const int TAPIERROR_UPPERFUND_QRY = 41901;

//==============================================================================
//! �����������
const int TAPIERROR_SETTLEDEAL_QRY = 42001;

//==============================================================================
//! ������̲�ѯ����
const int TAPIERROR_SETTLEPROCESS_QRY = 42101;
//! �������κŲ�ѯ����
const int TAPIERROR_SettleBatchNo_QRY = 42102;
//==============================================================================
//! ��־��ѯ����
const int TAPIERROR_LOG_QRY = 42201;

//==============================================================================
//! ������Ϣ���ʹ���
const int TAPIERROR_TRADEMESSAGE_SEND = 42301;
//! ������Ϣ��ѯ����
const int TAPIERROR_TRADEMESSAGE_QRY = 42302;
//! ������Ϣ����֪ͨ����
const int TAPIERROR_TRADEMESSAGE_NOTICE = 42303;

//==============================================================================
//! ������Ϣ���ʹ���
const int TAPIERROR_QUOTEMESSAGE_SEND = 42401;
//! ������Ϣ��ѯ����
const int TAPIERROR_QUOTEMESSAGE_QRY = 42402;
//! ������Ϣ����֪ͨ����
const int TAPIERROR_QUOTEMESSAGE_NOTICE = 42403;

//==============================================================================
//! ����ͳ�Ʊ����
const int TAPIERROR_TRADINGSTATISTICS_REQ = 42501;

//==============================================================================
//! PCS����ʧ��
const int TAPIERROR_PCS_REQ = 42601;
//! CGM����ʧ��
const int TAPIERROR_CGM_REQ = 42602;
//! LargeTrader����ʧ��
const int TAPIERROR_LARGETRADER_REQ = 42603;
//! PCS��ѯ����ʧ��
const int TAPIERROR_PCS_QRY_REQ = 42604;
//! CGM��ѯ����ʧ��
const int TAPIERROR_CGM_QRY_REQ = 42605;
//! LargeTrader��ѯ����ʧ��
const int TAPIERROR_LARGETRADER_QRY_REQ = 42606;

//==============================================================================
//! CME�ɽ���������ʧ��
const int TAPIERROR_CME_MATCH_IMPORT_REQ = 42701;
//! CME�ɽ���ѯ����ʧ��
const int TAPIERROR_CME_MATCHT_QRY_REQ = 42702;
//! CME�ֲֵ�������ʧ��
const int TAPIERROR_CME_POSITION_IMPORT_REQ = 42703;
//! CME�ֲֲ�ѯ����ʧ��
const int TAPIERROR_CME_POSITION_QRY_REQ = 42704;
//! CME�ɽ�ɾ������ʧ��
const int TAPIERROR_CMEMATCH_DEL_REQ = 42705;
//! CME�ֲ�ɾ������ʧ��
const int TAPIERROR_CMEPOSITION_DEL_REQ = 42706;

//==============================================================================
//! MQ�ɽ���������ʧ��
const int TAPIERROR_MQ_MATCH_ADD_REQ = 42801;
//! MQ�ɽ���ѯ����ʧ��
const int TAPIERROR_MQ_MATCHT_QRY_REQ = 42802;

//==============================================================================
//! �����˻�ƽ����Ϣ��ѯ����ʧ��
const int TAPIERROR_OMNIBUSACCOUNTCLOSEINFO_QRY_REQ = 42901;
//! �����˻�ƽ����Ϣ��������ʧ��
const int TAPIERROR_OMNIBUSACCOUNTCLOSEINFO_ADD_REQ = 42902;
//! �����˻�ƽ����Ϣ�޸�����ʧ��
const int TAPIERROR_OMNIBUSACCOUNTCLOSEINFO_MOD_REQ = 42903;
//! �����˻�ƽ����Ϣɾ������ʧ��
const int TAPIERROR_OMNIBUSACCOUNTCLOSEINFO_DEL_REQ = 42904;

//==============================================================================
//! �ɽ��˶�����ʧ��
const int TAPIERROR_CHECK_MATCH_REQ = 43001;
//! �ֲֺ˶�����ʧ��
const int TAPIERROR_CHECK_POSITION_REQ = 43002;

//==============================================================================
//! �ֲִ�������ʧ��
const int TAPIERROR_DEAL_POSITION_REQ = 43101;

//==============================================================================
//! �ֲ��۵ֲ�ѯ����ʧ��
const int TAPIERROR_POSITIONMORTGAGE_QRY_REQ = 43201;
//! �ֲ��۵���������ʧ��
const int TAPIERROR_POSITIONMORTGAGE_ADD_REQ = 43202;
//! �ֲ��۵��޸�����ʧ��
const int TAPIERROR_POSITIONMORTGAGE_MOD_REQ = 43203;
//! �ֲ��۵�ɾ������ʧ��
const int TAPIERROR_POSITIONMORTGAGE_DEL_REQ = 43204;

//==============================================================================
//! ������֤���Żݲ�����Ϣ��ѯ����ʧ��
const int TAPIERROR_DCEMARGINPREFERENT_QRY_REQ = 43301;
//! ������֤���Żݲ�����Ϣ��������ʧ��
const int TAPIERROR_DCEMARGINPREFERENT_ADD_REQ = 43302;
//! ������֤���Żݲ�����Ϣ�޸�����ʧ��
const int TAPIERROR_DCEMARGINPREFERENT_MOD_REQ = 43303;
//! ������֤���Żݲ�����Ϣɾ������ʧ��
const int TAPIERROR_DCEMARGINPREFERENT_DEL_REQ = 43304;

//==============================================================================
//! ֣�������������Ϣ��ѯ����ʧ��
const int TAPIERROR_ZCEAPPLYCMB_QRY_REQ = 43401;
//! ֣�������������Ϣ��������ʧ��
const int TAPIERROR_ZCEAPPLYCMB_ADD_REQ = 43402;
//! ֣�������������Ϣ�޸�����ʧ��
const int TAPIERROR_ZCEAPPLYCMB_MOD_REQ = 43403;
//! ֣�������������Ϣɾ������ʧ��
const int TAPIERROR_ZCEAPPLYCMB_DEL_REQ = 43404;

//==============================================================================
//! �ɽ��˶Ա�������ʧ��
const int TAPIERROR_MATCHREPORT_REQ = 43501;
//! �ֲֺ˶Ա�������ʧ��
const int TAPIERROR_POSITIONREPORT_REQ = 43502;

//==============================================================================
//! �ͻ������ʽ���������ʧ��
const int TAPIERROR_ACCOUNTAUTHCASH_ADD_REQ = 43601;
//! �ͻ������ʽ��ѯ����ʧ��
const int TAPIERROR_ACCOUNTAUTHCASH_DEL_REQ = 43602;

//==============================================================================
//! ���ֲֺ̳˶��������
const int TAPIERROR_FOREIGNPOSITION_CHECK_REQ = 43701;
//! ���̿ͻ��ʽ�˶��������		
const int TAPIERROR_ACCOUNTFUND_CHECK_REQ = 43702;
//! ����δ����ƽ�ֺ˶��������
const int TAPIERROR_UNEXPCLOSE_CHECK_REQ = 43703;

//==============================================================================
//! �����ʽ��ѯ�������
const int TAPIERROR_OTHERFUND_QRY_REQ = 43801;
//! �����ʽ������������		
const int TAPIERROR_OTHERFUND_ADD_REQ = 43802;
//! �����ʽ��޸��������
const int TAPIERROR_OTHERFUND_MOD_REQ = 43803;
//! �����ʽ�ɾ���������
const int TAPIERROR_OTHERFUND_DEL_REQ = 43804;

//==============================================================================
//! �ͻ��ʽ�ˢ��֪ͨ�������
const int TAPIERROR_ACCOUNTFUND_NOTICE_REQ = 43901;

//==============================================================================
//! ���ݿͻ��Ʋ���Ϣ��ѯ�������
const int TAPIERROR_POSITIONMOVEBYACCOUNT_QRY_REQ = 44001;
//! ���ݿͻ��Ʋ���Ϣ�����������		
const int TAPIERROR_POSITIONMOVEBYACCOUNT_ADD_REQ = 44002;
//! ���ݿͻ��Ʋ���Ϣ�޸��������
const int TAPIERROR_POSITIONMOVEBYACCOUNT_MOD_REQ = 44003;
//! ���ݿͻ��Ʋ���Ϣɾ���������
const int TAPIERROR_POSITIONMOVEBYACCOUNT_DEL_REQ = 44004;

//==============================================================================
//! �����������
const int TAPIERROR_ADJUSTMATCH_REQ = 44101;

//==============================================================================
//! ����֪ͨ�����
const int TAPIERROR_SWAPREPORT_REQ = 44201;

//==============================================================================
//! ׷��ǿƽ�������
const int TAPIERROR_ADDFOURCEREPORT_REQ = 44301;

//==============================================================================
//! �ʽ���˱����
const int TAPIERROR_ACCOUNTFUNDREPORT_REQ = 44401;

//==============================================================================
//! ���ʾ�����
const int TAPIERROR_DELIVERYALARMREPORT_REQ = 44501;

//==============================================================================
//! ���߿����ռ۸��ѯ�������
const int TAPIERROR_OHCL_QRY_REQ = 44601;
//! ���߿����ռ۸������������		
const int TAPIERROR_OHCL_ADD_REQ = 44602;
//! ���߿����ռ۸��޸��������
const int TAPIERROR_OHCL_MOD_REQ = 44603;
//! ���߿����ռ۸�ɾ���������
const int TAPIERROR_OHCL_DEL_REQ = 44604;

//==============================================================================
//! ��������Ϣ��ѯ�������
const int TAPIERROR_TODELIVERY_QRY_REQ = 44701;
//! ��������Ϣ�����������		
const int TAPIERROR_TODELIVERY_ADD_REQ = 44702;
//! ��������Ϣ�޸��������
const int TAPIERROR_TODELIVERY_MOD_REQ = 44703;
//! ��������Ϣɾ���������
const int TAPIERROR_TODELIVERY_DEL_REQ = 44704;

//==============================================================================
//! �ͻ���Ѻ�ʽ��ѯ�������
const int TAPIERROR_ACCOUNTPLEDGE_QRY_REQ = 44801;
//! �ͻ���Ѻ�ʽ������������		
const int TAPIERROR_ACCOUNTPLEDGE_ADD_REQ = 44802;
//==============================================================================
//! �ͻ����ۻ��ѯ�������
const int TAPIERROR_SETTLESALE_QRY_REQ = 44901;
//! �ͻ����ۻ������������		
const int TAPIERROR_SETTLESALE_ADD_REQ = 44902;
//! �ͻ����ۻ�ɾ���������		
const int TAPIERROR_SETTLESALE_DEL_REQ = 44903;

//==============================================================================
//! ϯλʹ�÷Ѳ�ѯ�������
const int TAPIERROR_SEATFEE_QRY_REQ = 45001;
//! ϯλʹ�÷������������		
const int TAPIERROR_SEATFEE_ADD_REQ = 45002;
//! ϯλʹ�÷�ɾ���������		
const int TAPIERROR_SEATFEE_DEL_REQ = 45003;
//! ϯλʹ�÷��޸��������		
const int TAPIERROR_SEATFEE_MOD_REQ = 45004;

//==============================================================================
//! ����ͨ���ʺŷֲ����Ӵ���
const int TAPIERROR_DISTRIBUTEPOSITION_ADD_REQ = 45101;

//==============================================================================
//! ����֮�ҽ�����ѯ�������
const int TAPIERROR_TRADERESULT_QRY_REQ = 45201;

//==============================================================================
//! ����֮�ҽ���������������
const int TAPIERROR_DEALRESULT_REQ = 45301;

//==============================================================================
//! ��ʱͳ�Ʊ������������
const int TAPIERROR_STATISTIC_ADD_REQ = 45401;

//==============================================================================
//! �ʹ�ϵͳ������Ϣ��ѯ�������
const int TAPIERROR_ORGANCHECK_QRY_REQ = 45501;

//=============================================================================
//! ��������Ƶ�ʹ���
const int TAPIERROR_ORDER_FREQUENCY                                    = 61001;
//! ί�в�ѯ����ǰ���ܽ����´β�ѯ
const int TAPIERROR_ORDER_QUERYING                                     = 61002;


//==============================================================================
//! һ�������ݰ��ո�����ѯʧ��
const int TAPIERROR_1MINUTEBYCOUNT_QRY = 70101;
//! һ�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_1MINUTEBYPERIOD_QRY = 70102;
//! һ�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_1MINUTEBYDATE_QRY = 70103;

//==============================================================================
//! ���������ݰ��ո�����ѯʧ��
const int TAPIERROR_3MINUTEBYCOUNT_QRY = 70201;
//! ���������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_3MINUTEBYPERIOD_QRY = 70202;
//! ���������ݰ�DATE��ѯʧ��	
const int TAPIERROR_3MINUTEBYDATE_QRY = 70203;

//==============================================================================
//! ��������ݰ��ո�����ѯʧ��
const int TAPIERROR_5MINUTEBYCOUNT_QRY = 70301;
//! ��������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_5MINUTEBYPERIOD_QRY = 70302;
//! ��������ݰ�DATE��ѯʧ��	
const int TAPIERROR_5MINUTEBYDATE_QRY = 70303;

//==============================================================================
//! ʮ�������ݰ��ո�����ѯʧ��
const int TAPIERROR_10MINUTEBYCOUNT_QRY = 70401;
//! ʮ�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_10MINUTEBYPERIOD_QRY = 70402;
//! ʮ�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_10MINUTEBYDATE_QRY = 70403;

//==============================================================================
//! ʮ��������ݰ��ո�����ѯʧ��
const int TAPIERROR_15MINUTEBYCOUNT_QRY = 70501;
//! ʮ��������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_15MINUTEBYPERIOD_QRY = 70502;
//! ʮ��������ݰ�DATE��ѯʧ��	
const int TAPIERROR_15MINUTEBYDATE_QRY = 70503;

//==============================================================================
//! ��ʮ�������ݰ��ո�����ѯʧ��
const int TAPIERROR_30MINUTEBYCOUNT_QRY = 70601;
//! ��ʮ�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_30MINUTEBYPERIOD_QRY = 70602;
//! ��ʮ�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_30MINUTEBYDATE_QRY = 70603;

//==============================================================================
//! ��ʮ�������ݰ��ո�����ѯʧ��
const int TAPIERROR_60MINUTEBYCOUNT_QRY = 70701;
//! ��ʮ�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_60MINUTEBYPERIOD_QRY = 70702;
//! ��ʮ�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_60MINUTEBYDATE_QRY = 70703;

//==============================================================================
//! 120�������ݰ��ո�����ѯʧ��
const int TAPIERROR_120MINUTEBYCOUNT_QRY = 70801;
//! 120�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_120MINUTEBYPERIOD_QRY = 70802;
//! 120�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_120MINUTEBYDATE_QRY = 70803;

//==============================================================================
//! 240�������ݰ��ո�����ѯʧ��
const int TAPIERROR_240MINUTEBYCOUNT_QRY = 70901;
//! 240�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_240MINUTEBYPERIOD_QRY = 70902;
//! 240�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_240MINUTEBYDATE_QRY = 70903;

//==============================================================================
//! 30�����ݰ��ո�����ѯʧ��
const int TAPIERROR_30SECONDSBYCOUNT_QRY = 71001;
//! 30�����ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_30SECONDSBYPERIOD_QRY = 71002;
//! 30�����ݰ�DATE��ѯʧ��	
const int TAPIERROR_30SECONDSBYDATE_QRY = 71003;

//==============================================================================
//! Tick���ݰ��ո�����ѯʧ��
const int TAPIERROR_TICKBYCOUNT_QRY = 71101;
//! Tick���ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_TICKBYPERIOD_QRY = 71102;
//! Tick���ݰ�DATE��ѯʧ��	
const int TAPIERROR_TICKBYDATE_QRY = 71103;

//==============================================================================
//! �������ݰ��ո�����ѯʧ��
const int TAPIERROR_DAYBYCOUNT_QRY = 71201;
//! �������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_DAYBYPERIOD_QRY = 71202;
//! �������ݰ�DATE��ѯʧ��	
const int TAPIERROR_DAYBYDATE_QRY = 71203;

//==============================================================================
//! �������ݰ��ո�����ѯʧ��
const int TAPIERROR_WEEKBYCOUNT_QRY = 71301;
//! �������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_WEEKBYPERIOD_QRY = 71302;
//! �������ݰ�DATE��ѯʧ��	
const int TAPIERROR_WEEKBYDATE_QRY = 71303;

//==============================================================================
//! �������ݰ��ո�����ѯʧ��
const int TAPIERROR_MONTHBYCOUNT_QRY = 71401;
//! �������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_MONTHBYPERIOD_QRY = 71402;
//! �������ݰ�DATE��ѯʧ��	
const int TAPIERROR_MONTHBYDATE_QRY = 71403;

//==============================================================================
//! �������ݰ��ո�����ѯʧ��
const int TAPIERROR_YEARBYCOUNT_QRY = 71501;
//! �������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_YEARBYPERIOD_QRY = 71502;
//! �������ݰ�DATE��ѯʧ��	
const int TAPIERROR_YEARBYDATE_QRY = 71503;

//==============================================================================
//! N�������ݰ��ո�����ѯʧ��
const int TAPIERROR_NMINUTESBYCOUNT_QRY = 71601;
//! N�������ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_NMINUTESBYPERIOD_QRY = 71602;
//! N�������ݰ�DATE��ѯʧ��	
const int TAPIERROR_NMINUTESBYDATE_QRY = 71603;

//==============================================================================
//! N�����ݰ��ո�����ѯʧ��
const int TAPIERROR_NDAYSBYCOUNT_QRY = 71701;
//! N�����ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_NDAYSBYPERIOD_QRY = 71702;
//! N�����ݰ�DATE��ѯʧ��	
const int TAPIERROR_NDAYSBYDATE_QRY = 71703;

//==============================================================================
//! N�����ݰ��ո�����ѯʧ��
const int TAPIERROR_NSECONDBYCOUNT_QRY = 71801;
//! N�����ݰ�ʱ��β�ѯʧ��	
const int TAPIERROR_NSECONDSBYPERIOD_QRY = 71802;
//! N�����ݰ�DATE��ѯʧ��	
const int TAPIERROR_NSECONDSBYDATE_QRY = 71803;

//==============================================================================
//! 
//!    �޸���Ϣ���߶��� +  2013/4/20  + �������ش�����붨��
//! 
//====================================�������ش�����붨��=======================
//! ��������ʧ��
const int TAPIERROR_ORDER_SEND = 80001;
//! ���ͱ���ʧ�ܣ�����û���ӵ�������
const int TAPIERROR_DLG_NULL = 80002;
//! �����ֶ�����
const int TAPIERROR_ORDER_FIELD = 80003;
//! �����־ܾ�
const int TAPIERROR_TRADE_REJ_BYUPPER = 80004;
//! ��������������������tapЭ��API������붨�塪��������������������������
//! 
//! 
//! �������׷������ʧ��
const int TAPIERROR_TAPSERVER_CREATE = 81001;
//! ��������ʧ��
const int TAPIERROR_CONNECT_BUS = 81002;
//! ���յ������ݴ���
const int TAPIERROR_GWRCV_DATA = 81003;
//! ����֡ͷ��ʶ����
const int TAPIERROR_FRAME_FLAG = 81004;
//! ���ݲ�ȫ
const int TAPIERROR_GWREC_DATA_PARTICAL = 81005;
//! FrameHead_TYPE����
const int TAPIERROR_FRAMEHEAD_TYPE = 81006;
//! ���������������	
const int TAPIERROR_MANAGESERVER_MATCH = 81007;
//! û�ж�Ӧ���ڲ�����
const int TAPIERROR_QRY_INNERCOMM0DITY = 81008;
//! û�ж�Ӧ�Ŀͻ�����
const int TAPIERROR_CLIENTNO = 81009;
//! û�ܶ�Ӧ���ⲿ����
const int TAPIERROR_QRY_UPPERCOMMODITY = 81010;
//! ���ص�ǰ���ܲ�ѯ������ʱ��
const int TAPIERROR_QRY_MARKETSTATE = 81011;

//! ----------------����ǰ�ô�����붨��-----------------------------------------------
//! �������׷������ʧ��
const int TAPIERROR_TRADEFRONT_TAPSERVER_CREATE = 82001;
//! ��������ʧ��
const int TAPIERROR_TRADEFRONT_CONNECT_BUS = 82002;
//! ������·�߳�ʧ��
const int TAPIERROR_TRADEFRONT_LINK_THREAD = 82003;
//! ���ĵ�¼����ʧ��
const int TAPIERROR_TRADEFRONT_SUBLOGIN = 82004;
//! ���ĵ�¼��ѯ����ʧ��
const int TAPIERROR_TRADEFRONT_SUBLOGINQUERY = 82005;
//! ���Ĺ����������ʧ��
const int TAPIERROR_TRADEFRONT_SUBMANAGEBASIC = 82006;
//! ���Ĺ���߼�����ʧ��
const int TAPIERROR_TRADEFRONT_SUBMANAGEADVANCED = 82007;
//! ���Ľ������ʧ��
const int TAPIERROR_TRADEFRONT_SUBSETTLE = 82008;
//! ���Ľ�����Ϣ����ʧ��
const int TAPIERROR_TRADEFRONT_SUBSETTLEMESSAGE = 82009;
//! ���Ľ����ʽ����ʧ��
const int TAPIERROR_TRADEFRONT_SUBSETTLEMONEY = 82010;
//! ���Ľ��׷���ʧ��
const int TAPIERROR_TRADEFRONT_SUBTRADE = 82011;
//! ��ɶ˿ڴ���ʧ��
const int TAPIERROR_TRADEFRONT_SERVERSTART_IOCP = 82012;
//! ���������������߳�ʧ��
const int TAPIERROR_TRADEFRONT_SERVERSTART_WORKER = 82013;
//! ���������������߳�ʧ��
const int TAPIERROR_TRADEFRONT_SERVERSTART_LISTEN = 82014;
//! �����˿�ʧ��
const int TAPIERROR_TRADEFRONT_SERVERSTART_PORT = 82015;
//! ǰ�ò������ģ���¼
const int TAPIERROR_TRADEFRONT_MODULETYPEERR = 82016;
//! ǰ���ύ����ʧ��
const int TAPIERROR_TRADEFRONT_SENDDATAERR = 82017;
//! ǰ�ò������¼
const int TAPIERROR_TRADEFRONT_NOTALLOWLOGIN = 82018;
//! һ������̫������
const int TAPIERROR_TRADEFRONT_TOOMANYDATA = 82019;
//! ǰ��û����Ҫ����
const int TAPIERROR_TRADEFRONT_NODATA = 82020;
//! �µ�ʧ�ܣ�Сǰ����������Ͽ�
const int TAPIERROR_TRADEFRONT_DICONNECT_SMTRADE = 82021;
//! �µ�ʧ�ܣ�ǰ���뽻�׷������Ͽ�
const int TAPIERROR_TRADEFRONT_DICONNECT_TRADE = 82022;
//! ----------------����ǰ�ô�����붨��-----------------------------------------------
//! ��֧�ֵ�����Э��
const int TAPIERROR_QUOTEFRONT_UNKNOWN_PROTOCOL = 83001;

//==============================================================================
//! ��ѯ�Զ�ǿƽ�������ʧ��
const int TAPIERROR_FORCECLOSEWARNINGPARAM_QRY = 85001;
//! �����Զ�ǿƽ�������ʧ��
const int TAPIERROR_FORCECLOSEWARNINGPARAM_ADD = 85002;
//! �޸��Զ�ǿƽ�������ʧ��
const int TAPIERROR_FORCECLOSEWARNINGPARAM_MOD = 85003;
//! ɾ���Զ�ǿƽ�������ʧ��
const int TAPIERROR_FORCECLOSEWARNINGPARAM_DEL = 85004;
//==============================================================================
//! ��ѯ�Զ�ǿƽ��ʼ����ʧ��
const int TAPIERROR_FORCECLOSESTARTPARAM_QRY = 85011;
//! �����Զ�ǿƽ��ʼ����ʧ��
const int TAPIERROR_FORCECLOSESTARTPARAM_ADD = 85012;
//! �޸��Զ�ǿƽ��ʼ����ʧ��
const int TAPIERROR_FORCECLOSESTARTPARAM_MOD = 85013;
//! ɾ���Զ�ǿƽ��ʼ����ʧ��
const int TAPIERROR_FORCECLOSESTARTPARAM_DEL = 85014;
//==============================================================================
//! ��ѯ�Զ�ǿƽ��ֹ����ʧ��
const int TAPIERROR_FORCECLOSESTOPPARAM_QRY = 85021;
//! �����Զ�ǿƽ��ֹ����ʧ��
const int TAPIERROR_FORCECLOSESTOPPARAM_ADD = 85022;
//! �޸��Զ�ǿƽ��ֹ����ʧ��
const int TAPIERROR_FORCECLOSESTOPPARAM_MOD = 85023;
//! ɾ���Զ�ǿƽ��ֹ����ʧ��
const int TAPIERROR_FORCECLOSESTOPPARAM_DEL = 85024;
//==============================================================================
//! ��ѯǿƽ˳�����ʧ��
const int TAPIERROR_FORCECLOSETURNPARAM_QRY = 85031;
//! ����ǿƽ˳�����ʧ��
const int TAPIERROR_FORCECLOSETURNPARAM_ADD = 85032;
//! �޸�ǿƽ˳�����ʧ��
const int TAPIERROR_FORCECLOSETURNPARAM_MOD = 85033;
//! ɾ��ǿƽ˳�����ʧ��
const int TAPIERROR_FORCECLOSETURNPARAM_DEL = 85034;
//==============================================================================
//! ��ѯǿƽִ�в���ʧ��
const int TAPIERROR_FORCECLOSEEXECPARAM_QRY = 85041;
//! ����ǿƽִ�в���ʧ��
const int TAPIERROR_FORCECLOSEEXECPARAM_ADD = 85042;
//! �޸�ǿƽִ�в���ʧ��
const int TAPIERROR_FORCECLOSEEXECPARAM_MOD = 85043;
//! ɾ��ǿƽִ�в���ʧ��
const int TAPIERROR_FORCECLOSEEXECPARAM_DEL = 85044;

//! ----------------���ڷ��������붨��-----------------------------------------------
//! �ڻ��ʽ��˻�������
const int TAPIERROR_ACCOUNTNO_NOEXIT = 90001;
//! �����в�������ڻ��˷���ǩ��Լ
const int TAPIERROR_BANKSINGED_NOTALLOW = 90002;
//! ������֤�������
const int TAPIERROR_BANKPASSWORDAUTH = 90003;
//! �˻�û�иñ����ʽ��¼
const int TAPIERROR_BANKFUTUREVALUE_NOTEXIT = 90004;
//! �˻���Ӧ���ֳ�������ڿ�ת�ʽ�
const int TAPIERROR_BANKFUTURETRANSFER_NOTENOUGH = 90005;
//! �˻���Ӧ���ֳ��𳬹����������
const int TAPIERROR_BANKFUTURETRANSFER_MORE_SIGMAXVALUE = 90006;
//! �˻���Ӧ���ֳ��𳬹��������������
const int TAPIERROR_BANKFUTURETRANSFER_MORE_DAYMAXCOUNT = 90007;
//! �˻���Ӧ���ֳ��𳬹�������������
const int TAPIERROR_BANKFUTURETRANSFER_MORE_DAYMAXVALUE = 90008;
//! �ʽ𶳽�ʧ��
const int TAPIERROR_FUTURE_FROZEN_FAIL = 90009;
//! ת�˲�ѯ�����˻���Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NOACCINFO = 90010;
//! ת�˲�ѯ�����ͻ�������Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NOACCBANKINFO = 90011;
//! ת�˲�ѯ�����ͻ��ʽ���Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NOACCFUNDINFO = 90012;
//! ת�˲�ѯ����ת�˲�����Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NORENTINFO = 90013;
//! ת�˲�ѯ�����ѳ�����Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NOCOUNTVALUEINFO = 90014;
//! ת�˲�ѯ�����˻�֤����Ϣ
const int TAPIERROR_BANKFUTURETRANSFER_FTOB_NOACCCERTINFO = 90015;
//! ��������û�������쳣
const int TAPIERROR_BANKWAY_STOP = 90016;
//! û���յ���ʧת����ˮ
const int TAPIERROR_TRANSFERINFO_LOST = 90017;
//! �ͻ����н�ֹת��
const int TAPIERROR_BANK_NOTALLOWTRANSFER = 90018;
//! ����ת�ڻ����������,�޷�����
const int TAPIERROR_CASHIN_NOREVERSE = 90019;

//! ----------------���ռ�ط��������붨��-----------------------------------------------
//! ���Ʒ����Ϣ��ѯʧ��
const int TAPIERROR_RISKCOMMODITY_QRY = 91001;
//! Ԥ���ѯ������Լ��Ϣ
const int TAPIERROR_RISKCONTRACT_FUND = 91002;
//! �����ʽ��ѯ�������ղ���
const int TAPIERROR_RISKFUND_QRY = 91003;
//! ��Լ����۸�����ʧ��
const int TAPIERROR_CONTRACTQUOTE_ADD = 91004;
//! ʱ��������ظ�
const int TAPIERROR_TIMEINTERVAL_ADD = 91005;

#endif //! TAP_API_ERROR_H
