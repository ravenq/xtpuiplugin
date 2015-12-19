// RibbonMDISampleDoc.cpp : implementation of the CRibbonMDISampleDoc class
//

#include "stdafx.h"
//#include "RibbonMDISample.h"

#include "mainframedoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleDoc

IMPLEMENT_DYNCREATE(CMainframeDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(CMainframeDoc, CRichEditDoc)
	//{{AFX_MSG_MAP(CRibbonMDISampleDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleDoc construction/destruction

CMainframeDoc::CMainframeDoc()
{

}

CMainframeDoc::~CMainframeDoc()
{
}

BOOL CMainframeDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	return TRUE;
}

CRichEditCntrItem* CMainframeDoc::CreateClientItem(REOBJECT* preo) const
{
	// cast away constness of this
	return new CManiframeCntrItem(preo, (CMainframeDoc*) this);
}



/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleDoc serialization

void CMainframeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	CRichEditDoc::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleDoc diagnostics

#ifdef _DEBUG
void CMainframeDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void CMainframeDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDISampleDoc commands
