#include "childfrm.h"

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)

END_MESSAGE_MAP()

CChildFrame::CChildFrame()
{
	
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style= WS_CHILD|WS_VISIBLE|WS_OVERLAPPEDWINDOW|WS_MAXIMIZE|FWS_ADDTOTITLE;

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


