// PictViewDoc.cpp : implementation of the CPictViewDoc class
//

#include "stdafx.h"
#include "PictView.h"

#include "PictViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPictViewDoc

IMPLEMENT_DYNCREATE(CPictViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CPictViewDoc, CDocument)
	//{{AFX_MSG_MAP(CPictViewDoc)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE, OnUpdateFileSave)
	ON_UPDATE_COMMAND_UI(ID_FILE_SAVE_AS, OnUpdateFileSaveAs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPictViewDoc construction/destruction

CPictViewDoc::CPictViewDoc()
{
	// TODO: add one-time construction code here
	m_bIsEmptyDoc = TRUE;	//�Ƿ�Ϊ���ĵ�
	m_bIsEmptyDir = FALSE;	//�����ʼʱ��ΪFALSE.�����ֱ�����û�����ʾ����ͼ����ʾ��
}

CPictViewDoc::~CPictViewDoc()
{
}

BOOL CPictViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	m_bIsEmptyDoc=TRUE;	//��־Ϊ���ĵ�
	//SetTitle("δ���κ��ļ�"); //Set File name for Title line when window is loaded.
	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CPictViewDoc serialization

void CPictViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

BOOL CPictViewDoc::InitPicList(LPCTSTR pszFileName)
{ 
	//BOOL bRet = FALSE;
	char drive[_MAX_DRIVE];   
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];   
	char ext[_MAX_EXT];
	_splitpath(pszFileName, drive, dir, fname, ext); 

	CString str;
	str.Format("%s%s",drive,dir);
	str = str + "*.*";

	CFileFind cFind;
	BOOL ans = cFind.FindFile(str);
	m_iFileNumber = 0;
	while(ans)
	{
		if(m_iFileNumber<MAX_SEARCH_NUM)
		{
			ans = cFind.FindNextFile();
			if(cFind.IsDirectory())		//����ҵ�����Ŀ¼������
				continue;
			CString FilName = cFind.GetFileName();
			LPCTSTR pszExt = _tcsrchr(FilName,_T('.'));

			if(pszExt)		//�������չ���������������չ�������򲻷������������չ���Է���
							//��_tcsicmp()��ִ�г���.
			{//##**##
				if((_tcsicmp(pszExt,".bmp") == 0)||(_tcsicmp(pszExt,".tga") == 0)
					||(_tcsicmp(pszExt,".pcx") == 0)||(_tcsicmp(pszExt,".jpg") == 0)
					||(_tcsicmp(pszExt,".jpeg") == 0)||(_tcsicmp(pszExt,".gif") == 0))
				{
					m_PicList[m_iFileNumber] = cFind.GetFileName();
					CString FilePath;
					FilePath.Format("%s%s",drive,dir);
					m_PicList[m_iFileNumber] = FilePath + m_PicList[m_iFileNumber] ;
					m_iFileNumber++;
				}
			}
		}
		else
		{
			CString	sPrompt;
			int		num = MAX_SEARCH_NUM;
			sPrompt.Format("��ǰĿ¼�а�����ͼƬ�ļ�����%d��������ҳ���ʱ��ֻ��ʾǰ%d����",num,num);
			AfxMessageBox("sPrompt");
		}
	}

	m_iFileNumber--;	//��Ϊ����whileÿѭ��һ��m_iFileNumber��1�������һ��ͼƬ�����б���Լ�1
						//�ʱ�ʵ�ʵĸ�����һ���ڴ˼�ȥ��
	cFind.Close();
	return TRUE;
}

void CPictViewDoc::ReInitPicList()
{
	//��ɾ����ͼƬ�б�ǰ���ļ��б��ֲ���
	//��ɾ����ͼƬ�б��Ĳ����б�ǰ��
	for(int i = m_iCurrFileNum + 1;i<=m_iFileNumber;i++)
	{
		m_PicList[i - 1] = m_PicList[i];
	}
	m_iFileNumber--;
}
/////////////////////////////////////////////////////////////////////////////
// CPictViewDoc diagnostics

#ifdef _DEBUG
void CPictViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPictViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPictViewDoc commands

void CPictViewDoc::OnUpdateFileSave(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bIsEmptyDoc || m_bIsEmptyDir)
		pCmdUI->Enable(FALSE);
	else
		pCmdUI->Enable(TRUE);
	
}

void CPictViewDoc::OnUpdateFileSaveAs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_bIsEmptyDoc || m_bIsEmptyDir)
		pCmdUI->Enable(!m_bIsEmptyDoc);
	else
		pCmdUI->Enable(TRUE);

}
