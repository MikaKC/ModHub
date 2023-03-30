#include "FileExplorerLayer.h"

USING_NS_CC;

void FileExplorerLayer::customSetup()
{
	// TODO: Stuff
	auto visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	auto greyBG = extension::CCScale9Sprite::create("square02_001-uhd.png", { 0, 0, 320, 320 });
	pLayer->addChild(greyBG, 1);

	greyBG->setContentSize({ 800, 475 });
	greyBG->setPosition(visibleSize / 2);
	greyBG->setPositionY(greyBG->getPositionY() - 30);
	greyBG->setOpacity(105);
}

FileExplorerLayer* FileExplorerLayer::create()
{
	auto ret = new (std::nothrow) FileExplorerLayer();
	if (ret != nullptr && ret->init({ 900, 600 }, "GJ_square04-uhd.png", "Manage Project:"))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
