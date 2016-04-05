#ifndef __REDUX_H__
#define __REDUX_H__

#include <vector>

template <class AppDataType, class ActionType>
class ReduxStore
{
public:
	typedef void (*ReducerType)(AppDataType&, const ActionType&);
	typedef std::vector<ReducerType> ReducerArray;

	ReduxStore(AppDataType &appData, const ReducerArray &reducers)
		: _appData(appData)
		, _reducers(reducers)
	{
	}

	void Dispatch(const ActionType &action)
	{
		for (std::vector<ReducerType>::iterator it = _reducers.begin(); it != _reducers.end(); ++it)
			(*it)(_appData, action);
	}

private:
	AppDataType &_appData;
	ReducerArray _reducers;
};

#endif
