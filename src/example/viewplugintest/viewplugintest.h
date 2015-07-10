#ifndef __VIEW_PLUGIN_TEST_H__
#define __VIEW_PLUGIN_TEST_H__

#include <module/classmacro.h>
#include <example/viewplugintest/iviewplugintest.h>
#include <interface/iviewlugin.h>

class CViewPluginTest : public IViewPluginTest, public IViewPlugin
{
    X3BEGIN_CLASS_DECLARE(CViewPluginTest, clsidViewPluginTest)
        X3DEFINE_INTERFACE_ENTRY(IViewPluginTest)
		 X3DEFINE_INTERFACE_ENTRY(IViewPlugin)
    X3END_CLASS_DECLARE()
protected:
    CViewPluginTest();
    virtual ~CViewPluginTest();

private:
	virtual CRuntimeClass* GetViewRC();
	virtual CRuntimeClass* GetDocRC();
};

#endif //!__VIEW_PLUGIN_TEST_H__