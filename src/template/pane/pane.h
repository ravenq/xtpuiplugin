#ifndef __{{project_name}}_H__
#define __{{project_name}}_H__

#include <module/classmacro.h>
#include <interface/ipaneplugin.h>
#include <{{pkg_name}}/{{project_name_lower}}/i{{project_name_lower}}.h>
#include "dlg{{project_name_lower}}.h"

class C{{project_name}} : public I{{project_name}}, public IPanePlugin
{
    X3BEGIN_CLASS_DECLARE(C{{project_name}}, clsid{{project_name}})
        X3DEFINE_INTERFACE_ENTRY(I{{project_name}})
		X3DEFINE_INTERFACE_ENTRY(IPanePlugin)
    X3END_CLASS_DECLARE()
protected:
    C{{project_name}}();
    virtual ~C{{project_name}}();

	CDlg{{project_name}} m_dlg{{project_name}};

private:
    CWnd* GetWnd();
};

#endif //!__{{project_name}}_H__