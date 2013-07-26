/*
 * CMBacklight.h
 *
 *  Created on: Jul 3, 2013
 *      Author: alex
 */

#ifndef CMBACKLIGHT_H_
#define CMBACKLIGHT_H_

#include "cocos2d.h"

using namespace cocos2d;

class CMBacklight
: public CCNode
{
public:
	virtual ~CMBacklight();

	bool init();

	static CMBacklight *create();

protected:
	CMBacklight();
};

#endif /* CMBACKLIGHT_H_ */
