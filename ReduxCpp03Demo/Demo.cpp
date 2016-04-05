#include <iostream>
#include <vector>
#include <ostream>

#include "Redux.h"
#include "AppData.h"
#include "ActionNewItem.h"

typedef ReduxStore<AppData, Action> StoreType;

class OutputAppDataSummaryHandler : public StoreType::DispatchNotificationHandler
{
public:
	virtual void AfterDispatch(const AppData &appData);
};

std::ostream& operator <<(std::ostream &s, const AppData &appData)
{
	for (AppData::ItemArray::const_iterator it = appData.items().begin();
		it != appData.items().end(); ++it)
	{
		s << (it->completed() ? 'X' : ' ') << "   ";
		s << it->name() << std::endl;
	}

	s << "**** Visibility: " << VisibilityDescription(appData.visibility()) << " ****" << std::endl;
	s << "========================================" << std::endl;

	return s;
}

void OutputAppDataSummaryHandler::AfterDispatch(const AppData &appData)
{
	std::cout << appData << std::endl;
}

int main(void)
{
	AppData data;
	StoreType::ReducerArray reducers;
	reducers.push_back(ActionNewItemReducer);

	ReduxStore<AppData, Action> store(data, reducers);

	OutputAppDataSummaryHandler handler;
	store.Subscribe(&handler);

	store.Dispatch(ActionNewItem("Hello"));
	store.Dispatch(ActionNewItem("World"));

	return 0;
}
