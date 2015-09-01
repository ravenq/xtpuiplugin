
// uimain.h : uimain 应用程序的主头文件
//
#pragma once
#include <objptr.h>

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

class CUimainApp : public CWinApp
{
public:
	CUimainApp();

private:
	 void LoadCorePlugins();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};

extern CUimainApp theApp;
