#include "AppData.h"

AppData::AppData()
: _visibility(vtAll)
{
}

VisibilityType AppData::visibility() const
{
	return _visibility;
}

std::vector<Item>& AppData::items()
{
	return _items;
}

size_t AppData::NextID() const
{
	return _items.size();
}
