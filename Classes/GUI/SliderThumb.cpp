#include "SliderThumb.h"
USING_NS_CC;

#define FORCE 1.f

SliderThumb* SliderThumb::createSliderThumb(std::vector<float> minMax, float* valueToMod)
{
	auto* ret = new (std::nothrow) SliderThumb();
	
	ret->setValueToModify(valueToMod);

	if (ret != nullptr && ret->init(minMax))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}

bool SliderThumb::init(std::vector<float> minMax)
{
	if (!CCSprite::init())
		return false;

	pSpriteActivated = CCSprite::create("sliderthumbsel-uhd.png");
	pSpriteActivated->setVisible(false);
	pSpriteDeactivated = CCSprite::create("sliderthumb-uhd.png");

	this->addChild(pSpriteActivated);
	this->addChild(pSpriteDeactivated);

	this->setContentSize(pSpriteDeactivated->getContentSize());
	pSpriteActivated->setPosition(this->getContentSize() / 2);
	pSpriteDeactivated->setPosition(this->getContentSize() / 2);

	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -127, true);
	pMinimumSliderPos = minMax[0];
	pMaximumSliderPos = minMax[1];

	return true;
}

bool SliderThumb::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)
{
	CCPoint touchLocation = pTouch->getLocation();
	if (this && this->isVisible())
	{
		CCPoint local = this->convertToNodeSpace(touchLocation);
		CCRect r = this->rect();
		r.origin = CCPointZero;

		if (r.containsPoint(local))
		{
			pSpriteActivated->setVisible(true);
			pSpriteDeactivated->setVisible(false);

			pIsClickingOnSprite = true;
		}
	}

	return true;
}

void SliderThumb::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent)
{
	if (pIsClickingOnSprite == true)
	{
		float movementAmt = pTouch->getPreviousLocationInView().x - pTouch->getLocationInView().x;
		CCLOG("%f.3", movementAmt);

		float desiredForce = -(movementAmt * FORCE);

		this->setPositionX(this->getPositionX() + desiredForce);
	}
}

void SliderThumb::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)
{
	pSpriteActivated->setVisible(false);
	pSpriteDeactivated->setVisible(true);

	pIsClickingOnSprite = false;
}