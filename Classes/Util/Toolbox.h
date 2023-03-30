#pragma once

#include <cocos2d.h>
#include <vector>

namespace Toolbox
{
	extern void alignItemsVerticallyWithPadding(std::vector<cocos2d::CCNode*> _children, float padding)
	{
		float height = -padding;

		for (const auto& child : _children)
			height += child->getContentSize().height * child->getScaleY() + padding;

		float y = height / 2.0f;

		for (const auto& child : _children) {
			child->setPosition(child->getPositionX(), child->getPositionY() +  y - child->getContentSize().height * child->getScaleY() / 2.0f);
			y -= child->getContentSize().height * child->getScaleY() + padding;
		}
	}
};