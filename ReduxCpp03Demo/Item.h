#ifndef __ITEM_H__
#define __ITEM_H__

#include <string>

class Item
{
public:
	Item(size_t id, const std::string &name);

	size_t id() const;
	const std::string& name() const;
	bool completed() const;

	void SetCompleted();

private:
	size_t _id;
	std::string _name;
	bool _completed;
};

#endif
