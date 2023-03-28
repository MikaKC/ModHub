#include "MainSelectLayer.h"

#include "GUI/SliderNode.h"

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

    float b = 0;
    SliderNode* slider = SliderNode::createSlider(b);
    this->addChild(slider);

    slider->setPosition({ 300, 300 });

    return true;
}