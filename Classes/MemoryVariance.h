/*
 * MemoryVariance.h
 *
 *  Created on: 10.06.2013
 *      Author: alex
 */

#ifndef MEMORYVARIANCE_H_
#define MEMORYVARIANCE_H_

template<typename T>
struct memoryVar
{
private:
	T _curr;
	T _prev;
	bool _isFirst;

public:

	memoryVar & operator=(T const &v)
	{
		if (_isFirst)
		{
			_prev = _curr = 0;
			_isFirst = false;
		}
		_prev = _curr;
		_curr = v;

		return *this;
	}

	T var()
	{
		return _curr;
	}

	T prev()
	{
		return _prev;
	}
	;

	// TODO: increment, decrement, +, - ,*, /

};

typedef memoryVar<int> intM;

#endif /* MEMORYVARIANCE_H_ */
