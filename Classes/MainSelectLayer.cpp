#include "MainSelectLayer.h"

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



    
    return true;
}