#include "{{project_name_lower}}view.h"

IMPLEMENT_DYNCREATE(C{{project_name}}View, CView)

BEGIN_MESSAGE_MAP(C{{project_name}}View, CView)

END_MESSAGE_MAP()

C{{project_name}}View::C{{project_name}}View()
{

}

C{{project_name}}View::~C{{project_name}}View()
{
}

void C{{project_name}}View::OnDraw(CDC* pDC)
{
	C{{project_name}}Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

}




