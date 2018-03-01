// HwDocWr.h : main header file for the HwDocWr DLL
//

#ifndef __HWDOCWR_H__
#define __HWDOCWR_H__

#ifdef HWDOCWR_EXPORTS
#define HWDOCWR_API __declspec(dllexport)
#else
#define HWDOCWR_API __declspec(dllimport)
#endif


enum DOCUMENT_TYPE
{
	doc_INVALID,
	doc_DOC,
	doc_DOCX
};

#define TEXT_FMT_BOLD				0x00000001
#define TEXT_FMT_UNDERLINE			0X00000002
#define TEXT_FMT_ITALIC				0X00000004
#define TEXT_FMT_EMPHASISMARK		0x00000008
#define TEXT_FMT_TEXT_COLOR			0X00000010
#define TEXT_FMT_FILL_COLOR			0X00000020

class HWDOCWR_API CHwDocumentWritter
{
public:
	CHwDocumentWritter(void);
	~CHwDocumentWritter(void);

	bool OpenDocument(const char* lpszFile, DOCUMENT_TYPE emDocType, bool bShowDoc=false);
	void CloseDocument();

	bool OpenTable(DWORD dwTableNo);
	bool OpenTable(const char* lpszBookmarkName, DWORD dwTableIndex);
	bool WriteTableCell(DWORD dwRow, DWORD dwCol, const char* lpszText);
	// dwTextFormat: TEXT_FMT_BOLD等的位或
	// nTextColor: 文字颜色，用RGB(?, ?, ?)表示
	// nFillColor：填充颜色，用RGB(?, ?, ?)表示
	// dwMask: dwTextFormat的掩码， TEXT_FMT_BOLD等的位或, 1代表使能该位，0代表禁止该位
	bool SetTableCellFormat(DWORD dwRow, DWORD dwCol, DWORD dwTextFormat, int nTextColor, int nFillColor, DWORD dwMask=TEXT_FMT_TEXT_COLOR);

protected:
	bool OpenWord(const char* lpszFile, bool bShowDoc=false);
	void CloseWord();

protected:
	DOCUMENT_TYPE	m_emDocType;
	void*			m_lpDoument;
};

#endif /* __HWDOCWR_H__*/
