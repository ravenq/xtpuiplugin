#include <module/plugininc.h>
#include <module/pluginimpl.h>
#include <module/modulemacro.h>

#include "{{project_name}}.h"

XBEGIN_DEFINE_MODULE()
	XDEFINE_CLASSMAP_ENTRY_Singleton(C{{project_name}})
XEND_DEFINE_MODULE_DLL()

OUTAPI bool x3InitializePlugin()
{
    return true;
}

OUTAPI void x3UninitializePlugin()
{
}
