#include "Toolbox.h"

namespace Toolbox
{
	void AlignItemsVerticallyWithPadding(std::vector<cocos2d::CCNode*> children, float padding)
	{
		float height = -padding;

		for (const auto& child : children)
			height += child->getContentSize().height * child->getScaleY() + padding;

		float y = height / 2.0f;

		for (const auto& child : children) {
			child->setPosition(child->getPositionX(), child->getPositionY() + y - child->getContentSize().height * child->getScaleY() / 2.0f);
			y -= child->getContentSize().height * child->getScaleY() + padding;
		}
	}

	std::string WideStringToString(const std::wstring& wstr)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(wstr);
	}

	std::wstring StringToWideString(const std::string& str)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.from_bytes(str);
	}
}