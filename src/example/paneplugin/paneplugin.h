#ifndef X3_EXAMPLE_SIMPLE_IMPL_H
#define X3_EXAMPLE_SIMPLE_IMPL_H

#include <module/classmacro.h>
#include <interface/ipaneplugin.h>
#include <example/ipaneplugintest.h>
#include "DlgPane.h"

class CPanePluginTest : public IPanePluginTest, public IPanePlugin
{
    X3BEGIN_CLASS_DECLARE(CPanePluginTest, clsidPanePluginTest)
        X3DEFINE_INTERFACE_ENTRY(IPanePluginTest)
		X3DEFINE_INTERFACE_ENTRY(IPanePlugin)
    X3END_CLASS_DECLARE()
protected:
    CPanePluginTest();
    virtual ~CPanePluginTest();

	CDlgPane m_dlgPane;

private:
    CWnd* GetWnd();
	BOOL m_b;
};

#endif