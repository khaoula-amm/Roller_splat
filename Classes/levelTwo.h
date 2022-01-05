#ifndef __LEVEL_TWO_SCENE_H__
#define __LEVEL_TWO_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class levelTwo : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    cocos2d::Sprite* boule;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(levelTwo);
    void next2(float dt);
    DrawNode* color;
};


#endif // LEVEL_TWO_SCENE_H__

