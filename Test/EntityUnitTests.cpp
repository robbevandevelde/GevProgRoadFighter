//
// Created by thibaut on 31.12.18.
//
#include <gtest/gtest.h>
#include <fstream>
#include <GLL_Entity_Factory.h>
#include <memory>
#include <Entities/EntityInclude.h>

using namespace roadfighter;

class EntityunitTests: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
       factory =  std::make_shared<GLL_Entity_Factory>();
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {}

    std::shared_ptr<GLL_Entity_Factory> factory;
    // Declares the variables your tests want to use.

};

TEST_F(EntityunitTests,MovingObject_Init_Tests){
    std::shared_ptr<MovingObject> testobject=std::make_shared<MovingObject>(Location(0,0),Location(1,0),100,10,10);
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getVerticalSpeed(),0);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getMaxVertSpeed(),100);
    ASSERT_EQ(testobject->getVertAccel(),10);
    ASSERT_EQ(testobject->getHorAccel(),10);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);
}

TEST_F(EntityunitTests,MovingObject_GetterSetters_Tests){
    std::shared_ptr<MovingObject> testobject=std::make_shared<MovingObject>(Location(0,0),Location(1,0),100,10,10);
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),100);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,MovingObject_function_Tests) {
    std::shared_ptr<MovingObject> testobject = std::make_shared<MovingObject>(Location(0, 0), Location(1, 0), 100, 10,10);
    testobject->updateMovement(1);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));

    testobject->setVerticalSpeed(10);
    testobject->setHorizontalSpeed(1);
    testobject->updateMovement(1);
    ASSERT_EQ(testobject->getLoc1(),Location(1,-10));
    ASSERT_EQ(testobject->getLoc2(),Location(2,-10));

    testobject->updateMovement(1);
    ASSERT_EQ(testobject->getLoc1(),Location(2,-20));
    ASSERT_EQ(testobject->getLoc2(),Location(3,-20));

    testobject->updateMovement(1);
    ASSERT_EQ(testobject->getLoc1(),Location(2,-30));
    ASSERT_EQ(testobject->getLoc2(),Location(3,-30));

    testobject->setVerticalSpeed(10);
    testobject->updateLogic();
    ASSERT_EQ(testobject->getVerticalSpeed(),10);

    testobject->setVerticalSpeedUnbounded(110);
    testobject->updateLogic();
    ASSERT_EQ(testobject->getVerticalSpeed(),105);

    testobject->updateLogic();
    ASSERT_EQ(testobject->getVerticalSpeed(),100);

    testobject->updateLogic();
    ASSERT_EQ(testobject->getVerticalSpeed(),100);

}

TEST_F(EntityunitTests,Bullet_Init_Tests){
    std::shared_ptr<Bullet> testobject=std::make_shared<Bullet>(Location(0,0),Location(1,0),10);
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getMaxVertSpeed(),10);
    ASSERT_EQ(testobject->getVertAccel(),0);
    ASSERT_EQ(testobject->getHorAccel(),0);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);

}

TEST_F(EntityunitTests,Bullet_GetterSetters_Tests){
    std::shared_ptr<Bullet> testobject=std::make_shared<Bullet>(Location(0,0),Location(1,0),10);
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,Bonus_Init_Tests){
    std::shared_ptr<BonusCar> testobject=std::make_shared<BonusCar>(Location(0,0),Location(1,0),10);
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getMaxVertSpeed(),10);
    ASSERT_EQ(testobject->getVertAccel(),0);
    ASSERT_EQ(testobject->getHorAccel(),0);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);

}

TEST_F(EntityunitTests,BonusCar_GetterSetters_Tests){
    std::shared_ptr<BonusCar> testobject=std::make_shared<BonusCar>(Location(0,0),Location(1,0),10);
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,End_Init_Tests){
    std::shared_ptr<End> testobject=std::make_shared<End>(Location(0,0),Location(1,0));
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isDelete(),false);
}

TEST_F(EntityunitTests,End_GetterSetters_Tests){
    std::shared_ptr <End> testobject=std::make_shared<End>(Location(0,0),Location(1,0));
    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,PassingCar_Init_Tests){
    std::shared_ptr<PassingCar> testobject=std::make_shared<PassingCar>(Location(0,0),Location(1,0),10);
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getMaxVertSpeed(),10);
    ASSERT_EQ(testobject->getVertAccel(),0);
    ASSERT_EQ(testobject->getHorAccel(),0);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);

}

TEST_F(EntityunitTests,PassingCar_GetterSetters_Tests){
    std::shared_ptr<PassingCar> testobject=std::make_shared<PassingCar>(Location(0,0),Location(1,0),10);
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),10);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,PlayerCar_Init_Tests){
    std::shared_ptr<PlayerCar> testobject=std::make_shared<PlayerCar>(100,10,10,factory->getController());
    ASSERT_EQ(testobject->getWidth(),0.5);
    ASSERT_EQ(testobject->getVerticalSpeed(),0);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(-0.25,-0.25));
    ASSERT_EQ(testobject->getLoc2(),Location(0.25,0.25));
    ASSERT_EQ(testobject->getMaxVertSpeed(),100);
    ASSERT_EQ(testobject->getVertAccel(),10);
    ASSERT_EQ(testobject->getHorAccel(),10);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0.5);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);

}

TEST_F(EntityunitTests,PlayerCar_GetterSetters_Tests){
    std::shared_ptr<PlayerCar> testobject=std::make_shared<PlayerCar>(100,10,10,factory->getController());
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),100);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}

TEST_F(EntityunitTests,RacingCar_Init_Tests){
    std::shared_ptr<RacingCar> testobject=std::make_shared<RacingCar>(Location(0,0),Location(1,0),100,10,10);
    ASSERT_EQ(testobject->getWidth(),1);
    ASSERT_EQ(testobject->getVerticalSpeed(),0);
    ASSERT_EQ(testobject->getHorizontalSpeed(),0);
    ASSERT_EQ(testobject->getStatus(),Driving);
    ASSERT_EQ(testobject->getLoc1(),Location(0,0));
    ASSERT_EQ(testobject->getLoc2(),Location(1,0));
    ASSERT_EQ(testobject->getMaxVertSpeed(),100);
    ASSERT_EQ(testobject->getVertAccel(),10);
    ASSERT_EQ(testobject->getHorAccel(),10);
    ASSERT_EQ(testobject->getTimeOut(),0);
    ASSERT_EQ(testobject->getheight(),0);
    ASSERT_EQ(testobject->isImmune(),false);
    ASSERT_EQ(testobject->isDelete(),false);

}

TEST_F(EntityunitTests,RacingCar_GetterSetters_Tests){
    std::shared_ptr<RacingCar> testobject=std::make_shared<RacingCar>(Location(0,0),Location(1,0),100,10,10);
    testobject->setImmune(true);
    ASSERT_EQ(true,testobject->isImmune());

    testobject->setDelete(true);
    ASSERT_EQ(true,testobject->isDelete());

    testobject->setHorizontalSpeed(100);
    ASSERT_EQ(testobject->getHorizontalSpeed(),100);

    testobject->setVerticalSpeedUnbounded(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),1000);

    testobject->setVerticalSpeed(5);
    ASSERT_EQ(testobject->getVerticalSpeed(),5);
    testobject->setVerticalSpeed(1000);
    ASSERT_EQ(testobject->getVerticalSpeed(),100);

    testobject->setVertAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setHorAccel(1000);
    ASSERT_EQ(testobject->getVertAccel(),1000);

    testobject->setMaxVertSpeed(500);
    ASSERT_EQ(testobject->getMaxVertSpeed(),500);

    testobject->setStatus(Crashed);
    ASSERT_EQ(testobject->getStatus(),Crashed);

    testobject->setTimeOut(500);
    ASSERT_EQ(testobject->getTimeOut(),500);

    testobject->setLoc1(Location(15,15));
    ASSERT_EQ(testobject->getLoc1(),Location(15,15));

    testobject->setLoc2(Location(14,14));
    ASSERT_EQ(testobject->getLoc2(),Location(14,14));

    ASSERT_EQ(testobject->getWidth(),-1);
    ASSERT_EQ(testobject->getheight(),-1);
}