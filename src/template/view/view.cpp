#include <module/plugininc.h>
#include "{{project_name_lower}}.h"
#include "{{project_name_lower}}view.h"
#include "{{project_name_lower}}doc.h"

C{{project_name}}::C{{project_name}}()
{
}

C{{project_name}}::~C{{project_name}}()
{
}

CRuntimeClass* C{{project_name}}::GetViewRC()
{
	return RUNTIME_CLASS(C{{project_name}}View);
}

CRuntimeClass* C{{project_name}}::GetDocRC()
{
	return RUNTIME_CLASS(C{{project_name}}Doc);
}
