#ifndef __LEVEL_THREE_SCENE_H__
#define __LEVEL_THREE_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class levelThree : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    cocos2d::Sprite* boule;

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(levelThree);

    void next3(float dt);
    DrawNode* color;

};


#endif // LEVEL_THREESCENE_H__
