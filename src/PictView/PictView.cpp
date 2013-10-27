// PictView.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "PictView.h"

#include "MainFrm.h"
#include "PictViewDoc.h"
#include "PictViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//extern BOOL AFXAPI AfxFullPath(LPTSTR lpszPathOut, LPCTSTR lpszFileIn);

/////////////////////////////////////////////////////////////////////////////
// CPictViewApp

BEGIN_MESSAGE_MAP(CPictViewApp, CWinApp)
	//{{AFX_MSG_MAP(CPictViewApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	//ON_COMMAND_EX_RANGE(ID_FILE_MRU_FILE1, ID_FILE_MRU_FILE16,OnOpenRecentMyFile)
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictViewApp construction/destruction

CPictViewApp::CPictViewApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/*
CPictViewApp::~CPictViewApp()
{
	delete m_pRecentFileListMyFiles;
}
*/

/////////////////////////////////////////////////////////////////////////////
// The one and only CPictViewApp object

CPictViewApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPictViewApp initialization

BOOL CPictViewApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	/*
	//ά��������򿪵��ļ����б�
	m_pRecentFileListMyFiles =new CRecentFileList( 5,"������ļ�","MyFile%d",5);
	m_pRecentFileListMyFiles->ReadList(); 
	*/

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPictViewDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CPictViewView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CPictViewApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CPictViewApp message handlers

 /*------------------------------------------------------------------------------------*\
 |																						|
 |	����ĺ�����PictView ���б�ע�͵���void AddToRecentFileList(LPCTSTR lpszPathName)��	|
 |	�����ļ�����ID_FILE_MRU_FILE1��"RecentFileList"�йص������Ϊ��ʵ��ά���˵��������	|
 |	�����б��д�ġ���ΪϵͳĬ��ά�����б�ʧЧ�ˡ������Լ�ά����û�������á�����������	|
 |	�����й��ļ��򿪵Ĳ�����ò�Ҫ��View����д�����񱾳���һ������Ϊ�����Ļ����ƹ�App��	|
 |	Doc����ļ��򿪵���Ϣ�����Ӷ�ʹRecent File ListʧЧ�����򱾳����������ļ��б���	|
 |	���󣬲�����View��ʵ��OnFileOpen()�����׽���Ч�����ʽ�����ļ��б�Disable��������	|
 |	�����еĽṹ��																		|
 |                                                                         2005-4-21	|
 |                                                                           By:Neo		|
 \*------------------------------------------------------------------------------------*/

/*
void CPictViewApp::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (m_pRecentFileListMyFiles == NULL) // no MRU files 
		pCmdUI->Enable(FALSE); 
	else 
	m_pRecentFileListMyFiles->UpdateMenu(pCmdUI);
}

BOOL CPictViewApp::OnOpenRecentMyFile(UINT nID)
{
 	int nIndex = nID - ID_FILE_MRU_MYFILE1;
 	if (OpenDocumentFile((*m_pRecentFileListMyFiles)[nIndex]) == NULL)
 	    m_pRecentFileListMyFiles->Remove(nIndex);
 	return TRUE;
}


int CPictViewApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	m_pRecentFileListMyFiles->WriteList();	//д������򿪵��ĵ��б�
	return CWinApp::ExitInstance();
}

///////////////////////////////////////////////////////////////////////
// Overload of CWinApp::AddToRecentFileList() in class CPictViewApp
///////////////////////////////////////////////////////////////////////
void CPictViewApp::AddToRecentFileList(LPCTSTR lpszPathName)
{
    // Somehow determine doc type, I used file extension
	if (m_pRecentFileListMyFiles!= NULL)
	{
		// fully qualify the path name
		TCHAR szTemp[_MAX_PATH];
		AfxFullPath(szTemp, lpszPathName);

		// then add to recent file list
		m_pRecentFileListMyFiles->Add(szTemp);
	}
}
*/

