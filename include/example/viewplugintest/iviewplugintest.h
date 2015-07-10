#ifndef __I_VIEW_PLUGIN_TEST_H__
#define __I_VIEW_PLUGIN_TEST_H__

#include <objptr.h>

const char* const clsidViewPluginTest = "e2f969c0-2600-11e5-a15a-0021ccd9da8f";

class IViewPluginTest : public x3::IObject
{
    X3DEFINE_IID(IViewPluginTest);
};

#endif //!__I_VIEW_PLUGIN_TEST_H__