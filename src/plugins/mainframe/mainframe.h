#ifndef __MAINFRAME_IMPL_H__
#define __MAINFRAME_IMPL_H__

#include <module/classmacro.h>
#include <mainframe/imainframe.h>
#include "mainframewnd.h"

class CMainFrame : public IMainFrame
{
    X3BEGIN_CLASS_DECLARE(CMainFrame, clsidMainFrame)
        X3DEFINE_INTERFACE_ENTRY(IMainFrame)
    X3END_CLASS_DECLARE()
protected:
    CMainFrame();
    virtual ~CMainFrame();

	CMainFrameWnd* m_pMainFrameWnd;

private:
	virtual BOOL CreateFrame(const wchar_t* factoryFile);
	virtual void ShowWindow();
	virtual CWnd* GetHandle();
	virtual void OnQuit();
	virtual BOOL OnIdle(long count);
};

#endif //!__MAINFRAME_IMPL_H__