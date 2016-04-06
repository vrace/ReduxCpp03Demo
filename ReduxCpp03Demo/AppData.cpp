#include "AppData.h"

AppData::AppData()
	: _visibility(vtAll)
{
}

VisibilityType AppData::visibility() const
{
	return _visibility;
}

AppData::ItemArray& AppData::items()
{
	return _items;
}

const AppData::ItemArray& AppData::items() const
{
	return _items;
}

size_t AppData::NextID() const
{
	return _items.size();
}
