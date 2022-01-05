#include "Home.h"
#include "MainMenuScene.h"
USING_NS_CC;

Scene* Home::createScene()
{
    return Home::create();
}


bool Home::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // declaration et position du fond
    auto sprite = Sprite::create("Roller.png");
    sprite->setScale(2);
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(sprite, 0);
    // declaration et position du button play
    auto playItem = MenuItemImage::create("play_avant.png", "play_apres.png", CC_CALLBACK_1(Home::play, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    playItem->setScale(2);
    auto* menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);

    return true;
}
// fonction pour passer au menu 
void Home::play(cocos2d::Ref* psender)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->pushScene(scene);
}



