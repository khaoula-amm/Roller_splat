#include "levelTwo.h"
#include "definition.h"
#include "levelNext2.h"
#define CC_SCHEDULE_SELECTOR(_SELECTOR) static_cast<cocos2d::SEL_SCHEDULE>(&_SELECTOR)

USING_NS_CC;

Scene* levelTwo::createScene()
{
    auto scene = Scene::create();
    auto layer = Scene::create();
    return levelTwo::create();
}

// on "init" you need to initialize your instance
bool levelTwo::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // creation et position du background
    auto background_1 = Sprite::create("Roller.2.png");
    background_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.1 + origin.y));
    this->addChild(background_1, 0);
    background_1->setScale(2);

    // creation et position du obstacle 1
    auto obstacle1 = Sprite::create("obstacle2.png");
    obstacle1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(obstacle1, 0);
    obstacle1->setScale(2);

    // creation et position du boule
    boule = Sprite::create("boule.png");
    boule->setPosition(Vec2(223, 71));
    this->addChild(boule, 2);
    boule->setScale(2);
    auto action = JumpBy::create(2, Point(0, 0), 18, 1);
    boule->runAction(action);

    auto eventListiner = EventListenerKeyboard::create();
    eventListiner->onKeyPressed = [=](EventKeyboard::KeyCode keycode, Event* event)
    {

        float x, y;
        float offsetX, offsetY;
        offsetX = offsetY = 0;

        switch (keycode)
        {
            case
            EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
                x = event->getCurrentTarget()->getPositionX();
                y = event->getCurrentTarget()->getPositionY();
                if (x == 223 && y == 164)
                {
                    offsetX = 85;
                }
                if (x == 263 && y == 71)
                {
                    offsetX = 45;
                }
                break;
                //drawnode->clear();
                case
                EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                    x = event->getCurrentTarget()->getPositionX();
                    y = event->getCurrentTarget()->getPositionY();
                    if (x == 308 && y == 71)
                    {
                        offsetX = -45;
                    }
                    if (x == 308 && y == 164)
                    {
                        offsetX = -85;
                    }
                    break;
                    case
                    EventKeyboard::KeyCode::KEY_UP_ARROW:
                        x = event->getCurrentTarget()->getPositionX();
                        y = event->getCurrentTarget()->getPositionY();
                        if (x == 223 && y == 71)
                        {
                            offsetY = 93;
                        }
                        if (x == 308 && y == 71)
                        {
                            offsetY = 93;
                        }

                        if (x == 263 && y == 71)
                        {
                            offsetY = 51;
                            auto action = JumpBy::create(3, Point(0, 0), 18, 2);
                            boule->runAction(action);
                            auto funPointer = static_cast<cocos2d::SEL_SCHEDULE>(&levelTwo::next2);
                            this->scheduleOnce(funPointer, 2.0f);
                        }
                        break;
                        case
                        EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                            x = event->getCurrentTarget()->getPositionX();
                            y = event->getCurrentTarget()->getPositionY();
                            if (x == 223 && y == 164)
                            {
                                offsetY = -93;
                            }

                            if (x == 308 && y == 164)
                            {
                                offsetY = -93;
                                //auto drawnode = DrawNode::create();
                            }

                            break;
        }

        auto Move = MoveTo::create(0.1, Vec2(event->getCurrentTarget()->getPositionX() + offsetX,
            event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(Move);
        auto color = DrawNode::create();
        color->drawSegment(Vec2(x - 25, y + 35), Vec2(x - 25 + offsetX, y + offsetY + 35), 9.8f, Color4F::YELLOW);
        this->addChild(color, 1);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListiner, boule);







    /* auto color = DrawNode::create();
     color->drawPoint(Vec2(boule->getPositionX(), boule->getPositionY()), 40.0f, Color4F::GRAY);
     this->addChild(color);*/




}

void levelTwo::next2(float dt)
{
    auto scene = levelNext2::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}

