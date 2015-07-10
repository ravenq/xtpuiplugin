#include "dlgpanetest.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CDlgPane, CDialog)

CDlgPane::CDlgPane(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPane::IDD, pParent)
{

}

CDlgPane::~CDlgPane()
{
}

void CDlgPane::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPane, CDialog)
END_MESSAGE_MAP()


// CDlgPane 消息处理程序
