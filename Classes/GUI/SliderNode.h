#pragma once

#include <cocos2d.h>

class SliderNode : public cocos2d::CCLayer
{
public:
	virtual bool init();

private:

	const float pMaxValue{ 100 };
	const float pMinValue{ 0 };
};