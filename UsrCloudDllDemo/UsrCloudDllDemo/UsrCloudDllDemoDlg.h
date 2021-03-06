// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// UsrCloudDllDemoDlg.h: 头文件
//

#pragma once
#include "afxcmn.h"
#include "UsrCloud.h"
#include "afxwin.h"


// CUsrCloudDllDemoDlg 对话框
class CUsrCloudDllDemoDlg : public CDialog
{
	// 构造
public:
	CUsrCloudDllDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_USRCLOUDDLLDEMO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//载入DLL
	boolean LoadDllAndGetProc();
	//释放DLL
	boolean FreeDll();

	//动态链接库句柄
	HINSTANCE hUsrCloud;
	//初始化和释放
	FN_USR_GetVer      USR_GetVer;
	FN_USR_Init        USR_Init;
	FN_USR_Release     USR_Release;
	//连接和断开
	FN_USR_OnConnAck	 USR_OnConnAck;
	FN_USR_Connect		 USR_Connect;
	FN_USR_DisConnect	 USR_DisConnect;
	// 订阅和取消订阅
	FN_USR_OnSubscribeAck		   USR_OnSubscribeAck;
	FN_USR_OnUnSubscribeAck		   USR_OnUnSubscribeAck;

	FN_USR_SubscribeDevParsed      USR_SubscribeDevParsed;
	FN_USR_SubscribeUserParsed     USR_SubscribeUserParsed;
	FN_USR_UnSubscribeDevParsed    USR_UnSubscribeDevParsed;
	FN_USR_UnSubscribeUserParsed   USR_UnSubscribeUserParsed;

	FN_USR_SubscribeDevRaw		   USR_SubscribeDevRaw;
	FN_USR_SubscribeUserRaw		   USR_SubscribeUserRaw;
	FN_USR_UnSubscribeDevRaw	   USR_UnSubscribeDevRaw;
	FN_USR_UnSubscribeUserRaw	   USR_UnSubscribeUserRaw;

	//推送消息
	FN_USR_OnPubAck                          USR_OnPubAck;
	FN_USR_PublishParsedSetSlaveDataPoint    USR_PublishParsedSetSlaveDataPoint;
	FN_USR_PublishParsedQuerySlaveDataPoint  USR_PublishParsedQuerySlaveDataPoint;
	//FN_USR_PublishParsedSetDataPoint     USR_PublishParsedSetDataPoint;
	//FN_USR_PublishParsedQueryDataPoint   USR_PublishParsedQueryDataPoint;
	FN_USR_PublishRawToDev                   USR_PublishRawToDev;
	FN_USR_PublishRawToUser                  USR_PublishRawToUser;
	//接收消息
	FN_USR_OnRcvParsedDataPointPush          USR_OnRcvParsedDataPointPush;
	FN_USR_OnRcvParsedDevStatusPush          USR_OnRcvParsedDevStatusPush;
	FN_USR_OnRcvParsedDevAlarmPush           USR_OnRcvParsedDevAlarmPush;
	FN_USR_OnRcvParsedOptionResponseReturn   USR_OnRcvParsedOptionResponseReturn;
	FN_USR_OnRcvRawFromDev                   USR_OnRcvRawFromDev;
 
	//回调函数
	static void _stdcall ConnAck_CBF(long ReturnCode, LPCWSTR Description);
	static void _stdcall SubscribeAck_CBF(long MessageID, LPCWSTR SubFunName, LPCWSTR SubParam, LPCWSTR ReturnCode);
	static void _stdcall UnSubscribeAck_CBF(long MessageID, LPCWSTR UnSubFunName, LPCWSTR UnSubParam);
	static void _stdcall PubAck_CBF(long MessageID);
	static void _stdcall RcvParsedDataPointPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr);
	static void _stdcall RcvParsedDevStatusPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr);
	static void _stdcall RcvParsedDevAlarmPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr);
	static void _stdcall RcvParsedOptionResponseReturn_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr);
	static void _stdcall RcvRawFromDev_CBF(long MessageID, LPCWSTR DevId, void *pData, long DataLen);

	afx_msg void OnBnClickedButtonGetver();
	afx_msg void OnBnClickedButtonInit();
	afx_msg void OnBnClickedButtonRelease();

	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonDisconnect();

	afx_msg void OnBnClickedButtonSubscribedevparsed();
	afx_msg void OnBnClickedButtonUnsubscribedevparsed();
	afx_msg void OnBnClickedButtonSubscribeuserparsed();
	afx_msg void OnBnClickedButtonUnsubscribeuserparsed();

	afx_msg void OnBnClickedButtonSubscribedevraw();
	afx_msg void OnBnClickedButtonUnsubscribedevraw();
	afx_msg void OnBnClickedButtonSubscribeuserraw();
	afx_msg void OnBnClickedButtonUnsubscribeuserraw();

	afx_msg void OnBnClickedButtonPublishparsedquerydatapoint();
	afx_msg void OnBnClickedButtonPublishparsedsetdatapoint();
	afx_msg void OnBnClickedButtonPublishrawtodev();
	afx_msg void OnBnClickedButtonPublishrawtouser();

	// 日志
	CRichEditCtrl logEdit;
	void AppendLog(CString str);
	afx_msg void OnBnClickedButtonClearlog();

	// 用户名
	CEdit m_Edit_Username;
	CEdit m_Edit_Password;
	CEdit m_Edit_SubParsedDevId;
	CEdit m_Edit_SubParsedUsername;
	CEdit m_Edit_SubRawDevId;
	CEdit m_Edit_SubRawUsername;
	CEdit m_Edit_PubParsedDevId;
	CEdit m_Edit_PubParsedPointId;
	CEdit m_Edit_PubParsedValueQ;
	CEdit m_Edit_PubParsedValueS;
	CEdit m_Edit_PubRawUsername;
	CEdit m_Edit_PubRawDevId;
	CRichEditCtrl m_RichEdit_PubRaw;
	CButton m_Check_PubRaw;
	CButton m_Edit_PubParsedSlaveIndex;
};
