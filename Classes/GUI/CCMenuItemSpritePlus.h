#pragma once

#include <cocos2d.h>
#include <functional>

class CCMenuItemSpritePlus : public cocos2d::CCMenuItemSprite
{
CC_SYNTHESIZE(float, pScaleMultiplier, ScaleMultiplier)
CC_SYNTHESIZE(float, pBaseScale, BaseScale)

private:
	std::function<void()> pSelector;

protected:
	bool pFunctionSelector = false;

public:
	static CCMenuItemSpritePlus* create(cocos2d::CCNode* childNode, cocos2d::CCObject* other, cocos2d::SEL_MenuHandler sel);
	static CCMenuItemSpritePlus* createWithFunction(cocos2d::CCNode* childNode, cocos2d::CCObject* other, std::function<void()> selector);

	void setScale(const float scale) override;

	void activate() override;
	void selected() override;
	void unselected() override;
};