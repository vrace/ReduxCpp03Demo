#ifndef __REDUX_H__
#define __REDUX_H__

#include <vector>

template <class AppDataType, class ActionType>
class ReduxStore
{
public:
	typedef void (*ReducerType)(AppDataType&, const ActionType&);
	typedef std::vector<ReducerType> ReducerArray;

	class DispatchNotificationHandler
	{
	public:
		DispatchNotificationHandler()
		{
		}

		virtual ~DispatchNotificationHandler()
		{
		}

		virtual void AfterDispatch(const AppDataType &appData) = 0;
	};

	ReduxStore(AppDataType &appData, const ReducerArray &reducers)
		: _appData(appData)
		, _reducers(reducers)
		, _dispatchNotificationHandler(NULL)
	{
	}

	void Dispatch(const ActionType &action)
	{
		for (std::vector<ReducerType>::iterator it = _reducers.begin(); it != _reducers.end(); ++it)
			(*it)(_appData, action);

		if (_dispatchNotificationHandler)
			_dispatchNotificationHandler->AfterDispatch(_appData);
	}

	void Subscribe(DispatchNotificationHandler *handler)
	{
		_dispatchNotificationHandler = handler;
	}

private:
	AppDataType &_appData;
	ReducerArray _reducers;
	DispatchNotificationHandler *_dispatchNotificationHandler;
};

#endif
