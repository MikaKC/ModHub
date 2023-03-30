#include "CreateProjectLayer.h"

USING_NS_CC;

void CreateProjectLayer::customSetup()
{
	// TODO: Stuff
	auto visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	
	auto greyBG = extension::CCScale9Sprite::create("square02_001-uhd.png", { 0, 0, 320, 320 });
	pLayer->addChild(greyBG, 1);
	
	greyBG->setContentSize({ 900, 475 });
	greyBG->setPosition(visibleSize / 2);
	greyBG->setPositionY(greyBG->getPositionY() - 30);
	greyBG->setOpacity(105);
}

CreateProjectLayer* CreateProjectLayer::create()
{
	auto ret = new (std::nothrow) CreateProjectLayer();
	if (ret != nullptr && ret->init({ 1000, 600 }, "GJ_square04-uhd.png", "Create New Project"))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
