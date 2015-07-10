#pragma once
#include "resource.h"
#include <afxwin.h>

class CDlg{{project_name}} : public CDialog
{
	DECLARE_DYNAMIC(CDlg{{project_name}})

public:
	CDlg{{project_name}}(CWnd* pParent = NULL);
	virtual ~CDlg{{project_name}}();

	enum { IDD = IDD_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
};
