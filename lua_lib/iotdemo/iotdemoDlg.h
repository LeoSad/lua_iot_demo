
// iotdemoDlg.h : header file
//

#pragma once


// CiotdemoDlg dialog
class CiotdemoDlg : public CDialog
{
// Construction
public:
	CiotdemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IOTDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	
	void LoadScript();
	void ApplyScript();

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
	afx_msg void OnTRBNThumbPosChangingSliderLight1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};
