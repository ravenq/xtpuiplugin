#pragma once
#include <afxwin.h>

class CViewPluginTestDoc : public CDocument
{
protected: // 仅从序列化创建
	CViewPluginTestDoc();
	DECLARE_DYNCREATE(CViewPluginTestDoc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~CViewPluginTestDoc();

protected:
	DECLARE_MESSAGE_MAP()
};
