#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__
#include "cocos2d.h"
using namespace cocos2d;
class GameOver : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();
    cocos2d::Sprite* boule;
    // a selector callback
    void menuCloseCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);

    cocos2d::Sprite* mySprite;
    void next(Ref* psender);
};
#endif // __GAME_OVER_H__

