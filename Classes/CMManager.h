/*
 * CMManager.h
 *
 *  Created on: Jul 3, 2013
 *      Author: alex
 */

#ifndef CMMANAGER_H_
#define CMMANAGER_H_

#include "cocos2d.h"
#include <pthread.h>

static pthread_mutex_t _initMutex = PTHREAD_MUTEX_INITIALIZER;

class CMManager
{
	static CMManager *sharedInstance;

public:

	CMManager *sharedManager()
	{
		if (!sharedInstance)
		{
			pthread_mutex_lock(&_initMutex);
			sharedInstance = new CMManager();
			pthread_mutex_unlock(&_initMutex);
		}

		return sharedInstance;
	}

private:

	CMManager();
	~CMManager();

	CMManager(const CMManager *){};
	CMManager * operator=(const CMManager *){};

	void lazyInit();
};

#endif /* CMMANAGER_H_ */
