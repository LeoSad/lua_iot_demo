
// iotdemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "iotdemo.h"
#include "iotdemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CiotdemoDlg dialog



CiotdemoDlg::CiotdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_IOTDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CiotdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CiotdemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER_LIGHT1, &CiotdemoDlg::OnTRBNThumbPosChangingSliderLight1)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CiotdemoDlg message handlers

BOOL CiotdemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	CSliderCtrl *pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_LIGHT1);
	if (pSlider)
	{
		pSlider->SetRange(0, 100);
		pSlider->SetPos(0);
	}
	pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_LIGHT2);
	if (pSlider)
	{
		pSlider->SetRange(0, 100);
		pSlider->SetPos(0);
	}
	theApp.m_Factory.InitializeFactory();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CiotdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CiotdemoDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CiotdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CiotdemoDlg::OnTRBNThumbPosChangingSliderLight1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// This feature requires Windows Vista or greater.
	// The symbol _WIN32_WINNT must be >= 0x0600.
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: Add your control notification handler code here
#if(0)
	CConcreteLamp *pLamp = theApp.m_Factory.GetLamp(0);
	if (pLamp)
	{
		if (pNMTPC->dwPos > 50)
			pLamp->TurnOn();
		else
			pLamp->TurnOff();
	}
#endif
	*pResult = 0;
}


void CiotdemoDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: Add your message handler code here and/or call default
	CSliderCtrl *pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_LIGHT1);
	int Pos;
	CConcreteDetector *pDetect=NULL;

	if (pSlider == (CSliderCtrl*)pScrollBar)
	{
		Pos = pSlider->GetPos();
		pDetect = theApp.m_Factory.GetDetector(0);
	}
	else
	{
		pSlider = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_LIGHT2);
		if (pSlider == (CSliderCtrl*)pScrollBar)
		{
			Pos = pSlider->GetPos();
			pDetect = theApp.m_Factory.GetDetector(1);
		}
	}
	if (pDetect)
	{
		pDetect->UpdateLightLevel(Pos);
		theApp.m_Visitor.ProcessEvent();
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
static TCHAR BASED_CODE szFilter[] = _T("LuaScripts (*.lua)|*.lua||");

BOOL CiotdemoDlg::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class

	DWORD dwControl = LOWORD(wParam);
	if (dwControl == IDC_LOAD)
		LoadScript();
	if (dwControl == IDC_EXECUTE)
		ApplyScript();
	return CDialog::OnCommand(wParam, lParam);
}

void CiotdemoDlg::LoadScript()
{
	CFileDialog fileDlg(TRUE, _T("lua"), _T("Lua scripts"), OFN_FILEMUSTEXIST, szFilter);
	if (fileDlg.DoModal() != IDOK)
		return;

	//Now - load the script
	CString pathName = fileDlg.GetPathName();
	SetDlgItemText(IDC_STATIC_SCRIPT_NAME, pathName);

	CFile tmpFile;
	char *pBuf = NULL;
	DWORD dwLen;

	if (tmpFile.Open(pathName, CFile::modeRead))
	{
		dwLen = (DWORD)tmpFile.GetLength();
		pBuf = new char[dwLen + 1];
		memset(pBuf, 0, dwLen + 1);
		tmpFile.Read(pBuf, dwLen);
		tmpFile.Close();
	}
	if (pBuf)
	{
		CString csData(pBuf);
		SetDlgItemText(IDC_RICHEDIT_SCRIPT, csData);
		delete[] pBuf;
	}
}

void CiotdemoDlg::ApplyScript()
{
	CString csData; 
	GetDlgItemTextW(IDC_RICHEDIT_SCRIPT,csData);

	csData += _T("\r\n");
	char *szBuf = new char[csData.GetLength() + 10];
	memset(szBuf, 0, csData.GetLength() + 10);
	WideCharToMultiByte(CP_ACP, 0, csData, -1, szBuf, csData.GetLength() + 10, NULL, NULL);
	theApp.m_Visitor.SetScript(szBuf);
	delete szBuf;
}