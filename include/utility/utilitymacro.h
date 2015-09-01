#ifndef __UTILITY_MACRO_H__
#define __UTILITY_MACRO_H__
class CLocalResource  
{
	HINSTANCE	m_hResource;
public:
	CLocalResource(HINSTANCE hResource)
	{	
		m_hResource=0;
		if(hResource)
		{
			m_hResource=AfxGetResourceHandle();
			AfxSetResourceHandle(hResource);		
		}

	};
	~CLocalResource()
	{
		if(m_hResource)
			AfxSetResourceHandle(m_hResource);
	}

};

#define SWITCH_RESOURCE_HANDLE CLocalResource _civlocalres(_AtlBaseModule.GetResourceInstance());

// evironment
#define ENV_LOADER_NAME _T("loader")
#define __PRO_DIR \
	HMODULE hMod = GetModuleHandle(ENV_LOADER_NAME); \
	TCHAR szName[MAX_PATH] = _T(""); \
	GetModuleFileName(hMod, szName, MAX_PATH); \
	PathRemoveFileSpec(szName);

#define ENV_PRO_DIR(x) \
	__PRO_DIR \
	x = szName;

#define ENV_RESOURCE_NAME _T("ToolkitPro.ResourceZhCn.xml")
#define ENV_RESOURCE_PATH(x) \
	__PRO_DIR \
	PathAppend(szName, _T("Translations")); \
	PathAppend(szName, ENV_RESOURCE_NAME); \
	x = szName;

#define ENV_STYLE_DIR(x) \
	__PRO_DIR \
	PathAppend(szName, _T("styles")); \
	x = szName;

#define  ENV_LAYOUT_FILE(x) \
	__PRO_DIR \
	PathAppend(szName, _T("layout.xml")); \
	x = szName;


#endif //!__UTILITY_MACRO_H__