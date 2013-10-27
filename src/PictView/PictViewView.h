// PictViewView.h : interface of the CPictViewView class
//
/////////////////////////////////////////////////////////////////////////////

#include "ClassImage.h"

#if !defined(AFX_PICTVIEWVIEW_H__BB4309C9_B62C_497D_892E_7A9E9E5D99C5__INCLUDED_)
#define AFX_PICTVIEWVIEW_H__BB4309C9_B62C_497D_892E_7A9E9E5D99C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//��ʾЧ�����ų����Ķ���
enum {Mosaic = 1, fromtop, frombottom, fromleft, fromright,
	   fromtopleft, fromtopright, frombottomleft, frombottomright, Blinds};


class CPictViewView : public CScrollView
{
protected: // create from serialization only
	CPictViewView();
	DECLARE_DYNCREATE(CPictViewView)

// Attributes
public:
	CPictViewDoc* GetDocument();

// Operations
public:
	LanImage	m_LImage;
	float		m_Llower_rate;		//�����ı���
	int			m_EffectNum;		//Ч�����š�
	BOOL		m_IsRandomEffect;	//�Ƿ���Ҫʹ�������ȷ��Ч��
	int			m_showX,m_showY;	//�ƶ����Ƶ���λ��
	int			m_nWindowWidth;		//�ͻ������
	int			m_nWindowHeight;	//�ͻ����߶�
	int			m_degree;			//��ת�ĽǶ�,1:δ��ת,2:��ʱ��90��,3:˳ʱ��90��,4:��ת180��
	BOOL		m_IsNormalShow;		//�Ƿ���Ҫʹ����Ч��ʾ��ΪFALSEʱ��ʹ����Ч��ΪTUREʱ����ʹ����Ч��
	BOOL		m_Isconvert;		//m_Isconvert �����Ƿ��ڴ�ͼƬʱ����Ե���ת.��ʱδʹ��.
	BOOL		m_bIsDrawFirstTime;	//�Ƿ��һ�δ�һ��ͼ����л��ƣ�����ǣ������ʹ����Ч������ʹ����Ч��
									//���ⴰ����ÿ���ػ�ʱ��������Ч��ʾ��

	void		Degree_Normal(CDC *pDC);
	void		Degree_turnleft90(CDC *pDC);
	void		Degree_turnright90(CDC *pDC);
	void		Degree_turn180(CDC *pDC);
	void		Degree_leftright(CDC *pDC);
	void		Degree_topbottom(CDC *pDC);

	void		Effect_Mosaic(CDC *pDC);											//1:������Ч��
	void		Effect_Fromtop(CDC *pDC, int transform);							//2:��������
	void		Effect_Frombottom(CDC *pDC, int transform);							//3:��������
	void		Effect_Fromleft(CDC *pDC, int transform);							//4:��������
	void		Effect_Fromright(CDC *pDC, int transform);							//5:��������
	void		Effect_Fromtopleft(CDC *pDC, int transform_w, int transform_h);		//6:�����Ͻǽ���
	void		Effect_Fromtopright(CDC *pDC, int transform_w, int transform_h);	//7:�����Ͻǽ���
	void		Effect_Frombottomleft(CDC *pDC, int transform_w, int transform_h);	//8:�����½ǽ���
	void		Effect_Frombottomright(CDC *pDC, int transform_w, int transform_h);	//9:�����½ǽ���
	void		Effect_Blinds(CDC *pDC);		//��Ҷ��Ч��
	void		Effect_Blinds_H_Mem();			//ˮƽ��Ҷ��[ֱ�Ӷ��ڴ��������]
	void		Effect_Blinds_V_Mem();			//��ֱ��Ҷ��[ֱ�Ӷ��ڴ��������]
	void		Effect_Mosaic_Mem();			//������[ֱ�Ӷ��ڴ��������]
	void		Effect_ScanFromTop_Mem();		//��������ɨ��[ֱ�Ӷ��ڴ��������]
	void		Effect_ScanFromBottom_Mem();	//��������ɨ��[ֱ�Ӷ��ڴ��������]
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPictViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPictViewView)
	afx_msg void OnUpdateFileNew(CCmdUI* pCmdUI);
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnUpdateFileMruFile1(CCmdUI* pCmdUI);
	afx_msg void OnUseSpecialEffect();
	afx_msg void OnUpdateUseSpecialEffect(CCmdUI* pCmdUI);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnZoomHalf();
	afx_msg void OnUpdateZoomHalf(CCmdUI* pCmdUI);
	afx_msg void OnZoomOriginal();
	afx_msg void OnUpdateZoomOriginal(CCmdUI* pCmdUI);
	afx_msg void OnZoomDouble();
	afx_msg void OnUpdateZoomDouble(CCmdUI* pCmdUI);
	afx_msg void OnZoom75percent();
	afx_msg void OnUpdateZoom75percent(CCmdUI* pCmdUI);
	afx_msg void OnZoom150percent();
	afx_msg void OnUpdateZoom150percent(CCmdUI* pCmdUI);
	afx_msg void OnEffectRandom();
	afx_msg void OnUpdateEffectRandom(CCmdUI* pCmdUI);
	afx_msg void OnEffectMosaic();
	afx_msg void OnUpdateEffectMosaic(CCmdUI* pCmdUI);
	afx_msg void OnEffectBlinds();
	afx_msg void OnUpdateEffectBlinds(CCmdUI* pCmdUI);
	afx_msg void OnEffectTopdown();
	afx_msg void OnUpdateEffectTopdown(CCmdUI* pCmdUI);
	afx_msg void OnEffectBottomup();
	afx_msg void OnUpdateEffectBottomup(CCmdUI* pCmdUI);
	afx_msg void OnEffectLeftright();
	afx_msg void OnUpdateEffectLeftright(CCmdUI* pCmdUI);
	afx_msg void OnEffectRightleft();
	afx_msg void OnUpdateEffectRightleft(CCmdUI* pCmdUI);
	afx_msg void OnEffectTopleft();
	afx_msg void OnUpdateEffectTopleft(CCmdUI* pCmdUI);
	afx_msg void OnEffectBottomleft();
	afx_msg void OnUpdateEffectBottomleft(CCmdUI* pCmdUI);
	afx_msg void OnEffectTopright();
	afx_msg void OnUpdateEffectTopright(CCmdUI* pCmdUI);
	afx_msg void OnEffectBottomright();
	afx_msg void OnUpdateEffectBottomright(CCmdUI* pCmdUI);
	afx_msg void OnViewPrevious();
	afx_msg void OnUpdateViewPrevious(CCmdUI* pCmdUI);
	afx_msg void OnViewNext();
	afx_msg void OnUpdateViewNext(CCmdUI* pCmdUI);
	afx_msg void OnEditDelete();
	afx_msg void OnUpdateEditDelete(CCmdUI* pCmdUI);
	afx_msg void OnZoomIn();
	afx_msg void OnUpdateZoomIn(CCmdUI* pCmdUI);
	afx_msg void OnZoomOut();
	afx_msg void OnUpdateZoomOut(CCmdUI* pCmdUI);
	afx_msg void OnEditExternal();
	afx_msg void OnUpdateEditExternal(CCmdUI* pCmdUI);
	afx_msg void OnEditInMpaint();
	afx_msg void OnUpdateEditInMpaint(CCmdUI* pCmdUI);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPlay();
	afx_msg void OnUpdatePlay(CCmdUI* pCmdUI);
	afx_msg void OnPause();
	afx_msg void OnUpdatePause(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnFullScreen();
	afx_msg void OnZoomFitscreen();
	afx_msg void OnUpdateZoomFitscreen(CCmdUI* pCmdUI);
	afx_msg void OnRotate90Clockwise();
	afx_msg void OnUpdateRotate90Clockwise(CCmdUI* pCmdUI);
	afx_msg void OnEffectMemVblinds();
	afx_msg void OnUpdateEffectMemVblinds(CCmdUI* pCmdUI);
	afx_msg void OnEffectMemHblinds();
	afx_msg void OnUpdateEffectMemHblinds(CCmdUI* pCmdUI);
	afx_msg void OnEffectMemMosaic();
	afx_msg void OnUpdateEffectMemMosaic(CCmdUI* pCmdUI);
	afx_msg void OnEffectMemScanfromtop();
	afx_msg void OnUpdateEffectMemScanfromtop(CCmdUI* pCmdUI);
	afx_msg void OnEffectMemScanfrombottom();
	afx_msg void OnUpdateEffectMemScanfrombottom(CCmdUI* pCmdUI);
	afx_msg void OnRotate90Anticlockwise();
	afx_msg void OnUpdateRotate90Anticlockwise(CCmdUI* pCmdUI);
	afx_msg void OnRotate180();
	afx_msg void OnUpdateRotate180(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FitScreen();
};

#ifndef _DEBUG  // debug version in PictViewView.cpp
inline CPictViewDoc* CPictViewView::GetDocument()
   { return (CPictViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTVIEWVIEW_H__BB4309C9_B62C_497D_892E_7A9E9E5D99C5__INCLUDED_)
