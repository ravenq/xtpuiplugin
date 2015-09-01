#include "stdafx.h"
#include <string>
#include "resource.h"
#include "mainframe.h"
#include "childfrm.h"
#include "mainframedoc.h"
#include "mainframeview.h"
#include "utility\utilitymacro.h"

#include <interface/iviewlugin.h>

CMainFrame::CMainFrame()
{
	m_pMainFrameWnd = NULL;
}

CMainFrame::~CMainFrame()
{
	
}

void CMainFrame::RegisterTemplates()
{
	//CMultiDocTemplate* pTemplate = new CMultiDocTemplate(
	//	IDR_MAINFRAME,
	//	RUNTIME_CLASS(CMainframeDoc),
	//	RUNTIME_CLASS(CChildFrame),
	//	RUNTIME_CLASS(CMainframeView));
	//AfxGetApp()->AddDocTemplate(pTemplate);

	// TODO: load from config
	x3::Object<IViewPlugin> viewPluginPtr;
	if(!viewPluginPtr.create(_T("e2f969c0-2600-11e5-a15a-0021ccd9da8f")))
		 return;
	
	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(
		 IDR_MAINFRAME,
		 viewPluginPtr->GetDocRC(),
		 RUNTIME_CLASS(CChildFrame),
		 viewPluginPtr->GetViewRC());
	AfxGetApp()->AddDocTemplate(pTemplate);
}

BOOL CMainFrame::CreateFrame()
{
	if (m_pMainFrameWnd != NULL)
		return TRUE;

	CXTPWinDwmWrapper().SetProcessDPIAware();

	CString strFile;
	ENV_RESOURCE_PATH(strFile);
	if (PathFileExists(strFile))
		XTPResourceManager()->SetResourceFile(strFile);
	else
		TRACE1("Warning: no translation file '%s'\n", strFile);

	// register template
	RegisterTemplates();

	m_pMainFrameWnd = new CMainFrameWnd();
	 
	BOOL bRt = m_pMainFrameWnd->LoadFrame(IDR_MAINFRAME);

	AfxGetApp()->m_pMainWnd = m_pMainFrameWnd;

	return bRt;
}


void CMainFrame::ShowWindow()
{
	CCommandLineInfo cmdInfo;
	AfxGetApp()->ParseCommandLine(cmdInfo);

	if (cmdInfo.m_nShellCommand == CCommandLineInfo::FileNew)
		cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	if (!AfxGetApp()->ProcessShellCommand(cmdInfo))
		return;

	AfxGetMainWnd()->ShowWindow(SW_SHOWMAXIMIZED);
	AfxGetMainWnd()->UpdateWindow();
}

CWnd* CMainFrame::GetHandle()
{
	return m_pMainFrameWnd;
}

void CMainFrame::OnQuit()
{
}

BOOL CMainFrame::OnIdle(long)
{
	bool more = false;

	return more;
}