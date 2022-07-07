#define _CRT_SECURE_NO_WARNINGS
// BuildInterfaceDlg.cpp: 实现文件
#include "pch.h"
#include "stdafx.h"
#include "framework.h"
#include "BuildInterface.h"
#include "BuildInterfaceDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <string>
#include <CString>
#include <cstdlib>
using namespace std;
#define _F_ConFig "./config.ini"

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


// CBuildInterfaceDlg 对话框




CBuildInterfaceDlg::CBuildInterfaceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUILDINTERFACE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

}

void CBuildInterfaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, edit1);
	DDX_Control(pDX, IDC_COMBO2, edit2);
	DDX_Control(pDX, IDC_EDIT1, edit3);
	DDX_Control(pDX, IDC_EDIT2, edit4);
	DDX_Control(pDX, IDC_EDIT3, edit5);

}

BEGIN_MESSAGE_MAP(CBuildInterfaceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBuildInterfaceDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CBuildInterfaceDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_CHECK1, &CBuildInterfaceDlg::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CBuildInterfaceDlg::OnCbnSelchangeCombo2)
	ON_EN_ERRSPACE(IDC_EDIT1, &CBuildInterfaceDlg::OnErrspaceEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CBuildInterfaceDlg::OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CBuildInterfaceDlg::OnChangeEdit3)
	ON_BN_CLICKED(IDOK, &CBuildInterfaceDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBuildInterfaceDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CBuildInterfaceDlg::OnCbnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT4, &CBuildInterfaceDlg::OnEnChangeEdit4)
	

	
END_MESSAGE_MAP()


// CBuildInterfaceDlg 消息处理程序

BOOL CBuildInterfaceDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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


	

	// TODO: 在此添加额外的初始化代码
	//edit1.AddString(TEXT("版本选择"));
	edit1.AddString(TEXT("All"));
	edit1.AddString(TEXT("Windows"));
	edit1.AddString(TEXT("Linux"));
	edit1.SetCurSel(0);


	edit2.AddString(TEXT("master"));
	edit2.AddString(TEXT("v12.2"));
	edit2.AddString(TEXT("v12.3"));
	edit2.SetCurSel(0);


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}




void CBuildInterfaceDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBuildInterfaceDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}



//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBuildInterfaceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CBuildInterfaceDlg::OnBnClickedButton1()
{
	///////////////获取当前日期/////////////////
	CString build_nowday;
	CTime tm; tm = CTime::GetCurrentTime();
	build_nowday = tm.Format("%Y-%m-%d");



	////////获取配置参数//D:\MyCode\GitRepository\BuildInterface
	CString strFileName = _T("D:\\MyCode\\GitRepository\\BuildInterface\\config.ini");
	if (!PathFileExists(strFileName))
	{
		return;
	}
	CStdioFile file;
	if (!file.Open(strFileName, CFile::modeRead))
	{
		MessageBox(_T("XXXXXXXX"));
		return;
	}

	CString strLine, strtemp;
	vector<CString>vecStr;
	CString WIN_USER, WIN_IP, WIN_SRC_PATH, WIN_PUBLISH_PATH,
		LINUX_USER, LINUX_IP, LINUX_SRC_PATH, LINUX_PUBLISH_PATH;
	while (file.ReadString(strLine))
	{
		USES_CONVERSION;
		char* str = T2A(strLine);
		strLine.GetBufferSetLength(strLine.GetLength());
		char* p;
		if (strLine != "")
		{
			for (p = strtok(str, " "); p != NULL; p = strtok(NULL, " "))
			{
				strtemp = p;
			}
			int num = strtemp.Find(_T(":"));
			CString value = strtemp.Right(strtemp.GetLength() - num - 1);
			CString key = strtemp.Left(num);
			if (key == "WIN_USER") {
				WIN_USER = value;
			}
			else if (key == "WIN_IP") {
				WIN_IP = value;
			}
			else if (key == "WIN_SRC_PATH") {
				WIN_SRC_PATH = value;
			}
			else if (key == "WIN_PUBLISH_PATH") {
				WIN_PUBLISH_PATH = value;
			}
			else if (key == "LINUX_USER") {
				LINUX_USER = value;
			}
			else if (key == "LINUX_IP") {
				LINUX_IP = value;
			}
			else if (key == "LINUX_SRC_PATH") {
				LINUX_SRC_PATH = value;
			}
			else if (key == "LINUX_PUBLISH_PATH") {
				LINUX_PUBLISH_PATH = value;
			}
		}
	}
	CString winbuild_config = WIN_USER + " " + WIN_IP + " " + WIN_SRC_PATH + " " + WIN_PUBLISH_PATH;
	CString linuxbuild_config = LINUX_USER + " " + LINUX_IP + " " + LINUX_SRC_PATH + " " + LINUX_PUBLISH_PATH;
	file.Close();
	



	///////////////构建平台///////////////
	
    ///////////////分支选择///////////////
	///////////////版本号////////////////
	///////////////上次发版日期/////////
	///////////////编号/////////////////
	///////////////是否自动下载////////
	CString build_plate,build_branch, build_version, build_lastday, build_number;

		    
	int edit1_index = edit1.GetCurSel();
	edit1.GetLBText(edit1_index, build_plate);
	int edit2_index = edit2.GetCurSel();
	edit2.GetLBText(edit2_index, build_branch);

	edit3.GetWindowTextW(build_version);
	edit4.GetWindowTextW(build_lastday);
	edit5.GetWindowTextW(build_number);

	CString bat_file_path, choice_true, choice_false;
	bat_file_path = " D:\\MyCode\\GitRepository\\BuildInterface\\nn.bat ";
	choice_true = " 是";
	choice_false = " 否";


	CString build_strEdit; //需手动输入的参数
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_CHECK1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了按钮
	{
		build_strEdit = build_branch +" " + build_version+" " + build_number+ " "+build_lastday+ choice_true;
	}
	else {
		build_strEdit = build_branch + " " + build_version + " " + build_number+" "+ build_lastday + choice_false;
	}

	///////////////////////////////////////////////////////////////////
	CString str_01, str_02,str_03;

	if (build_plate == "All") {
		str_01 = bat_file_path + "Windows" +" "+ winbuild_config+ " "+build_strEdit + " " + build_nowday;
		str_02 = bat_file_path + "Linux" + " " + linuxbuild_config+" "+build_strEdit + " " + build_nowday;
		CString startcmd_01 = CString("start ") + str_01;
		CString startcmd_02 = CString("start ") + str_02;
		USES_CONVERSION;
		system(T2A(startcmd_01));
		system(T2A(startcmd_02));
	}
	else if (build_plate == "Windows") {
		str_03 = bat_file_path + build_plate +" "+ winbuild_config+ " "+build_strEdit + " " + build_nowday;
		CString startcmd_03 = CString("start ") + str_03;
		USES_CONVERSION;
		system(T2A(startcmd_03));
	}
	else if (build_plate == "Linux") {
		str_03 = bat_file_path + build_plate + " " + linuxbuild_config + " "+build_strEdit + " " + build_nowday;
		CString startcmd_03 = CString("start ") + str_03;
		USES_CONVERSION;
		system(T2A(startcmd_03));
	}
}


void CBuildInterfaceDlg::OnLbnSelchangeList2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBuildInterfaceDlg::OnEnChangeEdit1()//版本号
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CBuildInterfaceDlg::OnBnClickedCheck1()//是否下载文件
{
	// TODO: 在此添加控件通知处理程序代码
	//IDC_CHECK1
	if (::SendMessage(::GetDlgItem(m_hWnd, IDC_CHECK1), BM_GETCHECK, NULL, NULL) == BST_CHECKED)//如果选择了单选按钮1
	{
		MessageBox(_T("已选择自动下载版本文件!"), NULL, MB_ICONINFORMATION);//弹出提示

	}




}


void CBuildInterfaceDlg::OnCbnSelchangeCombo2()//目标分支
{
	// TODO: 在此添加控件通知处理程序代码

}


void CBuildInterfaceDlg::OnErrspaceEdit1() //版本号
{
	// TODO: 在此添加控件通知处理程序代码
}


void CBuildInterfaceDlg::OnChangeEdit2() //序号
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CBuildInterfaceDlg::OnChangeEdit3()//上次发版日期
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}





void CBuildInterfaceDlg::OnBnClickedOk()
{
	UINT i;
	i = MessageBoxEx(NULL, TEXT("您是否要退出?"), TEXT("提示"), MB_OKCANCEL | MB_ICONQUESTION, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));
	if (i == IDCANCEL)
	{
		return;
	}
	CDialogEx::OnOK();





}


void CBuildInterfaceDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CBuildInterfaceDlg::OnCbnSelchangeCombo1()//控制平台
{
	// TODO: 在此添加控件通知处理程序代码




	}




void CBuildInterfaceDlg::OnEnChangeEdit4()
{

}

