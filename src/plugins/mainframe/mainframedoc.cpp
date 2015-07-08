#include "mainframedoc.h"
#include <propkey.h>

IMPLEMENT_DYNCREATE(CMainframeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMainframeDoc, CDocument)
END_MESSAGE_MAP()

CMainframeDoc::CMainframeDoc()
{

}

CMainframeDoc::~CMainframeDoc()
{
}

BOOL CMainframeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

void CMainframeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	
	}
	else
	{
	
	}
}