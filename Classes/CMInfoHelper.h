/*
 * CMInfoHelper.h
 *
 *  Created on: Jul 6, 2013
 *      Author: alex
 */

#ifndef CMINFOHELPER_H_
#define CMINFOHELPER_H_

#include "cocos2d.h"
#include "jni/JniHelper.h"

NS_CC_BEGIN

class CMInfoHelper
{
public:
  static long getAvailableRAM()
  {
    long retValue = 0;

    JniMethodInfo info;

    if (JniHelper::getStaticMethodInfo(info, "com/BananaHedgehog/CounterMove/CounterMove", "getAvailableRAM", "()J"))
      {
        jlong result = info.env->CallStaticLongMethod(info.classID, info.methodID);
        retValue = (long)result;
      }

    return retValue;
  }

  static long getThresholdMemory()
  {
    long retValue = 0;

    JniMethodInfo info;

    if (JniHelper::getStaticMethodInfo(info, "com/BananaHedgehog/CounterMove/CounterMove", "getThresholdMemory", "()J"))
      {
        jlong result = info.env->CallStaticLongMethod(info.classID, info.methodID);
        retValue = (long)result;
      }

    return retValue;
  }

  static long getTotalPSSMemory()
  {
    long retValue = 0;

    JniMethodInfo info;

    if (JniHelper::getStaticMethodInfo(info, "com/BananaHedgehog/CounterMove/CounterMove", "getPSSMemory", "()J"))
      {
        jlong result = info.env->CallStaticLongMethod(info.classID, info.methodID);
        retValue = (long)result;
      }

    return retValue;
  }

};

NS_CC_END;

#endif /* CMINFOHELPER_H_ */
