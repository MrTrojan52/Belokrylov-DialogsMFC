#pragma once


// Диалоговое окно CCustomDlg

class CCustomDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomDlg)

public:
	CCustomDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CCustomDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_messageText;
	afx_msg void OnBnClickedOK();
	int m_radioSelection;
};
