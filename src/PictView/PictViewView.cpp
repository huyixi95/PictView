// PictViewView.cpp : implementation of the CPictViewView class
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

/////////////////////////////////////////////////////////////////////////////
// CPictViewView

IMPLEMENT_DYNCREATE(CPictViewView, CScrollView)

BEGIN_MESSAGE_MAP(CPictViewView, CScrollView)
	//{{AFX_MSG_MAP(CPictViewView)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_MRU_FILE1, OnUpdateFileMruFile1)
	ON_COMMAND(ID_USE_SPECIAL_EFFECT, OnUseSpecialEffect)
	ON_UPDATE_COMMAND_UI(ID_USE_SPECIAL_EFFECT, OnUpdateUseSpecialEffect)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ZOOM_HALF, OnZoomHalf)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_HALF, OnUpdateZoomHalf)
	ON_COMMAND(ID_ZOOM_ORIGINAL, OnZoomOriginal)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_ORIGINAL, OnUpdateZoomOriginal)
	ON_COMMAND(ID_ZOOM_DOUBLE, OnZoomDouble)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_DOUBLE, OnUpdateZoomDouble)
	ON_COMMAND(ID_ZOOM_75PERCENT, OnZoom75percent)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_75PERCENT, OnUpdateZoom75percent)
	ON_COMMAND(ID_ZOOM_150PERCENT, OnZoom150percent)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_150PERCENT, OnUpdateZoom150percent)
	ON_COMMAND(ID_EFFECT_RANDOM, OnEffectRandom)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_RANDOM, OnUpdateEffectRandom)
	ON_COMMAND(ID_EFFECT_MOSAIC, OnEffectMosaic)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MOSAIC, OnUpdateEffectMosaic)
	ON_COMMAND(ID_EFFECT_BLINDS, OnEffectBlinds)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_BLINDS, OnUpdateEffectBlinds)
	ON_COMMAND(ID_EFFECT_TOPDOWN, OnEffectTopdown)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_TOPDOWN, OnUpdateEffectTopdown)
	ON_COMMAND(ID_EFFECT_BOTTOMUP, OnEffectBottomup)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_BOTTOMUP, OnUpdateEffectBottomup)
	ON_COMMAND(ID_EFFECT_LEFTRIGHT, OnEffectLeftright)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_LEFTRIGHT, OnUpdateEffectLeftright)
	ON_COMMAND(ID_EFFECT_RIGHTLEFT, OnEffectRightleft)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_RIGHTLEFT, OnUpdateEffectRightleft)
	ON_COMMAND(ID_EFFECT_TOPLEFT, OnEffectTopleft)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_TOPLEFT, OnUpdateEffectTopleft)
	ON_COMMAND(ID_EFFECT_BOTTOMLEFT, OnEffectBottomleft)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_BOTTOMLEFT, OnUpdateEffectBottomleft)
	ON_COMMAND(ID_EFFECT_TOPRIGHT, OnEffectTopright)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_TOPRIGHT, OnUpdateEffectTopright)
	ON_COMMAND(ID_EFFECT_BOTTOMRIGHT, OnEffectBottomright)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_BOTTOMRIGHT, OnUpdateEffectBottomright)
	ON_COMMAND(ID_VIEW_PREVIOUS, OnViewPrevious)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PREVIOUS, OnUpdateViewPrevious)
	ON_COMMAND(ID_VIEW_NEXT, OnViewNext)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NEXT, OnUpdateViewNext)
	ON_COMMAND(ID_EDIT_DELETE, OnEditDelete)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETE, OnUpdateEditDelete)
	ON_COMMAND(ID_ZOOM_IN, OnZoomIn)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_IN, OnUpdateZoomIn)
	ON_COMMAND(ID_ZOOM_OUT, OnZoomOut)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_OUT, OnUpdateZoomOut)
	ON_COMMAND(ID_EDIT_EXTERNAL, OnEditExternal)
	ON_UPDATE_COMMAND_UI(ID_EDIT_EXTERNAL, OnUpdateEditExternal)
	ON_COMMAND(ID_EDIT_IN_MPAINT, OnEditInMpaint)
	ON_UPDATE_COMMAND_UI(ID_EDIT_IN_MPAINT, OnUpdateEditInMpaint)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_PLAY, OnPlay)
	ON_UPDATE_COMMAND_UI(ID_PLAY, OnUpdatePlay)
	ON_COMMAND(ID_PAUSE, OnPause)
	ON_UPDATE_COMMAND_UI(ID_PAUSE, OnUpdatePause)
	ON_WM_ERASEBKGND()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_FULL_SCREEN, OnFullScreen)
	ON_COMMAND(ID_ZOOM_FITSCREEN, OnZoomFitscreen)
	ON_UPDATE_COMMAND_UI(ID_ZOOM_FITSCREEN, OnUpdateZoomFitscreen)
	ON_COMMAND(ID_ROTATE90_CLOCKWISE, OnRotate90Clockwise)
	ON_UPDATE_COMMAND_UI(ID_ROTATE90_CLOCKWISE, OnUpdateRotate90Clockwise)
	ON_COMMAND(ID_EFFECT_MEM_VBLINDS, OnEffectMemVblinds)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MEM_VBLINDS, OnUpdateEffectMemVblinds)
	ON_COMMAND(ID_EFFECT_MEM_HBLINDS, OnEffectMemHblinds)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MEM_HBLINDS, OnUpdateEffectMemHblinds)
	ON_COMMAND(ID_EFFECT_MEM_MOSAIC, OnEffectMemMosaic)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MEM_MOSAIC, OnUpdateEffectMemMosaic)
	ON_COMMAND(ID_EFFECT_MEM_SCANFROMTOP, OnEffectMemScanfromtop)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MEM_SCANFROMTOP, OnUpdateEffectMemScanfromtop)
	ON_COMMAND(ID_EFFECT_MEM_SCANFROMBOTTOM, OnEffectMemScanfrombottom)
	ON_UPDATE_COMMAND_UI(ID_EFFECT_MEM_SCANFROMBOTTOM, OnUpdateEffectMemScanfrombottom)
	ON_COMMAND(ID_ROTATE90_ANTICLOCKWISE, OnRotate90Anticlockwise)
	ON_UPDATE_COMMAND_UI(ID_ROTATE90_ANTICLOCKWISE, OnUpdateRotate90Anticlockwise)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSave)
	ON_COMMAND(ID_ROTATE180, OnRotate180)
	ON_UPDATE_COMMAND_UI(ID_ROTATE180, OnUpdateRotate180)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictViewView construction/destruction

CPictViewView::CPictViewView()
{
	// TODO: add construction code here

	//m_IsRandomEffect = TRUE;
	m_showX=0;
	m_showY=0;
	m_degree=1;
	m_Llower_rate=1.0;
	m_IsRandomEffect=TRUE;
	m_IsNormalShow=FALSE;	//Ĭ��״̬Ϊʹ����Ч
	m_Isconvert=FALSE;		//m_Isconvert Specify if the file is to be converted to 32bit

}

CPictViewView::~CPictViewView()
{
}

BOOL CPictViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPictViewView diagnostics

#ifdef _DEBUG
void CPictViewView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPictViewView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CPictViewDoc* CPictViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPictViewDoc)));
	return (CPictViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictViewView printing

BOOL CPictViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPictViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPictViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPictViewView drawing

void CPictViewView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

///*******  ͼ�����ʾ  ***********///
void CPictViewView::OnDraw(CDC* pDC)
{
	// TODO: add draw code for native data here
	CPictViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if(!(pDoc->m_bIsEmptyDir))		//��m_bIsEmptyDirΪTRUEʱ˵����ǰĿ¼�����ļ���������ʾ
	{
		if(m_LImage.IsLoad() == FALSE)
			return;

		CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
		if(pFrame->m_bScrModeChged)	//��������ʾģʽ�л������¼���ͼƬ��ʾλ��
		{
			CRect rect;
			GetClientRect(&rect);							//��ȡ�û�������
			m_nWindowWidth = rect.right - rect.left;		//������
			m_nWindowHeight = rect.bottom - rect.top;		//����߶�

			//ֻ�е���ʾ�Ŀ���С�ڿͻ������ʱ�ž��У�	
			//����ֱ�Ӵ����Ͻǿ�ʼ��ʾ.���������������λ�û᲻��ȷ
			//���ҵ���ʾ��С�����ͻ���ʱ����Ҳû�����塣
			if(m_LImage.m_nDrawWidth<m_nWindowWidth)
				m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
			else 
				m_showX = 0;
			if(m_LImage.m_nDrawHeight<m_nWindowHeight)
				m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
			else
				m_showY = 0;

			pFrame->m_bScrModeChged = FALSE;
		}
	
		int transform=0;						//���������ҽ�����Ļ�Ľ��������
		int transform_w=0,transform_h=0;		//���ĸ��ǽ�����Ļ�Ľ����x,y����ı�����

		if(m_IsRandomEffect && !m_IsNormalShow && m_bIsDrawFirstTime)
		{
			srand( (unsigned)time( NULL ) );	//Seed the random-number generator with current time so that 
												//the numbers will be different every time we run.
			m_EffectNum = rand()%11;			//��������Ч��,������������Ա������뼰�任ʱʹ�����Ч��
		}
	/*==============================********************====================*\
	|                           ͼ������ʱ����ʾ��Ч
	|
	| <!!-ֻ�е�һ�������任ʱ�ſ���ʹ����Ч����ϵͳ����OnDraw()��������ʾ-!!>
	|
	| 0:������ʾ��1:������Ч��2:��������3:��������4:��������5:��������
	| 6:�����Ͻǽ���7:�����Ͻǽ���8:�����½ǽ���9:�����½ǽ���
	\*==============================********************====================*/
		if((m_bIsDrawFirstTime == TRUE)&&(m_IsNormalShow == FALSE))	//�ǵ�һ�λ��ƣ���ʹ����Ч
		{
			switch(m_EffectNum)
			{
		
				case Mosaic:		//������Ч��
					Effect_Mosaic(pDC);
					break;
				case fromtop:		//��������
					Effect_Fromtop(pDC,transform);
					break;
				case frombottom:	//��������
					Effect_Frombottom(pDC,transform);
					break;
				case fromleft:		//��������
					Effect_Fromleft(pDC,transform);
					break;
				case fromright:		//��������
					Effect_Fromright(pDC,transform);
					break;
				case fromtopleft:	//�����Ͻǽ���
					Effect_Fromtopleft(pDC, transform_w, transform_h);
					break;
				case fromtopright:	//�����Ͻǽ���
					Effect_Fromtopright(pDC, transform_w, transform_h);
					break;
				case frombottomleft://�����½ǽ���
					Effect_Frombottomleft(pDC, transform_w, transform_h);
					break;
				case frombottomright://�����½ǽ���
					Effect_Frombottomright(pDC, transform_w, transform_h);
					break;
				case Blinds:		//��Ҷ��
					Effect_Blinds(pDC);
					break;
				default:            //��ʹ��Ч��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
							int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
							0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
			}	// end switch(m_EffectNum)
		}
		else	//���ǵ�һ�λ��ƻ��û�δѡ��ʹ����Ч����ʹ����Ч
		{
			m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
					int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
					0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		}
	
		m_bIsDrawFirstTime=FALSE;				//��ΪFALSE��֤���Ѿ����ǵ�һ�λ��ơ�
	
		SIZE sz;						
		sz.cx = m_LImage.m_nDrawWidth;			//�������ù�������С
		sz.cy = m_LImage.m_nDrawHeight;
		this->SetScrollSizes(MM_TEXT,sz);
	}
	else	//Ŀ¼������ͼ��
	{
		SIZE sz;
		CRect rect;
		sz.cx = 100;
		sz.cy = 100;
		this->SetScrollSizes(MM_TEXT,sz);

		GetClientRect(&rect);							//��ȡ�û�������
		m_nWindowWidth = rect.right - rect.left;		//������
		m_nWindowHeight = rect.bottom - rect.top;
		pDC->TextOut(m_nWindowWidth/2-100,m_nWindowHeight/2,"��Ŀ¼���޿���ʾ��ͼ��");
	}

}

/////////////////////////////////////////////////////////////////////////////
// CPictViewView message handlers

//************ ʹ�½��˵������� *********//
void CPictViewView::OnUpdateFileNew(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//************ ʹ��������ļ��������� *********//
void CPictViewView::OnUpdateFileMruFile1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(FALSE);
}

//************ �����ʹ����Ч��ʱ *********//
void CPictViewView::OnUseSpecialEffect() 
{
	// TODO: Add your command handler code here
	if(m_IsNormalShow)
		m_IsNormalShow = FALSE;
	else
		m_IsNormalShow = TRUE;
}

void CPictViewView::OnUpdateUseSpecialEffect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(FALSE == m_IsNormalShow)	//��ʹ����Ч����ΪChecked.
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);//��ʹ����Ч����ΪUnChecked.
}

//////////////////////////////////////////////////
//               ͼ���ļ��Ķ���
//////////////////////////////////////////////////

void CPictViewView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	
	CFileDialog		fdialog(TRUE);
	//##**##
	fdialog.m_ofn.lpstrFilter = "�����ļ�(*.*)\0*.bmp;*.tga;*.pcx;*.jpg;*.jpeg;*.gif\0"
								"BMP(*.bmp)\0*.bmp\0"
								"TGA(*.tga)\0*.tga\0"
								"PCX(*.pcx)\0*.pcx\0"
								"JPEG(*.jpg,*.jpeg)\0*.jpg;*.jpeg\0"
								"GIF(*.gif)\0*.gif\0";
	if(fdialog.DoModal() == IDOK)
	{
		//##**##**********************************************
		//�ڴ�һ����ͼƬʱ�Ȼ�����һ��ͼƬ���ڴ棬���������ڴ�й©
		//����ϴ�δʹ��Lib Sources�������ڴ˻��գ�LanImage::Create()���Ѿ�����
		if(m_LImage.m_bReadWithLibSupport)
		{
			//��LanImage::LoadImage()�� m_pJpeg = new CJpeg()����Ŀռ�
			if(m_LImage.m_pJpeg != NULL)	//�ϴδ򿪵�ʱJPEG��ʽ
			{
				CJpeg * pTempJpeg = m_LImage.m_pJpeg;
				m_LImage.m_pJpeg = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempJpeg;
			}
			if(m_LImage.m_pGif != NULL)	//�ϴδ򿪵�ʱGIF��ʽ
			{
				CGif * pTempGif = m_LImage.m_pGif;
				m_LImage.m_pGif = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempGif;
			}
		}
		else
			m_LImage.Release();
		//***********************************************

		if (m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(fdialog.GetPathName(),m_degree,TRUE))
				return ;
		}
		if (!m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(fdialog.GetPathName(),m_degree,FALSE))
				return ;
		}

		CString sTitle=fdialog.GetFileName();	//�ڱ�������ʾ���ļ����ļ���
		CString sPath=fdialog.GetPathName();	//Ϊ��״̬����ʾ·����д
		CString sImageSize;						//Ϊ��״̬����ʾͼƬ�ߴ�
		CString sFileSize;						//Ϊ��״̬����ʾ�ļ���С
		CString sDisplayRate;					//Ϊ��״̬����ʾͼ��ǰ��ʾ����
		CPictViewDoc *pDoc=GetDocument();
		pDoc->SetTitle(sTitle);
		pDoc->m_bIsEmptyDoc = FALSE;			//��־Ϊ�ǿ��ĵ�
		pDoc->m_bIsEmptyDir = FALSE;			//��־��ǰĿ¼Ϊ�ǿ�
		m_LImage.m_bBufferIsOriginal = TRUE;

//		if(!m_LImage.m_bReadWithLibSupport)		//��дJPEG,GIFʱʹ��Lib Sources�еķ�����������ת����
//			m_LImage.Convert32();				//תΪ32λɫ;�˺����ڵ���ʱ�����⣬��û����Ԥ��Ŀ�ģ�
												//��ʱ��ת��,����ԭ��ͼ�������λ����ʾ
			
//		SIZE sz;
//		sz.cx = m_LImage.m_nWidth;
//		sz.cy = m_LImage.m_nHeight;
//		this->SetScrollSizes(MM_TEXT,sz);

		// **** �������ͼƬ��λ�ã�����ʾ��С **>>
		FitScreen();

		// **** ����״̬������ʾ����Ϣ���ļ�·�����ļ���С��ͼƬ��С ****
		CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
		CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������
		if(pStatus)
		{
			sImageSize.Format("����� = %d��%d",m_LImage.m_nWidth,m_LImage.m_nHeight);
			sFileSize.Format("%.1f KB",m_LImage.nFileSize/1024.0);
			sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
			pStatus->SetPaneText(0,sPath);
			pStatus->SetPaneText(1,sDisplayRate);
			pStatus->SetPaneText(2,sFileSize);
			pStatus->SetPaneText(3,sImageSize);
		}
		else
			AfxMessageBox("Can not get StatusBar pointer!");

		m_bIsDrawFirstTime=TRUE;	//��һ��ͼ�񣬵�һ�λ��ƣ���Ҫʹ����Ч��֮����OnDraw()�б���ΪFALSE.
		Invalidate(TRUE);	//֪ͨWindow������Ҫ���»���
							//��Ϊ��MainFrm.cpp��ʹ��SetWindowPlacement()ǿ�Ƴ�������ʱ
							//������󻯣����Invalidate()����ΪFALSE����ô�ᵼ������һ
							//����ǰͼС��ͼƬʱǰͼʾ�����ǲ�����Ȼ��������Ļ�ϡ�

		// **** ������ǰĿ¼�µ�ͼƬ�ļ��б� ****
		pDoc->InitPicList(sPath);
		for(int i=0;i<=(pDoc->m_iFileNumber);i++)		//ȷ����ǰ�򿪵��ļ����б��е�λ��
		{
			if(sPath == pDoc->m_PicList[i])
			{
				pDoc->m_iCurrFileNum = i;
				break;
			}
		}

	}
}


//////////////////////////////////////////////////
//               ͼ���ļ��ı���
//////////////////////////////////////////////////
void CPictViewView::OnFileSave() 
{
	// TODO: Add your command handler code here

	CFileDialog		fdialog(FALSE);
	//##**##
	fdialog.m_ofn.lpstrFilter = "�����ļ�(*.*)\0*.bmp;*.tga;*.jpg;*.pcx;*.gif\0"
									"BMP(*.bmp)\0*.bmp\0"
						    		"TGA(*.tga)\0*.tga\0"
									"JPEG(*.jpg)\0*.jpg\0"
									"PCX(*.pcx)\0*.pcx\0"
									"GIF(*.gif)\0*.gif\0";
	if(fdialog.DoModal() == IDOK)
	{ 
		CString strFileName = fdialog.GetPathName();
		int nFilterIndex=fdialog.m_ofn.nFilterIndex;

		if(2 == nFilterIndex)					//���û�ѡ���ļ�������Ϊ".BMP"ʱ
		{
			//fdialog.SetDefExt(".bmp");
			strFileName = strFileName + ".bmp";	//�Զ�����չ��.bmp
			m_LImage.SaveBmp(strFileName);
		}
		else if(3 == nFilterIndex)				//���û�ѡ���ļ�������Ϊ".TGA"ʱ
		{
			//fdialog.SetDefExt(".tga");
			strFileName = strFileName + ".tga";	//�Զ�����չ��.tga
			m_LImage.SaveTga(strFileName);
		}
		else if(4 == nFilterIndex)				//���û�ѡ���ļ�������Ϊ".jpg"ʱ
		{
			strFileName = strFileName + ".jpg";	//�Զ�����չ��.jpg
			//��ʱʹ����Lib Sources�еķ���
			//�򿪵���JPEGͼ������m_pJpeg������CDib����
			if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pJpeg!=NULL) )
				m_LImage.m_pJpeg->Save(strFileName,NULL,TRUE,75);
			//�򿪵���GIFͼ������m_pGif������CDib����
			else if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pGif!=NULL) )
			{
				m_LImage.m_pJpeg = new CJpeg();	//��δ�򿪹�JPEGͼ���ȴ�������
				m_LImage.m_pJpeg->Save(strFileName,m_LImage.m_pGif->GetDib(),TRUE,75);
				delete m_LImage.m_pJpeg; m_LImage.m_pJpeg = NULL;
			}
			//��ʱδʹ��Lib Sources�еķ��������򿪵��Ƿ�JPEGͼ���ȴ���CDib����
			else
			{
				m_LImage.m_pJpeg = new CJpeg();
				CDib* pDib;
				m_LImage.CreateDib(&pDib);
				m_LImage.m_pJpeg->Save(strFileName,pDib,TRUE,75);
				delete pDib;
				delete m_LImage.m_pJpeg; m_LImage.m_pJpeg = NULL;
			}
		}
		else if(5 == nFilterIndex)				//���û�ѡ���ļ�������Ϊ".pcx"ʱ
		{
			strFileName = strFileName + ".pcx";	//�Զ�����չ��.pcx
			CDib* pDib;
			m_LImage.CreateDib(&pDib);
			m_LImage.SavePcx(strFileName,pDib);
			delete pDib;
		}
		else if(6 == nFilterIndex)				//���û�ѡ���ļ�������Ϊ".gif"ʱ
		{
			strFileName = strFileName + ".gif";	//�Զ�����չ��.gif
			if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pGif!=NULL) )
				m_LImage.m_pGif->Save(strFileName,NULL);
			else if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pJpeg!=NULL) )
			{
				m_LImage.m_pGif = new CGif();	//�ȴ����������ռ䣬����CGif�е�buffer��������
				m_LImage.m_pGif->Save(strFileName,m_LImage.m_pJpeg->GetDib());
				delete m_LImage.m_pGif; m_LImage.m_pGif = NULL;
			}
			else
			{
				m_LImage.m_pGif = new CGif();
				CDib* pDib;
				m_LImage.CreateDib(&pDib);
				m_LImage.m_pGif->Save(strFileName,pDib);
				delete pDib;
				delete m_LImage.m_pGif; m_LImage.m_pGif = NULL;
			}
		}
		else	// - - - - - - - - - - - - - - -//δѡ�񣬼����������ڡ������ļ���ʱ 
		{
			LPCTSTR pszExt = strchr(strFileName,'.');
			if(pszExt)	// - - - - - - - - - - -//�û���������չ������������ļ����к�'.'��δ������Ч��չ��
			{
				if(_stricmp(pszExt,".bmp") == 0)
					m_LImage.SaveBmp(strFileName);
				else if(_stricmp(pszExt,".tga") == 0)
					m_LImage.SaveTga(strFileName);
				else if( (_stricmp(pszExt,".jpg") == 0)||(_stricmp(pszExt,".jpeg") == 0) )
				{
					//��ʱʹ����Lib Sources�еķ���
					//�򿪵���JPEGͼ������m_pJpeg������CDib����
					if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pJpeg!=NULL) )
						m_LImage.m_pJpeg->Save(strFileName,NULL,TRUE,75);
					//�򿪵���GIFͼ������m_pGif������CDib����
					else if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pGif!=NULL) )
					{
						m_LImage.m_pJpeg = new CJpeg();	//��δ�򿪹�JPEGͼ���ȴ�������
						m_LImage.m_pJpeg->Save(strFileName,m_LImage.m_pGif->GetDib(),TRUE,75);
						delete m_LImage.m_pJpeg; m_LImage.m_pJpeg = NULL;
					}
					else								//��ʱδʹ��Lib Sources�еķ������ȴ���CDib����
					{
						m_LImage.m_pJpeg = new CJpeg();
						CDib* pDib;
						m_LImage.CreateDib(&pDib);
						m_LImage.m_pJpeg->Save(strFileName,pDib,TRUE,75);
						delete pDib;
						delete m_LImage.m_pJpeg; m_LImage.m_pJpeg = NULL;
					}
				}
				else if(_stricmp(pszExt,".gif") == 0)
				{
					if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pGif!=NULL) )
						m_LImage.m_pGif->Save(strFileName,NULL);
					else if(m_LImage.m_bReadWithLibSupport && (m_LImage.m_pJpeg!=NULL) )
					{
						m_LImage.m_pGif = new CGif();
						m_LImage.m_pGif->Save(strFileName,m_LImage.m_pJpeg->GetDib());
						delete m_LImage.m_pGif; m_LImage.m_pGif = NULL;
					}
					else			//��ʱδʹ��Lib Sources�еķ������ȴ���CDib����
					{
						m_LImage.m_pGif = new CGif();
						CDib* pDib;
						m_LImage.CreateDib(&pDib);
						m_LImage.m_pGif->Save(strFileName,pDib);
						delete pDib;
						delete m_LImage.m_pGif; m_LImage.m_pGif = NULL;
					}
				}
				else if(_stricmp(pszExt,".pcx") == 0)
				{
					CDib* pDib;
					m_LImage.CreateDib(&pDib);
					m_LImage.SavePcx(strFileName,pDib);
					delete pDib;
				}
				else	// - - - - - - - - - - -//��������ļ����к�'.'��δ������Ч��չ��
				{
					strFileName = strFileName + ".bmp";	//�Զ�����ΪBMP��ʽ
					m_LImage.SaveBmp(strFileName);
				}

			}
			else								//�û�δ������չ�������Զ�����ΪBMP��ʽ��
			{
				//fdialog.SetDefExt(".bmp");
				strFileName = strFileName + ".bmp";
				m_LImage.SaveBmp(strFileName);
			}
		}
		
	}	
	
}
//////////////////////////////////////////////////////////
//                 ��Ч��ʾ����
//////////////////////////////////////////////////////////

//************ 1.������Ч�� ***************//
void	CPictViewView::Effect_Mosaic(CDC *pDC)
{
		int m_count=0;
//		int	LanArrow[128][128];			//����Ϊ128*128��

//		for(int i=0;i<128;i++)			//�˴�forѭ�����û�У������Release���г���Crash,
//			for(int j=0;j<128;j++)		//���������ֶ���ʼ������
//			{
//				LanArrow[i][j] = 0;
//			}

//		while ( m_count < 16384)		/*-------------------------------------------------*\
//		{								|����ע�͵��������ԭ�������˵�ʵ�ַ����������ֳ�	|
//			int x = rand()%128;			|128��128=16384�飬ÿ���СΪ8��6������128��8=1024	|
//			int y = rand()%128;			|128��6=768������ԭͼƬ�Ĵ�С��ÿ�λ���ʱ�򶼻�ȡ��	|
//			while(LanArrow[x][y] == 1)	|1024��768�����أ���������ʾ����1028��768��С��ͼƬ	|
//			{							|ʱ�Ϳ��ܻ������Access Violation�Ĵ���			|
//				x = rand()%128;			\*-------------------------------------------------*/
//				y = rand()%128;
//			}
//			LanArrow[x][y] = 1;
//			m_count++;
//			m_LImage.Draw(pDC->GetSafeHdc(),
//						  int(m_Llower_rate*8*x)+m_showX,
//						  int(m_Llower_rate*6*y)+m_showY,
//						  int(m_Llower_rate*8),
//						  int(m_Llower_rate*6),
//						  8*x,6*y,8,6);
//		}

		int blockNum_w = 0;		//ˮƽ����ָ�Ŀ���,������
		int blockNum_h = 0;		//��ֱ����ָ�Ŀ���,������
		int blockSize = 0;

		if(m_LImage.m_nWidth<=160 || m_LImage.m_nHeight<=160)
			blockSize = 10;
		else if(m_LImage.m_nWidth<=400 || m_LImage.m_nHeight<=400)
			blockSize = 20;
		else
			blockSize = 30;

		blockNum_w = m_LImage.m_nWidth/blockSize;	//ÿ����ΪblockSize��blockSize��������
		blockNum_h = m_LImage.m_nHeight/blockSize;

		int **LanArrow = new int *[blockNum_h];
		for(int k=0;k<blockNum_h;k++)
		{
			LanArrow[k] = new int [blockNum_w];
		}

		for(int i=0;i<blockNum_h;i++)
			for(int j=0;j<blockNum_w;j++)
			{
				LanArrow[i][j] = 0;
			}

		srand( (unsigned)time( NULL ) );

		while( m_count < blockNum_h*blockNum_w )
		{
			int x = rand()%blockNum_w;	//�����ȡˮƽ�����ϵ�x�飬����x��
			int y = rand()%blockNum_h;	//�����ȡ��ֱ�����ϵ�y�飬����y��
			while(LanArrow[y][x] == 1)	//�ÿ��ѻ�����
			{
				 x = rand()%blockNum_w;
				 y = rand()%blockNum_h;
			}
			LanArrow[y][x] = 1;
			m_count++;
			m_LImage.Draw(pDC->GetSafeHdc(),
						  int(m_Llower_rate*blockSize*x)+m_showX,
						  int(m_Llower_rate*blockSize*y)+m_showY,
						  int(m_Llower_rate*blockSize),
						  int(m_Llower_rate*blockSize),
						  blockSize*x,blockSize*y,blockSize,blockSize);
			Delay(1);
		}
		
		for (int n=0; n<blockNum_h; n++)
			delete [blockNum_w] LanArrow[n];
		delete [blockNum_h] LanArrow;

		//�����ű�����Ϊ1ʱ��������ǿ��ȡ����ʹͼƬ����ʱ���ֿհ���,
		//�ҵ�ͼƬ�Ŀ��߲���ǡ�÷�Ϊ8��8�Ŀ�ʱ,����ѭ������߽紦���в���δ����ʾ,
		//������������ȥ.
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
}

//************ 2.�������� ***************//
void	CPictViewView::Effect_Fromtop(CDC *pDC, int transform)
{
		for ( transform=0;transform<=m_LImage.m_nHeight;transform+=12 )
		{
			if((m_LImage.m_nHeight-transform)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),	//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
			else
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
						  int(m_Llower_rate*m_LImage.m_nWidth),
						  int(m_Llower_rate*transform),
						  0,m_LImage.m_nHeight-transform,m_LImage.m_nWidth,transform);
			Delay(10);
 		}
}

//************ 3.�������� ***************//
void	CPictViewView::Effect_Frombottom(CDC *pDC, int transform)
{
		for( transform=0;transform<=m_LImage.m_nHeight;transform+=12 )
		{
			if((m_LImage.m_nHeight-transform)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),	//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
			else
				m_LImage.Draw(pDC->GetSafeHdc(),
						  m_showX,
						  int((m_LImage.m_nHeight-transform)*m_Llower_rate)+m_showY,
						  int(m_Llower_rate*m_LImage.m_nWidth),
						  int(m_Llower_rate*transform),
						  0,0,m_LImage.m_nWidth,transform);
			Delay(10);
		}
}

//************ 4.�������� ***************//
void	CPictViewView::Effect_Fromleft(CDC *pDC, int transform)
{
		for ( transform=0;transform<=m_LImage.m_nWidth;transform+=12 )
		{
			if((m_LImage.m_nWidth-transform)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),	//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
			else
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
						  int(m_Llower_rate*transform),
						  int(m_Llower_rate*m_LImage.m_nHeight),
						  m_LImage.m_nWidth-transform,0,
						  transform,m_LImage.m_nHeight);
			Delay(10);
		}
}

//************ 5.�������� ***************//
void	CPictViewView::Effect_Fromright(CDC *pDC, int transform)
{
		for ( transform=0;transform<=m_LImage.m_nWidth;transform+=12 )
		{
			if((m_LImage.m_nWidth-transform)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
				m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),	//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
			else
				m_LImage.Draw(pDC->GetSafeHdc(),
						  int((m_LImage.m_nWidth-transform)*m_Llower_rate)+m_showX,
						  m_showY,
						  int(m_Llower_rate*transform),
						  int(m_Llower_rate*m_LImage.m_nHeight),
						  0,0,transform,m_LImage.m_nHeight);
			Delay(10);
		}	
}

//************ 6.�����Ͻǽ��� ***************//
void	CPictViewView::Effect_Fromtopleft(CDC *pDC, int transform_w, int transform_h)
{
		if (m_LImage.m_nWidth > m_LImage.m_nHeight)
		{
			transform_w+=12;	//(1)
			transform_h+=9;
			while(transform_w<m_LImage.m_nWidth)
			{
//				transform_w+=12;	//����ı�transform�������������������ʱ�����while�ж�ʱtransform
//				transform_h+=9;		//С��m_Limage.m_nWidth,������ѭ��transform�������Ӻ��ѳ���m_nWidth
									//��ʹ����Draw������m_LImage.m_nWidth-transform_wΪ��ֵ,�Ӷ�����Crash
									//��ȥ���˴����ж�����(1)��(2)����.��ͬ��
				if((m_LImage.m_nWidth-transform_w)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_h>=m_LImage.m_nHeight )
						transform_h=m_LImage.m_nHeight;
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
								int(m_Llower_rate*transform_w),
								int(m_Llower_rate*transform_h),
								m_LImage.m_nWidth-transform_w,m_LImage.m_nHeight-transform_h,
								transform_w,transform_h);
				}
				Delay(10);
				transform_w+=12;	//(2)
				transform_h+=9;
			}
		}
		else
		{
			transform_w+=9;
			transform_h+=12;
			while(transform_h<m_LImage.m_nHeight)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nHeight-transform_h)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_w>=m_LImage.m_nWidth )
						transform_w=m_LImage.m_nWidth;
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
								  int(m_Llower_rate*transform_w),
								  int(m_Llower_rate*transform_h),
								  m_LImage.m_nWidth-transform_w,
								  m_LImage.m_nHeight-transform_h,
								  transform_w,transform_h);
				}
				Delay(10);
				transform_w+=9;
				transform_h+=12;
			}
		}
}

//************ 7.�����Ͻǽ��� ***************//
void	CPictViewView::Effect_Fromtopright(CDC *pDC, int transform_w, int transform_h)
{
		if (m_LImage.m_nWidth > m_LImage.m_nHeight)
		{
			transform_w+=12;
			transform_h+=9;
			while(transform_w<m_LImage.m_nWidth)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nWidth-transform_w)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_h>=m_LImage.m_nHeight )
						transform_h=m_LImage.m_nHeight;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  int((m_LImage.m_nWidth-transform_w)*m_Llower_rate)+m_showX,
							  m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  0,m_LImage.m_nHeight-transform_h,
							  transform_w,transform_h);
				}
				Delay(10);
				transform_w+=12;
				transform_h+=9;
			}
		}
		else
		{
			transform_w+=9;
			transform_h+=12;
			while(transform_h<m_LImage.m_nHeight)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nHeight-transform_h)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_w>=m_LImage.m_nWidth )
						transform_w=m_LImage.m_nWidth;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  int((m_LImage.m_nWidth-transform_w)*m_Llower_rate+m_showX),
							  m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  0,m_LImage.m_nHeight-transform_h,
							  transform_w,transform_h);
				}
				Delay(10);
				transform_w+=9;
				transform_h+=12;
			}
		}
}

//************ 8.�����½ǽ��� ***************//
void	CPictViewView::Effect_Frombottomleft(CDC *pDC, int transform_w, int transform_h)
{
		if (m_LImage.m_nWidth >= m_LImage.m_nHeight)
		{
			transform_w+=12;
			transform_h+=9;
			while(transform_w<m_LImage.m_nWidth)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nWidth-transform_w)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_h>=m_LImage.m_nHeight )
						transform_h=m_LImage.m_nHeight;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  m_showX,
							  int((m_LImage.m_nHeight-transform_h)*m_Llower_rate)+m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  m_LImage.m_nWidth-transform_w,0,
							  transform_w,transform_h);
				}
				Delay(10);
				transform_w+=12;
				transform_h+=9;
			}
		}
		else
		{
			transform_w+=9;
			transform_h+=12;
			while(transform_h<m_LImage.m_nHeight)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nHeight-transform_h)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_w>=m_LImage.m_nWidth )
						transform_w=m_LImage.m_nWidth;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  m_showX,
							  int((m_LImage.m_nHeight-transform_h)*m_Llower_rate)+m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  m_LImage.m_nWidth-transform_w,0,
							  transform_w,transform_h);
				}
				Delay(10);
				transform_w+=9;
				transform_h+=12;
			}
		}
}

//************ 9.�����½ǽ���  ***************//
void	CPictViewView::Effect_Frombottomright(CDC *pDC, int transform_w, int transform_h)
{
		if (m_LImage.m_nWidth >= m_LImage.m_nHeight)
		{
			transform_w+=12;
			transform_h+=9;
			while(transform_w<m_LImage.m_nWidth)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nWidth-transform_w)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_h>=m_LImage.m_nHeight )
						transform_h=m_LImage.m_nHeight;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  int((m_LImage.m_nWidth-transform_w)*m_Llower_rate)+m_showX,
							  int((m_LImage.m_nHeight-transform_h)*m_Llower_rate)+m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  0,0,transform_w,transform_h);
				}
				Delay(10);
				transform_w+=12;
				transform_h+=9;
			}
		}
		else
		{
			transform_w+=9;
			transform_h+=12;
			while(transform_h<m_LImage.m_nHeight)
			{
//				transform_w+=12;
//				transform_h+=9;
				if((m_LImage.m_nHeight-transform_h)<12)				//��ʣ��δ��ʾ�Ĳ��ֲ���12ʱ����ζ��
					m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,//�������һ��Draw�ˣ��ʲ�����������
						  int(m_Llower_rate*m_LImage.m_nWidth),		//else�еĺ����ˣ���������ͼƬ���
						  int(m_Llower_rate*m_LImage.m_nHeight),	//һ����ʾ������.
						  0,0,
						  m_LImage.m_nWidth,m_LImage.m_nHeight);
				else
				{
					if ( transform_w>=m_LImage.m_nWidth )
						transform_w=m_LImage.m_nWidth;
					m_LImage.Draw(pDC->GetSafeHdc(),
							  int((m_LImage.m_nWidth-transform_w)*m_Llower_rate)+m_showX,
							  int((m_LImage.m_nHeight-transform_h)*m_Llower_rate)+m_showY,
							  int(m_Llower_rate*transform_w),
							  int(m_Llower_rate*transform_h),
							  0,0,transform_w,transform_h);
				}
				Delay(10);
				transform_w+=9;
				transform_h+=12;
			}
		}
}

//************ 10.��Ҷ�� ***************//
void	CPictViewView::Effect_Blinds(CDC *pDC)
{
		int m=1,n=1;
		while(n<=18 && m<=18)
		{
			if(m_LImage.m_nWidth%m==0)
				n = m;
			m++;
		}

		if(n == 1)			//n=1˵���Ը�ͼƬ��1��18��û���ҵ������������ȵ�����
		{					//��ô���� ���� ʹ��������С ������
			m = 2;
			n = 2;
			while(m<=18)
			{
				if((m_LImage.m_nWidth%m) <= (m_LImage.m_nWidth%n))
					n = m;
				m++;
			}
		}

		for( int i=0;i<=m_LImage.m_nWidth/n;i+=1 )
		{
			for(int j=0;j<=(n-1);j++)
			{
				m_LImage.Draw(pDC->GetSafeHdc(),
							  int((m_LImage.m_nWidth*j/n)*m_Llower_rate)+m_showX,m_showY,
							  int(i*m_Llower_rate),int(m_LImage.m_nHeight*m_Llower_rate),
							  int(m_LImage.m_nWidth*j/n),0,		//�˴�֮ǰδ��int,�����Release���г���Crash
							  i,m_LImage.m_nHeight);
			}
			Delay(10);
		}
		//�����ű�����Ϊ1ʱ��������ǿ��ȡ����ʹͼƬ����ʱ���ֿհ���,��ʱ�ô˷���ȥ���д��Ľ�
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
}

//******** [�ڴ���Ч]-ˮƽ��Ҷ�� *************//
void CPictViewView::Effect_Blinds_H_Mem()
{
	int iSrcWidth = m_LImage.m_nWidth;
	int iSrcHeight = m_LImage.m_nHeight;
	//int iBitCount = m_LImage.m_nBitCount;
	int iSrcRowBytes = m_LImage.m_nPitch;
	int iBlindHeight = 0;	//ˮƽ��Ҷ��һ���ĸ߶�
	int i,j,k;

	if(iSrcWidth<=160 || iSrcHeight<=160)
		iBlindHeight = 10;
	else
		iBlindHeight = 20;

	int iBlindNum =			//һ��ͼ��ֳɵ�����
		((iSrcHeight % iBlindHeight == 0) ? iSrcHeight / iBlindHeight : (iSrcHeight / iBlindHeight + 1));

	CDC* pDC = GetDC();

	//����ԭʼͼ��
	BYTE *pOriginImage = new BYTE[m_LImage.m_nImage];
	CopyMemory(pOriginImage,m_LImage.m_pImage,m_LImage.m_nImage);

	//��ͼ��任,һ����һ���ֽ�,�Բ�ͬBitCount��ͼ�������
	//��������:
	for(i = 0;i < iBlindHeight;i++)
	{
		for(j = 0 ;j < iBlindNum;j++)
		{
			for(k = 0;k < iSrcRowBytes; k++)
			{
				//����߽粻��һ���������
				if( (j * iBlindHeight + i) * iSrcRowBytes + k > m_LImage.m_nImage )
					continue;
				m_LImage.m_pImage[(j * iBlindHeight + i) * iSrcRowBytes + k] = 255;//��Ϊ��ɫ
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(100);
	}

	//�𽥻ָ�:
	for(i = 0;i < iBlindHeight;i++)
	{
		for(j = 0 ;j < iBlindNum;j++)
		{
			for(k = 0;k < iSrcRowBytes; k++)
			{
				//����߽粻��һ���������
				if( (j * iBlindHeight + i) * iSrcRowBytes + k > m_LImage.m_nImage )
					continue;
				CopyMemory(&m_LImage.m_pImage[(j * iBlindHeight + i) * iSrcRowBytes + k],
					       &pOriginImage[(j * iBlindHeight + i) * iSrcRowBytes + k],1);
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(100);
	}

	delete [] pOriginImage;
	pOriginImage = NULL;
	
}

//************** [�ڴ���Ч]-��ֱ��Ҷ�� ****************//
// ---- ��ֱ��Ҷ��Ҫ���ǲ�ͬBitCount����� ------------//
void CPictViewView::Effect_Blinds_V_Mem()
{
	int iSrcWidth = m_LImage.m_nWidth;
	int iSrcHeight = m_LImage.m_nHeight;
	int iBitCount = m_LImage.m_nBitCount;
	int iSrcRowBytes = m_LImage.m_nPitch;
	int iBlindWidth = 16;	//��ֱ��Ҷ��һ���Ŀ��,��Ϊ16���ظ������ʺϲ�ͬBitCount��ͼ��
							//�����ˮƽ��Ҷ����ͬ
	int i,j,k;

	int iBlindNum =			//һ��ͼ��ֳɵ�����
		((iSrcWidth % iBlindWidth == 0) ? iSrcWidth / iBlindWidth : (iSrcWidth / iBlindWidth + 1));

	int iBytesPerPixel = ( (iBitCount>8) ? iBitCount/8 : 1 );//һ������ռ���ֽ�����1��4λ�Ĳ��ÿ���,��Ϊ1
	int iBytesPerBlind;		//��Ҷ��һ�����ռ�õ��ֽ���
	switch(iBitCount)
	{
		case 1:
			iBytesPerBlind = 2;
			break;
		case 4:
			iBytesPerBlind = 8;
			break;
		case 8:
			iBytesPerBlind = 16;
			break;
		case 16:
			iBytesPerBlind = 32;
			break;
		case 24:
			iBytesPerBlind = 48;
			break;
		case 32:
			iBytesPerBlind = 64;
			break;
	}

	CDC* pDC = GetDC();

	//����ԭʼͼ��
	BYTE *pOriginImage = new BYTE[m_LImage.m_nImage];
	CopyMemory(pOriginImage,m_LImage.m_pImage,m_LImage.m_nImage);

	//��ͼ��任,1��4λ��һ�α�һ���ֽڣ�Ҳ���Ƿֱ��8��2�����أ���������һ�α�һ������
	//������1λ��4λ��ʱ���ٶȱ�������Ҫ��
	//��������:
	for(i = 0;i < iBytesPerBlind;)
	{
		for(j = 0;j < iBlindNum;j++)
		{
			for(k = 0;k < iSrcHeight; k++)
			{
				//�������ұ߽粻��һ���������
				if( j*iBytesPerBlind+i > iSrcRowBytes )
					continue;
				memset(&m_LImage.m_pImage[k*iSrcRowBytes+j*iBytesPerBlind+i],255,iBytesPerPixel);//��Ϊ��ɫ
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);

			Delay(100);

		i+=iBytesPerPixel;
	}

	//�𽥻ָ�:
	for(i = 0;i < iBytesPerBlind;)
	{
		for(j = 0;j < iBlindNum;j++)
		{
			for(k = 0;k < iSrcHeight; k++)
			{
				//�������ұ߽粻��һ���������
				if( j*iBytesPerBlind+i > iSrcRowBytes )
					continue;
				CopyMemory(&m_LImage.m_pImage[k*iSrcRowBytes+j*iBytesPerBlind+i],
							&pOriginImage[k*iSrcRowBytes+j*iBytesPerBlind+i],iBytesPerPixel);
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);

			Delay(100);

		i+=iBytesPerPixel;
	}

	delete [] pOriginImage;
	pOriginImage = NULL;
}

//******** [�ڴ���Ч]-������ ***********//
void CPictViewView::Effect_Mosaic_Mem()
{
	int  iSrcWidth     = m_LImage.m_nWidth;
	int  iSrcHeight    = m_LImage.m_nHeight;
	int  iBitCount     = m_LImage.m_nBitCount;
	int  iSrcRowBytes  = m_LImage.m_nPitch;
	int  iBytesNum     = iBitCount * 4; //32 * iBitCount / 8
	CDC *pDC = GetDC();
	//�ȱ���Դ����
	BYTE* pOriginImage = new BYTE[m_LImage.m_nImage];
	CopyMemory(pOriginImage,m_LImage.m_pImage,m_LImage.m_nImage);

	int nCount = 0;
	int i,j;
	//32��32����Ϊһ��
	int nWidthCount  = ((iSrcRowBytes % iBytesNum==0) ? iSrcRowBytes / iBytesNum : (iSrcRowBytes /iBytesNum + 1)); 
	int nHeightCount = ((iSrcHeight % 32==0) ? iSrcHeight / 32 : (iSrcHeight/32 + 1));

	int **ImageArray = new int *[nHeightCount];
	for(int k=0;k<nHeightCount;k++)
	{
		ImageArray[k] = new int [nWidthCount];
	}

	for(i=0;i<nHeightCount;i++)
		for(j=0;j<nWidthCount;j++)
	{
		ImageArray[i][j] = 0;
	}

	//1.��ͼƬתΪ��ɫ
	srand( (unsigned)time( NULL ) );
	while ( nCount < nWidthCount * nHeightCount)
	{
		int x = rand() % nHeightCount;
		int y = rand() % nWidthCount;

		while(ImageArray[x][y] == 1)
		{
			x = rand()% nHeightCount;
			y = rand()% nWidthCount;
		}

		ImageArray[x][y] = 1;
		nCount++;

		//�ı�m_pImage��ֵ
		for(i = 0;i < 32 ;i++)
		{
			for(j = 0;j<iBytesNum; j++)
			{	
				//�����Ե��������ͼƬ����32�ı�����ʱ��Ҫ�����ر���
				//1.�������
				if((iSrcWidth%32!=0)&&(y == nWidthCount-1)&&(iSrcRowBytes % iBytesNum - 1<j))
					continue;
				//2.��������
				if((iSrcHeight%32 !=0)&&(x == nHeightCount-1)&&((iSrcHeight%32-1)<i))
					continue;
				*(m_LImage.GetLine((x * 32 + i)) + y * iBytesNum + j) = 255;
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);

		Delay(10);
	}

	//2.��ͼƬתΪԭɫ
	nCount = 0;
	while ( nCount < nWidthCount * nHeightCount)
	{
		int x = rand() % nHeightCount;
		int y = rand() % nWidthCount;

		while(ImageArray[x][y] == 0)
		{
			x = rand()% nHeightCount;
			y = rand()% nWidthCount;
		}

		ImageArray[x][y] = 0;
		nCount++;

		//�ı�m_pImage��ֵ
		for(i = 0;i < 32;i++)
		{
			for(j = 0;j <iBytesNum; j++)
			{	
				//�����Ե��������ͼƬ����32�ı�����ʱ��һ��Ҫ����
				//1.�������
				if((iSrcWidth % 32 !=0)&&(y == nWidthCount-1)&&(iSrcRowBytes % iBytesNum - 1<j))
					continue;
				//2.��������
				if((iSrcHeight%32 !=0)&&(x == nHeightCount-1)&&((iSrcHeight%32- 1)<i))
					continue;
				m_LImage.m_pImage[(x * 32 + i)*iSrcRowBytes + y * iBytesNum + j] = 
					pOriginImage[(x * 32 + i)*iSrcRowBytes + y * iBytesNum + j];
			}
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);

		Delay(10);
	}
	//����ȷ������������
	for(k=0;k<nHeightCount;k++)
	{
		delete []ImageArray[k];
	}
	delete ImageArray;
	delete [] pOriginImage;
}

//******** [�ڴ���Ч]-����ɨ�� ***********//
void CPictViewView::Effect_ScanFromTop_Mem()
{
	int iSrcWidth = m_LImage.m_nWidth;
	int iSrcHeight = m_LImage.m_nHeight;
	int iSrcRowBytes = m_LImage.m_nPitch;
	int i,j;

	CDC* pDC = GetDC();

	//����ԭʼͼ��
	BYTE *pOriginImage = new BYTE[m_LImage.m_nImage];
	CopyMemory(pOriginImage,m_LImage.m_pImage,m_LImage.m_nImage);

	//��ɨ������:[ע��DIB�洢���������ϵ�!!]
	for(i=iSrcHeight-1;i>=0;i--)
	{
		for(j=0;j<iSrcRowBytes;j++)
		{
			m_LImage.m_pImage[i*iSrcRowBytes+j] = 255;	//��Ϊ��ɫ
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(10);
	}
	//��ɨ��ָ�:
	for(i=iSrcHeight-1;i>=0;i--)
	{
		for(j=0;j<iSrcRowBytes;j++)
		{
			m_LImage.m_pImage[i*iSrcRowBytes+j] = pOriginImage[i*iSrcRowBytes+j];	//��Ϊ��ɫ
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(10);
	}

	delete [] pOriginImage;
	pOriginImage = NULL;
}

//******** [�ڴ���Ч]-����ɨ�� ***********//
void CPictViewView::Effect_ScanFromBottom_Mem()
{
	int iSrcWidth = m_LImage.m_nWidth;
	int iSrcHeight = m_LImage.m_nHeight;
	int iSrcRowBytes = m_LImage.m_nPitch;
	int i,j;

	CDC* pDC = GetDC();

	//����ԭʼͼ��
	BYTE *pOriginImage = new BYTE[m_LImage.m_nImage];
	CopyMemory(pOriginImage,m_LImage.m_pImage,m_LImage.m_nImage);

	//��ɨ������:[ע��DIB�洢���������ϵ�!!]
	for(i=0;i<iSrcHeight;i++)
	{
		for(j=0;j<iSrcRowBytes;j++)
		{
			m_LImage.m_pImage[i*iSrcRowBytes+j] = 255;	//��Ϊ��ɫ
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(10);
	}
	//��ɨ��ָ�:
	for(i=0;i<iSrcHeight;i++)
	{
		for(j=0;j<iSrcRowBytes;j++)
		{
			m_LImage.m_pImage[i*iSrcRowBytes+j] = pOriginImage[i*iSrcRowBytes+j];	//��Ϊ��ɫ
		}
		m_LImage.Draw(pDC->GetSafeHdc(),m_showX,m_showY,
				int(m_Llower_rate*m_LImage.m_nWidth),int(m_Llower_rate*m_LImage.m_nHeight),
				0,0,m_LImage.m_nWidth,m_LImage.m_nHeight);
		Delay(10);
	}

	delete [] pOriginImage;
	pOriginImage = NULL;
}

//******* ������ƶ�ʱ��ʾ���꼰ȫ��ʱ������ʾ������ ************//
void CPictViewView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	//CScrollView::OnMouseMove(nFlags, point);
	CString str;
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	//������ƶ�ʱ��ʾ����
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	if(pStatus)
	{
		str.Format("X = %d , Y = %d",point.x,point.y);
		pStatus->SetPaneText(4,str);
	}
	//ȫ��ʱ������ʾ������
	if(pFrame->m_bFullScreen)
	{
		CRect HotRect;			//�˴������򲻿�̫С������Ҫ�ȸ����������Դ���Ϊ�������
		HotRect.left = 700;		//������ʱ���൱���������һ�������ڣ�������ס�Ĵ�����ʧЧ
		HotRect.right = 1028;	//��������͸���������һ��������С����ô���ж�����Ƿ��ڴ�
		HotRect.top = -5;		//����ʱ�������⡣
		HotRect.bottom = 80;	//
		if(HotRect.PtInRect(point))	//������Ƶ���������ʱ
		{
			if(!pFrame->m_bIsFullBarShowed)	//��������δ��ʾ������ʾ����
			{
				pFrame->m_bIsFullBarShowed = TRUE;
				RECT	rectDesktop;
				RECT	FullScrnBarRect;
				::GetWindowRect(::GetDesktopWindow(), &rectDesktop);
				pFrame->m_pwndFullScrnBar->GetWindowRect(&FullScrnBarRect);
				int BarWidth = FullScrnBarRect.right - FullScrnBarRect.left;
				int BarPos_x = rectDesktop.right - rectDesktop.left - BarWidth - 10;
				pFrame->FloatControlBar(pFrame->m_pwndFullScrnBar,CPoint(BarPos_x,3));
				//AfxMessageBox("Bar Displayed!");//For Debuging Purpose.
			}
			else		//����������ʾ
			{
				if(pFrame->m_bTiming)
				{
					pFrame->StopTimer();		//ֹͣ��ʱ�����û��������ڹ�������
					//AfxMessageBox("Timer Killed!");//For Debuging Purpose.
					pFrame->m_bTiming = FALSE;
					//AfxMessageBox("m_bTiming FALSE!");//For Debuging Purpose.
				}
			}
		}
		else	//����겻�ڴ�������ʱ
		{
			if(pFrame->m_bIsFullBarShowed)		//������������ʾ
			{
				if(!pFrame->m_bTiming)		//��δ��ʼ��ʱ
				{
					pFrame->StartTimer();	//��ʼ��ʱ
					//AfxMessageBox("Timer Started!");//For Debuging Purpose.
					pFrame->m_bTiming = TRUE;
					//AfxMessageBox("m_bTiming TRUE!");//For Debuging Purpose.
				}
			}
		}
	}
}

// *********  ���� �ָ�ԭʼ��С(100%)  ********* //
void CPictViewView::OnZoomOriginal() 
{
	// TODO: Add your command handler code here
	m_Llower_rate = 1;
	m_LImage.m_nDrawWidth = m_LImage.m_nWidth;	//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = m_LImage.m_nHeight;
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoomOriginal(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  ���� �ʺ���Ļ��С ********* //
void CPictViewView::OnZoomFitscreen() 
{
	// TODO: Add your command handler code here
//	CRect rect;
//	GetClientRect(&rect);							//��ȡ�û�������
//	int iClientRectWidth = rect.right - rect.left;	//������
//	int iClientRectHeight = rect.bottom - rect.top;	//����߶�

	m_LImage.m_nDrawWidth = m_nWindowWidth - 4;	//�Ƚ���Ŵ�����(��ͻ���),�ټ�����߶�
	m_Llower_rate = float(m_LImage.m_nDrawWidth)/float(m_LImage.m_nWidth);
	m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*m_Llower_rate);
	m_showX = 0;
	m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;

	if(m_LImage.m_nDrawHeight>=m_nWindowHeight)	//�����ʱ�ó��ĸ߳����ͻ��������ø����¼���
	{
		m_LImage.m_nDrawHeight = m_nWindowHeight - 4;
		m_Llower_rate = float(m_LImage.m_nDrawHeight)/float(m_LImage.m_nHeight);
		m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*m_Llower_rate);
		m_showY = 0;
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	}

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoomFitscreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  ���� 50%  ********* //
void CPictViewView::OnZoomHalf() 
{
	// TODO: Add your command handler code here
	m_Llower_rate = 0.5;
	m_LImage.m_nDrawWidth = m_LImage.m_nWidth/2;	//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = m_LImage.m_nHeight/2;
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;						//�Ա����û�ѡ��ʹ����Ч��ʱ����������Ч��ʾ
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoomHalf(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  ���� 75%  ********* //
void CPictViewView::OnZoom75percent() 
{
	// TODO: Add your command handler code here
	m_Llower_rate = 0.75;
	m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*0.75);	//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*0.75);
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoom75percent(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  ���� 150%  ********* //
void CPictViewView::OnZoom150percent() 
{
	// TODO: Add your command handler code here
	m_Llower_rate = 1.5;
	m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*1.5);	//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*1.5);
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoom150percent(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  ���� 200%  ********* //
void CPictViewView::OnZoomDouble() 
{
	// TODO: Add your command handler code here
	m_Llower_rate = 2;
	m_LImage.m_nDrawWidth = m_LImage.m_nWidth*2;	//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = m_LImage.m_nHeight*2;
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoomDouble(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"�𽥷Ŵ�"  ********* //
void CPictViewView::OnZoomIn() 
{
	// TODO: Add your command handler code here
	m_Llower_rate += 0.1f;
	m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*m_Llower_rate);//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
	m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*m_Llower_rate);
	if(m_LImage.m_nDrawWidth<m_nWindowWidth)
		m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
	else 
		m_showX = 0;
	if(m_LImage.m_nDrawHeight<m_nWindowHeight)
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
	else
		m_showY = 0;

	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();									//֪ͨWindow����Ҫ�ػ�
}

void CPictViewView::OnUpdateZoomIn(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"����С"  ********* //
void CPictViewView::OnZoomOut() 
{
	// TODO: Add your command handler code here
	m_Llower_rate -= 0.1f;
	if(m_Llower_rate>0)
	{
		m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*m_Llower_rate);//ʹ��ʾ��߸������ű����仯��Ϊ�����ź����ܾ�����ʾ
		m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*m_Llower_rate);
		if(m_LImage.m_nDrawWidth<m_nWindowWidth)
			m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
		else 
			m_showX = 0;
		if(m_LImage.m_nDrawHeight<m_nWindowHeight)
			m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
		else
			m_showY = 0;

		//����״̬��"��ʾ����"
		CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
		CStatusBar *pStatus = &pFrame->m_wndStatusBar;
		CString sDisplayRate;
		sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
		pStatus->SetPaneText(1,sDisplayRate);

		m_bIsDrawFirstTime = TRUE;
		Invalidate();									//֪ͨWindow����Ҫ�ػ�
	}
}

void CPictViewView::OnUpdateZoomOut(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir || m_Llower_rate<0)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"���Ч��"  ********* //
void CPictViewView::OnEffectRandom() 
{
	// TODO: Add your command handler code here
	if(m_IsRandomEffect)			//"���Ч��"�˵����൱�ڸ�ѡ��ÿ���һ��״̬�ı�һ�Σ�
	{								//����Ч���˵����򵥻�ֻ��ѡ�������ܷ�ѡ����
		m_IsRandomEffect = FALSE;
		m_EffectNum = Mosaic;		//��ʹ�����Ч��ʱ����Ĭ��ָ��Ϊ������Ч��
	}
	else
		m_IsRandomEffect = TRUE;
}

void CPictViewView::OnUpdateEffectRandom(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(m_IsRandomEffect)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"������"  ********* //
void CPictViewView::OnEffectMosaic() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = Mosaic;
}

void CPictViewView::OnUpdateEffectMosaic(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(Mosaic == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��Ҷ��"  ********* //
void CPictViewView::OnEffectBlinds() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = Blinds;
}

void CPictViewView::OnUpdateEffectBlinds(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(Blinds == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��������"  ********* //
void CPictViewView::OnEffectTopdown() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = fromtop;
}

void CPictViewView::OnUpdateEffectTopdown(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(fromtop == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��������"  ********* //
void CPictViewView::OnEffectBottomup() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = frombottom;
}

void CPictViewView::OnUpdateEffectBottomup(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(frombottom == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��������"  ********* //
void CPictViewView::OnEffectLeftright() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = fromleft;
}

void CPictViewView::OnUpdateEffectLeftright(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(fromleft == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��������"  ********* //
void CPictViewView::OnEffectRightleft() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = fromright;
}

void CPictViewView::OnUpdateEffectRightleft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(fromright == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"�����Ͻ���"  ********* //
void CPictViewView::OnEffectTopleft() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = fromtopleft;
}

void CPictViewView::OnUpdateEffectTopleft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(fromtopleft == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"�����½���"  ********* //
void CPictViewView::OnEffectBottomleft() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = frombottomleft;
}

void CPictViewView::OnUpdateEffectBottomleft(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(frombottomleft == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"�����Ͻ���"  ********* //
void CPictViewView::OnEffectTopright() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = fromtopright;
}

void CPictViewView::OnUpdateEffectTopright(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(fromtopright == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"�����½���"  ********* //
void CPictViewView::OnEffectBottomright() 
{
	// TODO: Add your command handler code here
	m_IsRandomEffect = FALSE;
	m_EffectNum = frombottomright;
}

void CPictViewView::OnUpdateEffectBottomright(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_IsNormalShow)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	if(frombottomright == m_EffectNum)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);
}

// *********  �˵�"��һ��"  ********* //
void CPictViewView::OnViewPrevious() 
{
	// TODO: Add your command handler code here
	char drive[_MAX_DRIVE];   
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];   
	char ext[_MAX_EXT];

	CPictViewDoc *pDoc=GetDocument();
	//-------------------------------------------------
	//�ѵ����һ��,�򷵻أ��������κβ�������Ϊ�����ǰ
	//��ʾ���ǵ�ǰĿ¼�б��еڶ���ͼƬ,����һ��ͼƬ�ϴ�
	//������ϳ�ʱ�䣬��һ�Ŵ��JPEG����ô�������������һ��
	//���ڻ�ͼ��δ��ɵ������(��ʱUI��δ���£��Կɽ�������)
	//�ֵ�һ�θð�ť����ᵼ�³����������Ϊ����Խ����
	if(pDoc->m_iCurrFileNum == 0)
		return;
	//-------------------------------------------------
	BOOL	bFind = FALSE;	//��־�Ƿ�ԭ���ġ���ǰ����������б����ҵ�				//*
	CString OriginalCurrent;															//*
	OriginalCurrent = pDoc->m_PicList[pDoc->m_iCurrFileNum];							//*
	pDoc->InitPicList(OriginalCurrent);				//�ؽ��б��Է�ֹ��ǰĿ¼���ļ��Ѹı�//*
	for(int i=0;i<=(pDoc->m_iFileNumber);i++)		//ȷ����ǰ�򿪵��ļ������б��е�λ��//*
	{												//�Եõ����б�����һ�ŵ�λ��		//*
		if(OriginalCurrent == pDoc->m_PicList[i])										//*
		{																				//*
			pDoc->m_iCurrFileNum = i;													//*
			bFind = TRUE;																//*
			break;																		//*
		}																				//*
	}																					//*
	if(bFind)
		pDoc->m_iCurrFileNum = pDoc->m_iCurrFileNum - 1;//�õ���һ��ͼ���ļ��б��е�λ��
	else
		pDoc->m_iCurrFileNum = 0;

	_splitpath(pDoc->m_PicList[pDoc->m_iCurrFileNum], drive, dir, fname, ext);

	CString sTitle;
	sTitle.Format("%s%s",fname,ext);	//�ڱ�������ʾ���ļ����ļ���
	pDoc->SetTitle(sTitle);
	CString sImageSize;					//Ϊ��״̬����ʾͼƬ�ߴ�
	CString sFileSize;					//Ϊ��״̬����ʾ�ļ���С
	CString sDisplayRate;				//Ϊ��״̬����ʾͼ��ǰ��ʾ����
	
	//##**##**********************************************
	//�ڴ�һ����ͼƬʱ�Ȼ�����һ��ͼƬ���ڴ棬���������ڴ�й©
	//����ϴ�δʹ��Lib Sources�еķ����������ڴ˻��գ�LanImage::Create()���Ѿ�����
	if(m_LImage.m_bReadWithLibSupport)
	{
		//��LanImage::LoadImage()�� m_pJpeg = new CJpeg()����Ŀռ�
		if(m_LImage.m_pJpeg != NULL)	//�ϴδ򿪵�ʱJPEG��ʽ
		{
			CJpeg * pTempJpeg = m_LImage.m_pJpeg;
			m_LImage.m_pJpeg = NULL;
			if(!m_LImage.m_bBufferIsOriginal)	//���й��任
				delete [] m_LImage.m_pImage;
			m_LImage.m_pImage = NULL;
			m_LImage.m_pOriginImage = NULL;
			delete pTempJpeg;
		}
		if(m_LImage.m_pGif != NULL)	//�ϴδ򿪵�ʱGIF��ʽ
		{
			CGif * pTempGif = m_LImage.m_pGif;
			m_LImage.m_pGif = NULL;
			if(!m_LImage.m_bBufferIsOriginal)	//���й��任
				delete [] m_LImage.m_pImage;
			m_LImage.m_pImage = NULL;
			m_LImage.m_pOriginImage = NULL;
			delete pTempGif;
		}
	}
	else
		m_LImage.Release();
	//***********************************************
	if (m_Isconvert)
	{
		if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,TRUE))
			return ;
	}
	if (!m_Isconvert)
	{
		if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,FALSE))
			return ;
	}

	m_LImage.m_bBufferIsOriginal = TRUE;
//	if(!m_LImage.m_bReadWithLibSupport)
//		m_LImage.Convert32();

	// **** �������ͼƬ��λ�ã�����ʾ��С **>>
	FitScreen();

	// **** ����״̬������ʾ����Ϣ���ļ�·�����ļ���С��ͼƬ��С ****
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������
	if(pStatus)
	{
		sImageSize.Format("����� = %d��%d",m_LImage.m_nWidth,m_LImage.m_nHeight);
		sFileSize.Format("%.1f KB",m_LImage.nFileSize/1024.0);
		sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
		pStatus->SetPaneText(0,pDoc->m_PicList[pDoc->m_iCurrFileNum]);
		pStatus->SetPaneText(1,sDisplayRate);
		pStatus->SetPaneText(2,sFileSize);
		pStatus->SetPaneText(3,sImageSize);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

	m_bIsDrawFirstTime=TRUE;
	Invalidate(TRUE);
}

void CPictViewView::OnUpdateViewPrevious(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CPictViewDoc *pDoc=GetDocument();
	if(pDoc->m_iCurrFileNum == 0 || pDoc->m_bIsEmptyDoc == TRUE)	//�Ѿ������һ��ͼƬ����ĵ�
		pCmdUI->Enable(FALSE);			//ע��:�ļ�ȫ��ɾ��ʱm_iCurrFileNum��Ϊ0����ViewNext��ͬ
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"��һ��"  ********* //
void CPictViewView::OnViewNext() 
{
	// TODO: Add your command handler code here
	char drive[_MAX_DRIVE];   
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];   
	char ext[_MAX_EXT];

	CPictViewDoc *pDoc=GetDocument();
	//-------------------------------------------------
	//�ѵ������һ��,�򷵻أ��������κβ�������Ϊ�����ǰ
	//��ʾ���ǵ�ǰĿ¼�б��е����ڶ���ͼƬ,�����һ��ͼƬ�ϴ�
	//������ϳ�ʱ�䣬��һ�Ŵ��JPEG����ô�������������һ��
	//���ڻ�ͼ��δ��ɵ������(��ʱUI��δ���£��Կɽ�������)
	//�ֵ�һ�θð�ť����ᵼ�³����������Ϊ����Խ����
	if(pDoc->m_iCurrFileNum == pDoc->m_iFileNumber)
		return;
	//--------------------------------------------------
	BOOL	bFind = FALSE;	//��־�Ƿ�ԭ���ġ���ǰ����������б����ҵ�				//*
	CString OriginalCurrent;															//*
	OriginalCurrent = pDoc->m_PicList[pDoc->m_iCurrFileNum];							//*
	pDoc->InitPicList(OriginalCurrent);				//�ؽ��б��Է�ֹ��ǰĿ¼���ļ��Ѹı�//*
	for(int i=0;i<=(pDoc->m_iFileNumber);i++)		//ȷ����ǰ�򿪵��ļ����б��е�λ��	//*
	{												//�Եõ����б�����һ�ŵ�λ��		//*
		if(OriginalCurrent == pDoc->m_PicList[i])										//*
		{																				//*
			pDoc->m_iCurrFileNum = i;													//*
			bFind = TRUE;																//*
			break;																		//*
		}																				//*
	}																					//*
	if(bFind)											//���ҵ�������ǰͼƬδ���Ƴ�
		pDoc->m_iCurrFileNum = pDoc->m_iCurrFileNum + 1;//�õ���һ��ͼ���ļ��б��е�λ��
	else												//δ�ҵ�������ǰͼƬ���Ƴ�
		pDoc->m_iCurrFileNum = 0;						//�����б��һ����ʾ

	_splitpath(pDoc->m_PicList[pDoc->m_iCurrFileNum], drive, dir, fname, ext);

	CString sTitle;
	sTitle.Format("%s%s",fname,ext);	//�ڱ�������ʾ���ļ����ļ���
	pDoc->SetTitle(sTitle);
	CString sImageSize;					//Ϊ��״̬����ʾͼƬ�ߴ�
	CString sFileSize;					//Ϊ��״̬����ʾ�ļ���С
	CString sDisplayRate;				//Ϊ��״̬����ʾͼ��ǰ��ʾ����
	
	//##**##**********************************************
	//�ڴ�һ����ͼƬʱ�Ȼ�����һ��ͼƬ���ڴ棬���������ڴ�й©
	//����ϴ�δʹ��Lib Sources�еķ����������ڴ˻��գ�LanImage::Create()���Ѿ�����
	if(m_LImage.m_bReadWithLibSupport)
	{
		//��LanImage::LoadImage()�� m_pJpeg = new CJpeg()����Ŀռ�
		if(m_LImage.m_pJpeg != NULL)	//�ϴδ򿪵�ʱJPEG��ʽ
		{
			CJpeg * pTempJpeg = m_LImage.m_pJpeg;
			m_LImage.m_pJpeg = NULL;
			if(!m_LImage.m_bBufferIsOriginal)	//���й��任
				delete [] m_LImage.m_pImage;
			m_LImage.m_pImage = NULL;
			m_LImage.m_pOriginImage = NULL;
			delete pTempJpeg;
		}
		if(m_LImage.m_pGif != NULL)	//�ϴδ򿪵�ʱGIF��ʽ
		{
			CGif * pTempGif = m_LImage.m_pGif;
			m_LImage.m_pGif = NULL;
			if(!m_LImage.m_bBufferIsOriginal)	//���й��任
				delete [] m_LImage.m_pImage;
			m_LImage.m_pImage = NULL;
			m_LImage.m_pOriginImage = NULL;
			delete pTempGif;
		}
	}
	else
		m_LImage.Release();
	//***********************************************
	if (m_Isconvert)
	{
		if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,TRUE))
			return ;
	}
	if (!m_Isconvert)
	{
		if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,FALSE))
			return ;
	}

	m_LImage.m_bBufferIsOriginal = TRUE;
//	if(!m_LImage.m_bReadWithLibSupport)
//		m_LImage.Convert32();

	// **** �������ͼƬ��λ�ã�����ʾ��С **>>
	FitScreen();

	// **** ����״̬������ʾ����Ϣ���ļ�·�����ļ���С��ͼƬ��С ****
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������
	if(pStatus)
	{
		sImageSize.Format("����� = %d��%d",m_LImage.m_nWidth,m_LImage.m_nHeight);
		sFileSize.Format("%.1f KB",m_LImage.nFileSize/1024.0);
		sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
		pStatus->SetPaneText(0,pDoc->m_PicList[pDoc->m_iCurrFileNum]);
		pStatus->SetPaneText(1,sDisplayRate);
		pStatus->SetPaneText(2,sFileSize);
		pStatus->SetPaneText(3,sImageSize);
	}
	else
		AfxMessageBox("Can not get StatusBar pointer!");

	m_bIsDrawFirstTime=TRUE;
	Invalidate(TRUE);
}

void CPictViewView::OnUpdateViewNext(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CPictViewDoc *pDoc=GetDocument();
	if(pDoc->m_iCurrFileNum == pDoc->m_iFileNumber || pDoc->m_bIsEmptyDoc == TRUE
		|| pDoc->m_iFileNumber < 0)	//�Ѿ��������һ��ͼƬ����ĵ����ļ�ȫ����ɾ��
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"ɾ��"  ********* //
void CPictViewView::OnEditDelete() 
{
	// TODO: Add your command handler code here
	char drive[_MAX_DRIVE];   
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];   
	char ext[_MAX_EXT];
	CString FromStr;

	CPictViewDoc *pDoc = GetDocument();
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������
	FromStr = pDoc->m_PicList[pDoc->m_iCurrFileNum];
	FromStr+='\0';
	SHFILEOPSTRUCT FileOp; 
	FileOp.hwnd = NULL; 
	FileOp.wFunc = FO_DELETE; 
	FileOp.pFrom = FromStr;//FromBuff; 
	FileOp.pTo = NULL; 
	FileOp.fFlags = FOF_ALLOWUNDO | FOF_NOERRORUI;
	FileOp.fAnyOperationsAborted = TRUE;
	FileOp.hNameMappings = NULL;
	FileOp.lpszProgressTitle = _T("����ɾ���ļ�����");
	::SHFileOperation( &FileOp );

	if(FileOp.fAnyOperationsAborted)	//���ɾ������ʾִ�У������ؽ��б�����Ĳ�������ִ��
		return;

	//ɾ��֮���ؽ��б�Ȼ�����ɾ�����ǵ�һ�ţ�������ʾ���ڵĵ�һ�ţ����ɾ�������һ��,
	//������ʾ���ڵ����һ�ţ����ɾ��������ͼƬ������ʾ����һ��(�������б��б�ɾͼƬ��λ��)
	pDoc->ReInitPicList();
	if(!(pDoc->m_iFileNumber < 0))	//�����һ��Ҳ��ɾ�������������ReInitPicList(),m_iFileNumber��Ϊ��
	{
		if(pDoc->m_iCurrFileNum == 0)							//ɾ�����ǵ�һ��
			pDoc->m_iCurrFileNum = 0;							//������ʾ���ڵĵ�һ��
		else if(pDoc->m_iCurrFileNum == pDoc->m_iFileNumber+1)	//ɾ�������һ��(ReInit��m_iFileNumber�Ѿ���1)
			pDoc->m_iCurrFileNum = pDoc->m_iCurrFileNum - 1;	//������ʾ���ڵ����һ��
		else													//ɾ���м��ͼƬ
			pDoc->m_iCurrFileNum = pDoc->m_iCurrFileNum;		//m_iCurrFileNum���ñ�
		_splitpath(pDoc->m_PicList[pDoc->m_iCurrFileNum], drive, dir, fname, ext);

		CString sTitle;
		sTitle.Format("%s%s",fname,ext);	//�ڱ�������ʾ���ļ����ļ���
		pDoc->SetTitle(sTitle);
		CString sImageSize;					//Ϊ��״̬����ʾͼƬ�ߴ�
		CString sFileSize;					//Ϊ��״̬����ʾ�ļ���С
		CString sDisplayRate;				//Ϊ��״̬����ʾͼ��ǰ��ʾ����
	
		//##**##**********************************************
		//�ڴ�һ����ͼƬʱ�Ȼ�����һ��ͼƬ���ڴ棬���������ڴ�й©
		//����ϴ�δʹ��Lib Sources�еķ����������ڴ˻��գ�LanImage::Create()���Ѿ�����
		if(m_LImage.m_bReadWithLibSupport)
		{
			//��LanImage::LoadImage()�� m_pJpeg = new CJpeg()����Ŀռ�
			if(m_LImage.m_pJpeg != NULL)	//�ϴδ򿪵�ʱJPEG��ʽ
			{
				CJpeg * pTempJpeg = m_LImage.m_pJpeg;
				m_LImage.m_pJpeg = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempJpeg;
			}
			if(m_LImage.m_pGif != NULL)	//�ϴδ򿪵�ʱGIF��ʽ
			{
				CGif * pTempGif = m_LImage.m_pGif;
				m_LImage.m_pGif = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempGif;
			}
		}
		else
			m_LImage.Release();
		//***********************************************
		if (m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,TRUE))
				return ;
		}
		if (!m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,FALSE))
				return ;
		}

		m_LImage.m_bBufferIsOriginal = TRUE;
//		if(!m_LImage.m_bReadWithLibSupport)
//			m_LImage.Convert32();

		// **** �������ͼƬ��λ�ã�����ʾ��С **>>
		FitScreen();

		// **** ����״̬������ʾ����Ϣ���ļ�·�����ļ���С��ͼƬ��С ****
		if(pStatus)
		{
			sImageSize.Format("����� = %d��%d",m_LImage.m_nWidth,m_LImage.m_nHeight);
			sFileSize.Format("%.1f KB",m_LImage.nFileSize/1024.0);
			sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
			pStatus->SetPaneText(0,pDoc->m_PicList[pDoc->m_iCurrFileNum]);
			pStatus->SetPaneText(1,sDisplayRate);
			pStatus->SetPaneText(2,sFileSize);
			pStatus->SetPaneText(3,sImageSize);
		}
		else
			AfxMessageBox("Can not get StatusBar pointer!");

		m_bIsDrawFirstTime=TRUE;
		Invalidate(TRUE);
	}
	else	//���һ�ű�ɾ����Ŀ¼Ϊ�գ���
	{
		pDoc->m_bIsEmptyDir = TRUE;
		pDoc->SetTitle("�ޱ���");
		pStatus->SetPaneText(0,"δ���κ�ͼ��");
		pStatus->SetPaneText(1,"");
		pStatus->SetPaneText(2,"");
		Invalidate(TRUE);
	}
}

void CPictViewView::OnUpdateEditDelete(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CPictViewDoc *pDoc=GetDocument();
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	if(pDoc->m_bIsEmptyDoc == TRUE || pDoc->m_iFileNumber < 0 || pFrame->m_bIsPlay)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"��Ĭ�ϳ����"  ********* //
void CPictViewView::OnEditExternal() 
{
	// TODO: Add your command handler code here
	CPictViewDoc* pDoc = GetDocument();

//	LPCTSTR ext = _tcsrchr(pDoc->m_PicList[pDoc->m_iCurrFileNum],_T('.'));
//	if((ext[1] =='b'||ext[1] =='B')&&(ext[2] =='m'||ext[2] =='M')
//	&&(ext[3] =='p'||ext[3] =='P'))
//	{
//		if(NULL== ShellExecute(NULL,"open","pDoc->m_PicList[pDoc->m_iCurrFileNum]",
//			NULL,"",SW_SHOW))
//		return ;
//	}
	CString Str;
	Str += '\"';	//��ֹ�ѿո����ָ����ĳ����޷�ʶ��·���к��ո���ļ���
	for(int i=0;i<(pDoc->m_PicList[pDoc->m_iCurrFileNum].GetLength());i++)
	{
		if(pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i) == '\\')	//SellExecute�������ļ�ȫ·���е�'\'������ת���ַ�
		{
			Str += pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i);
			Str += '\\';
		}
		else
		{
			Str += pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i);
		}
	}
	Str += '\"';	//��ֹ�ѿո����ָ����ĳ����޷�ʶ��·���к��ո���ļ���

	if(NULL== ShellExecute(NULL,"open",Str,NULL,NULL,SW_SHOW))
		return ;
}

void CPictViewView::OnUpdateEditExternal(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

// *********  �˵�"�û�ͼ�򿪲��༭"  ********* //
void CPictViewView::OnEditInMpaint() 
{
	// TODO: Add your command handler code here
	CPictViewDoc* pDoc = GetDocument();
	CString Str;
	Str += '\"';	//��ͼ���������ʱ�����ո�ᵱ���ָ��������粻�����ţ�������·�����пո���޷��򿪡�
	for(int i=0;i<(pDoc->m_PicList[pDoc->m_iCurrFileNum].GetLength());i++)
	{
		if(pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i) == '\\')	//SellExecute�������ļ�ȫ·���е�'\'������ת���ַ�
		{
			Str += pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i);
			Str += '\\';
		}
		else
		{
			Str += pDoc->m_PicList[pDoc->m_iCurrFileNum].GetAt(i);
		}
	}
	Str += '\"';

	if(NULL== ShellExecute(NULL,"open","mspaint.exe",Str,NULL,SW_SHOW))
		return ;
}

void CPictViewView::OnUpdateEditInMpaint(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//**** ��ESC���˳�ȫ������Ϣ������ *******
void CPictViewView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar==VK_ESCAPE)//������ļ�ΪEsc��
	{
		//��ȡ����ܴ��ڵ�ָ��
		CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
		//��������������Զ��庯�� EndFullScreen() ������˳�ȫ����ʾ״̬
		pFrame->EndFullScreen();
	}

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

//******* ��ʱ������(�õ�Ƭ����)���� ***********
void CPictViewView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == IDT_TIMER_PLAY)	//�ǻõ�Ƭ���Ŷ�ʱ��ʱ
	{
		CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;	//�������ܴ���
		if(FALSE == pFrame->m_bIsPlay)		//���жϲ��ű�־�����ΪFALSE��
		{									//˵���û��Ѱ�"ֹͣ"�������˳�ȫ��
			KillTimer(IDT_TIMER_PLAY);		//��ôKillTimer
			return;							//������
		}

		char drive[_MAX_DRIVE];   
		char dir[_MAX_DIR];
		char fname[_MAX_FNAME];   
		char ext[_MAX_EXT];

		CPictViewDoc *pDoc=GetDocument();

		if(pDoc->m_iCurrFileNum == pDoc->m_iFileNumber)		//���ѵ����һ�ţ�
			pDoc->m_iCurrFileNum = 0;						//�ӵ�һ�����¿�ʼ
		else												//����
			pDoc->m_iCurrFileNum = pDoc->m_iCurrFileNum + 1;//������һ��

		_splitpath(pDoc->m_PicList[pDoc->m_iCurrFileNum], drive, dir, fname, ext);

		CString sTitle;
		sTitle.Format("%s%s",fname,ext);	//�ڱ�������ʾ���ļ����ļ���
		pDoc->SetTitle(sTitle);
		CString sImageSize;					//Ϊ��״̬����ʾͼƬ�ߴ�
		CString sFileSize;					//Ϊ��״̬����ʾ�ļ���С
		CString sDisplayRate;				//Ϊ��״̬����ʾͼ��ǰ��ʾ����

		//##**##**********************************************
		//�ڴ�һ����ͼƬʱ�Ȼ�����һ��ͼƬ���ڴ棬���������ڴ�й©
		//����ϴ�δʹ��Lib Sources�еķ����������ڴ˻��գ�LanImage::Create()���Ѿ�����
		if(m_LImage.m_bReadWithLibSupport)
		{
			//��LanImage::LoadImage()�� m_pJpeg = new CJpeg()����Ŀռ�
			if(m_LImage.m_pJpeg != NULL)	//�ϴδ򿪵�ʱJPEG��ʽ
			{
				CJpeg * pTempJpeg = m_LImage.m_pJpeg;
				m_LImage.m_pJpeg = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempJpeg;
			}
			if(m_LImage.m_pGif != NULL)	//�ϴδ򿪵�ʱGIF��ʽ
			{
				CGif * pTempGif = m_LImage.m_pGif;
				m_LImage.m_pGif = NULL;
				if(!m_LImage.m_bBufferIsOriginal)	//���й��任
					delete [] m_LImage.m_pImage;
				m_LImage.m_pImage = NULL;
				m_LImage.m_pOriginImage = NULL;
				delete pTempGif;
			}
		}
		else
			m_LImage.Release();
		//***********************************************
		if (m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,TRUE))
				return ;
		}
		if (!m_Isconvert)
		{
			if(FALSE == m_LImage.LoadImage(pDoc->m_PicList[pDoc->m_iCurrFileNum],m_degree,FALSE))
				return ;
		}

		m_LImage.m_bBufferIsOriginal = TRUE;
//		if(!m_LImage.m_bReadWithLibSupport)
//			m_LImage.Convert32();

		// **** �������ͼƬ��λ�ã�����ʾ��С **>>
		FitScreen();

		// **** ����״̬������ʾ����Ϣ���ļ�·�����ļ���С��ͼƬ��С ****
		CStatusBar *pStatus = &pFrame->m_wndStatusBar;				//���״̬������
		if(pStatus)
		{
			sImageSize.Format("����� = %d��%d",m_LImage.m_nWidth,m_LImage.m_nHeight);
			sFileSize.Format("%.1f KB",m_LImage.nFileSize/1024.0);
			sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
			pStatus->SetPaneText(0,pDoc->m_PicList[pDoc->m_iCurrFileNum]);
			pStatus->SetPaneText(1,sDisplayRate);
			pStatus->SetPaneText(2,sFileSize);
			pStatus->SetPaneText(3,sImageSize);
		}
		else
			AfxMessageBox("Can not get StatusBar pointer!");

		m_bIsDrawFirstTime=TRUE;
		Invalidate(TRUE);
	}//End if(nIDEvent == IDT_TIMER_PLAY)

	//CScrollView::OnTimer(nIDEvent);
}

//**** ȫ��������"��ʼ�õ�Ƭ" ****
void CPictViewView::OnPlay() 
{
	// TODO: Add your command handler code here
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pFrame->m_bIsPlay = TRUE;
	SetTimer(IDT_TIMER_PLAY,3000,NULL);
}

void CPictViewView::OnUpdatePlay(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CPictViewDoc *pDoc = GetDocument();
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir || pFrame->m_bIsPlay)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//**** ȫ��������"ֹͣ�õ�Ƭ" ****
void CPictViewView::OnPause() 
{
	// TODO: Add your command handler code here
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pFrame->m_bIsPlay = FALSE;
}

void CPictViewView::OnUpdatePause(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CPictViewDoc *pDoc = GetDocument();
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir || !(pFrame->m_bIsPlay))
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//****** ��䱳��ɫ *******
BOOL CPictViewView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	/*
	CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
	if(pFrame)	//��������ʱFrame��Ϊ�գ����ڴ˲����ж���ᱨ��
	{
		if(pFrame->m_bFullScreen)
		{
			CRect rect;
			CBrush brush;
			brush.CreateSolidBrush(RGB(0,0,0));
			pDC->GetClipBox(rect);
			pDC->FillRect(rect,&brush);
		}
		else
		{
			CRect rect;
			CBrush brush;
			brush.CreateSolidBrush(RGB(255,255,255));
			pDC->GetClipBox(rect);
			pDC->FillRect(rect,&brush);
		}
	}

	return TRUE;
	*/
	return CScrollView::OnEraseBkgnd(pDC);
}

// ****************** �Ҽ��˵� ***************************
void CPictViewView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu PopupMenu,*pPopup;
	PopupMenu.LoadMenu(IDR_POPUPMENU);
	pPopup = PopupMenu.GetSubMenu(0);

	/////��Popup Menu�����ս��������Ϣ��������û򲻿���״̬Ҫ���д���
	UINT uEnable;
	CPictViewDoc *pDoc=GetDocument();
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	//"��һ��"
	if(pDoc->m_iCurrFileNum == 0 || pDoc->m_bIsEmptyDoc == TRUE)//�Ѿ������һ��ͼƬ����ĵ�
	{								//ע��:�ļ�ȫ��ɾ��ʱm_iCurrFileNum��Ϊ0����ViewNext��ͬ
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_VIEW_PREVIOUS,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_VIEW_PREVIOUS,uEnable);
	}
	//"��һ��"
	if(pDoc->m_iCurrFileNum == pDoc->m_iFileNumber || pDoc->m_bIsEmptyDoc == TRUE
		|| pDoc->m_iFileNumber < 0)	//�Ѿ��������һ��ͼƬ����ĵ����ļ�ȫ����ɾ��
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_VIEW_NEXT,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_VIEW_NEXT,uEnable);
	}
	//"˳ʱ����ת90��"
	if(pDoc->m_bIsEmptyDoc == TRUE || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ROTATE90_CLOCKWISE,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ROTATE90_CLOCKWISE,uEnable);
	}
	//"��ʱ����ת90��"
	if(pDoc->m_bIsEmptyDoc == TRUE || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ROTATE90_ANTICLOCKWISE,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ROTATE90_ANTICLOCKWISE,uEnable);
	}
	//"�Ŵ�"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ZOOM_IN,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ZOOM_IN,uEnable);
	}
	//"��С"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir || m_Llower_rate<0)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ZOOM_OUT,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ZOOM_OUT,uEnable);
	}
	//"�ʺϴ�С"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ZOOM_FITSCREEN,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ZOOM_FITSCREEN,uEnable);
	}
	//"ԭʼ��С"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_ZOOM_ORIGINAL,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_ZOOM_ORIGINAL,uEnable);
	}
	//"��ʾˮƽ��Ҷ��"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_HBLINDS,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_HBLINDS,uEnable);
	}
	//"��ʾ��ֱ��Ҷ��"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_VBLINDS,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_VBLINDS,uEnable);
	}
	//"��ʾ������Ч��"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_MOSAIC,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_MOSAIC,uEnable);
	}
	//"��ʾ����ɨ��"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_SCANFROMBOTTOM,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_SCANFROMBOTTOM,uEnable);
	}
	//"��ʾ����ɨ��"
	if(pDoc->m_bIsEmptyDoc || pDoc->m_bIsEmptyDir)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_SCANFROMTOP,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EFFECT_MEM_SCANFROMTOP,uEnable);
	}
	//"ɾ��"
	if(pDoc->m_bIsEmptyDoc == TRUE || pDoc->m_iFileNumber < 0 || pFrame->m_bIsPlay)
	{
		uEnable = MF_BYCOMMAND|MF_GRAYED;
		pPopup->EnableMenuItem(ID_EDIT_DELETE,uEnable);
	}
	else
	{
		uEnable = MF_BYCOMMAND|MF_ENABLED;
		pPopup->EnableMenuItem(ID_EDIT_DELETE,uEnable);
	}
	//"ȫ��"
	MENUITEMINFO MInfo;
	MInfo.cbSize = sizeof(MENUITEMINFO);
	MInfo.fMask = MIIM_STATE;	//˵����Ҫ����fState
	if(pFrame->m_bFullScreen)
	{
		MInfo.fState = MFS_CHECKED;
		SetMenuItemInfo(pPopup->m_hMenu,ID_FULL_SCREEN,FALSE,&MInfo);
	}
	else
	{
		MInfo.fState = MFS_UNCHECKED;
		SetMenuItemInfo(pPopup->m_hMenu,ID_FULL_SCREEN,FALSE,&MInfo);
	}
	/////

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this);
}

// **** �Ҽ��˵���"ȫ��"���� ****
void CPictViewView::OnFullScreen() 
{
	// TODO: Add your command handler code here
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	pFrame->OnFullScreen();
}

//**** ����ʱ���ͼƬ�����ͻ�����������С�����ʴ�С ****
void CPictViewView::FitScreen()
{
	CRect rect;
	GetClientRect(&rect);							//��ȡ�û�������
	m_nWindowWidth = rect.right - rect.left;		//�����û������
	m_nWindowHeight = rect.bottom - rect.top;		//�����û����߶�

	//���ͼƬ�Ŀ�����һ�������û�����С�������ŵ��ʺϴ�С
	if( (m_LImage.m_nWidth >m_nWindowWidth) || (m_LImage.m_nHeight>m_nWindowHeight) )
	{
		m_LImage.m_nDrawWidth = m_nWindowWidth - 4;	//�Ƚ���Ŵ�����(��ͻ���),�ټ�����߶�
		m_Llower_rate = float(m_LImage.m_nDrawWidth)/float(m_LImage.m_nWidth);
		m_LImage.m_nDrawHeight = int(m_LImage.m_nHeight*m_Llower_rate);
		m_showX = 0;
		m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;

		if(m_LImage.m_nDrawHeight>=m_nWindowHeight)	//�����ʱ�ó��ĸ߳����ͻ��������ø����¼���
		{
			m_LImage.m_nDrawHeight = m_nWindowHeight - 4;
			m_Llower_rate = float(m_LImage.m_nDrawHeight)/float(m_LImage.m_nHeight);
			m_LImage.m_nDrawWidth = int(m_LImage.m_nWidth*m_Llower_rate);
			m_showY = 0;
			m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
		}
	}
	//��δ��������ԭʼ��С��ʾ
	else
	{
		m_LImage.m_nDrawWidth = m_LImage.m_nWidth;		//֮���Բ�ֱ��ʹ��m_nWidth��m_nHeight,��Ϊ��
		m_LImage.m_nDrawHeight = m_LImage.m_nHeight;	//���ı�ԭʼͼ�����ԣ��Ա����ź�������ȷ��ʾͼ��,
														//���ڴ˳�ʼ��m_nDrawWidth,m_nDrawHeight
		//ֻ�е���ʾ�Ŀ���С�ڿͻ������ʱ�ž��У�	
		//����ֱ�Ӵ����Ͻǿ�ʼ��ʾ.���������������λ�û᲻��ȷ
		//���ҵ���ʾ��С�����ͻ���ʱ����Ҳû�����塣
		if(m_LImage.m_nDrawWidth<m_nWindowWidth)
			m_showX = m_nWindowWidth/2 - m_LImage.m_nDrawWidth/2;
		else 
			m_showX = 0;
		if(m_LImage.m_nDrawHeight<m_nWindowHeight)
			m_showY = m_nWindowHeight/2 - m_LImage.m_nDrawHeight/2;
		else
			m_showY = 0;
		m_Llower_rate = 1.0;			//��ͼ��ʱ��ԭʼ��С��ʾ
	}
}

//********* ˳ʱ����ת90�� ***********
void CPictViewView::OnRotate90Clockwise() 
{
	// TODO: Add your command handler code here
	m_LImage.Rotate90Clockwise();
	FitScreen();
	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();
}

void CPictViewView::OnUpdateRotate90Clockwise(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//********* ��ʱ����ת90�� ***********
void CPictViewView::OnRotate90Anticlockwise() 
{
	// TODO: Add your command handler code here
	m_LImage.Rotate90Clockwise();
	m_LImage.Rotate90Clockwise();
	m_LImage.Rotate90Clockwise();
	FitScreen();
	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();
}

void CPictViewView::OnUpdateRotate90Anticlockwise(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//********* ��ת180�� ***********
void CPictViewView::OnRotate180() 
{
	// TODO: Add your command handler code here
	m_LImage.Rotate90Clockwise();
	m_LImage.Rotate90Clockwise();
	FitScreen();
	//����״̬��"��ʾ����"
	CMainFrame *pFrame = (CMainFrame *)AfxGetApp()->m_pMainWnd;
	CStatusBar *pStatus = &pFrame->m_wndStatusBar;
	CString sDisplayRate;
	sDisplayRate.Format("��ʾ����: %.3f",m_Llower_rate);
	pStatus->SetPaneText(1,sDisplayRate);

	m_bIsDrawFirstTime = TRUE;
	Invalidate();
}

void CPictViewView::OnUpdateRotate180(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}
//==================================================
// *****   ֱ����ʾ����Ч(��������Ч)   ****
//--------------------------------------------------
//*************  []��ֱ��Ҷ�� **************
void CPictViewView::OnEffectMemVblinds() 
{
	// TODO: Add your command handler code here
	Effect_Blinds_V_Mem();
}

void CPictViewView::OnUpdateEffectMemVblinds(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//*************  []ˮƽ��Ҷ�� **************
void CPictViewView::OnEffectMemHblinds() 
{
	// TODO: Add your command handler code here
	Effect_Blinds_H_Mem();
}

void CPictViewView::OnUpdateEffectMemHblinds(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//*************  []������ **************
void CPictViewView::OnEffectMemMosaic() 
{
	// TODO: Add your command handler code here
	Effect_Mosaic_Mem();
}

void CPictViewView::OnUpdateEffectMemMosaic(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

//*************  []����ɨ�� **************
void CPictViewView::OnEffectMemScanfromtop() 
{
	// TODO: Add your command handler code here
	Effect_ScanFromTop_Mem();
}

void CPictViewView::OnUpdateEffectMemScanfromtop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

////*************  []����ɨ�� **************
void CPictViewView::OnEffectMemScanfrombottom() 
{
	// TODO: Add your command handler code here
	Effect_ScanFromBottom_Mem();
}

void CPictViewView::OnUpdateEffectMemScanfrombottom(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(TRUE == ((CPictViewDoc *)GetDocument())->m_bIsEmptyDoc || 
		  ((CPictViewDoc *)GetDocument())->m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
}

