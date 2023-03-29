#pragma once

#include <cocos2d.h>

class CCMenuItemSpritePlus : public cocos2d::CCMenuItemSprite
{
CC_SYNTHESIZE(float, scaleMultiplier, ScaleMultiplier)
public:
	static CCMenuItemSpritePlus* create(cocos2d::CCNode* childNode, cocos2d::CCObject* other, cocos2d::SEL_MenuHandler sel);

	void activate() override;
	void selected() override;
	void unselected() override;
};