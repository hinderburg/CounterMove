#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "memvar.h"

class HelloWorld : public cocos2d::CCLayer
{

protected:
  CC_SYNTHESIZE(cocos2d::CCLabelTTF *, m_pRAMIndicator, RAMIndicator);
  CC_SYNTHESIZE(cocos2d::CCLabelTTF *, m_pTotalIndocator, TotalIndicator);

  CC_SYNTHESIZE(longM, m_cPSSIndicator, PSSIndicator);
  CC_SYNTHESIZE(longM, m_cIndicator, Indicator);

public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);

    void update();
    void reloadImage();

    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
