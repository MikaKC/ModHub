#include "MainSelectLayer.h"

#include "GUI/SliderThumb.h"

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

    SliderThumb* thumb = SliderThumb::createSliderThumb({ 100.f, 100.f });
    menu->addChild(thumb);
    this->addChild(menu);

    return true;
}