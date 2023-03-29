#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by CCDirector.
*/
class  AppDelegate : private cocos2d::CCApplication
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    /**
    @brief    Implement CCDirector and CCScene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

    /**
    @brief  Returns the refresh rate of the current monitor  
    */
    inline const float& getRefreshRate() {
        DEVMODE lpDevMode;
        memset(&lpDevMode, 0, sizeof(DEVMODE));
        lpDevMode.dmSize = sizeof(DEVMODE);
        lpDevMode.dmDriverExtra = 0;

        return static_cast<float>(lpDevMode.dmDisplayFrequency);
    };

    /**
    @brief  Loads all assets needed in memory
    */
    void loadAssets();
};

#endif // _APP_DELEGATE_H_

