#pragma once

#include "PopupLayer.h"

class ProjectsLayer : public PopupLayer, public cocos2d::CCMouseDelegate
{
private:
	// TODO: Cells
	std::vector<cocos2d::CCNode*> pCells;

public:

	virtual void scrollWheel(float x, float y);

	void customSetup() override;
	static ProjectsLayer* create();
};
