#pragma once
#include <afxwin.h>

class CMainframeDoc : public CDocument
{
protected: // 仅从序列化创建
	CMainframeDoc();
	DECLARE_DYNCREATE(CMainframeDoc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CMainframeDoc();

protected:
	DECLARE_MESSAGE_MAP()
};
