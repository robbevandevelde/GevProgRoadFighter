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
    struct highScore{
        std::string name;
        unsigned int score;

        highScore(const std::string &name, unsigned int score);
    };

    class HighScoreManager {
    public:
        static void addHighScore(const std::string& name, unsigned int score);

        static std::vector<highScore> gethighScores();

        static void writeHighScores(std::vector<highScore>& towrite);
    };
}


#endif //GEVPROGROADFIGHTER_HIGHSCOREMANAGER_H
