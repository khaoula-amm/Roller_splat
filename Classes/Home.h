#ifndef __Home_SCENE_H__
#define __Home_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;

class Home : public Scene
{

public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(Home);

    cocos2d::Sprite* mySprite;
    // declaration de  la methode 'play'
    void play(Ref* psender);
};
#endif // __Home_SCENE_H__


