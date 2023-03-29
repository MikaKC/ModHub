#include "MainSelectLayer.h"

#include "GUI/SliderNode.h"
#include "GUI/CCMenuItemSpritePlus.h"

#include "CreateProjectLayer.h"

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

    CCLOG("hi");

    auto winSize = CCDirector::sharedDirector()->getVisibleSize();
    
    auto menu = CCMenu::create();

    auto button = CCMenuItemSpritePlus::createWithFunction(CCSprite::createWithSpriteFrameName("GJ_newBtn_001.png"), this, [&](void) {
        CreateProjectLayer::create()->show();
    });


    menu->addChild(button);

    auto slider = SliderNode::createSlider(0.f);
    slider->setPosition({ 100, 100 });
    
    this->addChild(slider);
    this->addChild(menu);

    return true;
}