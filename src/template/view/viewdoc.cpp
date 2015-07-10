#include "{{project_name_lower}}doc.h"
#include <propkey.h>

IMPLEMENT_DYNCREATE(C{{project_name}}Doc, CDocument)

BEGIN_MESSAGE_MAP(C{{project_name}}Doc, CDocument)
END_MESSAGE_MAP()

C{{project_name}}Doc::C{{project_name}}Doc()
{

}

C{{project_name}}Doc::~C{{project_name}}Doc()
{
}

BOOL C{{project_name}}Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

void C{{project_name}}Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	
	}
	else
	{
	
	}
}