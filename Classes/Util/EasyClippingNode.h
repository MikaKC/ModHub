#pragma once

#include <cocos2d.h>

/**
 * Class for dealing with clipping (rendering only parts of nodes). Simply add
 * children to this node, and use the content size to adjust the area being clipped.
 */
class EasyClipping : public cocos2d::CCClippingNode {
protected:
    cocos2d::CCLayerColor* m_stencil;

    bool init(bool invert) {
        m_stencil = cocos2d::CCLayerColor::create({ 255, 255, 255, 255 });

        if (!CCClippingNode::init(m_stencil))
            return false;

        this->setInverted(invert);
        this->updateClippingRect();

        return true;
    }

    void updateClippingRect() {
        m_stencil->setContentSize(m_obContentSize);
    }

public:
    /**
     * Create a Clip. All ares of children that exceed the clip's content size
     * are not rendered (clipped out)
     * @param invert Invert the clipping behaviour, so only parts of children
     * outside the clip's content size are rendered
     */
    static EasyClipping* create(bool invert = false) {
        auto ret = new EasyClipping();
        if (ret && ret->init(invert)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    void setContentSize(cocos2d::CCSize const& size) override {
        CCClippingNode::setContentSize(size);
        this->updateClippingRect();
    }
};