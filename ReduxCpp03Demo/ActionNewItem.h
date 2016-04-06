#ifndef __ACTION_NEW_ITEM_H__
#define __ACTION_NEW_ITEM_H__

#include <string>
#include "Action.h" 

class ActionNewItem : public Action
{
public:
	ActionNewItem(const std::string &name);

	const std::string& name() const;

private:
	std::string _name;
};

void ActionNewItemReducer(class AppData &appData, const Action &action);

#endif
