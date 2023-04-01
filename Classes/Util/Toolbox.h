#pragma once

#include <cocos2d.h>
#include <vector>
#include <locale>
#include <codecvt>

namespace Toolbox
{
	extern void AlignItemsVerticallyWithPadding(std::vector<cocos2d::CCNode*> _children, float padding);

	std::string WideStringToString(const std::wstring& wstr);
	std::wstring StringToWideString(const std::string& str);
};