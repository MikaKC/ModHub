#pragma once

#include "PopupLayer.h"

class SettingsLayer : public PopupLayer
{
public:
	void customSetup() override;
	static SettingsLayer* create();
};