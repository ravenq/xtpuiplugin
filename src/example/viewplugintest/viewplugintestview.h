#pragma once
#include "viewplugintestdoc.h"

class CViewPluginTestView : public CView
{
protected:
	CViewPluginTestView();
	DECLARE_DYNCREATE(CViewPluginTestView)

public:
	CViewPluginTestDoc* GetDocument() const;

public:
	virtual void OnDraw(CDC* pDC);

public:
	virtual ~CViewPluginTestView();

	DECLARE_MESSAGE_MAP()
};

inline CViewPluginTestDoc* CViewPluginTestView::GetDocument() const
{ return reinterpret_cast<CViewPluginTestDoc*>(m_pDocument); }


