#include <module/plugininc.h>
#include "viewplugintest.h"
#include "viewplugintestview.h"
#include "viewplugintestdoc.h"

CViewPluginTest::CViewPluginTest()
{
}

CViewPluginTest::~CViewPluginTest()
{
}

CRuntimeClass* CViewPluginTest::GetViewRC()
{
	return RUNTIME_CLASS(CViewPluginTestView);
}

CRuntimeClass* CViewPluginTest::GetDocRC()
{
	return RUNTIME_CLASS(CViewPluginTestDoc);
}
