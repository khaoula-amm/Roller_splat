#ifndef __MAIN_MENU_SCENE_H__
#define __MAIN_MENU_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class MainMenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually

    CREATE_FUNC(MainMenuScene);

    cocos2d::Sprite* mySprite;
    // declaration de  la methode 'one'
    void one(Ref* psender);
};
#endif // __MAIN_MENU_SCENE_H__