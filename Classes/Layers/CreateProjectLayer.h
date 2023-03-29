#pragma once

#include "PopupLayer.h"

class CreateProjectLayer : public PopupLayer
{
public:
	void customSetup() override;
	static CreateProjectLayer* create();
};