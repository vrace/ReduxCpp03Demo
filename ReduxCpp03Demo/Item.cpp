#include "Item.h"

Item::Item(size_t id, const std::string &name)
	: _id(id)
	, _name(name)
	, _completed(false)
{
}

size_t Item::id() const
{
	return _id;
}

const std::string& Item::name() const
{
	return _name;
}

bool Item::completed() const
{
	return _completed;
}

void Item::SetCompleted()
{
	_completed = true;
}
