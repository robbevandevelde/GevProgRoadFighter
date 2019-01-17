/**
 * @file
 * this file contains all the tests regarding the input controller
 */
#include <gtest/gtest.h>
#include <fstream>
#include <GLL_Entity_Factory.h>
#include <memory>
#include <InputController.h>
using namespace roadfighter;

class InputTests: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    void SetUp() override {}

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    void TearDown() override{}

    // Declares the variables your tests want to use.

};

TEST_F(InputTests,InputController_Init_Tests){
    auto controller=InputController();
    ASSERT_EQ(controller.getText(),"");
    ASSERT_EQ(controller.getNextVertMove(),v_none);
    ASSERT_EQ(controller.getNextHorMove(),h_none);
    ASSERT_EQ(controller.mustShoot(),false);
}

TEST_F(InputTests,InputController_getterSetter_Tests){
    auto controller=InputController();

    controller.setText("testtext");
    ASSERT_EQ(controller.getText(),"testtext");

    controller.shoot();
    ASSERT_EQ(controller.mustShoot(),true);

    controller.noShoot();
    ASSERT_EQ(controller.mustShoot(),false);

    controller.setVertMove(v_accel);
    ASSERT_EQ(controller.getNextVertMove(),v_accel);

    controller.setVertMove(v_decel);
    ASSERT_EQ(controller.getNextVertMove(),v_decel);

    controller.setHorMove(h_right);
    ASSERT_EQ(controller.getNextHorMove(),h_right);

    controller.setHorMove(h_left);
    ASSERT_EQ(controller.getNextHorMove(),h_left);

    controller.shoot();

    controller.setNone();
    ASSERT_EQ(controller.getText(),"");
    ASSERT_EQ(controller.getNextVertMove(),v_none);
    ASSERT_EQ(controller.getNextHorMove(),h_none);
    ASSERT_EQ(controller.mustShoot(),false);
}