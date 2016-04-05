#ifndef __APP_DATA_H__
#define __APP_DATA_H__

#include <vector>
#include "Item.h"
#include "Visibility.h"

class AppData
{
public:
	typedef std::vector<Item> ItemArray;

	AppData();

	VisibilityType visibility() const;
	ItemArray& items();
	const ItemArray& items() const;

	size_t NextID() const;

private:
	VisibilityType _visibility;
	ItemArray _items;
};

#endif
