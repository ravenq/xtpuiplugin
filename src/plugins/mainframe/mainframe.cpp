#include <module/plugininc.h>
#include "mainframe.h"
#include <string>
#include "resource.h"
#include <utility/utilitymacro.h>
#include "mainframedoc.h"
#include "childfrm.h"
#include "mainframeview.h"

CMainFrame::CMainFrame()
{
	m_pMainFrameWnd = NULL;
}

CMainFrame::~CMainFrame()
{
	
}

BOOL CMainFrame::CreateFrame(LPCWSTR factoryFile)
{
	if (m_pMainFrameWnd != NULL)
		return TRUE;

	SWITCH_RESOURCE_HANDLE

	CXTPWinDwmWrapper().SetProcessDPIAware();

	CString strFile;
	ENV_RESOURCE_PATH(strFile)
	if (PathFileExists(strFile))
		XTPResourceManager()->SetResourceFile(strFile);
	else
		TRACE1("Warning: no translation file '%s'\n", strFile);

	// register template
	CMultiDocTemplate* pTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMainframeDoc),
		RUNTIME_CLASS(CChildFrame),
		RUNTIME_CLASS(CMainframeView));
	AfxGetApp()->AddDocTemplate(pTemplate);

	m_pMainFrameWnd = new CMainFrameWnd();
	 
	BOOL bRt = m_pMainFrameWnd->LoadFrame(IDR_MAINFRAME);

	AfxGetApp()->m_pMainWnd = m_pMainFrameWnd;

	return bRt;
}


void CMainFrame::ShowWindow()
{
	SWITCH_RESOURCE_HANDLE
	//AFX_MANAGE_STATE(AfxGetStaticModuleState());

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