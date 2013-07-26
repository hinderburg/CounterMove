#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CMManager.h"
#include "CMInfoHelper.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
  // 'scene' is an autorelease object
  CCScene *scene = CCScene::create();

  // 'layer' is an autorelease object
  HelloWorld *layer = HelloWorld::create();

  // add layer as a child to scene
  scene->addChild(layer);

  // return the scene
  return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
  //////////////////////////////
  // 1. super init first
  if (!CCLayer::init())
    {
      return false;
    }

  m_bRunning = true;

  /////////////////////////////
  // 2. add a menu item with "X" image, which is clicked to quit the program
  //    you may modify it.

  // add a "close" icon to exit the progress. it's an autorelease object

  CCTexture2D::setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888);
  CCMenuItemImage *pCloseItem = CCMenuItemImage::create("CloseNormal.png",
      "CloseSelected.png", this,
      menu_selector(HelloWorld::reloadImage));
  pCloseItem->setPosition(
      ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20));

  CCControlButton *button = CCControlButton::create(CCLabelTTF::create("Test", "Thonburi", 20), CCScale9Sprite::create("button.png"));
  button->setZoomOnTouchDown(true);
  button->setContentSize(CCSizeMake(50, 50));
  button->setPreferredSize(CCSizeMake(50, 50));
  button->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::reloadImage), CCControlEventTouchUpInside);

  // create menu, it's an autorelease object
  CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
  pMenu->setPosition(CCPointZero);
  this->addChild(pMenu, 1);

  CCLayerColor *pLayer = CCLayerColor::create();
  pLayer->setColor(ccBLUE);
  pLayer->setOpacity(255);
  this->addChild(pLayer, 0, 0);

  /////////////////////////////
  // 3. add your codes below...

  // add a label shows "Hello World"
  // create and initialize a label

  m_pRAMIndicator = CCLabelTTF::create(CCString::createWithFormat("Free RAM - %i Kb", (int)CMInfoHelper::getAvailableRAM())->getCString(), "Thonburi", 34);
  m_pRAMIndicator->setColor(ccYELLOW);

  m_pTotalIndocator = CCLabelTTF::create(CCString::createWithFormat("")->getCString(), "Thonburi", 20);
  m_pTotalIndocator->setColor(ccBLACK);

  // ask director the window size
  CCSize size = CCDirector::sharedDirector()->getWinSize();

  // position the label on the center of the screen
  m_pRAMIndicator->setPosition(ccp(size.width / 2, size.height - 20));
  m_pTotalIndocator->setPosition(ccp(size.width / 2, size.height - 120));

  button->setPosition(ccp(size.width / 2, button->getContentSize().height / 2));
  this->addChild(button);

  // add the label as a child to this layer
  this->addChild(m_pRAMIndicator, 1);
  this->addChild(m_pTotalIndocator, 1);

  this->schedule(schedule_selector(HelloWorld::update), 1.0f);

  return true;
}


void HelloWorld::reloadImage()
{
  m_cPSSIndicator = CMInfoHelper::getTotalPSSMemory();
  m_cIndicator = CMInfoHelper::getAvailableRAM() - CMInfoHelper::getThresholdMemory();

  CCTextureCache::sharedTextureCache()->addImage("anime.png");
  CCTextureCache::sharedTextureCache()->addImage("1.png");
  CCTextureCache::sharedTextureCache()->addImage("2.png");
  CCTextureCache::sharedTextureCache()->addImage("3.png");
  CCTextureCache::sharedTextureCache()->addImage("4.png");

  m_cPSSIndicator = CMInfoHelper::getTotalPSSMemory();
  m_cIndicator = CMInfoHelper::getAvailableRAM() - CMInfoHelper::getThresholdMemory();
}


void HelloWorld::update()
{
  m_pRAMIndicator->setString(CCString::createWithFormat("PSS delta - %i Kb", m_cPSSIndicator.delta())->getCString());
  m_pTotalIndocator->setString(CCString::createWithFormat("Free Memory - %i Kb", m_cIndicator.delta())->getCString());
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
  CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  exit(0);
#endif
}
