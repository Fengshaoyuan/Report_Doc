
// Report_DocDlg.h : header file
//

#pragma once


// CReport_DocDlg dialog
class CReport_DocDlg : public CDialogEx
{
// Construction
public:
	CReport_DocDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_REPORT_DOC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CHwDocumentWritter	m_doc;
	CString strFileName;
	afx_msg void OnBnClickedButtonOpenfile();
};
