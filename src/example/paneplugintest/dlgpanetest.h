#pragma once
#include "resource.h"
#include <afxwin.h>

class CDlgPane : public CDialog
{
	DECLARE_DYNAMIC(CDlgPane)

public:
	CDlgPane(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPane();

// 对话框数据
	enum { IDD = IDD_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
