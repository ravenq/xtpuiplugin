#pragma once
#include <afxwin.h>

class C{{project_name}}Doc : public CDocument
{
protected: // 仅从序列化创建
	C{{project_name}}Doc();
	DECLARE_DYNCREATE(C{{project_name}}Doc)

public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 实现
public:
	virtual ~C{{project_name}}Doc();

protected:
	DECLARE_MESSAGE_MAP()
};
