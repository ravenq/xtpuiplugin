#ifndef __I_{{project_name_upper}}_H__
#define __I_{{project_name_upper}}_H__

#include <module/classmacro.h>
#include <{{pkg_name}}/{{project_name_lower}}/i{{project_name_lower}}.h>

class C{{project_name}} : public I{{project_name}}
{
    X3BEGIN_CLASS_DECLARE(C{{project_name}}, clsid{{project_name}})
        X3DEFINE_INTERFACE_ENTRY(I{{project_name}})
    X3END_CLASS_DECLARE()
protected:
    C{{project_name}}();
    virtual ~C{{project_name}}();

private:

};

#endif //!__I_{{project_name_upper}}_H__