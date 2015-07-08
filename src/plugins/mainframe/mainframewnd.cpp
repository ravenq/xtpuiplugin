#include <module/plugininc.h>
#include "mainframewnd.h"
#include "resource.h"
#include <utility/utilitymacro.h>
#include <interface/ipaneplugin.h>

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrameWnd, CXTPMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrameWnd, CXTPMDIFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(XTPWM_DOCKINGPANE_NOTIFY, OnDockingPaneNotify)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ×´Ì¬ÐÐÖ¸Ê¾Æ÷
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

CMainFrameWnd::CMainFrameWnd()
{
	
}

CMainFrameWnd::~CMainFrameWnd()
{
}

BOOL CMainFrameWnd::InitRibbonBars()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	pCommandBars->GetCommandBarsOptions()->ShowKeyboardCues(xtpKeyboardCuesShowWindowsDefault);
	pCommandBars->GetCommandBarsOptions()->bToolBarAccelTips = TRUE;
	pCommandBars->GetCommandBarsOptions()->bShowKeyboardTips = TRUE;
	pCommandBars->GetShortcutManager()->SetAccelerators(IDR_MAINFRAME);

	if (InitRibbonTheme() && !CreateRibbonBar())
	{
		TRACE0("Failed to create ribbon\n");
	}

	//if (!CreateStatusBar())
		//return FALSE;

	CXTPToolTipContext* pToolTipContext = pCommandBars->GetToolTipContext();
	pToolTipContext->SetStyle((XTPToolTipStyle)(xtpToolTipLuna + 1));
	pToolTipContext->ShowTitleAndDescription();
	pToolTipContext->SetMargin(CRect(2, 2, 2, 2));
	pToolTipContext->SetMaxTipWidth(180);

	//LoadCommandBars();

	//CreateDockingPanes();

	return TRUE;
}

BOOL CMainFrameWnd::CreateRibbonBar()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	CFile file(_T("D:\\GitHub\\xtpuiplugin\\build\\Debug\\cmdbars.xcb"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);

	pCommandBars->LoadDesignerBars(ar);

	CXTPRibbonBar* pRibbonBar = DYNAMIC_DOWNCAST(CXTPRibbonBar, pCommandBars->GetMenuBar());
	if (NULL == pRibbonBar)
		return FALSE;

	//SetRibbonFont();

	pRibbonBar->GetSystemButton()->SetStyle(xtpButtonCaption);
	pRibbonBar->EnableFrameTheme();

	return TRUE;
}

BOOL CMainFrameWnd::InitRibbonTheme()
{
	CXTPCommandBars* pCommandBars = GetCommandBars();

	CString strStyle;
	ENV_STYLE_DIR(strStyle);
	strStyle.Append(_T("\\Office2010.dll"));
	XTPResourceImages()->SetHandle(strStyle);
	XTPPaintManager()->SetTheme(xtpThemeRibbon);
	pCommandBars->SetTheme(xtpThemeRibbon);

	return TRUE;
}

BOOL CMainFrameWnd::InitDockPane()
{
	CXTPClientRect rect(this);

	m_dockPaneMgr.InstallDockingPanes(this);
	m_dockPaneMgr.SetTheme(xtpPaneThemeOffice2007);

	CXTPDockingPane* pPane = m_dockPaneMgr.CreatePane(222, CRect(0, 0, 190, rect.Height() / 2), xtpPaneDockLeft); // load from plugin
	pPane->SetOptions(xtpPaneNoFloatable | xtpPaneNoCloseable | xtpPaneNoDockable);

	return TRUE;
}

int CMainFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CXTPMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!InitCommandBars())
		return -1;

	if(!InitRibbonBars())
		return -1;
		
	if(!InitDockPane())
		return -1;

	m_wndClient.Attach(this, FALSE);
	m_wndClient.GetToolTipContext()->SetStyle((XTPToolTipStyle)(xtpToolTipLuna + 1));
	m_wndClient.SetFlags(xtpWorkspaceHideClose | xtpWorkspaceHideArrowsAlways);

	return 0;
}

LRESULT CMainFrameWnd::OnDockingPaneNotify(WPARAM wParam, LPARAM lParam)
{
	if(wParam != XTP_DPN_SHOWWINDOW)
		return FALSE;

	CXTPDockingPane* pPane = (CXTPDockingPane*)lParam;
	if(pPane->IsValid())
		return TRUE;

	switch(pPane->GetID())
	{
	case 222: // load from config
		{	
			x3::Object<IPanePlugin> panePtr;
			if(!panePtr.create("dc9869b9-520a-4b56-a6e9-9c8b1bde2be2")) // clsidPanePluginTest load from config
				return FALSE;

			CWnd* pWnd = panePtr->GetWnd();
			if(pWnd == NULL)
				return FALSE;

			pPane->Attach(pWnd);
			pWnd->ShowWindow(SW_SHOW);
		}
		break;
	default:
		break;
	}

	return TRUE;
}

BOOL CMainFrameWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style &= ~FWS_ADDTOTITLE;
	cs.lpszClass = _T("XTPMainFrame");
	cs.lpszName = _T("xtpuiplugin");
	CXTPDrawHelpers::RegisterWndClass(AfxGetInstanceHandle(), cs.lpszClass, CS_DBLCLKS, AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


