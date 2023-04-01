#include "FileExplorerLayer.h"
#include "ProjectsLayer.h"

USING_NS_CC;

void FileExplorerLayer::closeOther(cocos2d::CCObject* pSel)
{
	auto layer = static_cast<ProjectsLayer*>(pSel);
	layer->onClose(nullptr);
}

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

void FileExplorerLayer::onClose(cocos2d::CCObject* pSender)
{
	getProjectLayer()->runAction(CCEaseElasticOut::create(CCScaleTo::create(0.5f, 1), 0.6f));
	getProjectLayer()->show();
	PopupLayer::onClose(nullptr);
}
static FileExplorerLayer* _sharedFileExplorer = nullptr;

FileExplorerLayer* FileExplorerLayer::sharedLayer(ProjectsLayer* pl)
{
	if (_sharedFileExplorer == nullptr) {
		_sharedFileExplorer = FileExplorerLayer::create(pl);
	}
	
	return _sharedFileExplorer;
}

FileExplorerLayer* FileExplorerLayer::create(ProjectsLayer* pl)
{
	auto ret = new (std::nothrow) FileExplorerLayer();
	pl->runAction(CCSequence::createWithTwoActions(CCEaseElasticOut::create(CCScaleTo::create(0.5f, 0), 0.6f), CCCallFuncO::create(ret, callfuncO_selector(FileExplorerLayer::closeOther), pl)));
	
	ret->setProjectLayer(pl);

	if (ret != nullptr && ret->init({ 900, 600 }, "GJ_square04-uhd.png", "Manage Project:"))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
