#pragma once

#include <cocos2d.h>
#include <cocos-ext.h>

#include "Other/ProjectDelegate.h"

class ProjectCell : public cocos2d::CCLayer, public ProjectDelegate
{
private:
	cocos2d::extension::CCScale9Sprite* pBackground;
public:
	virtual bool init();
	static ProjectCell* create(const std::string& name);
};