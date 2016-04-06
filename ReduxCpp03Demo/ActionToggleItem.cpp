#include "ActionToggleItem.h"
#include "AppData.h"

ActionToggleItem::ActionToggleItem(size_t itemID)
	: _id(itemID)
{
}

size_t ActionToggleItem::id() const
{
	return _id;
}

void ActionToggleItemReducer(AppData &appData, const Action &action)
{
	const ActionToggleItem *toggle = dynamic_cast<const ActionToggleItem*>(&action);

	if (toggle)
	{
		AppData::ItemArray &items = appData.items();
		size_t id = toggle->id();

		if (id >= 0 && id < items.size())
		{
			Item &item = items[id];
			item.SetCompleted();
		}
	}
}
