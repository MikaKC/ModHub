#pragma once

#include <cocos2d.h>

#include "SliderThumb.h"
#include <functional>

class SliderNode : public cocos2d::CCLayer
{
public:
	virtual bool init(float valueToMod);

	static SliderNode* createSlider(float valueToMod);

private:
	SliderThumb* pThumb;

	const float pMaxValue{ 100 };
	const float pMinValue{ 0 };
};