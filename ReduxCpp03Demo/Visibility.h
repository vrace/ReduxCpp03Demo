#ifndef __VISIBILITY_H__
#define __VISIBILITY_H__

#include <string>

enum VisibilityType
{
	vtAll,
	vtIncomplete,
	vtCompleted,
};

std::string VisibilityDescription(VisibilityType visibility);

#endif
