
// BuildInterfaceDlg.h: 头文件
//
#include<locale.h>
#pragma once





// CBuildInterfaceDlg 对话框
class CBuildInterfaceDlg : public CDialogEx
{
// 构造
public:
	CBuildInterfaceDlg(CWnd* pParent = nullptr);	// 标准构造函数
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUILDINTERFACE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();





	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCheck1();
private:
	CComboBox edit1;
	CComboBox edit2;
public:
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnErrspaceEdit1();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnCbnSelchangeCombo1();
private:
	CEdit edit3;
	CEdit edit4;
	CEdit edit5;
public:
	afx_msg void OnEnChangeEdit4();
private:
	CButton edit_out;
	CEdit str_out;
};
