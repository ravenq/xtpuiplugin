#ifndef __IFRAMEWND_H__
#define __IFRAMEWND_H__

#include <afxwin.h>

class IMainFrame
{
    //virtual bool CheckAppInstance(const wchar_t* appid) = 0;

    virtual BOOL CreateFrame() = 0;

	virtual void ShowWindow() = 0;

	virtual CWnd* GetHandle() = 0;

    virtual void OnQuit() = 0;

    virtual BOOL OnIdle(long count) = 0;
};

#endif //!__IFRAMEWND_H__