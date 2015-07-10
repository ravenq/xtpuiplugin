#include "dlg{{project_name_lower}}.h"

IMPLEMENT_DYNAMIC(CDlg{{project_name}}, CDialog)

CDlg{{project_name}}::CDlg{{project_name}}(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg{{project_name}}::IDD, pParent)
{

}

CDlg{{project_name}}::~CDlg{{project_name}}()
{
}

void CDlg{{project_name}}::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlg{{project_name}}, CDialog)
END_MESSAGE_MAP()

