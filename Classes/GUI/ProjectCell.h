#pragma once

#include <cocos2d.h>
#include <cocos-ext.h>

#include "Other/ProjectDelegate.h"
#include "GUI/CCMenuItemSpritePlus.h"

class ProjectsLayer;
class ProjectCell : public cocos2d::CCLayer, public ProjectDelegate
{
CC_SYNTHESIZE(ProjectsLayer*, pProjectLayer, ProjectLayer)
private:
	cocos2d::extension::CCScale9Sprite* pBackground;
	CCMenuItemSpritePlus *pLabel;

public:
	virtual bool init();
	static ProjectCell* create(const std::string& name, ProjectsLayer* pl);
};