#pragma once

#include "PopupLayer.h"

class FileExplorerLayer : public PopupLayer
{
public:
	void customSetup() override;
	static FileExplorerLayer* create();
};