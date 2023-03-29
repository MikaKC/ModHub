#pragma once

#include <cocos2d.h>
#include <cocos-ext.h>

class PopupLayer : public cocos2d::CCLayerColor
{
CC_SYNTHESIZE(bool, pAnimation, Animation)

private:
	cocos2d::CCSize pLayerSize;

	cocos2d::CCLayer* pLayer;
	cocos2d::extension::CCScale9Sprite* pBG;

	cocos2d::CCMenu* pMenu;

public:
	virtual void customSetup()=0;
	virtual bool init(cocos2d::CCSize scale, const std::string& sprite, const std::string& title);

	virtual void keyBackClicked();
	
	virtual void show();

	virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) override { return true; }

	void onClose(cocos2d::CCObject* pSender);
};
