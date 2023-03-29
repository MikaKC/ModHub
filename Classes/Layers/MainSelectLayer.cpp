#include "MainSelectLayer.h"

#include "GUI/SliderNode.h"
#include "GUI/CCMenuItemSpritePlus.h"

USING_NS_CC;

CCScene* MainSelectLayer::scene()
{
    CCScene *scene = CCScene::create();
    MainSelectLayer *layer = MainSelectLayer::create();

    scene->addChild(layer);

    return scene;
}

bool MainSelectLayer::init()
{
    if (!CCLayer::init())
    {
        return false;
    }

    auto winSize = CCDirector::sharedDirector()->getVisibleSize();
    
    auto menu = CCMenu::create();

    auto button = CCMenuItemSpritePlus::create(CCLabelBMFont::create("Hello World", "bigFont-uhd.fnt"), this, nullptr);
    menu->addChild(button);

    this->addChild(menu);

    return true;
}