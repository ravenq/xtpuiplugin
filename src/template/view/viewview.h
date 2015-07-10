#pragma once
#include "{{project_name_lower}}doc.h"

class C{{project_name}}View : public CView
{
protected:
	C{{project_name}}View();
	DECLARE_DYNCREATE(C{{project_name}}View)

public:
	C{{project_name}}Doc* GetDocument() const;

public:
	virtual void OnDraw(CDC* pDC);

public:
	virtual ~C{{project_name}}View();

	DECLARE_MESSAGE_MAP()
};

inline C{{project_name}}Doc* C{{project_name}}View::GetDocument() const
{ return reinterpret_cast<C{{project_name}}Doc*>(m_pDocument); }


