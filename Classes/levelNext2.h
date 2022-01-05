#ifndef __LEVEL_NEXT2_SCENE_H__
#define __LEVEL_NEXT2_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

class levelNext2 : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    cocos2d::Sprite* boule;


    // a selector callback
    void menuCloseCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(levelNext2);

    cocos2d::Sprite* mySprite;
    void next(Ref* psender);


};


#endif // LEVEL_NEXT2_SCENE_H__

