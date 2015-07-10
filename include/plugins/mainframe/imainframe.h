#ifndef __IFRAMEWND_H__
#define __IFRAMEWND_H__

#include <objptr.h>
#include <afxwin.h>

const char* const clsidMainFrame = "b19216ed-ecdb-4b0e-8e7d-75a4b4299e80";

class IMainFrame : public x3::IObject
{
    X3DEFINE_IID(IMainFrame);

    //virtual bool CheckAppInstance(const wchar_t* appid) = 0;

    virtual BOOL CreateFrame(const wchar_t* factoryFile) = 0;

	virtual void ShowWindow() = 0;

	virtual CWnd* GetHandle() = 0;

    virtual void OnQuit() = 0;

    virtual BOOL OnIdle(long count) = 0;
};

#endif //!__IFRAMEWND_H__