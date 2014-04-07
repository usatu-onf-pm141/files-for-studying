
// example_project.h : главный файл заголовка для приложения example_project
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// Cexample_projectApp:
// О реализации данного класса см. example_project.cpp
//

class Cexample_projectApp : public CWinAppEx
{
public:
	Cexample_projectApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexample_projectApp theApp;
