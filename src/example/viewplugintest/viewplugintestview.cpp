#include "viewplugintestview.h"

IMPLEMENT_DYNCREATE(CViewPluginTestView, CView)

BEGIN_MESSAGE_MAP(CViewPluginTestView, CView)

END_MESSAGE_MAP()

CViewPluginTestView::CViewPluginTestView()
{

}

CViewPluginTestView::~CViewPluginTestView()
{
}

void CViewPluginTestView::OnDraw(CDC* pDC)
{
	CViewPluginTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rc;
	GetClientRect(&rc);
	rc.DeflateRect(1, 1, 1, 1);

	HFONT oldFont = (HFONT)pDC->SelectObject((HFONT)GetStockObject(SYSTEM_FIXED_FONT));
	pDC->Rectangle(rc);
	pDC->DrawText(_T("Hello! I am the view plugin"), &rc, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	pDC->SelectObject(oldFont);
}




