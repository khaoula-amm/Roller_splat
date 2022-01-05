#include"definition.h"
#include "levelOne.h"
#include "levelNext.h"

USING_NS_CC;

Scene* levelOne::createScene()
{
    auto scene = Scene::create();
    auto layer = Scene::create();
    return levelOne::create();
}

// on "init" you need to initialize your instance
bool levelOne::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // creation et position du background
    auto background_1 = Sprite::create("Roller.1.png");
    background_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.1 + origin.y));
    this->addChild(background_1, 0);
    background_1->setScale(2);

    // creation et position du obstacle 1
    auto obstacle1 = Sprite::create("obstacle.png");
    obstacle1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(obstacle1, 0);
    obstacle1->setScale(2);

    // creation et position du boule
    boule = Sprite::create("boule.png");
    boule->setPosition(Vec2(238, 56));
    this->addChild(boule, 2);
    boule->setScale(2);
    // pour faire la boule sauter 
    auto action = JumpBy::create(2, Point(0, 0), 15, 1);
    boule->runAction(action);
    //declaration de event keybord
    auto eventListiner = EventListenerKeyboard::create();
    eventListiner->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
    {

        float x, y;
        float offsetX, offsetY;
        offsetX = offsetY = 0;

        switch (keycode)
        {
            case
            EventKeyboard::KeyCode::KEY_RIGHT_ARROW: // pour la click droite
                x = event->getCurrentTarget()->getPositionX();
                y = event->getCurrentTarget()->getPositionY();
                if (x == 238 && y == 56)
                {
                    offsetX = 54;
                }

                break;

                
                case
                EventKeyboard::KeyCode::KEY_LEFT_ARROW:// pour la click gauche 
                    x = event->getCurrentTarget()->getPositionX();
                    y = event->getCurrentTarget()->getPositionY();
                    if (x == 292 && y == 160)
                    {
                        offsetX = -54;
                        // condition pour passer automatiquement de levelOne au page 'Nextlevel'
                        auto action = JumpBy::create(1, Point(0, 0), 18, 2);
                        boule->runAction(action);
                        this->scheduleOnce(CC_SCHEDULE_SELECTOR(levelOne::next), DISPLAY_TIME_SPLASH_SCENE);
                    }
                    if (x == 292 && y == 56)
                    {
                        offsetX = -54;
                    }
                    break;
                    case
                    EventKeyboard::KeyCode::KEY_UP_ARROW:// pour la click haut 
                        x = event->getCurrentTarget()->getPositionX(); 
                        y = event->getCurrentTarget()->getPositionY();
                        if (x == 292 && y == 56)
                        {
                            offsetY = 104;
                        }

                        break;
                        case
                        EventKeyboard::KeyCode::KEY_DOWN_ARROW:// pour la click bas
                            x = event->getCurrentTarget()->getPositionX();
                            y = event->getCurrentTarget()->getPositionY();
                            if (x == 292 && y == 160)
                            {
                                offsetY = -104;
                                auto drawnode = DrawNode::create();
                            }
                            break;
        }
                 

          // fonction pour deplacer la boule
        auto Move = MoveTo::create(0.1, Vec2(event->getCurrentTarget()->getPositionX() + offsetX, 
                                            event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(Move);
        //fonction de colorer le chemin du boule
        auto color = DrawNode::create();
        color->drawSegment(Vec2(x - 25, y + 35), Vec2(x - 25 + offsetX, y + offsetY + 35), 12.0f, Color4F::YELLOW);
        this->addChild(color, 1);
  
    };

    // pour lier event du keybord avec la boule
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListiner, boule);

}
// declaration de la fonction pour passer au 'Nextlevel'
void levelOne::next(float dt) 
{
    auto scene = levelNext::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

 }
