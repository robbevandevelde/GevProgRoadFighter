/**
 * @file
 * this file contains all tests for the scoreObservers
 */

#include <gtest/gtest.h>
#include <fstream>
#include <GLL_Entity_Factory.h>
#include <memory>
#include <Entities/EntityInclude.h>
#include <Observer/Observable.h>
#include <Observer/ScoreObserver.h>
using namespace roadfighter;
class ObserverTests: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    void SetUp() override{
        factory =  std::make_shared<GLL_Entity_Factory>();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    void TearDown() override{}

    std::shared_ptr<GLL_Entity_Factory> factory;
    // Declares the variables your tests want to use.

};

TEST_F(ObserverTests,ScoreObserver_Init_Tests){
    ScoreObserver testObject=ScoreObserver();
    ASSERT_EQ(testObject.getScore(),0);
}

TEST_F(ObserverTests,ScoreObserver_update_Tests){
    ScoreObserver testObject=ScoreObserver();
    testObject.update(100);
    ASSERT_EQ(testObject.getScore(),100);

    testObject.update(0);
    ASSERT_EQ(testObject.getScore(),100);

    testObject.update(-100);
    ASSERT_EQ(testObject.getScore(),0);

    testObject.update(-100);
    ASSERT_EQ(testObject.getScore(),0);
}

TEST_F(ObserverTests,Observer_Integration_Tests){
    std::shared_ptr<ScoreObserver> testObserver=std::dynamic_pointer_cast<ScoreObserver>(factory->getScoreObserver());
    auto player=std::dynamic_pointer_cast<PlayerCar>(factory->createPlayerCar(10,10,10,10,10,10));
    player->bonus();
    ASSERT_EQ(testObserver->getScore(),500);

    player->crash();
    ASSERT_EQ(testObserver->getScore(),0);

    player->win();
    ASSERT_EQ(testObserver->getScore(),6500);

    auto racer=std::dynamic_pointer_cast<RacingCar>(factory->createRacingCar(10,10,10,10,10));

    racer->shot();
    ASSERT_EQ(testObserver->getScore(),6700);

    racer->win();
    ASSERT_EQ(testObserver->getScore(),5700);

    auto passing=std::dynamic_pointer_cast<PassingCar>(factory->creatPassingCar(10,10,10));

    passing->shot();
    ASSERT_EQ(testObserver->getScore(),5800);

    auto bonus=std::dynamic_pointer_cast<BonusCar>(factory->createBonusCar(10,10,10));

    bonus->shot();
    ASSERT_EQ(testObserver->getScore(),5700);

    player=std::dynamic_pointer_cast<PlayerCar>(factory->createPlayerCar(10,10,10,10,10,10));
    player->detach();

    player->bonus();
    ASSERT_EQ(testObserver->getScore(),5700);

    player->crash();
    ASSERT_EQ(testObserver->getScore(),5700);

    player->win();
    ASSERT_EQ(testObserver->getScore(),5700);

}