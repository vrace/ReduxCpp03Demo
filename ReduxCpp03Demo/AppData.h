#ifndef __APP_DATA_H__
#define __APP_DATA_H__

#include <vector>
#include "Item.h"
#include "Visibility.h"

class AppData
{
public:
	AppData();

	VisibilityType visibility() const;
	std::vector<Item>& items();

	size_t NextID() const;

private:
	VisibilityType _visibility;
	std::vector<Item> _items;
};

#endif
