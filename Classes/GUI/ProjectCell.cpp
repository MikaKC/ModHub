#include "ProjectCell.h"
#include "Layers/FileExplorerLayer.h"
USING_NS_CC;
USING_NS_CC_EXT;

bool ProjectCell::init()
{
	if (!CCLayer::init()) return false;

	this->setContentSize({ 1100, 169 });
	auto menu = CCMenu::create();

	pLabel = CCMenuItemSpritePlus::createWithFunction(CCLabelBMFont::create(getProjectName().c_str(), "bigFont-uhd.fnt"), this, [=]() {  });
	menu->addChild(pLabel, 1);
	pLabel->setScale(0.5f);
	
	pBackground = CCScale9Sprite::create("square.png", { 0, 0, 32, 32 });
	this->addChild(pBackground, 0);
	pBackground->setColor({ 80, 45, 123 });
	pBackground->setOpacity(50);
	pBackground->setContentSize(this->getContentSize());

	menu->setTouchPriority(-500);
	this->addChild(menu);
	menu->setPosition({ 0, 0 });

	return true;
}

ProjectCell* ProjectCell::create(const std::string& name)
{
	auto ret = new (std::nothrow) ProjectCell;
	ret->setProjectName(name);

	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
