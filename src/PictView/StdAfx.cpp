// stdafx.cpp : source file that includes just the standard includes
//	PictView.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#undef		WINVER
#define		WINVER 0X500
#include	"stdafx.h"

//��ʵ�ֶ������ڵĳ���ʱ���������ֱ����VC��ʹ��AnimateWindow������
//�ڱ���ʱ�ᱨ���������������Ϊ�����ڱ���ʱϵͳ�ᱨ�棺  
//''AnimateWindow'' : undeclared identifier 
//''AW_HIDE'' : undeclared identifier 
//''AW_CENTER'' : undeclared identifier 
//   ͨ��������ʾ���Կ����Ǳ���ϵͳ��ΪAnimateWindow������AW_HIDE��AW_CENTER��������û�ж��塣
//��ú����Ƕ�����Winuser.hͷ�ļ��еģ���ʱ��������ʾ���ڳ����ж����˶Ը�ͷ�ļ��İ���������ʱ
//ȴ��Ȼ������ͬ�Ĵ���Ϊʲô��VC�б��벻��ͨ���أ�ͨ������MSDN���߷�����MSDN����ȷ�ᵽ
//WindowsNT5.0��Windows98���ϰ汾��֧�ָú�����ͨ�����ߵ��о����֣�������ڶ���AnimateWindow
//������ͷ�ļ�Winuser.h�У���VC��װĿ¼�½���include��Ŀ¼����EDIT��Winuser.h�ļ�����F3����
//��AnimateWindow�����Է������������壬һ���Ƕ���ú�����ʹ�õ��Ĳ�������һ���Ǹú���ԭ�͵Ķ��塣
//�������������о������˶�Windows�汾�������жϣ�#if (WINVER >= 0X500)������ԭ������������
//����Ŀǰ��ʹ�õĸ���Windows���汾�ž�Ϊ5�������£�������VC�б�����������ʱ������ϵͳ��Ȼ��
//AnimateWindow�����ų����⡣���Ϊ�������ǵĳ�����ʹ�øú������͵ö���ͷ�ļ�����һЩСС���޸ģ�
//����#if (WINVER >= 0X500)��Ϊ#if (WINVER >= 0X400)����ע���������ָú�������Ĳ��ֶ�Ҫ�����޸ġ� 
//�����㲻���޸�Winuser.h,�����ڹ������StdAfx.h�ļ���ǰλ�ü������¶��� 
//#undef WINVER
//#define WINVER 0X500
 



