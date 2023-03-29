#include "CreateProjectLayer.h"

void CreateProjectLayer::customSetup()
{
	// TODO: Stuff
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
