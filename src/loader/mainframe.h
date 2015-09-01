#ifndef __MAINFRAME_IMPL_H__
#define __MAINFRAME_IMPL_H__

#include "mainframewnd.h"
#include "interface/imainframe.h"

class CMainFrame : public IMainFrame
{
public:
    CMainFrame();
    virtual ~CMainFrame();

	virtual BOOL CreateFrame();
	virtual void ShowWindow();
	virtual CWnd* GetHandle();
	virtual void OnQuit();
	virtual BOOL OnIdle(long count);

protected:
	void RegisterTemplates();
	CMainFrameWnd* m_pMainFrameWnd;
};

#endif //!__MAINFRAME_IMPL_H__