#include "MainMenuScene.h"
#include "levelOne.h"
#include "Home.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{ // 'scene' is autorlease objet
    auto scene = MainMenuScene::create();
    // 'layer' is autorelease object 
    auto layer = MainMenuScene::create();
    //add layer as child to scene 
    scene->addChild(layer);
    //r return the scene
    return scene;
}

bool MainMenuScene::init()
{
   
    if (!Scene::init())
    {
        return false;
    }
   // il permit de preciser la position et Size du l'élement 
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //declaration et position du fond menu
    auto sprite = Sprite::create("menu.png");
    sprite->setScale(2);
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x,
        visibleSize.height / 2.3 + origin.y));
    this->addChild(sprite, 0);

    // declaration et position du button level1 
    auto menu_item_1 = MenuItemImage::create("level1.png", "level1.png",
        CC_CALLBACK_1(MainMenuScene::one, this));
    menu_item_1->setPosition(Point(visibleSize.width / 2 + origin.x,
        visibleSize.height / 2 + origin.y));
    menu_item_1->setScale(2);
    auto* menu_1 = Menu::create(menu_item_1, NULL);
    menu_1->setPosition(Point::ZERO);
    this->addChild(menu_1);

    // declaration et position level2
    auto menu_item_2 = Sprite::create("level2.png");
    menu_item_2->setScale(2);
    menu_item_2->setPosition(Vec2(visibleSize.width / 2 + origin.x,
        visibleSize.height / 2 + origin.y));
    this->addChild(menu_item_2, 0);

    // declaration et position du button level3
    auto menu_item_3 = Sprite::create("level3.png");
    menu_item_3->setScale(2);
    menu_item_3->setPosition(Vec2(visibleSize.width / 2 + origin.x,
        visibleSize.height / 2 + origin.y));
    this->addChild(menu_item_3, 0);
    return true;
}

// fonction pour passer au levelOne
void MainMenuScene::one(cocos2d::Ref* psender)
{
    CCLOG("level1.png");
    auto scene = levelOne::createScene();
    Director::getInstance()->replaceScene(scene);
}
