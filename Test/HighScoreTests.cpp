/**
 * @file
 * this file contains all tests for the HighScoreManager
 */
#include <gtest/gtest.h>
#include <fstream>
#include <GLL_Entity_Factory.h>
#include <memory>
#include <HighScoreManager.h>
using namespace roadfighter;

class HighScoreTests: public ::testing::Test {
protected:
    // You should make the members protected s.t. they can be
    // accessed from sub-classes.

    // virtual void SetUp() will be called before each test is run.  You
    // should define it if you need to initialize the variables.
    // Otherwise, this can be skipped.
    virtual void SetUp() {
        std::vector<highScore> remove;
        HighScoreManager::writeHighScores(remove);
    }

    // virtual void TearDown() will be called after each test is run.
    // You should define it if there is cleanup work to do.  Otherwise,
    // you don't have to provide it.
    virtual void TearDown() {}


};

TEST_F(HighScoreTests,WriteRead_Tests){
    std::vector<highScore> scores;
    HighScoreManager::writeHighScores(scores);
    ASSERT_EQ(0,HighScoreManager::gethighScores().size());

    scores.emplace_back("jon",100);
    HighScoreManager::writeHighScores(scores);
    ASSERT_EQ(1,HighScoreManager::gethighScores().size());
    ASSERT_EQ("jon",HighScoreManager::gethighScores()[0].name);
    ASSERT_EQ(100,HighScoreManager::gethighScores()[0].score);

    for (int i = 0; i <9 ; ++i) {
        scores.emplace_back("jonny",100+i+1);
    }
    HighScoreManager::writeHighScores(scores);
    ASSERT_EQ(10,HighScoreManager::gethighScores().size());
    ASSERT_EQ("jonny",HighScoreManager::gethighScores()[9].name);
    ASSERT_EQ(109,HighScoreManager::gethighScores()[9].score);
}

TEST_F(HighScoreTests,HighScoreTests_AddScore_Tests){
    std::vector<highScore> scores;
    HighScoreManager::addHighScore("jos",100);
    ASSERT_EQ(1,HighScoreManager::gethighScores().size());
    ASSERT_EQ("jos",HighScoreManager::gethighScores()[0].name);
    ASSERT_EQ(100,HighScoreManager::gethighScores()[0].score);

    HighScoreManager::addHighScore("josbetter",105);
    ASSERT_EQ(2,HighScoreManager::gethighScores().size());
    ASSERT_EQ("josbetter",HighScoreManager::gethighScores()[0].name);
    ASSERT_EQ(105,HighScoreManager::gethighScores()[0].score);

    for (int i = 0; i <9 ; ++i) {
        HighScoreManager::addHighScore("jonny",100+i+1);
    }

    ASSERT_EQ(10,HighScoreManager::gethighScores().size());
    ASSERT_EQ("jonny",HighScoreManager::gethighScores()[0].name);
    ASSERT_EQ(109,HighScoreManager::gethighScores()[0].score);
}