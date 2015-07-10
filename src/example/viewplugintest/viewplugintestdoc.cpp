#include "viewplugintestdoc.h"
#include <propkey.h>

IMPLEMENT_DYNCREATE(CViewPluginTestDoc, CDocument)

BEGIN_MESSAGE_MAP(CViewPluginTestDoc, CDocument)
END_MESSAGE_MAP()

CViewPluginTestDoc::CViewPluginTestDoc()
{

}

CViewPluginTestDoc::~CViewPluginTestDoc()
{
}

BOOL CViewPluginTestDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

void CViewPluginTestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	
	}
	else
	{
	
	}
}