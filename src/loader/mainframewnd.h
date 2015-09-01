// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__80941DC7_4E2C_448D_9EFB_39D39517AF9C__INCLUDED_)
#define AFX_MAINFRM_H__80941DC7_4E2C_448D_9EFB_39D39517AF9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrameWnd : public CXTPMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrameWnd)
public:
	CMainFrameWnd();
	virtual ~CMainFrameWnd();

protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	BOOL CreateRibbonBar();
	BOOL InitDockPane();
	void LoadIcons();

	void OnSetPreviewMode(BOOL bPreview, CPrintPreviewState* pState);
	void ShowCustomizeDialog(int nSelectedPage);
	void OnCustomize();
	void OnCustomizeQuickAccess();
	void OnViewWorkspace();
	void OnUpdateViewWorkspace(CCmdUI* pCmdUI);
	void OnUpdateRibbonTab(CCmdUI* pCmdUI);

protected:
	CXTPStatusBar  m_wndStatusBar;
	CXTPTabClientWnd m_wndClient;
	CXTPDockingPaneManager m_dockPaneMgr;
	UINT m_nRibbonStyle;
	BOOL m_bShowWorkspace;

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewFullscreen();
	afx_msg void OnViewNormal();
	afx_msg void OnUpdateViewNormal(CCmdUI* pCmdUI);
	afx_msg void OnWindowArrange();
	afx_msg void OnUpdateWindowSwitch(CCmdUI* pCmdUI);
	afx_msg void OnClose();
	afx_msg BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	afx_msg BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg void OnOptionsRighttoleft();
	afx_msg void OnUpdateOptionsRighttoleft(CCmdUI* pCmdUI);
	afx_msg void OnOptionsStyle(UINT nStyle);
	afx_msg void OnUpdateOptionsStyle(CCmdUI* pCmdUI);
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__80941DC7_4E2C_448D_9EFB_39D39517AF9C__INCLUDED_)
