#include <iostream>
#include <vector>

#include "Redux.h"
#include "AppData.h"
#include "ActionNewItem.h"

int main(void)
{
	typedef ReduxStore<AppData, Action> StoreType;

	AppData data;
	StoreType::ReducerArray reducers;
	reducers.push_back(ActionNewItemReducer);

	ReduxStore<AppData, Action> store(data, reducers);

	store.Dispatch(ActionNewItem("Hello"));
	store.Dispatch(ActionNewItem("World"));

	return 0;
}
