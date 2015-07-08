#ifndef __I_PANE_PLUGIN_H__
#define __I_PANE_PLUGIN_H__

#include <objptr.h>
#include <afxwin.h>

class IPanePlugin : public x3::IObject
{
    X3DEFINE_IID(IPanePlugin);
	
	virtual CWnd* GetWnd() = 0;
};

#endif //!__I_PANE_PLUGIN_H__