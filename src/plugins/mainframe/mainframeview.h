#pragma once

class CMainframeView : public CView
{
protected:
	CMainframeView();
	DECLARE_DYNCREATE(CMainframeView)

public:
	CMainframeDoc* GetDocument() const;

public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	virtual ~CMainframeView();

protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

inline CMainframeDoc* CMainframeView::GetDocument() const
{ return reinterpret_cast<CMainframeDoc*>(m_pDocument); }


