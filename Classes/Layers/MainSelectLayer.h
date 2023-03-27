#pragma once

#include "cocos2d.h"

class MainSelectLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();  

    static cocos2d::CCScene* scene();

    CREATE_FUNC(MainSelectLayer);
};
