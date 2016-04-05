#include "ActionNewItem.h"

ActionNewItem::ActionNewItem(const std::string &name)
: _name(name)
{
}

const std::string& ActionNewItem::name() const
{
	return _name;
}

void ActionNewItemReducer(AppData &appData, const Action &action)
{
	const ActionNewItem *actionNewItem = dynamic_cast<const ActionNewItem*>(&action);

	if (actionNewItem)
	{
		Item item(appData.NextID(), actionNewItem->name());
		appData.items().push_back(item);
	}
}
