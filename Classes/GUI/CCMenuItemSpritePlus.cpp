#include "CCMenuItemSpritePlus.h"

USING_NS_CC;

CCMenuItemSpritePlus* CCMenuItemSpritePlus::create(cocos2d::CCNode* childNode, cocos2d::CCObject* other, cocos2d::SEL_MenuHandler sel)
{
	auto ret = new (std::nothrow) CCMenuItemSpritePlus();
	ret->setScaleMultiplier(1.25f);

	if (ret && ret->initWithNormalSprite(childNode, childNode, childNode, other, sel))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

void CCMenuItemSpritePlus::activate()
{
	CCMenuItemSprite::activate();
	this->stopAllActions();
	this->setScale(1);
}

void CCMenuItemSpritePlus::selected()
{
	CCMenuItemSprite::selected();

	CCScaleTo* scaleAction = CCScaleTo::create(0.35f, 1.f * getScaleMultiplier());
	CCEaseBounceOut* action = CCEaseBounceOut::create(scaleAction);

	this->runAction(action);
}

void CCMenuItemSpritePlus::unselected()
{
	CCMenuItemSprite::unselected();

	CCScaleTo* scaleAction = CCScaleTo::create(0.35f, 1.f);
	CCEaseBounceOut* action = CCEaseBounceOut::create(scaleAction);

	this->runAction(action);
}