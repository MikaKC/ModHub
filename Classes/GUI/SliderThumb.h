#pragma once

#include <cocos2d.h>
#include <vector>

class SliderThumb : public cocos2d::CCSprite, public cocos2d::CCTouchDelegate
{
public:
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);

    virtual bool init(std::vector<float> minMax);

    static SliderThumb* createSliderThumb(std::vector<float> minMax);
private:

    CCSprite* pSpriteDeactivated;
    CCSprite* pSpriteActivated;

    float pMinimumSliderPos;
    float pMaximumSliderPos;

    bool pIsClickingOnSprite;
};