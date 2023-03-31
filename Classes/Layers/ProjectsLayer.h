#pragma once

#include "PopupLayer.h"

class ProjectsLayer : public PopupLayer, public cocos2d::CCMouseDelegate, public cocos2d::CCTouchDelegate
{
private:
	// TODO: Cells
	std::vector<cocos2d::CCNode*> pCells;

public:

	virtual void scrollWheel(float x, float y);

	virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);


	void customSetup() override;
	static ProjectsLayer* create();
};
