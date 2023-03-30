#pragma once

#include "PopupLayer.h"

class ProjectsLayer : public PopupLayer
{
public:
	void customSetup() override;
	static ProjectsLayer* create();
};
