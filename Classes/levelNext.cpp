#include "levelNext.h"
#include "levelTwo.h"

USING_NS_CC;

Scene* levelNext::createScene()
{
    auto scene = Scene::create();
    auto layer = Scene::create();
    return levelNext::create();
}

// on "init" you need to initialize your instance
bool levelNext::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // creation et position du background
    auto background_Next = Sprite::create("next.png");
    background_Next->setPosition(Vec2(visibleSize.width / 2.1 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background_Next, 0);
    background_Next->setScale(2);

    auto playItem = MenuItemImage::create("bouton_next.png", "bouton_next.png",
        CC_CALLBACK_1(levelNext::next, this));
    playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    playItem->setScale(2);
    auto* menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    return true;
}
void levelNext::next(cocos2d::Ref* psender)
{
    auto scene = levelTwo::createScene();
    Director::getInstance()->pushScene(scene);
}




