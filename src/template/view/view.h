#ifndef __{{project_name_upper}}_H__
#define __{{project_name_upper}}_H__

#include <module/classmacro.h>
#include <interface/iviewlugin.h>
#include <{{pkg_name}}/{{project_name_lower}}/i{{project_name_lower}}.h>

class C{{project_name}} : public I{{project_name}}, public IViewPlugin
{
    X3BEGIN_CLASS_DECLARE(C{{project_name}}, clsid{{project_name}})
        X3DEFINE_INTERFACE_ENTRY(I{{project_name}})
		 X3DEFINE_INTERFACE_ENTRY(IViewPlugin)
    X3END_CLASS_DECLARE()
protected:
    C{{project_name}}();
    virtual ~C{{project_name}}();

private:
	virtual CRuntimeClass* GetViewRC();
	virtual CRuntimeClass* GetDocRC();
};

#endif //!__{{project_name_upper}}_H__