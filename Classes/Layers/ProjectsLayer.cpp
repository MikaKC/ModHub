#include "ProjectsLayer.h"

#include "Util/EasyClippingNode.h"
#include "Util/Toolbox.h"

#include "GUI/CCMenuItemSpritePlus.h"
#include "FileExplorerLayer.h"

USING_NS_CC;

void ProjectsLayer::scrollWheel(float x, float y)
{
	for (CCNode* cell : pCells)
	{
		cell->setPositionY(cell->getPositionY() + (-y * 0.1f));
	}
}

bool ProjectsLayer::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	return true;
}

void ProjectsLayer::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent)
{
	float movementAmt = pTouch->getPreviousLocationInView().y - pTouch->getLocationInView().y;
	CCLOG("%f.3", movementAmt);

	float desiredForce = movementAmt * 10.f;

	this->scrollWheel(0, desiredForce);
}

void ProjectsLayer::customSetup()
{
	auto visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCDirector::sharedDirector()->getMouseDispatcher()->addDelegate(this);

	auto greyBG = extension::CCScale9Sprite::create("square02_001-uhd.png", { 0, 0, 320, 320 });
	pLayer->addChild(greyBG, 1);

	greyBG->setContentSize({ 1100, 675 });
	greyBG->setPosition(visibleSize / 2);
	greyBG->setPositionY(greyBG->getPositionY() - 30);
	greyBG->setOpacity(105);

	auto baseClippingNode = EasyClipping::create();
	pLayer->addChild(baseClippingNode, 2);
	baseClippingNode->setContentSize({ 1100, 673 });
	baseClippingNode->setPosition({ 250, 84.f });

	pCells.push_back(CCMenuItemSpritePlus::createWithFunction(CCLabelBMFont::create("FutureDash", "bigFont-uhd.fnt"), pLayer, [&]() { FileExplorerLayer::create(this)->show(); }));
	pCells.push_back(CCMenuItemSpritePlus::createWithFunction(CCLabelBMFont::create("FutureDash-Geode", "bigFont-uhd.fnt"), pLayer, [&]() { FileExplorerLayer::create(this)->show(); }));
	pCells.push_back(CCMenuItemSpritePlus::createWithFunction(CCLabelBMFont::create("GDPSTools", "bigFont-uhd.fnt"), pLayer, [&]() { FileExplorerLayer::create(this)->show(); }));

	CCMenu* listMenu = CCMenu::create();
	listMenu->setTouchPriority(-350);

	// add any list objects in baseClippingNode
	for (CCNode* cell : pCells)
	{
		static_cast<CCMenuItemSpritePlus*>(cell)->setScale(0.5f);
		listMenu->addChild(cell);

		cell->setPosition(baseClippingNode->getContentSize() / 2);
		
		baseClippingNode->addChild(listMenu);
	}

	listMenu->setPosition(baseClippingNode->getContentSize() / 2);
	listMenu->alignItemsVerticallyWithPadding(1.f);
}

ProjectsLayer* ProjectsLayer::create()
{
	auto ret = new (std::nothrow) ProjectsLayer();
	if (ret != nullptr && ret->init({ 1200, 800 }, "GJ_square04-uhd.png", "Projects:"))
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
