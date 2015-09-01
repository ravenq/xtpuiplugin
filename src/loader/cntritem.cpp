#include "stdafx.h"
#include "mainframedoc.h"
#include "mainframeview.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleCntrItem implementation

IMPLEMENT_SERIAL(CManiframeCntrItem, CRichEditCntrItem, 0)

CManiframeCntrItem::CManiframeCntrItem(REOBJECT* preo, CMainframeDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: add one-time construction code here
	
}

CManiframeCntrItem::~CManiframeCntrItem()
{
	// TODO: add cleanup code here
	
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleCntrItem diagnostics

#ifdef _DEBUG
void CManiframeCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void CManiframeCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
