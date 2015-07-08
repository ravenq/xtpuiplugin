#include "mainframedoc.h"
#include "mainframeview.h"

IMPLEMENT_DYNCREATE(CMainframeView, CView)

BEGIN_MESSAGE_MAP(CMainframeView, CView)
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMainframeView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

CMainframeView::CMainframeView()
{

}

CMainframeView::~CMainframeView()
{
}

BOOL CMainframeView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CView::PreCreateWindow(cs);
}

void CMainframeView::OnDraw(CDC* /*pDC*/)
{
	CMainframeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
}


void CMainframeView::OnFilePrintPreview()
{

}

BOOL CMainframeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void CMainframeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{

}

void CMainframeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{

}

void CMainframeView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMainframeView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{

}
