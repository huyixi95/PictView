#pragma once

#include <afx.h>
#include "Lib/Jpeg.h"
#include "Lib/Gif.h"
#pragma comment(lib,"vfw32.lib")

#ifndef UC_SWAP_HEIGHT
#define UC_SWAP_HEIGHT(a)	((a))
#endif
#define UC_USE_DC	//\\\\\\\\\\\\\\\\

enum LanFormat
{
	LanF_Unkown		= 0,
	LanF_A8R8G8B8	= 1,
	LanF_R8G8B8		= 2,
	LanF_R5G6B5		= 3,
	LanF_R5G5B5		= 4,
	LanF_A4R4G4B4	= 5,
	LanF_Index8		= 6,
	LanF_Index4		= 7,
	LanF_Index1		= 8,
};


class LanImage
{
public:
	BYTE *		m_pImage;
	CJpeg*		m_pJpeg;		//CJpeg�����ָ�룬����Lib Sources�еĶ���ʱʹ��
								//#����ֱ���ö���,��CJpeg���л���ָ�룬������ʱ�����
	CGif*		m_pGif;
	int			m_nWidth;		//ͼ��ʵ�ʿ��
	int			m_nHeight;		//ͼ��ʵ�ʸ߶�
	int			m_nDrawWidth;	//ͼ����ʾ���
	int			m_nDrawHeight;	//ͼ����ʾ�߶�
	int			m_nBitCount;
	int			m_nPitch;		//DIBһ����ռ�ֽ���
	int			m_nImage;		//ͼ�����ݵ��ֽ���
	int			m_nPalette;
	long		nFileSize;
	//----------------------	//������תʱ����ԭ����ͼ����ܱ��ı����Ϣ
	BYTE *		m_pOriginImage;
	int			m_nOriginWidth;
	int			m_nOriginHeight;
	int			m_nOriginPitch;
	int			m_nOriginImage;
	BOOL		m_bBufferIsOriginal;
	//----------------------
	BOOL		m_bReadWithLibSupport;	//��ʹ��Lib Sources�еķ����������еĶ�д������ClassImage�Ĳ�ͬ
	RGBQUAD		*m_pPal;
	LanFormat	m_eFmt;
#ifdef UC_USE_DC
	HBITMAP	m_hBitmap;
#endif
public:
	LanImage()
	{
		memset(this,0,sizeof(LanImage));
		m_bReadWithLibSupport = FALSE;
		m_pJpeg = NULL;
		m_pGif = NULL;
		m_pPal = NULL;
	}

	~LanImage()
	{
#ifdef UC_USE_DC
		if(m_hBitmap)
			DeleteObject(m_hBitmap);	//m_hBitmap�а�����m_pImage���ָ�������
#else
		if(m_bReadWithLibSupport)//���ʹ����Lib Sources����ʱm_pImageָ�����ԭ��CJpeg���һ���ֿռ䣬
			m_pImage = NULL;	//�������Ѵݻ٣����ǲ��ֿռ��������ջء�
		
		delete [] m_pImage;
		m_pImage = NULL;
#endif
		delete m_pJpeg;
		m_pJpeg = NULL;
		delete m_pGif;
		m_pGif = NULL;

		if(m_pPal)
		{
			delete [] m_pPal;
			m_pPal = NULL;
		}
	}

///////////////////////////////////////////////////////////////////////////
//	The following eight functions are implemented is file ClassImage.cpp

	BOOL Create(int nWidth,int nHeight,int nBitCount,int ndegree,LanFormat eFmt = LanF_Unkown);
	BOOL Create_No(int nWidth,int nHeight,int nBitCount,LanFormat eFmt = LanF_Unkown);
	BOOL LoadImage(LPCTSTR pszFileName,int ndegree,BOOL isconvert);
 	BOOL CopyFrom(const LanImage & Img);
	void Release();
	//######
	BOOL CreateDib(CDib **pDib);	//��������������CDib����,����**pDibΪ�˴���ָ��ĵ�ַ
	void Rotate90Clockwise();		//˳ʱ����תͼ��90��
	
#ifdef UC_USE_DC
	HDC  GetDC();
	void ReleaseDC(HDC hdc);
#endif
/////////////////////////////////////////////////////////////////////////////
//##**##
	BOOL ReadBmp(LPBYTE pBuffer,UINT uLength,int ndegree,BOOL isconvert);	//Implemented in file ImageBmp.cpp
	BOOL ReadTga(LPBYTE pBuffer,UINT uLength,int ndegree);					//Implemented in file ImageTga.cpp
	BOOL ReadPcx(LPBYTE pBuffer,UINT uLength,int ndegree);					//Implemented in file ImagePcx.cpp


//////////////////////////////////////////////////////////////////////////////
//  The following four functions are implemented in file ImageBmpConvert.cpp

	BOOL Convert32();
	BOOL Convert32(const LanImage &Img);
	BOOL ConvertFrom32(LanFormat eFmt);
	BOOL ConvertFrom32(const LanImage &Img,LanFormat eFmt);
///////////////////////////////////////////////////////////////////////////////
//##**##
	BOOL SaveBmp(LPCTSTR pszFileName) const;
	BOOL SaveTga(LPCTSTR pszFileName) const;
	BOOL SavePcx(LPCTSTR lpstrFileName, CDib* pDib);

	//Function of Displaying the image:
	BOOL Draw(HDC hdc,int nDx,int nDy,int nDw,int nDh,
				int nSx,int nSy,int nSw,int nSh,UINT uFlags = 0) const;

	BOOL	IsLoad() const{ return m_pImage != NULL;}
	
	int		GetWidth() const{ return m_nWidth;}
	int		GetHeight() const{ return m_nHeight;}
	int		GetBitCount() const{ return m_nBitCount;}
	int		GetPitch() const{ return m_nPitch;}
	int		GetBltPitch() const
	{
		if(UC_SWAP_HEIGHT(0))
			return m_nPitch;
		else
			return -m_nPitch;
	}
	LanFormat GetFormat()
	{
		return m_eFmt;
	}
	int		GetPalCount() const{ return m_nPalette;}
	RGBQUAD*GetPalette(){ return m_pPal;}
	const RGBQUAD *	GetPalette() const{ return m_pPal;}
	int		GetSize() const{ return m_nImage;}
	BYTE *	GetImage(){ return m_pImage;}
	const BYTE * GetImage() const{ return m_pImage;}

	BYTE * GetBltLine(int nLine)	/////////////////////////////
	{
		if(UC_SWAP_HEIGHT(0))
			return m_pImage + m_nPitch * nLine;
		else
			return m_pImage + m_nPitch * (m_nHeight - nLine - 1);
	}

	const BYTE * GetBltLine(int nLine) const
	{
		if(UC_SWAP_HEIGHT(0))
			return m_pImage + m_nPitch * nLine;
		else
			return m_pImage + m_nPitch * (m_nHeight - nLine - 1);
	}

	BYTE * GetLine(int nLine)
	{
		return m_pImage + m_nPitch * nLine;
	}
	const BYTE * GetLine(int nLine) const
	{
			return m_pImage + m_nPitch * nLine;
	}
private:
	LanImage(const LanImage &);
	LanImage & operator = (const LanImage &);
};