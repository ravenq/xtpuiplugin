//#include "stdafx.h"
#include <module/plugininc.h>
#include "paneplugintest.h"
#include <utility/utilitymacro.h>

CPanePluginTest::CPanePluginTest()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_dlgPane.Create(CDlgPane::IDD);
}

CPanePluginTest::~CPanePluginTest()
{
}

CWnd* CPanePluginTest::GetWnd()
{
	return &m_dlgPane;
}
