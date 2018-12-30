//
// Created by thibaut on 17.12.18.
//

#ifndef GEVPROGROADFIGHTER_HIGHSCOREMANAGER_H
#define GEVPROGROADFIGHTER_HIGHSCOREMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>
#include "parsers/json.hpp"
using json = nlohmann::json;

namespace roadfighter {

    //simple struct to link a name and an int that is seen as a high score
    struct highScore{
        std::string name;
        unsigned int score;

        //constructor for highscore
        highScore(const std::string &name, unsigned int score);
    };

    class HighScoreManager {
    public:

        //function to add a new possible highscore (if it isnt in the highest 10 it will be discarded)
        static void addHighScore(const std::string& name, unsigned int score);

        //getter for all the highscores, these highscores are taken from a json file
        static std::vector<highScore> gethighScores();

        //function that takes a vector of highscores and writes them to json file
        static void writeHighScores(std::vector<highScore>& towrite);
    };
}


#endif //GEVPROGROADFIGHTER_HIGHSCOREMANAGER_H
