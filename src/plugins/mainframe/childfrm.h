#pragma once
#include <afxwin.h>

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

public:
	virtual ~CChildFrame();

protected:
	DECLARE_MESSAGE_MAP()
};
