#pragma once

#include "PopupLayer.h"

class FileExplorerLayer : public PopupLayer
{
private:
	void closeOther(cocos2d::CCObject* p);

public:
	void customSetup() override;
	static FileExplorerLayer* create();
};