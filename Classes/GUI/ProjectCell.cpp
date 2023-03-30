#include "ProjectCell.h"

USING_NS_CC;
USING_NS_CC_EXT;

bool ProjectCell::init()
{
	if (!CCLayer::init()) return false;

	return true;
}

ProjectCell* ProjectCell::create(const std::string& name)
{
	auto ret = new (std::nothrow) ProjectCell();
	ret->setProjectName(name);

	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}

	CC_SAFE_DELETE(ret);
	return nullptr;
}
