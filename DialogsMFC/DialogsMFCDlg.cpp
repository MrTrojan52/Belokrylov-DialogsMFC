
// DialogsMFCDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "DialogsMFC.h"
#include "DialogsMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CDialogsMFCDlg



CDialogsMFCDlg::CDialogsMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGSMFC_DIALOG, pParent)
	, m_resultsEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDialogsMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_RESULTS, m_resultsEdit);
}

BEGIN_MESSAGE_MAP(CDialogsMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_YNC, &CDialogsMFCDlg::OnBnClickedYnc)
	ON_BN_CLICKED(IDC_ARI, &CDialogsMFCDlg::OnBnClickedARI)
	ON_BN_CLICKED(IDC_FILE, &CDialogsMFCDlg::OnBnClickedFile)
	ON_BN_CLICKED(IDC_CUSTOMD, &CDialogsMFCDlg::OnBnClickedCustomD)
	ON_BN_CLICKED(IDC_WOPTION, &CDialogsMFCDlg::OnBnClickedWOption)
END_MESSAGE_MAP()


// Обработчики сообщений CDialogsMFCDlg

BOOL CDialogsMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CDialogsMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CDialogsMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CDialogsMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDialogsMFCDlg::OnBnClickedYnc()
{
	int result = MessageBox(L"Press the Yes, No or Cancel button", L"Yes, No, Cancel Dialog",  MB_YESNOCANCEL | MB_ICONINFORMATION);
	switch (result) {
	case IDYES:
		m_resultsEdit = _T("Yes Button");
		UpdateData(FALSE);
		break;
	case IDNO:
		m_resultsEdit = _T("No Button");
		UpdateData(FALSE);
		break;
	case IDCANCEL:
		m_resultsEdit = _T("Cancel Button");
		UpdateData(FALSE);
		break;
	}
}

void CDialogsMFCDlg::OnBnClickedARI()
{
	int result = MessageBox(L"Press the Abort, Retry or Ignore button", L"Abort, Retry, Ignore Dialog", MB_ABORTRETRYIGNORE | MB_ICONQUESTION);
	switch (result) {
	case IDABORT:
		m_resultsEdit = _T("Abort Button");
		UpdateData(FALSE);
		break;
	case IDRETRY:
		m_resultsEdit = _T("Retry Button");
		UpdateData(FALSE);
		break;
	case IDIGNORE:
		m_resultsEdit = _T("Ignore Button");
		UpdateData(FALSE);
		break;
	}
}

void CDialogsMFCDlg::OnBnClickedFile()
{
	CFileDialog fileDialog(TRUE);
	
	if (fileDialog.DoModal() == IDOK)
	{
		m_resultsEdit = fileDialog.GetPathName();
		UpdateData(FALSE);
	}
}

void CDialogsMFCDlg::OnBnClickedCustomD()
{
	if (m_customDlg.DoModal() == IDOK) {
		m_resultsEdit = m_customDlg.m_messageText;
		UpdateData(FALSE);
	}
}

void CDialogsMFCDlg::OnBnClickedWOption()
{
	if (m_customDlg.m_radioSelection != -1) {
		CString selection[4] = { L"first", L"second", L"third", L"fourth" };
		CString res;
		res.Format(_T("The %s option was selected."), selection[m_customDlg.m_radioSelection]);
		m_resultsEdit = res;
		UpdateData(FALSE);
	}
	else {
		m_resultsEdit = L"No option was selected.";
		UpdateData(FALSE);
	}
}