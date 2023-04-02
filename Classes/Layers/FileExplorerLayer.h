#pragma once

#include "PopupLayer.h"
class ProjectsLayer;
class FileExplorerLayer : public PopupLayer
{
CC_SYNTHESIZE(ProjectsLayer*, pProjectsLayer, ProjectLayer)
private:
	void closeOther(cocos2d::CCObject* p);

public:
	void customSetup() override;
	void onClose(cocos2d::CCObject* pSender) override;
	static FileExplorerLayer* create(ProjectsLayer* pl);
};