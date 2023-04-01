#include "CCMenuItemSpritePlus.h"

USING_NS_CC;

CCMenuItemSpritePlus* CCMenuItemSpritePlus::create(cocos2d::CCNode* childNode, cocos2d::CCObject* other, cocos2d::SEL_MenuHandler sel)
{
	auto ret = new (std::nothrow) CCMenuItemSpritePlus();

	ret->setScaleMultiplier(1.25f);
	ret->setBaseScale(1.f);
	ret->pFunctionSelector = false;
	ret->pSelector = nullptr;

	if (ret && ret->initWithNormalSprite(childNode, childNode, childNode, other, sel))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

CCMenuItemSpritePlus* CCMenuItemSpritePlus::createWithFunction(cocos2d::CCNode* childNode, cocos2d::CCObject* other, std::function<void()> sel)
{
	auto ret = new (std::nothrow) CCMenuItemSpritePlus();

	ret->setScaleMultiplier(1.25f);
	ret->setBaseScale(1.f);
	ret->pFunctionSelector = true;
	ret->pSelector = sel;

	if (ret && ret->initWithNormalSprite(childNode, childNode, childNode, other, nullptr))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

void CCMenuItemSpritePlus::setScale(const float scale)
{
	CCMenuItemSprite::setScale(scale);
	setBaseScale(scale);
}

void CCMenuItemSpritePlus::activate()
{
	CCMenuItemSprite::activate();
	this->stopAllActions();
	this->setScale(getBaseScale());

	if (pFunctionSelector)
		pSelector();
}

void CCMenuItemSpritePlus::selected()
{
	CCMenuItemSprite::selected();

	CCScaleTo* scaleAction = CCScaleTo::create(0.35f, getBaseScale() * getScaleMultiplier());
	CCEaseBounceOut* action = CCEaseBounceOut::create(scaleAction);

	this->runAction(action);
}

void CCMenuItemSpritePlus::unselected()
{
	CCMenuItemSprite::unselected();

	CCScaleTo* scaleAction = CCScaleTo::create(0.35f, getBaseScale());
	CCEaseBounceOut* action = CCEaseBounceOut::create(scaleAction);

	this->runAction(action);
}