
// example_project.h : ������� ���� ��������� ��� ���������� example_project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// Cexample_projectApp:
// � ���������� ������� ������ ��. example_project.cpp
//

class Cexample_projectApp : public CWinAppEx
{
public:
	Cexample_projectApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexample_projectApp theApp;
