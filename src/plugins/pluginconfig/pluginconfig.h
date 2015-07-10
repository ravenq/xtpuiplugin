#ifndef X3_EXAMPLE_SIMPLE_IMPL_H
#define X3_EXAMPLE_SIMPLE_IMPL_H

#include <module/classmacro.h>
#include <plugins/pluginconfig/ipluginconfig.h>

class CPluginConfig : public IPluginConfig
{
    X3BEGIN_CLASS_DECLARE(CPluginConfig, clsidPluginConfig)
        X3DEFINE_INTERFACE_ENTRY(IPluginConfig)
    X3END_CLASS_DECLARE()
protected:
    CPluginConfig();
    virtual ~CPluginConfig();

};

#endif