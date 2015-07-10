#ifndef __I_PANE_PLUGIN_TEST__
#define __I_PANE_PLUGIN_TEST__
#include <objptr.h>

const char* const clsidPanePluginTest = "dc9869b9-520a-4b56-a6e9-9c8b1bde2be2";

class IPanePluginTest : public x3::IObject
{
    X3DEFINE_IID(IPanePluginTest);

	//virtual 
};

#endif //!__I_PANE_PLUGIN_TEST__