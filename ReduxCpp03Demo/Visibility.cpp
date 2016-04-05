#include "Visibility.h"

std::string VisibilityDescription(VisibilityType visibility)
{
	switch (visibility)
	{
	case vtAll:
		return "All";

	case vtIncomplete:
		return "Incomplete";

	case vtCompleted:
		return "Completed";

	default:
		break;
	}

	return "";
}
