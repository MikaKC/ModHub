#include "MainSelectLayer.h"

#include "GUI/SliderNode.h"
#include "GUI/CCMenuItemSpritePlus.h"

#include "CreateProjectLayer.h"
#include "SettingsLayer.h"
#include "ProjectsLayer.h"

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

    auto newButton = CCMenuItemSpritePlus::createWithFunction(CCSprite::createWithSpriteFrameName("GJ_newBtn_001.png"), this, [&](void) {
        CreateProjectLayer::create()->show();
    });
    newButton->setScale(0.f);
    newButton->runAction(CCEaseInOut::create(CCScaleTo::create(0.6f, 1), 2.f));
    newButton->setBaseScale(1.f);

    auto existingButton = CCMenuItemSpritePlus::createWithFunction(CCSprite::createWithSpriteFrameName("GJ_downloadBtn_001.png"), this, [&](void) {
        ProjectsLayer::create()->show();
    });
    existingButton->runAction(CCEaseBackOut::create(CCMoveTo::create(0.75f, { -newButton->getContentSize().width, 0 })));

    auto settingsButton = CCMenuItemSpritePlus::createWithFunction(CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png"), this, [&](void) {
        SettingsLayer::create()->show();
    });
    settingsButton->setScale(0.8f);
    settingsButton->runAction(CCEaseBackOut::create(CCMoveTo::create(0.75f, { newButton->getContentSize().width, 0 })));

    auto mainSprite = CCSprite::create("MH_MainSprite.png");
    mainSprite->setScale(0.f);
    this->addChild(mainSprite);
    mainSprite->runAction(CCEaseElasticOut::create(CCScaleTo::create(1.f, 0.8f), 0.6f));
    mainSprite->setPosition({ winSize.width / 2, winSize.height - mainSprite->getContentSize().height + 80 });

    menu->addChild(existingButton);
    menu->addChild(newButton, 1);
    menu->addChild(settingsButton);

    this->addChild(menu);

    return true;
}