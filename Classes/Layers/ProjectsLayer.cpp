#include "ProjectsLayer.h"

#include "Util/EasyClippingNode.h"
#include "Util/Toolbox.h"

#include "GUI/CCMenuItemSpritePlus.h"
#include "GUI/ProjectCell.h"

#include "FileExplorerLayer.h"
#include "Other/ProjectManager.h"

USING_NS_CC;

#define SCROLL_SPEED 0.175f

void ProjectsLayer::moveScroll(float y)
{
	for (CCNode* cell : pCells)
	{
		cell->setPositionY(cell->getPositionY() + y);
	}
}

void ProjectsLayer::scrollWheel(float x, float y)
{
	this->moveScroll(-y * SCROLL_SPEED);
}

bool ProjectsLayer::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
	return true;
}
void ProjectsLayer::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent)
{
	float movementAmt = pTouch->getPreviousLocationInView().y - pTouch->getLocationInView().y;

	this->moveScroll(movementAmt);
}

void ProjectsLayer::customSetup()
{
	auto visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	CCDirector::sharedDirector()->getMouseDispatcher()->addDelegate(this);

	auto greyBG = extension::CCScale9Sprite::create("square.png", { 0, 0, 32, 32 });
	pLayer->addChild(greyBG, 1);

	greyBG->setColor({ 0,0,0 });
	greyBG->setContentSize({ 1100, 675 });
	greyBG->setPosition(visibleSize / 2);
	greyBG->setPositionY(greyBG->getPositionY() - 30);
	greyBG->setOpacity(105);

	auto baseClippingNode = EasyClipping::create();
	pLayer->addChild(baseClippingNode, 1);
	baseClippingNode->setContentSize({ 1100, 673 });
	baseClippingNode->setPosition({ 250, 84.f });

	for (const std::string& entry : ProjectManager::sharedManager()->GetAllFoldersInDir(ProjectManager::sharedManager()->getSearchDirectory()))
		pCells.push_back(ProjectCell::create(entry));

	CCMenu* listMenu = CCMenu::create();

	// add any list objects in baseClippingNode
	for (CCNode* cell : pCells)
	{
		listMenu->addChild(cell);
	}

	baseClippingNode->addChild(listMenu);
	listMenu->setPosition(baseClippingNode->getContentSize() / 2);
	listMenu->alignItemsVertically();
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
