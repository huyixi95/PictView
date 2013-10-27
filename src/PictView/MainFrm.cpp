// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "PictView.h"

#include "MainFrm.h"
#include "WINUSER.H"	//AnimateWindow()

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_STATUS_BAR, OnViewStatusBar)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STATUS_BAR, OnUpdateViewStatusBar)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_LEFT,OnUpdateLeft)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_RIGHT,OnUpdateRight)
	ON_WM_CLOSE()
	ON_COMMAND(ID_FULL_SCREEN, OnFullScreen)
	ON_WM_GETMINMAXINFO()
	ON_UPDATE_COMMAND_UI(ID_FULL_SCREEN, OnUpdateFullScreen)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//static UINT indicators[] =
//{
//	ID_SEPARATOR,           // status line indicator
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
//};

static UINT indicators[] =
{
	ID_SEPARATOR,			//0.First message line pane,display the FULL PATH of the opened file.
	ID_SEPARATOR,			//1.Second message line pane,display the DISPLAY RATE OF THE PICTURE
	ID_SEPARATOR,			//2.Third message line pane,display the picture FILE SIZE.
	ID_SEPARATOR,			//3.Forth message line pane,dispaly the picture WIDTH and HEIGHT.
	ID_SEPARATOR,			//4.Fifth message line pane,display the POSITION OF MOUSE.
	ID_INDICATOR_LEFT,		//5.Sixth message line pane,
	ID_INDICATOR_RIGHT,		//6.Seventh message line pane,
};
/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_bFullScreen = FALSE;	//��ʼ״̬��ȫ��
	m_bIsPlay = FALSE;
	m_bIsFullBarShowed = FALSE;
	m_bTiming = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

/*	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	} */

	if (!m_wndStatusBar.Create(this,WS_CHILD|WS_VISIBLE|CBRS_BOTTOM,ID_MY_STATUS_BAR) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	
	m_wndStatusBar.SetPaneInfo(0,0,SBPS_STRETCH,50);
	m_wndStatusBar.SetPaneInfo(1,0,0,100);
	m_wndStatusBar.SetPaneInfo(2,0,0,100);
	m_wndStatusBar.SetPaneInfo(3,0,0,100);
	m_wndStatusBar.SetPaneInfo(4,0,0,100);

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	//����ʱ�������ڵ�ʵ��
	CenterWindow();				//���ھ���
	int	AnimationEffect = 0;
	srand( (unsigned)time( NULL ) );//Seed the random-number generator with current time so that 
									//the numbers will be different every time we run.
	AnimationEffect = rand()%20;
	switch(AnimationEffect)
	{
		case 0:
			AnimateWindow(GetSafeHwnd(),1500,AW_CENTER|AW_ACTIVATE);
			break;
		case 1:
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_ACTIVATE);
			break;
		case 2:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_ACTIVATE);
			break;
		case 3:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_ACTIVATE);
			break;
		case 4:
			AnimateWindow(GetSafeHwnd(),1500,AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 5:
			AnimateWindow(GetSafeHwnd(),1500,AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 6:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_ACTIVATE);
			break;
		case 7:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_ACTIVATE);
			break;
		case 8:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 9:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 10:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 11:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 12:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 13:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 14:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 15:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 16:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_VER_POSITIVE|AW_ACTIVATE);
			break;
		case 17:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_VER_NEGATIVE|AW_ACTIVATE);
			break;
		case 18://��1һ�������뵭��Ч������Ϊ�����Է��֣���Ч�������ܺܵ͵Ļ�����ִ��Ч��Ҳ�Ϻ�
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_ACTIVATE);
			break;
		case 19://��1һ�������뵭��Ч������Ϊ�����Է��֣���Ч�������ܺܵ͵Ļ�����ִ��Ч��Ҳ�Ϻ�
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_ACTIVATE);
			break;
	}
	
	WINDOWPLACEMENT lwndpl;		//ʹ�������붯���������	
	WINDOWPLACEMENT * lpwndpl;
	lpwndpl=&lwndpl;
	GetWindowPlacement(lpwndpl);
	lpwndpl->showCmd=SW_SHOWMAXIMIZED;
	SetWindowPlacement(lpwndpl);
	
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnViewStatusBar() 
{
	// TODO: Add your command handler code here
	m_wndStatusBar.ShowWindow((m_wndStatusBar.GetStyle() & WS_VISIBLE) == 0);
	RecalcLayout();
}

void CMainFrame::OnUpdateViewStatusBar(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck((m_wndStatusBar.GetStyle() & WS_VISIBLE) != 0);
}

void CMainFrame::OnUpdateLeft(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(::GetKeyState(VK_LBUTTON)<0);
}

void CMainFrame::OnUpdateRight(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(::GetKeyState(VK_RBUTTON)<0);
}

//�رճ���ʱ�������ڵ�ʵ��
void CMainFrame::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	//�Ȼָ�����Ϊ�����
	RECT ScrRect;		//��ȡ��Ļ�ֱ���
	GetDesktopWindow()->GetWindowRect(&ScrRect);
	WINDOWPLACEMENT lwndpl;
	WINDOWPLACEMENT * lpwndpl;
	lpwndpl = &lwndpl;
	GetWindowPlacement(lpwndpl);
	lpwndpl->rcNormalPosition.left = 40;					//������Ļ�ֱ����Ƕ��٣������40����
	lpwndpl->rcNormalPosition.right = ScrRect.right-40;		//���ұ�40����
	lpwndpl->rcNormalPosition.top = 30;						//�ඥ��30����
	lpwndpl->rcNormalPosition.bottom = ScrRect.bottom-30;	//��ײ�30����
	lpwndpl->showCmd = SW_SHOWNORMAL;
	SetWindowPlacement(lpwndpl);

	int	AnimationEffect=0;
	srand( (unsigned)time( NULL ) );//Seed the random-number generator with current time so that 
									//the numbers will be different every time we run.
	AnimationEffect = rand()%20;
	switch(AnimationEffect)
	{
		case 0:
			AnimateWindow(GetSafeHwnd(),1500,AW_CENTER|AW_HIDE);
			break;
		case 1:
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_HIDE);
			break;
		case 2:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_HIDE);
			break;
		case 3:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_HIDE);
			break;
		case 4:
			AnimateWindow(GetSafeHwnd(),1500,AW_VER_POSITIVE|AW_HIDE);
			break;
		case 5:
			AnimateWindow(GetSafeHwnd(),1500,AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 6:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_HIDE);
			break;
		case 7:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_HIDE);
			break;
		case 8:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_VER_POSITIVE|AW_HIDE);
			break;
		case 9:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 10:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_VER_POSITIVE|AW_HIDE);
			break;
		case 11:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_POSITIVE|AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 12:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_VER_POSITIVE|AW_HIDE);
			break;
		case 13:
			AnimateWindow(GetSafeHwnd(),1500,AW_HOR_NEGATIVE|AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 14:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_VER_POSITIVE|AW_HIDE);
			break;
		case 15:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_POSITIVE|AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 16:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_VER_POSITIVE|AW_HIDE);
			break;
		case 17:
			AnimateWindow(GetSafeHwnd(),1500,AW_SLIDE|AW_HOR_NEGATIVE|AW_VER_NEGATIVE|AW_HIDE);
			break;
		case 18://��1һ�������뵭��Ч������Ϊ�����Է��֣���Ч�������ܺܵ͵Ļ�����ִ��Ч��Ҳ�Ϻ�
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_HIDE);
			break;
		case 19://��1һ�������뵭��Ч������Ϊ�����Է��֣���Ч�������ܺܵ͵Ļ�����ִ��Ч��Ҳ�Ϻ�
			AnimateWindow(GetSafeHwnd(),1500,AW_BLEND|AW_HIDE);
			break;
	}
	CFrameWnd::OnClose();
}

//*********** �˵�"ȫ��" **************
void CMainFrame::OnFullScreen() 
{
	// TODO: Add your command handler code here
	/*
	GetWindowPlacement(&m_OldWndPlacement);
	CRect	WindowRect;
	CRect	ClientRect;
	GetWindowRect(&WindowRect);
	RepositionBars(0, 0xffff, AFX_IDW_PANE_FIRST, reposQuery, &ClientRect);
	ClientToScreen(&ClientRect);	//���û�������תΪ��Ļ����
	//��ȡ��Ļ�ķֱ���
	int	nFullWidth=GetSystemMetrics(SM_CXSCREEN);
	int	nFullHeight=GetSystemMetrics(SM_CYSCREEN);
	//������������Ŀͻ���ȫ����ʾ����(0,0)��(nFullWidth, nFullHeight)����, 
	//��(0,0)��(nFullWidth, nFullHeight)������������ԭ���ںͳ�������֮��� 
	//�ͻ���λ�ü�Ĳ�ֵ, �͵õ�ȫ����ʾ�Ĵ���λ��
	m_FullScreenRect.left=WindowRect.left-ClientRect.left;
	m_FullScreenRect.top=WindowRect.top-ClientRect.top;
	m_FullScreenRect.right=WindowRect.right-ClientRect.right+nFullWidth;
	m_FullScreenRect.bottom=WindowRect.bottom-ClientRect.bottom+nFullHeight;
	m_bFullScreen=TRUE;	//����ȫ����ʾ��־Ϊ TRUE
	//����ȫ����ʾ״̬
	WINDOWPLACEMENT wndpl;
	wndpl.length=sizeof(WINDOWPLACEMENT);
	wndpl.flags=0;
	wndpl.showCmd=SW_SHOWNORMAL;
	wndpl.rcNormalPosition=m_FullScreenRect;
	SetWindowPlacement(&wndpl);
	*/

	RECT			rectDesktop;
	WINDOWPLACEMENT	NewWndPlacement;		//����ȫ��״̬�Ĵ��ڲ���
	if (!m_bFullScreen)
	{
		// ����Ҫԭ״̬����������
		m_wndStatusBar.ShowWindow(SW_HIDE);
		m_wndToolBar.ShowWindow(SW_HIDE);

		// ����Ҫ�ָ�ԭ״,����ԭ���ֵ�m_OldWndPlacement
		GetWindowPlacement(&m_OldWndPlacement);
		m_OldWndPlacement.length = sizeof(m_OldWndPlacement);

		// ͨ������ RECT ��ȷ���´��ڵĴ�С
		::GetWindowRect(::GetDesktopWindow(), &rectDesktop);
		::AdjustWindowRectEx(&rectDesktop, GetStyle(), TRUE, GetExStyle());

		// �Ѳ������� OnGetMinMaxInfo()
		m_FullScreenRect = rectDesktop;

		NewWndPlacement = m_OldWndPlacement;
		NewWndPlacement.showCmd =  SW_SHOWNORMAL;
		NewWndPlacement.rcNormalPosition = rectDesktop;

		// �����µĹ�����
		m_pwndFullScrnBar=new CToolBar;
		if(!m_pwndFullScrnBar->CreateEx(this,TBSTYLE_FLAT,WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC | CBRS_FLOATING | 
			    CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY) || !m_pwndFullScrnBar->LoadToolBar(IDR_FULLSCREEN))
		{
			TRACE0("Failed to create toolbar!\n");
				return;		//����ʧ��
		}

		// ����������ͣ��
		m_pwndFullScrnBar->EnableDocking(0);
		m_pwndFullScrnBar->SetWindowPos(&CWnd::wndTop,0,100,100,0,SWP_NOSIZE|SWP_NOZORDER|SWP_NOACTIVATE|SWP_SHOWWINDOW);
		m_pwndFullScrnBar->SetWindowText(_T("ȫ��/�õ�Ƭģʽ"));
		//�õ���������С��������ͣ��λ��
		FloatControlBar(m_pwndFullScrnBar,CPoint(100,100));	//������ȵ���һ�δ˺�����ȡ������RECT
		RECT FullScrnBarRect;
		m_pwndFullScrnBar->GetWindowRect(&FullScrnBarRect);
		int BarWidth = FullScrnBarRect.right - FullScrnBarRect.left;
		int BarPos_x = rectDesktop.right - rectDesktop.left - BarWidth - 15;
		FloatControlBar(m_pwndFullScrnBar,CPoint(BarPos_x,3));	//��λ�ý�����SetWindowPos()�е�����
		//
		m_bFullScreen=TRUE;		//����ȫ����ʾ��־Ϊ TRUE
		m_bScrModeChged=TRUE;	//�Ա���CPictViewView::OnDraw()�����¼���ͼƬ��ʾλ��
		//����ȫ��ʱ���ü�ʱ������־�Ա��Զ�����ȫ��������
		m_bIsFullBarShowed = TRUE;
		SetTimer(IDT_TIMER_HIDEFULLSCRBAR,5000,NULL);
	}
	else		//ԭ����ȫ������ʱ�ٵ����ȫ������Ӧ��������״̬
	{
		m_pwndFullScrnBar->DestroyWindow();
		delete	m_pwndFullScrnBar;
		m_pwndFullScrnBar = NULL;

		m_bFullScreen=FALSE;
		m_bScrModeChged=TRUE;	//�Ա���CPictViewView::OnDraw()�����¼���ͼƬ��ʾλ��
		//������ڽ��лõ�Ƭ���ţ���ֹͣ
		if(m_bIsPlay)
		{
			m_bIsPlay = FALSE;
			//KillTimer(IDT_TIMER_PLAY);
		}
		//���ȫ���������Զ����ؼ�ʱ����δֹͣ�����˳�ȫ��ʱֹͣ
		if(m_bIsFullBarShowed && m_bTiming)	//���������ʱ���ǹ����ŵ�
		{
			m_bIsFullBarShowed = FALSE;
			KillTimer(IDT_TIMER_HIDEFULLSCRBAR);
			m_bTiming = FALSE;
		}
		else
			m_bIsFullBarShowed = FALSE;		//ֻ�ѱ�־��Ϊδ��ʾ������KillTimer,��Timer����Kill
		//�ָ�����
		m_wndStatusBar.ShowWindow(SW_SHOWNORMAL);
		m_wndToolBar.ShowWindow(SW_SHOWNORMAL);
		NewWndPlacement = m_OldWndPlacement;
	}

	SetWindowPlacement(&NewWndPlacement);
}

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_bFullScreen)
	{
		lpMMI->ptMaxSize.y = m_FullScreenRect.Height();
		lpMMI->ptMaxTrackSize.y = lpMMI->ptMaxSize.y;
		lpMMI->ptMaxSize.x = m_FullScreenRect.Width();
		lpMMI->ptMaxTrackSize.x = lpMMI->ptMaxSize.x;
	}

	CFrameWnd::OnGetMinMaxInfo(lpMMI);
}

void CMainFrame::OnUpdateFullScreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(TRUE);
	if(m_bFullScreen)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);

}

//��ESC���˳�ȫ����ʾ, �ָ�ԭ������ʾ��ִ�к�����(��Ϣ��������CPictViewView��)
void CMainFrame::EndFullScreen()
{
	if(m_bFullScreen)
	{
		m_pwndFullScrnBar->DestroyWindow();
		delete	m_pwndFullScrnBar;
		m_pwndFullScrnBar = NULL;
		m_bFullScreen=FALSE;
		m_bScrModeChged=TRUE;	//�Ա���CPictViewView::OnDraw()�����¼���ͼƬ��ʾλ��
		//������ڽ��лõ�Ƭ���ţ���ֹͣ
		if(m_bIsPlay)
		{
			m_bIsPlay = FALSE;
			//int result = KillTimer(IDT_TIMER_PLAY);//��һ���ļ����ǲ���Kill��һ���ļ��е�Timer��
		}
		//���ȫ���������Զ����ؼ�ʱ����δֹͣ�����˳�ȫ��ʱֹͣ
		if(m_bIsFullBarShowed && m_bTiming)	//���������ʱ���ǹ����ŵ�
		{
			m_bIsFullBarShowed = FALSE;
			KillTimer(IDT_TIMER_HIDEFULLSCRBAR);
			m_bTiming = FALSE;
		}
		else
			m_bIsFullBarShowed = FALSE;		//ֻ�ѱ�־��Ϊδ��ʾ������KillTimer,��Timer����Kill
		//�ָ�����
		m_wndStatusBar.ShowWindow(SW_SHOWNORMAL);
		m_wndToolBar.ShowWindow(SW_SHOWNORMAL);
		//ShowWindow(SW_HIDE);
		SetWindowPlacement(&m_OldWndPlacement);
	}
}

//**** �Զ�����ȫ����������ʱ�������� ****
void CMainFrame::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == IDT_TIMER_HIDEFULLSCRBAR)
	{
		KillTimer(IDT_TIMER_HIDEFULLSCRBAR);				//������һ�����أ����������ʱ
		FloatControlBar(m_pwndFullScrnBar,CPoint(1028,0));	//���ع�����
		m_bIsFullBarShowed = FALSE;
		m_bTiming = FALSE; //��ʱ���
	}

	//CFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::StartTimer()
{
	SetTimer(IDT_TIMER_HIDEFULLSCRBAR,5000,NULL);
}

void CMainFrame::StopTimer()
{
	KillTimer(IDT_TIMER_HIDEFULLSCRBAR);
}
