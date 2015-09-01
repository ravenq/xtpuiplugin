#ifndef __I_PANE_PLUGIN_H__
#define __I_PANE_PLUGIN_H__

#include <module/plugininc.h>
#include <objptr.h>
#include <afxwin.h>

class IViewPlugin : public x3::IObject
{
    X3DEFINE_IID(IViewPlugin);
	
	virtual CRuntimeClass* GetViewRC() = 0;
	virtual CRuntimeClass* GetDocRC() = 0;
};

#endif //!__I_PANE_PLUGIN_H__