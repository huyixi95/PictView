// PictViewDoc.h : interface of the CPictViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PICTVIEWDOC_H__2009D3B6_6AE8_4F2E_951E_1E9980A43B5C__INCLUDED_)
#define AFX_PICTVIEWDOC_H__2009D3B6_6AE8_4F2E_951E_1E9980A43B5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	MAX_SEARCH_NUM	500

class CPictViewDoc : public CDocument
{
protected: // create from serialization only
	CPictViewDoc();
	DECLARE_DYNCREATE(CPictViewDoc)

// Attributes
public:
	BOOL	m_bIsEmptyDoc;	//�Ƿ�Ϊ���ĵ�
	BOOL	m_bIsEmptyDir;	//�Ƿ�ǰĿ¼�ѿ�
	int		m_iFileNumber;	//��¼��ǰĿ¼��ͼƬ�ļ�������
	int		m_iCurrFileNum; //��¼��ǰ�򿪵��Ǹ�Ŀ¼�µڼ����ļ�
	CString	m_PicList[MAX_SEARCH_NUM];
// Operations
public:
	BOOL InitPicList(LPCTSTR pszFileName);	//������ǰĿ¼��ͼƬ�ļ��б�
	void ReInitPicList();					//��ɾ���ļ����ؽ��б�
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPictViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPictViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPictViewDoc)
	afx_msg void OnUpdateFileSave(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFileSaveAs(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICTVIEWDOC_H__2009D3B6_6AE8_4F2E_951E_1E9980A43B5C__INCLUDED_)
