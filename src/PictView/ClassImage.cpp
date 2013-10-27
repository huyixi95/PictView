#include "stdafx.h" 
#include "ClassImage.h"
#include <vfw.h>	//Ϊ��ʹ��DrawDibDraw()����
#include <assert.h>

LanFormat __BitCount2Fmt(int nBitCount)
{
	switch(nBitCount)
	{
	case 1:
		return LanF_Index1;
	case 4:
		return LanF_Index4;
	case 8:
		return LanF_Index8;
	case 16:
		return LanF_R5G5B5;
	case 24:
		return LanF_R8G8B8;
	case 32:
		return LanF_A8R8G8B8;
	}
	return LanF_Unkown;
}
BOOL LanImage::Create(int nWidth,int nHeight,int nBitCount,int ndegree,LanFormat eFmt)
{
	Release();
	if (ndegree==1 || ndegree==4)
	{
		m_eFmt = eFmt;
		m_nWidth = nWidth;
		m_nHeight = nHeight;
	}
	else if(ndegree==2 || ndegree==3)
	{
		m_eFmt = eFmt;
		m_nWidth = nHeight;
		m_nHeight = nWidth;
	}
	m_nBitCount = nBitCount;
	m_nPitch = (nWidth * nBitCount + 31) / 32 * 4;
	m_nImage = m_nPitch * nHeight;

	if(nBitCount <= 8)
	{
		m_nPalette = 1 << nBitCount;
		m_pPal = new RGBQUAD[m_nPalette];
	}
	else
	{
		m_nPalette = 0;		//�ص�������
	}

#ifdef UC_USE_DC
	BITMAPINFOHEADER bih;
	memset(&bih,0,sizeof(bih));
	bih.biSize = sizeof(bih);
	bih.biPlanes = 1;
	bih.biWidth = m_nWidth;
	if(UC_SWAP_HEIGHT(1))
		bih.biHeight = m_nHeight;
	else
		bih.biHeight = -m_nHeight;
	bih.biBitCount = m_nBitCount;
	bih.biSizeImage = m_nImage;
	bih.biClrUsed = m_nPalette;
	HDC hdc = ::GetDC(NULL);
	m_hBitmap = CreateDIBSection(hdc,(BITMAPINFO *)&bih,DIB_RGB_COLORS,(void **)&m_pImage,NULL,0);
	::ReleaseDC(NULL,hdc);
#else
	m_pImage = new BYTE[m_nImage];
#endif

	return TRUE;

}

BOOL LanImage::Create_No(int nWidth,int nHeight,int nBitCount,LanFormat eFmt)
{
	VERIFY(nWidth > 0 && nHeight > 0);			//���Ϊassert();�ָ�ΪVERIFY()
	VERIFY(nBitCount > 0 && nBitCount <= 32);
	if(eFmt == LanF_Unkown)
		eFmt = __BitCount2Fmt(nBitCount);
	if(eFmt == LanF_Unkown)
		return FALSE;

	Release();

	m_eFmt = eFmt;
	m_nWidth = nWidth;
	m_nHeight = nHeight;
	m_nBitCount = nBitCount;
	m_nPitch = (nWidth * nBitCount + 31) / 32 * 4;
	m_nImage = m_nPitch * nHeight;

	if(nBitCount <= 8)
	{
		m_nPalette = 1 << nBitCount;
		m_pPal = new RGBQUAD[m_nPalette];
	}
	else
	{
		m_nPalette = 0;		//�ص�������
	}

#ifdef UC_USE_DC
	BITMAPINFOHEADER bih;
	memset(&bih,0,sizeof(bih));
	bih.biSize = sizeof(bih);
	bih.biPlanes = 1;
	bih.biWidth = m_nWidth;
	if(UC_SWAP_HEIGHT(1))
		bih.biHeight = m_nHeight;
	else
		bih.biHeight = -m_nHeight;
	bih.biBitCount = m_nBitCount;
	bih.biSizeImage = m_nImage;
	bih.biClrUsed = m_nPalette;
	HDC hdc = ::GetDC(NULL);
	m_hBitmap = CreateDIBSection(hdc,(BITMAPINFO *)&bih,DIB_RGB_COLORS,(void **)&m_pImage,NULL,0);
	::ReleaseDC(NULL,hdc);
#else
	m_pImage = new BYTE[m_nImage];
#endif

	return TRUE;

}

BOOL LanImage::CopyFrom(const LanImage & Img)
{
	if(&Img == this || Img.IsLoad() == FALSE)
		return FALSE;

//	if(Create_No(Img,Img.GetWidth(),Img.GetHeight(),Img.m_eFmt) == FALSE)
//		return FALSE;
//	if(Create_No(Img.GetWidth(),Img.GetHeight(),Img.GetBitCount(),Img.m_eFmt) == FALSE)
//		return FALSE;

	memcpy(m_pImage,Img.GetImage(),GetSize());
	memcpy(m_pPal,Img.GetPalette(),GetPalCount() * sizeof(RGBQUAD));

	return TRUE;
}
//-----------------------------------------------------------------------------
void LanImage::Release()
{
#ifdef UC_USE_DC
	if(m_hBitmap)		//ɾ������ԭʼͼ������
	{
		DeleteObject(m_hBitmap);
		//m_pOriginImageָ�����m_hBitmap��ͼ�����ݿռ�,�ռ䱻�ͷ�,��ΪNULL
		m_pOriginImage = NULL;
	}

	if(!m_bBufferIsOriginal)
	{
		delete [] m_pImage;
		m_pImage = NULL;
	}
#else
	if(m_pImage)		//��û�ö���UC_USE_DC,��˴�ɾ���ǵ�ǰ��ʾ������
	{
		delete [] m_pImage;
		m_pImage = NULL;
	}

	if(!m_bBufferIsOriginal)
	{
		delete [] m_pOriginImage;
		m_pOriginImage = NULL;
	}
#endif
	if(m_pPal)
	{
		delete [] m_pPal;
		m_pPal = NULL;
	}

//	memset(this,0,sizeof(LanImage));
}
//-----------------------------------------------------------------------------
#ifdef UC_USE_DC
HDC LanImage::GetDC()
{
	HDC hdc = CreateCompatibleDC(NULL);
	SelectObject(hdc,m_hBitmap);
	if(m_nPalette > 0)
		SetDIBColorTable(hdc,0,m_nPalette,m_pPal);
	return hdc;
}

void LanImage::ReleaseDC(HDC hdc)
{
	DeleteDC(hdc);
}

#endif

BOOL LanImage::LoadImage(LPCTSTR pszFileName,int ndegree,BOOL isconvert)
{
	//�ж��ļ��ĺ�׺�����Ծ���ͼ���Ǻθ�ʽ.���ַ�������̫�ã�����ķ���Ӧ���Ƕ�ȡ�ļ�
	//���ݲ�����ȡ��ͼ���ʽ����Ϣ��
	LPCTSTR pszExt = _tcsrchr(pszFileName,_T('.'));		//ȡ��׺��
	BOOL bRet = FALSE;

	//��ΪJPEG��ʽ�������Lib Sources�еĶ���
	if( (_tcsicmp(pszExt,".jpg") == 0) || (_tcsicmp(pszExt,".jpeg") == 0) )
	{
		m_bReadWithLibSupport = TRUE;
		m_pJpeg = new CJpeg();
		//int size = sizeof(m_pJpeg);
		//CString str;
		//str.Format("%d",size);
		//AfxMessageBox(str);////////////
		bRet = m_pJpeg->Load(pszFileName);

		if(!bRet)
		{
			AfxMessageBox("����JPEG�ļ�ʱ��������!");
			return FALSE;
		}

		CDib *pDib = m_pJpeg->GetDib();	//��ȡCDibָ��
		m_pImage = pDib->GetBitsPtr();	//��ȡDIB������ָ��
		m_nWidth = pDib->GetWidth();
		m_nHeight = pDib->GetHeight();
		m_nBitCount = pDib->GetBitCount();
		m_nImage = m_nHeight*(pDib->GetWidthBytes());
		m_nPitch = pDib->GetWidthBytes();
		m_nPalette = 0;
		//Ϊ�˵õ��ļ��ĳ���
		CFile file;
		if(file.Open(pszFileName,CFile::modeRead) == FALSE)
		{
			AfxMessageBox("��ȡ�ļ���С�����޷����ļ�!");
			return FALSE;
		}
		nFileSize = file.GetLength();
		file.Close();
	}
	//��ΪGIF��ʽ��Ҳ����Lib Sources�еĶ���
	else if( _tcsicmp(pszExt,".gif") == 0 )
	{
		m_bReadWithLibSupport = TRUE;
		m_pGif = new CGif();
		bRet = m_pGif->Load(pszFileName);

		if(!bRet)
		{
			AfxMessageBox("����GIF�ļ�ʱ��������!");
			return FALSE;
		}

		CDib *pDib = m_pGif->GetDib();	//��ȡCDibָ��
		m_pImage = pDib->GetBitsPtr();	//��ȡDIB������ָ��
		m_nWidth = pDib->GetWidth();
		m_nHeight = pDib->GetHeight();
		m_nBitCount = pDib->GetBitCount();
		m_nImage = m_nHeight*(pDib->GetWidthBytes());
		m_nPitch = pDib->GetWidthBytes();
		m_nPalette = 0;
		//Ϊ�˵õ��ļ��ĳ���
		CFile file;
		if(file.Open(pszFileName,CFile::modeRead) == FALSE)
		{
			AfxMessageBox("��ȡ�ļ���С�����޷����ļ�!");
			return FALSE;
		}
		nFileSize = file.GetLength();
		file.Close();
	}
	else
	{
		m_bReadWithLibSupport = FALSE;
		CFile file;
		if(file.Open(pszFileName,CFile::modeRead) == FALSE)
		{
			AfxMessageBox("�޷����ļ�!��ȷ���ļ��Ƿ���ڻ�·���Ƿ���ȷ!");
			return FALSE;
		}

		// Ϊ�˵õ��ļ��ĳ��ȡ�
		nFileSize = file.GetLength();
	
		BYTE * pFileBuffer = new BYTE[nFileSize]; //

		file.Read(pFileBuffer,nFileSize);

		file.Close();

//##**##
		if(_tcsicmp(pszExt,".bmp") == 0)
			bRet = ReadBmp(pFileBuffer,nFileSize,ndegree,isconvert);
		else if(_tcsicmp(pszExt,".tga") == 0)
			bRet = ReadTga(pFileBuffer,nFileSize,ndegree);
		else if(_tcsicmp(pszExt,".pcx") == 0)
			bRet = ReadPcx(pFileBuffer,nFileSize,ndegree);

		delete [] pFileBuffer;
		pFileBuffer = NULL;
	}

	return bRet;
}

struct LanDrawDib
{
	HDRAWDIB hDraw;
	LanDrawDib()
	{
		hDraw = DrawDibOpen();
	}

	~LanDrawDib(){
		DrawDibClose(hDraw);
	}

	operator HDRAWDIB ()
	{
		return hDraw;
	}

	static LanDrawDib & GetDrawDib()
	{
		static LanDrawDib	__DrawDib;
		return __DrawDib;
	}
};


struct LanDrawHeader : public BITMAPINFOHEADER
{
	RGBQUAD	pal[256];
	LanDrawHeader(){
		memset(this,0,sizeof(LanDrawHeader));
		biSize = sizeof(BITMAPINFOHEADER);
		biPlanes = 1;
	}
};

static LanDrawHeader  g_LanDH;

BOOL LanImage::Draw(HDC hdc,int nDx,int nDy,int nDw,int nDh,
				int nSx,int nSy,int nSw,int nSh,UINT uFlags) const
{
	if(IsLoad() == FALSE)
		return FALSE;

	g_LanDH.biWidth = m_nWidth;
	g_LanDH.biHeight = m_nHeight;
	g_LanDH.biBitCount = m_nBitCount;
	if(m_nBitCount <= 8)
	{
//		memcpy(g_LanDH.pal,m_pPal,(1 << m_nBitCount) * sizeof(RGBQUAD));
		g_LanDH.biClrUsed = m_nPalette;
		memcpy(g_LanDH.pal,m_pPal,m_nPalette * sizeof(RGBQUAD));
	}

	DrawDibDraw(LanDrawDib::GetDrawDib(),hdc,
		nDx,nDy,nDw,nDh,
		&g_LanDH,m_pImage,
		nSx,nSy,nSw,nSh,
		uFlags);

	return TRUE;
}

//**** �˺���Ϊ���ڴ�ͼ��ʱû�д���CDib������´���CDib���� ****
BOOL LanImage::CreateDib(CDib **pDib)
{
	BITMAPINFOHEADER	bmiHeader;
	HDIB				hDIB;
	bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmiHeader.biWidth = m_nWidth;
	bmiHeader.biHeight = m_nHeight;
	bmiHeader.biPlanes = 1;
	bmiHeader.biBitCount = m_nBitCount;
	bmiHeader.biCompression = BI_RGB;
	bmiHeader.biSizeImage = m_nImage;
	bmiHeader.biXPelsPerMeter = 0;
	bmiHeader.biYPelsPerMeter = 0;
	//����򿪵�ͼƬBitCount>8���޵�ɫ��
	if(m_nBitCount>8)
		bmiHeader.biClrUsed = 0;
	else
		bmiHeader.biClrUsed = m_nPalette;
	bmiHeader.biClrImportant = 0;
	
	// Allocate enough memory for the new CF_DIB, and copy bits 
	DWORD dwHeaderSize = sizeof(BITMAPINFOHEADER);
	DWORD dwPaletteSize = sizeof(RGBQUAD)*m_nPalette;
	DWORD dwBitsSize = WIDTHBYTES(m_nWidth*m_nBitCount) * m_nHeight;
	if(m_nBitCount>8)
		hDIB = GlobalAlloc(GHND, dwHeaderSize + dwBitsSize);
	else
		hDIB = GlobalAlloc(GHND, dwHeaderSize + dwPaletteSize + dwBitsSize);

	if (hDIB == NULL)
		return FALSE;
		
	LPBYTE lpDIB = (LPBYTE)GlobalLock(hDIB); 
	memcpy(lpDIB, (LPBYTE)&bmiHeader, dwHeaderSize);
	if(m_nBitCount<=8)		//д��ɫ��
		memcpy(lpDIB+dwHeaderSize,m_pPal,dwPaletteSize);
	memcpy(FindDIBBits((LPBYTE)lpDIB), m_pImage, dwBitsSize);

	*pDib = new CDib();
	(*pDib)->Attach(hDIB);
	GlobalUnlock(hDIB);
	return TRUE;
}

//****** ��תͼ��-˳ʱ��90�� ********
//
//		ע��ͼ���4�ֽڶ���!!!
//
//-----------------------------------
void LanImage::Rotate90Clockwise()
{
	BYTE* pNewImage = NULL;
	
	int iSrcWidth = m_nWidth;
	int iSrcHeight = m_nHeight;
	int iSrcRowBytes = m_nPitch;

	//���㷭ת��һ��ռ�õ��ֽ������������Ĵ�С
	int iNewPitch = (iSrcHeight * m_nBitCount + 31) / 32 * 4;	//4�ֽڶ���
	int iNewImgDataSize = iNewPitch * iSrcWidth;

	//Ϊ��ת������ݷ���ռ�
	pNewImage = new BYTE[iNewImgDataSize];
	switch(m_nBitCount)
	{
	case 8:	//8λͼ��ķ�ת
		{
			int OutPointer = 0;
			for(int y = 0;y < iSrcHeight;y++)
			{
				BYTE *pIn = GetLine(y);
				for(int x = 0;x < iSrcWidth;x++)
				{
					int OutColumn = y;				//�����п�����������ʱ����ת��������DIB
					int OutRow = iSrcWidth - x - 1;	//�����µ��ϴ洢ͼ��ģ���ʵ������˳ʱ��
					//int OutColumn = iSrcHeight - y - 1;//��������ע�͵��������෴������ʱ���
					//int OutRow = x;
					OutPointer = OutRow * iNewPitch + OutColumn;
					CopyMemory(&pNewImage[OutPointer],&pIn[x],1);
				}
			}
		}
		break;
	case 1:		//1λ��4λ�Ƚ��鷳��Ҫ��λ���в���
		{
			memset(pNewImage,0,iNewImgDataSize);	//ȫ��Ϊ0�����ں���İ�λ�����
			int OutPointer = 0;
			for(int y=0;y<iSrcHeight;y++)
			{
				BYTE* pIn = GetLine(y);
				for(int x=0;x<iSrcRowBytes;x++)
				{
					int BitPointer = 0;		//ȷ�����ڸ��ֽ��еĵڼ�λ
					int OutColumn = y/8;	//8�з�ת��Ź���һ�ֽ�
					BYTE byTempIn = pIn[x];	//ȡһ���ֽڣ���8������
					BYTE byTempOut;

					for(BitPointer=0;BitPointer<8;BitPointer++)
					{
						int OutRow = iSrcWidth - (x*8+BitPointer) - 1;
						//ע�⣺���λ��������ߵ�����!
						switch(BitPointer)
						{
						case 0:
							byTempOut = (byTempIn & 0x80);	//1000 0000
							byTempOut = (byTempOut >> (y%8));//�ó���λ��Ŀ���ֽ���Ӧ����һλ
							break;
						case 1:
							byTempOut = (byTempIn & 0x40);	//0100 0000
							if(y%8-1 < 0)
								byTempOut = (byTempOut << (1-y%8));
							else
								byTempOut = (byTempOut >> (y%8-1));
							break;
						case 2:
							byTempOut = (byTempIn & 0x20);	//0010 0000
							if(y%8-2 < 0)
								byTempOut = (byTempOut << (2-y%8));
							else
								byTempOut = (byTempOut >> (y%8-2));
							break;
						case 3:
							byTempOut = (byTempIn & 0x10);	//0001 0000
							if(y%8-3 < 0)
								byTempOut = (byTempOut << (3-y%8));
							else
								byTempOut = (byTempOut >> (y%8-3));
							break;
						case 4:
							byTempOut = (byTempIn & 0x08);	//0000 1000
							if(y%8-4 < 0)
								byTempOut = (byTempOut << (4-y%8));
							else
								byTempOut = (byTempOut >> (y%8-4));
							break;
						case 5:
							byTempOut = (byTempIn & 0x04);	//0000 0100
							if(y%8-5 < 0)
								byTempOut = (byTempOut << (5-y%8));
							else
								byTempOut = (byTempOut >> (y%8-5));
							break;
						case 6:
							byTempOut = (byTempIn & 0x02);	//0000 0010
							if(y%8-6 < 0)
								byTempOut = (byTempOut << (6-y%8));
							else
								byTempOut = (byTempOut >> (y%8-6));
							break;
						case 7:
							byTempOut = (byTempIn & 0x01);	//0000 0001
							byTempOut = (byTempOut << (7-y%8));
							break;
						}

						OutPointer = OutRow * iNewPitch +OutColumn;
						BYTE byDestBuffer = pNewImage[OutPointer];
						byDestBuffer = (byDestBuffer | byTempOut);
						pNewImage[OutPointer] = byDestBuffer;
					}//for(BitPointer)
				}//for(x)
			}//for(y)
		}
		break;
	case 4:
		{
			memset(pNewImage,0,iNewImgDataSize);	//ȫ��Ϊ0�����ں���İ�λ�����
			int OutPointer = 0;
			for(int y=0;y<iSrcHeight;y++)
			{
				BYTE* pIn = GetLine(y);
				for(int x=0;x<iSrcRowBytes;x++)
				{
					int PixPointer = 0;		//ȷ�����ڸ��ֽ��еĵڼ�������
					int OutColumn = y/2;	//2�з�ת�󹹳�һ�ֽ�
					BYTE byTempIn = pIn[x];	//ȡһ���ֽڣ���2������
					BYTE byTempOut;

					for(PixPointer=0;PixPointer<2;PixPointer++)
					{
						int OutRow = iSrcWidth - (x*2+PixPointer) - 1;
						//ע�⣺���λ��������ߵ�����!
						switch(PixPointer)
						{
						case 0:
							byTempOut = (byTempIn & 0xF0);	//1111 0000
							byTempOut = (byTempOut >> (y%2*4));
							break;
						case 1:
							byTempOut = (byTempIn & 0x0F);	//0000 1111
							byTempOut = (byTempIn << (4-y%2*4));
							break;
						}

						OutPointer = OutRow * iNewPitch +OutColumn;
						BYTE byDestBuffer = pNewImage[OutPointer];
						byDestBuffer = (byDestBuffer | byTempOut);
						pNewImage[OutPointer] = byDestBuffer;
					}//for(PixPointer)
				}//for(x)
			}//for(y)
		}
		break;
	case 16:
		{
			int OutPointer = 0;
			for(int y = 0;y < iSrcHeight;y++)
			{
				BYTE *pIn = GetLine(y);
				for(int x = 0;x < iSrcWidth;x++)
				{
					//16λʱһ������ռ���ֽڿ�
					int OutColumn = y*2;			//�����п�����������ʱ����ת��������DIB
					int OutRow = iSrcWidth - x - 1;	//�����µ��ϴ洢ͼ��ģ���ʵ������˳ʱ��
					//int OutColumn = iSrcHeight - y - 1;//��������ע�͵��������෴������ʱ���
					//int OutRow = x;
					OutPointer = OutRow * iNewPitch + OutColumn;
					CopyMemory(&pNewImage[OutPointer],&pIn[x*2],2);
				}
			}
		}
		break;
	case 24:
		{
			int OutPointer = 0;
			for(int y = 0;y < iSrcHeight;y++)
			{
				BYTE *pIn = GetLine(y);
				for(int x = 0;x < iSrcWidth;x++)
				{
					//16λʱһ������ռ���ֽڿ�
					int OutColumn = y*3;			//�����п�����������ʱ����ת��������DIB
					int OutRow = iSrcWidth - x - 1;	//�����µ��ϴ洢ͼ��ģ���ʵ������˳ʱ��
					//int OutColumn = iSrcHeight - y - 1;//��������ע�͵��������෴������ʱ���
					//int OutRow = x;
					OutPointer = OutRow * iNewPitch + OutColumn;
					CopyMemory(&pNewImage[OutPointer],&pIn[x*3],3);
				}
			}
		}
		break;
	case 32:
		{
			int OutPointer = 0;
			for(int y = 0;y < iSrcHeight;y++)
			{
				BYTE *pIn = GetLine(y);
				for(int x = 0;x < iSrcWidth;x++)
				{
					//16λʱһ������ռ���ֽڿ�
					int OutColumn = y*4;			//�����п�����������ʱ����ת��������DIB
					int OutRow = iSrcWidth - x - 1;	//�����µ��ϴ洢ͼ��ģ���ʵ������˳ʱ��
					//int OutColumn = iSrcHeight - y - 1;//��������ע�͵��������෴������ʱ���
					//int OutRow = x;
					OutPointer = OutRow * iNewPitch + OutColumn;
					CopyMemory(&pNewImage[OutPointer],&pIn[x*4],4);
				}
			}
		}
		break;
	}

	//��ͼ���δ���任������delete,����ʱ��m_pImageָ��Ŀռ䲻���ڴ�new������
	if(m_bBufferIsOriginal)
	{
		m_pOriginImage = m_pImage;	//����ԭ����ͼ������
		m_nOriginWidth = m_nWidth;
		m_nOriginHeight = m_nHeight;
		m_nOriginPitch = m_nPitch;
		m_nOriginImage = m_nImage;
	}
	else
		delete [] m_pImage;

	m_pImage = pNewImage;
	pNewImage = NULL;
	//�������[!-ע�⣺�����ڴ˺�����ͷ�͸ı�m_LImage�Ŀ�ߣ���Ϊ�ڴ�Դ������ȡ����ʱ�õ���
	//GetLine()���������˺�����ԭͼƬ�Ŀ�ߺ�m_nPitch�йأ��翪ʼ���ƻ���ԭͼƬ�Ŀ��ֵ��
	//��ô���õ�����Ľ����-]
	m_nWidth = iSrcHeight;
	m_nHeight = iSrcWidth;
	m_nPitch = iNewPitch;
	m_nImage = iNewImgDataSize;
	m_bBufferIsOriginal = FALSE;
}
