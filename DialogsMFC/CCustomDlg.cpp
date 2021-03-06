// CCustomDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "DialogsMFC.h"
#include "CCustomDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CCustomDlg

IMPLEMENT_DYNAMIC(CCustomDlg, CDialogEx)

CCustomDlg::CCustomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_messageText(_T(""))
	, m_radioSelection(-1)
{

}

CCustomDlg::~CCustomDlg()
{
}

void CCustomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EMESSAGE, m_messageText);
	DDX_Radio(pDX, IDC_ROPTION1, m_radioSelection);
}


BEGIN_MESSAGE_MAP(CCustomDlg, CDialogEx)
	ON_BN_CLICKED(IDCUSTOMOK, &CCustomDlg::OnBnClickedOK)
END_MESSAGE_MAP()


// Обработчики сообщений CCustomDlg


void CCustomDlg::OnBnClickedOK()
{
	UpdateData(TRUE);
	EndDialog(IDOK);
	CWnd* parent = GetParent();
	parent->GetDlgItem(IDC_WOPTION)->EnableWindow(TRUE);
}
