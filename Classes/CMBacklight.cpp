/*
 * CMBacklight.cpp
 *
 *  Created on: Jul 3, 2013
 *      Author: alex
 */

#include "CMBacklight.h"

CMBacklight::~CMBacklight()
{
	// TODO Auto-generated destructor stub
}
CMBacklight::CMBacklight()
{
	// TODO Auto-generated constructor stub
}

bool CMBacklight::init()
{
	bool result = true;

	result &= CCNode::init();

	return result;
}


CMBacklight * CMBacklight::create()
{
	CMBacklight *pRet = new CMBacklight();
	if (!pRet || !pRet->init())
		CC_SAFE_DELETE(pRet);

	return pRet;
}
