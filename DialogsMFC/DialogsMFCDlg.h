
// DialogsMFCDlg.h: файл заголовка
//

#pragma once
#include "CCustomDlg.h"

// Диалоговое окно CDialogsMFCDlg
class CDialogsMFCDlg : public CDialogEx
{
// Создание
public:
	CDialogsMFCDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOGSMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedYnc();
	afx_msg void OnBnClickedARI();
	afx_msg void OnBnClickedFile();
	afx_msg void OnBnClickedCustomD();
	afx_msg void OnBnClickedWOption();
	CString m_resultsEdit;
	CCustomDlg m_customDlg;
};
