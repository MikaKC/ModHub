#include "SliderNode.h"

USING_NS_CC;

SliderNode* SliderNode::createSlider(float valueToMod)
{
	auto* ret = new (std::nothrow) SliderNode();
	if (ret && ret->init(valueToMod))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool SliderNode::init(float valueToMod)
{
	if (!CCLayer::init())
		return false;
	
	pThumb = SliderThumb::createSliderThumb({ pMinValue, pMaxValue }, &valueToMod);

	CCSprite* pSprite = CCSprite::create("slidergroove-uhd.png");
	pSprite->setPositionX(pSprite->getContentSize().width / 2);

	this->addChild(pThumb, 1);
	this->addChild(pSprite, 0);

	return true;
}