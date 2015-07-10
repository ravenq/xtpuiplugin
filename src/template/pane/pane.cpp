#include <module/plugininc.h>
#include <utility/utilitymacro.h>
#include "{{project_name_lower}}.h"

C{{project_name}}::C{{project_name}}()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_dlg{{project_name}}.Create(CDlg{{project_name}}::IDD);
}

C{{project_name}}::~C{{project_name}}()
{
}

CWnd* C{{project_name}}::GetWnd()
{
	return &m_dlg{{project_name}};
}
