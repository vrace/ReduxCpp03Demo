#ifndef __ACTION_TOGGLE_ITEM_H__
#define __ACTION_TOGGLE_ITEM_H__

#include "Action.h"

class ActionToggleItem : public Action
{
public:
	ActionToggleItem(size_t itemID);

	size_t id() const;

private:
	size_t _id;
};

void ActionToggleItemReducer(class AppData &appData, const Action &action);

#endif
