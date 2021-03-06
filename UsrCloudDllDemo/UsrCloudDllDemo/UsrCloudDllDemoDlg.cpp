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

// UsrCloudDllDemoDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "UsrCloudDllDemo.h"
#include "UsrCloudDllDemoDlg.h"
#include "afxdialogex.h"
#include "UsrCloud.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CUsrCloudDllDemoDlg 对话框



CUsrCloudDllDemoDlg::CUsrCloudDllDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_USRCLOUDDLLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUsrCloudDllDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT22, logEdit);
	DDX_Control(pDX, IDC_EDIT_Username, m_Edit_Username);
	DDX_Control(pDX, IDC_EDIT_Password, m_Edit_Password);
	DDX_Control(pDX, IDC_EDIT_SubParsedDevId, m_Edit_SubParsedDevId);
	DDX_Control(pDX, IDC_EDIT_SubParsedUsername, m_Edit_SubParsedUsername);
	DDX_Control(pDX, IDC_EDIT_SubRawDevId, m_Edit_SubRawDevId);
	DDX_Control(pDX, IDC_EDIT_SubRawUsername, m_Edit_SubRawUsername);
	DDX_Control(pDX, IDC_EDIT_PubParsedDevId, m_Edit_PubParsedDevId);
	DDX_Control(pDX, IDC_EDIT_PubParsedPointId, m_Edit_PubParsedPointId);
	DDX_Control(pDX, IDC_EDIT_PubParsedValueQ, m_Edit_PubParsedValueQ);
	DDX_Control(pDX, IDC_EDIT_PubParsedValueS, m_Edit_PubParsedValueS);
	DDX_Control(pDX, IDC_EDIT_PubRawUsername, m_Edit_PubRawUsername);
	DDX_Control(pDX, IDC_EDIT_PubRawDevId, m_Edit_PubRawDevId);
	DDX_Control(pDX, IDC_RICHEDIT_PubRaw, m_RichEdit_PubRaw);
	DDX_Control(pDX, IDC_CHECK_PubRaw, m_Check_PubRaw);
	DDX_Control(pDX, IDC_EDIT_PubParsedSlaveIndex, m_Edit_PubParsedSlaveIndex);
}

BEGIN_MESSAGE_MAP(CUsrCloudDllDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_GETVER, &CUsrCloudDllDemoDlg::OnBnClickedButtonGetver)
	ON_BN_CLICKED(IDC_BUTTON_INIT, &CUsrCloudDllDemoDlg::OnBnClickedButtonInit)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CUsrCloudDllDemoDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_RELEASE, &CUsrCloudDllDemoDlg::OnBnClickedButtonRelease)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CUsrCloudDllDemoDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_SubscribeDevParsed, &CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribedevparsed)
	ON_BN_CLICKED(IDC_BUTTON_UnSubscribeDevParsed, &CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribedevparsed)
	ON_BN_CLICKED(IDC_BUTTON_SubscribeUserParsed, &CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribeuserparsed)
	ON_BN_CLICKED(IDC_BUTTON_UnSubscribeUserParsed, &CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribeuserparsed)
	ON_BN_CLICKED(IDC_BUTTON_PublishParsedQueryDataPoint, &CUsrCloudDllDemoDlg::OnBnClickedButtonPublishparsedquerydatapoint)
	ON_BN_CLICKED(IDC_BUTTON_PublishParsedSetDataPoint, &CUsrCloudDllDemoDlg::OnBnClickedButtonPublishparsedsetdatapoint)
	ON_BN_CLICKED(IDC_BUTTON_SubscribeDevRaw, &CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribedevraw)
	ON_BN_CLICKED(IDC_BUTTON_UnSubscribeDevRaw, &CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribedevraw)
	ON_BN_CLICKED(IDC_BUTTON_SubscribeUserRaw, &CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribeuserraw)
	ON_BN_CLICKED(IDC_BUTTON_UnSubscribeUserRaw, &CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribeuserraw)
	ON_BN_CLICKED(IDC_BUTTON_PublishRawToDev, &CUsrCloudDllDemoDlg::OnBnClickedButtonPublishrawtodev)
	ON_BN_CLICKED(IDC_BUTTON_PublishRawToUser, &CUsrCloudDllDemoDlg::OnBnClickedButtonPublishrawtouser)
	ON_BN_CLICKED(IDC_BUTTON_ClearLog, &CUsrCloudDllDemoDlg::OnBnClickedButtonClearlog)
END_MESSAGE_MAP()


// CUsrCloudDllDemoDlg 消息处理程序

BOOL CUsrCloudDllDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	//ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码
	//加载DLL 获取函数地址
	LoadDllAndGetProc();
	m_Edit_Username.SetWindowTextW(L"sdktest");
	m_Edit_Password.SetWindowTextW(L"sdktest");
	m_Edit_SubParsedDevId.SetWindowTextW(L"00007867000000000001");
	m_Edit_SubParsedUsername.SetWindowTextW(L"sdktest");

	m_Edit_PubParsedDevId.SetWindowTextW(L"00007867000000000001");
	m_Edit_PubParsedSlaveIndex.SetWindowTextW(L"1");
	m_Edit_PubParsedPointId.SetWindowTextW(L"118");
	m_Edit_PubParsedValueS.SetWindowTextW(L"1234");

	m_Edit_SubRawDevId.SetWindowTextW(L"00007867000000000001");
	m_Edit_SubRawUsername.SetWindowTextW(L"sdktest");

	m_Edit_PubRawDevId.SetWindowTextW(L"00007867000000000001");
	m_Edit_PubRawUsername.SetWindowTextW(L"sdktest");
	m_RichEdit_PubRaw.SetWindowTextW(L"01 03 00 63 00 03 F5 D5 ");
	m_Check_PubRaw.SetCheck(true);


	CString str ;
	str = "";
	str += "使用流程:\n";
	str += "\n";
	str += "一、准备\n";
	str += "	1、初始化 : 创建实例\n";
	str += "	2、注册回调函数\n";
	str += "	3、连接\n";
	str += "\n";
	str += "二、通讯\n";
	str += "	订阅 : 告诉服务器, 想接收哪些设备的数据\n";
	str += "	推送 : 向设备发送数据\n";
	str += "\n";
	str += "三、结束\n";
	str += "	断开连接\n";
	str += "	释放资源\n";
	str += "\n";
	str += "更多使用说明, 参见 http://cloud.usr.cn/sdk/dll/ \n";
	str += "如需帮助, 请提交工单 http://h.usr.cn/create/number/cloud-usr-cn \n";
	str += "\n";
	str += "-----------------------------\n";
	logEdit.SetSel(-1, -1);
	logEdit.ReplaceSel(str);
 
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CUsrCloudDllDemoDlg::OnDestroy()
{
	CDialog::OnDestroy();
	FreeDll();
}

void CUsrCloudDllDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CUsrCloudDllDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CUsrCloudDllDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CUsrCloudDllDemoDlg::AppendLog(CString str)
{
	CString tmstr; //获取系统时间 　　
	CTime tm;
	tm = CTime::GetCurrentTime();
	tmstr = tm.Format("------%X------\n");
	logEdit.SetSel(-1, -1);
	logEdit.ReplaceSel(tmstr);
	logEdit.SetSel(-1, -1);
	logEdit.ReplaceSel(str + "\n");
	logEdit.PostMessage(WM_VSCROLL, SB_BOTTOM, 0);
}

void CUsrCloudDllDemoDlg::OnBnClickedButtonClearlog()
{
	logEdit.SetSel(0, -1);
	logEdit.Clear();
}

boolean CUsrCloudDllDemoDlg::LoadDllAndGetProc()
{
	hUsrCloud = LoadLibraryA("UsrCloud.dll");
	//初始化和释放
	USR_GetVer = (FN_USR_GetVer)GetProcAddress(hUsrCloud, "USR_GetVer");
	USR_Init = (FN_USR_Init)GetProcAddress(hUsrCloud, "USR_Init");
	USR_Release = (FN_USR_Release)GetProcAddress(hUsrCloud, "USR_Release");
	//连接和断开
	USR_OnConnAck = (FN_USR_OnConnAck)GetProcAddress(hUsrCloud, "USR_OnConnAck");
	USR_Connect = (FN_USR_Connect)GetProcAddress(hUsrCloud, "USR_Connect");
	USR_DisConnect = (FN_USR_DisConnect)GetProcAddress(hUsrCloud, "USR_DisConnect");
	// 订阅和取消订阅
	USR_OnSubscribeAck = (FN_USR_OnSubscribeAck)GetProcAddress(hUsrCloud, "USR_OnSubscribeAck");
	USR_OnUnSubscribeAck = (FN_USR_OnUnSubscribeAck)GetProcAddress(hUsrCloud, "USR_OnUnSubscribeAck");
	USR_SubscribeDevParsed = (FN_USR_SubscribeDevParsed)GetProcAddress(hUsrCloud, "USR_SubscribeDevParsed");
	USR_SubscribeUserParsed = (FN_USR_SubscribeUserParsed)GetProcAddress(hUsrCloud, "USR_SubscribeUserParsed");
	USR_UnSubscribeDevParsed = (FN_USR_UnSubscribeDevParsed)GetProcAddress(hUsrCloud, "USR_UnSubscribeDevParsed");
	USR_UnSubscribeUserParsed = (FN_USR_UnSubscribeUserParsed)GetProcAddress(hUsrCloud, "USR_UnSubscribeUserParsed");
	USR_SubscribeDevRaw = (FN_USR_SubscribeDevRaw)GetProcAddress(hUsrCloud, "USR_SubscribeDevRaw");
	USR_SubscribeUserRaw = (FN_USR_SubscribeUserRaw)GetProcAddress(hUsrCloud, "USR_SubscribeUserRaw");
	USR_UnSubscribeDevRaw = (FN_USR_UnSubscribeDevRaw)GetProcAddress(hUsrCloud, "USR_UnSubscribeDevRaw");
	USR_UnSubscribeUserRaw = (FN_USR_UnSubscribeUserRaw)GetProcAddress(hUsrCloud, "USR_UnSubscribeUserRaw");
	//推送消息
	USR_OnPubAck = (FN_USR_OnPubAck)GetProcAddress(hUsrCloud, "USR_OnPubAck");
	USR_PublishParsedSetSlaveDataPoint = (FN_USR_PublishParsedSetSlaveDataPoint)GetProcAddress(hUsrCloud, "USR_PublishParsedSetSlaveDataPoint");
	USR_PublishParsedQuerySlaveDataPoint = (FN_USR_PublishParsedQuerySlaveDataPoint)GetProcAddress(hUsrCloud, "USR_PublishParsedQuerySlaveDataPoint");
	//USR_PublishParsedSetDataPoint = (FN_USR_PublishParsedSetDataPoint)GetProcAddress(hUsrCloud, "USR_PublishParsedSetDataPoint");
	//USR_PublishParsedQueryDataPoint = (FN_USR_PublishParsedQueryDataPoint)GetProcAddress(hUsrCloud, "USR_PublishParsedQueryDataPoint");
	USR_PublishRawToDev = (FN_USR_PublishRawToDev)GetProcAddress(hUsrCloud, "USR_PublishRawToDev");
	USR_PublishRawToUser = (FN_USR_PublishRawToUser)GetProcAddress(hUsrCloud, "USR_PublishRawToUser");
	//接收消息
	USR_OnRcvParsedDataPointPush = (FN_USR_OnRcvParsedDataPointPush)GetProcAddress(hUsrCloud, "USR_OnRcvParsedDataPointPush");
	USR_OnRcvParsedDevStatusPush = (FN_USR_OnRcvParsedDevStatusPush)GetProcAddress(hUsrCloud, "USR_OnRcvParsedDevStatusPush");
	USR_OnRcvParsedDevAlarmPush = (FN_USR_OnRcvParsedDevAlarmPush)GetProcAddress(hUsrCloud, "USR_OnRcvParsedDevAlarmPush");
	USR_OnRcvParsedOptionResponseReturn = (FN_USR_OnRcvParsedOptionResponseReturn)GetProcAddress(hUsrCloud, "USR_OnRcvParsedOptionResponseReturn");
	USR_OnRcvRawFromDev = (FN_USR_OnRcvRawFromDev)GetProcAddress(hUsrCloud, "USR_OnRcvRawFromDev");

	return true;
}

boolean CUsrCloudDllDemoDlg::FreeDll()
{
	USR_Release();
	FreeLibrary(hUsrCloud);
	return true;
}

void CUsrCloudDllDemoDlg::OnBnClickedButtonGetver()
{
	long iVer = USR_GetVer();
	CString sVer;
	sVer.Format(_T("DLL版本号: %d\n"), iVer);
	AppendLog(sVer);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonInit()
{
	LPCWSTR Host = _T("clouddata.usr.cn");
	unsigned short Port = 1883;
	CString str;
	boolean b = USR_Init(Host, Port, 2);
	if (b) {
		str.Format(_T("初始化成功\n"));
		//注册回调函数
		USR_OnConnAck(ConnAck_CBF);
		USR_OnSubscribeAck(SubscribeAck_CBF);
		USR_OnUnSubscribeAck(UnSubscribeAck_CBF);
		USR_OnPubAck(PubAck_CBF);
		USR_OnRcvParsedDataPointPush(RcvParsedDataPointPush_CBF);
		USR_OnRcvParsedDevStatusPush(RcvParsedDevStatusPush_CBF);
		USR_OnRcvParsedDevAlarmPush(RcvParsedDevAlarmPush_CBF);
		USR_OnRcvParsedOptionResponseReturn(RcvParsedOptionResponseReturn_CBF);
		USR_OnRcvRawFromDev(RcvRawFromDev_CBF);
	}
	else
	{
		str.Format(_T("初始化失败\n"));
	}
	AppendLog(str);
}

void CUsrCloudDllDemoDlg::OnBnClickedButtonRelease()
{
	boolean b = USR_Release();
	CString str;
	if (b) {
		str.Format(_T("释放成功\n"));
	}
	else
	{
		str.Format(_T("释放失败\n"));
	}
	AppendLog(str);
}

void CUsrCloudDllDemoDlg::OnBnClickedButtonConnect()
{
	CString sUserName, sPassword;
	m_Edit_Username.GetWindowTextW(sUserName);
	m_Edit_Password.GetWindowTextW(sPassword);
	LPCWSTR UserName = (LPCWSTR)sUserName;
	LPCWSTR Password = (LPCWSTR)sPassword;
	boolean b = USR_Connect(UserName, Password);
	CString str;
	if (b) {
		str.Format(_T("连接已发起\n"));
	}
	else
	{
		str.Format(_T("连接已发起失败\n"));
	}
	AppendLog(str);
}

void CUsrCloudDllDemoDlg::OnBnClickedButtonDisconnect()
{
	boolean b = USR_DisConnect();
	CString str;
	if (b) {
		str.Format(_T("连接已断开\n"));
	}
	else
	{
		str.Format(_T("连接断开失败\n"));
	}
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribedevparsed()
{
	CString sDevId;
	m_Edit_SubParsedDevId.GetWindowTextW(sDevId);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	long iMsgId = USR_SubscribeDevParsed(DevId);
	CString str;
	str.Format(_T("USR_SubscribeDevParsed 订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribedevparsed()
{
	CString sDevId;
	m_Edit_SubParsedDevId.GetWindowTextW(sDevId);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	long iMsgId = USR_UnSubscribeDevParsed(DevId);
	CString str;
	str.Format(_T("USR_UnSubscribeDevParsed 取消订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribeuserparsed()
{
	CString sUserName;
	m_Edit_SubParsedUsername.GetWindowTextW(sUserName);
	LPCWSTR UserName = (LPCWSTR)sUserName;
	long iMsgId = USR_SubscribeUserParsed(UserName);
	CString str;
	str.Format(_T("USR_SubscribeUserParsed 订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribeuserparsed()
{
	CString sUserName;
	m_Edit_SubParsedUsername.GetWindowTextW(sUserName);
	LPCWSTR UserName = (LPCWSTR)sUserName;
	long iMsgId = USR_UnSubscribeUserParsed(UserName);
	CString str;
	str.Format(_T("USR_UnSubscribeUserParsed 取消订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonPublishparsedquerydatapoint()
{
	CString sDevId, sSlaveIndex, sPointId;
	m_Edit_PubParsedDevId.GetWindowTextW(sDevId);
	m_Edit_PubParsedSlaveIndex.GetWindowTextW(sSlaveIndex);
	m_Edit_PubParsedPointId.GetWindowTextW(sPointId);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	LPCWSTR SlaveIndex = (LPCWSTR)sSlaveIndex;
	LPCWSTR PointId = (LPCWSTR)sPointId;
	long iMsgId = USR_PublishParsedQuerySlaveDataPoint(DevId, SlaveIndex, PointId);
	CString str;
	str.Format(_T("消息已推送\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonPublishparsedsetdatapoint()
{
	CString sDevId, sSlaveIndex, sPointId, sValue;
	m_Edit_PubParsedDevId.GetWindowTextW(sDevId);
	m_Edit_PubParsedSlaveIndex.GetWindowTextW(sSlaveIndex);
	m_Edit_PubParsedPointId.GetWindowTextW(sPointId);
	m_Edit_PubParsedValueS.GetWindowTextW(sValue);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	LPCWSTR SlaveIndex = (LPCWSTR)sSlaveIndex;
	LPCWSTR PointId = (LPCWSTR)sPointId;
	LPCWSTR Value = (LPCWSTR)sValue;
	long iMsgId = USR_PublishParsedSetSlaveDataPoint(
		DevId, SlaveIndex, PointId, Value);
	CString str;
	str.Format(_T("消息已推送\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribedevraw()
{
	CString sDevId;
	m_Edit_SubRawDevId.GetWindowTextW(sDevId);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	long iMsgId = USR_SubscribeDevRaw(DevId);
	CString str;
	str.Format(_T("USR_SubscribeDevRaw 订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribedevraw()
{
	CString sDevId;
	m_Edit_SubRawDevId.GetWindowTextW(sDevId);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	long iMsgId = USR_UnSubscribeDevRaw(DevId);
	CString str;
	str.Format(_T("USR_UnSubscribeDevRaw 取消订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonSubscribeuserraw()
{
	CString sUserName;
	m_Edit_SubRawUsername.GetWindowTextW(sUserName);
	LPCWSTR UserName = (LPCWSTR)sUserName;
	long iMsgId = USR_SubscribeUserRaw(UserName);
	CString str;
	str.Format(_T("USR_SubscribeUserRaw 订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonUnsubscribeuserraw()
{
	CString sUserName;
	m_Edit_SubRawUsername.GetWindowTextW(sUserName);
	LPCWSTR UserName = (LPCWSTR)sUserName;
	long iMsgId = USR_UnSubscribeUserRaw(UserName);
	CString str;
	str.Format(_T("USR_UnSubscribeUserRaw 取消订阅已发起\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}



int HexStr2Buf(CString str, unsigned char *data)
{
	unsigned int t;
	int Length;
	int len = str.GetLength();
	char a[10] = { 0 };
	Length = 0;
	for (int i = 0; i < len; )
	{
		if (str[i] == ' ')  //空格
		{
			i++;
			continue;
		}
		a[0] = str[i]; // high byte
		i++;
		if (i >= len)
		{
			break;
		}
		a[1] = str[i]; // low byte
		a[2] = '\0';  // 字符串结束标志
		t = strtoul(a, NULL, 16);   //将字符串转换成无符号长整型数
		data[Length] = (unsigned char)t;
		Length++;
		i++;
	}
	return Length;  //转换的字节数
}

 

void CUsrCloudDllDemoDlg::OnBnClickedButtonPublishrawtodev()
{
	CString sDevId, sData;
	m_Edit_PubRawDevId.GetWindowTextW(sDevId);
	m_RichEdit_PubRaw.GetWindowTextW(sData);
	LPCWSTR DevId = (LPCWSTR)sDevId;
	byte buf[1024];
	int len = 0;
	if (m_Check_PubRaw.GetCheck()) {
		len = HexStr2Buf(sData, buf);
	}
	else
	{
		len = WideCharToMultiByte(CP_ACP, 0, sData, -1, NULL, 0, NULL, NULL) - 1;
		WideCharToMultiByte(CP_ACP, 0, sData, -1, (LPSTR)&buf[0], len, NULL, NULL);
	};
	long iMsgId = USR_PublishRawToDev(DevId, &buf[0], len);
	CString str;
	str.Format(_T("消息已推送\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}


void CUsrCloudDllDemoDlg::OnBnClickedButtonPublishrawtouser()
{
	CString sUsername, sData;
	m_Edit_PubRawUsername.GetWindowTextW(sUsername);
	m_RichEdit_PubRaw.GetWindowTextW(sData);
	LPCWSTR Username = (LPCWSTR)sUsername;
	byte buf[1024];
	int len = 0;
	if (m_Check_PubRaw.GetCheck()) {
		len = HexStr2Buf(sData, buf);
	}
	else
	{
		len = WideCharToMultiByte(CP_ACP, 0, sData, -1, NULL, 0, NULL, NULL) - 1;
		WideCharToMultiByte(CP_ACP, 0, sData, -1, (LPSTR)&buf[0], len, NULL, NULL);
	};
	long iMsgId = USR_PublishRawToUser(Username, &buf[0], len);
	CString str;
	str.Format(_T("消息已推送\n MsgId:%d\n"), iMsgId);
	AppendLog(str);
}

void CUsrCloudDllDemoDlg::ConnAck_CBF(long ReturnCode, LPCWSTR Description)
{
	CString str;
	str.Format(_T("【连接事件】\n返回码：%d  描述： %s\n"), ReturnCode, Description);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::SubscribeAck_CBF(long MessageID, LPCWSTR SubFunName, LPCWSTR SubParam, LPCWSTR ReturnCode)
{
	CString str;
	str.Format(_T("【订阅事件】\nMessageID：%d\n  SubFunName： %s\n 设备ID(或用户名)： %s\n 订阅结果:%s\n"), MessageID, SubFunName, SubParam, ReturnCode);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::UnSubscribeAck_CBF(long MessageID, LPCWSTR UnSubFunName, LPCWSTR UnSubParam)
{
	CString str;
	str.Format(_T("【取消订阅事件】\nMessageID：%d\n  UnSubFunName： %s\n 设备ID(或用户名)： %s\n"), MessageID, UnSubFunName, UnSubParam);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::PubAck_CBF(long MessageID)
{
	CString str;
	str.Format(_T("【推送事件】\n MessageID：%d\n"), MessageID);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::RcvParsedDataPointPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr)
{
	CString str;
	str.Format(_T("【接收数据点推送事件】\n MessageID：%d\n DevId：%s\n JsonStr：%s\n"), MessageID, DevId, JsonStr);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
	// todo json数据解析
}

void CUsrCloudDllDemoDlg::RcvParsedDevStatusPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr)
{
	CString str;
	str.Format(_T("【接收设备在线状态推送事件】\n MessageID：%d\n DevId：%s\n JsonStr：%s\n"), MessageID, DevId, JsonStr);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::RcvParsedDevAlarmPush_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr)
{
	CString str;
	str.Format(_T("【接收设备报警推送事件】\n MessageID：%d\n DevId：%s\n JsonStr：%s\n"), MessageID, DevId, JsonStr);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::RcvParsedOptionResponseReturn_CBF(long MessageID, LPCWSTR DevId, LPCWSTR JsonStr)
{
	CString str;
	str.Format(_T("【接收数据点操作应答事件】\n MessageID：%d\n DevId：%s\n JsonStr：%s\n"), MessageID, DevId, JsonStr);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

void CUsrCloudDllDemoDlg::RcvRawFromDev_CBF(long MessageID, LPCWSTR DevId, void *pData, long DataLen)
{
	CString sHex, sByte;
	byte* pBuf = (byte*)pData;
	for (int i = 0; i < DataLen; i++)
	{
		sByte.Format(_T("%02x "), pBuf[i]);
		sHex += sByte;
	}
	
	CString str;
	str.Format(_T("【接收设备原始数据流事件】\n MessageID：%d\n DevId：%s\n 内容(HEX)：%s\n"), MessageID, DevId, sHex);
	((CUsrCloudDllDemoDlg*)theApp.GetMainWnd())->AppendLog(str);
}

