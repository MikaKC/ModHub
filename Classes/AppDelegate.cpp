#include "AppDelegate.h"
#include "Layers/MainSelectLayer.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
    pDirector->setAnimationInterval(1.0 / this->getRefreshRate());
    pDirector->setContentScaleFactor(2.f);

    loadAssets();

    pDirector->runWithScene(MainSelectLayer::scene());

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}

void AppDelegate::loadAssets()
{
    auto sfc = CCSpriteFrameCache::sharedSpriteFrameCache();
    auto tc = CCTextureCache::sharedTextureCache();

    tc->addImage("GJ_GameSheet03-uhd.png");
    sfc->addSpriteFramesWithFile("GJ_GameSheet03-uhd.plist", "GJ_GameSheet03-uhd.png");
}