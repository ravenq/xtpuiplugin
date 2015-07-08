#pragma once
#include <XTToolkitPro.h>

class CMainFrameWnd : public CXTPMDIFrameWnd
{
	DECLARE_DYNCREATE(CMainFrameWnd)
public:
	CMainFrameWnd();
	virtual ~CMainFrameWnd();

public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	CXTPTabClientWnd  m_wndClient;
	CXTPDockingPaneManager m_dockPaneMgr;

	BOOL InitRibbonBars();
	BOOL CreateRibbonBar();
	BOOL InitRibbonTheme();
	BOOL InitDockPane();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

};


