#include "ProjectsLayer.h"

USING_NS_CC;

void ProjectsLayer::customSetup()
{
	// TODO: Stuff
	auto visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	auto greyBG = extension::CCScale9Sprite::create("square02_001-uhd.png", { 0, 0, 320, 320 });
	pLayer->addChild(greyBG, 1);

	greyBG->setContentSize({ 1100, 675 });
	greyBG->setPosition(visibleSize / 2);
	greyBG->setPositionY(greyBG->getPositionY() - 30);
	greyBG->setOpacity(105);
}

ProjectsLayer* ProjectsLayer::create()
{
	auto ret = new (std::nothrow) ProjectsLayer();
	if (ret != nullptr && ret->init({ 1200, 800 }, "GJ_square04-uhd.png", "Projects Layer:"))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
