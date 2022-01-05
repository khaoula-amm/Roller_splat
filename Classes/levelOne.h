#ifndef __LEVEL_ONE_SCENE_H__
#define __LEVEL_ONE_SCENE_H__
#include "cocos2d.h"
using namespace cocos2d;
class levelOne : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    cocos2d::Sprite* boule;

    // implement the "static create()" method manually
    CREATE_FUNC(levelOne);
    // declaration de  la methode 'next'
    void next(float dt);
    // declaration de  la methode de coloration
    DrawNode* color;
};
#endif // LEVEL_ONE_SCENE_H__