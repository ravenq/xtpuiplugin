#ifndef __I_PLUGIN_CONFIG_H__
#define __I_PLUGIN_CONFIG_H__

#include <objptr.h>

const char* const clsidPluginConfig = "8b33bf62-0877-4d41-b952-5cfd52256b88";

class IPluginConfig : public x3::IObject
{
	X3DEFINE_IID(IPluginConfig);
	// ribbon

	// plugin
	//virtual 
};

#endif //!__I_PLUGIN_CONFIG_H__