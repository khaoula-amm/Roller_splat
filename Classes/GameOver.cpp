#include "GameOver.h"
#include "definition.h"
#include "MainMenuScene.h"
USING_NS_CC;

Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = Scene::create();
    return GameOver::create();
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // creation et position du background
    auto background = Sprite::create("GameOver.png");
    background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(background);
    background->setScale(2);


    auto label = Label::createWithTTF("Return", "fonts/Marker Felt.ttf", 24);
    label->setPosition(Vec2(origin.x + visibleSize.width / 4, origin.y + visibleSize.height / 3.7 
                          - label->getContentSize().height));
    this->addChild(label, 1);

    auto playItem = MenuItemImage::create("bouton_next.png", "bouton_next.png", 
                                  CC_CALLBACK_1(GameOver::next, this));
    playItem->setPosition(Point(visibleSize.width / 1.5 + origin.x, visibleSize.height / 3.6 + origin.y));
    playItem->setScale(2);
    auto* menu = Menu::create(playItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu);
    return true;
}
void GameOver::next(cocos2d::Ref* psender)
{
    auto scene = MainMenuScene::createScene();
    Director::getInstance()->pushScene(scene);
}




