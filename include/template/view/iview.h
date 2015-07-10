#ifndef __I_{{project_name_upper}}_H__
#define __I_{{project_name_upper}}_H__

#include <objptr.h>

const char* const clsid{{project_name}} = "{{uuid}}";

class I{{project_name}} : public x3::IObject
{
    X3DEFINE_IID(I{{project_name}});
};

#endif //!__I_{{project_name_upper}}_H__