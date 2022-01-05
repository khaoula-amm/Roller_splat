#include"definition.h"
#include "levelThree.h"
#include "GameOver.h"
USING_NS_CC;

Scene* levelThree::createScene()
{
    auto scene = Scene::create();
    auto layer = Scene::create();
    return levelThree::create();
}

// on "init" you need to initialize your instance
bool levelThree::init()
{
    if (!Scene::init())
    {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // creation et position du background
    auto background_1 = Sprite::create("ROLLER.3.png");
    background_1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2.1 + origin.y));
    this->addChild(background_1, 0);
    background_1->setScale(2);

    // creation et position du obstacle 1
    auto obstacle1 = Sprite::create("obstacle3.png");
    obstacle1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(obstacle1, 0);
    obstacle1->setScale(2);

    // creation et position du boule
    boule = Sprite::create("boule.png");
    boule->setPosition(Vec2(233, 67));
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
                if (x == 233 && y == 67)
                {
                    offsetX = 69;
                }
                if (x == 234 && y == 171)
                {
                    offsetX = 71;
                    auto action = JumpBy::create(3, Point(0, 0), 18, 1);
                    boule->runAction(action);
                    this->scheduleOnce(CC_SCHEDULE_SELECTOR(levelThree::next3), DISPLAY_TIME_SPLASH_SCENE);

                }
                if (x == 234 && y == 120)
                {
                    offsetX = 68;

                }
                break;
                //drawnode->clear();
                case
                EventKeyboard::KeyCode::KEY_LEFT_ARROW:
                    x = event->getCurrentTarget()->getPositionX();
                    y = event->getCurrentTarget()->getPositionY();
                    if (x == 302 && y == 120)
                    {
                        offsetX = -68;

                    }
                    if (x == 302 && y == 67)
                    {
                        offsetX = -69;

                    }
                    break;
                    case
                    EventKeyboard::KeyCode::KEY_UP_ARROW:
                        x = event->getCurrentTarget()->getPositionX();
                        y = event->getCurrentTarget()->getPositionY();
                        if (x == 302 && y == 67)
                        {
                            offsetY = 53;
                        }
                        if (x == 234 && y == 120)
                        {
                            offsetY = 51;
                        }
                        break;
                        case
                        EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                            x = event->getCurrentTarget()->getPositionX();
                            y = event->getCurrentTarget()->getPositionY();
                            if (x == 292 && y == 160)
                            {
                                offsetY = -104;
                            }
                            if (x == 302 && y == 120)
                            {
                                offsetY = -53;
                            }
                            if (x == 234 && y == 171)
                            {
                                offsetY = -51;
                            }

                            if (x == 261 && y == 211)
                            {
                                offsetY = -102;

                            }
                            break;
        }



        auto Move = MoveTo::create(0.1, Vec2(event->getCurrentTarget()->getPositionX() + offsetX,
            event->getCurrentTarget()->getPositionY() + offsetY));
        event->getCurrentTarget()->runAction(Move);
        auto color = DrawNode::create();
        color->drawSegment(Vec2(x - 25, y + 35), Vec2(x - 25 + offsetX, y + offsetY + 35), 9.9f, Color4F::YELLOW);
        this->addChild(color, 1);
    };

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListiner, boule);


}
void levelThree::next3(float dt)
{
    auto scene = GameOver::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

}
