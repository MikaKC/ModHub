#include "PopupLayer.h"
#include "GUI/CCMenuItemSpritePlus.h"

USING_NS_CC;

bool PopupLayer::init(cocos2d::CCSize scale, const std::string& sprite, const std::string& title)
{
    auto visibleSize = cocos2d::CCDirector::sharedDirector()->getVisibleSize();
    this->pLayerSize = scale;

    if (!this->initWithColor({ 0, 0, 0, 75 })) return false;
    this->pLayer = cocos2d::CCLayer::create();
    this->addChild(this->pLayer);

    auto bg = cocos2d::extension::CCScale9Sprite::create(sprite.c_str(), {0.0f, 0.0f, 320.f, 320.f});
    bg->setContentSize(this->pLayerSize);
    bg->setPosition(visibleSize.width / 2, visibleSize.height / 2);
    this->pLayer->addChild(bg);

    this->pMenu = cocos2d::CCMenu::create();
    this->pLayer->addChild(this->pMenu);

    if (sizeof title > 0) {
        auto text = CCLabelBMFont::create(title.c_str(), "bigFont-uhd.fnt");
        text->setScale(0.4f);

        text->setPosition(
            visibleSize.width / 2,
            visibleSize.height / 2 + this->pLayerSize.height / 2 - 50
        );

        this->pLayer->addChild(text);
    }

    customSetup();


    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -300, true);
    pMenu->setTouchPriority(-400);

    auto closeSpr = cocos2d::CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    closeSpr->setScale(.75f);

    auto closeBtn = CCMenuItemSpritePlus::create(
        closeSpr,
        this,
        (cocos2d::SEL_MenuHandler)&PopupLayer::onClose
    );
    closeBtn->setUserData(reinterpret_cast<void*>(this));

    this->pMenu->addChild(closeBtn);

    closeBtn->setPosition(-scale.width / 2 + 40, scale.height / 2 - 10);

    this->setKeypadEnabled(true);
    this->setTouchEnabled(true);

    return true;
}

void PopupLayer::keyBackClicked()
{
    this->onClose(nullptr);
}

void PopupLayer::show()
{
    CCDirector::sharedDirector()->getRunningScene()->addChild(this, CCDirector::sharedDirector()->getRunningScene()->getHighestChildOrder() + 1);

    auto visibleSize = cocos2d::CCDirector::sharedDirector()->getVisibleSize();

    // Add margin (+5)
    this->setPositionX(visibleSize.width + pLayerSize.width + 5);

    auto moveAction = CCMoveTo::create(0.5f, {0,0});
    auto ease = CCEaseElasticOut::create(moveAction, 0.6f);
    
    if (this->getAnimation())
        this->runAction(ease);
    else
        this->setPosition({ 0, 0 });
}

void PopupLayer::onClose(cocos2d::CCObject* pSender)
{
    this->setKeypadEnabled(false);
    this->removeFromParentAndCleanup(true);
}