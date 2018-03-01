
// Report_DocDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Report_Doc.h"
#include "Report_DocDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CReport_DocDlg dialog



CReport_DocDlg::CReport_DocDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_REPORT_DOC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReport_DocDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_FILENAME, strFileName);
}

BEGIN_MESSAGE_MAP(CReport_DocDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CReport_DocDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_OPENFILE, &CReport_DocDlg::OnBnClickedButtonOpenfile)
END_MESSAGE_MAP()


// CReport_DocDlg message handlers

BOOL CReport_DocDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReport_DocDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CReport_DocDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CReport_DocDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CReport_DocDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	if (m_doc.OpenDocument((char*)(LPCTSTR)strFileName, doc_DOC, 0))
	{
		m_doc.OpenTable(1);
		m_doc.WriteTableCell(1, 1, "001");
		m_doc.WriteTableCell(1, 2, "002");

		m_doc.OpenTable(2);
		m_doc.WriteTableCell(1, 1, "003");
		m_doc.WriteTableCell(1, 2, "004");
		m_doc.CloseDocument();
	}
	GetDlgItem(IDOK)->EnableWindow(FALSE);
	//CDialogEx::OnOK();
}


void CReport_DocDlg::OnBnClickedButtonOpenfile()
{
	// TODO: Add your control notification handler code here
	BOOL isOpen = TRUE;     //是否打开(否则为保存)  
	CString defaultDir = "D:\\JETLAB\Report\\IMU";   //默认打开的文件路径  
	CString fileName = "";         //默认打开的文件名  
	CString filter = "文件 (*.doc;)|*.doc;||";   //文件过虑的类型  
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
	INT_PTR result = openFileDlg.DoModal();
	if (result == IDOK)
	{
		strFileName = openFileDlg.GetPathName();
	}
	UpdateData(FALSE);
	GetDlgItem(IDOK)->EnableWindow(TRUE);
}
