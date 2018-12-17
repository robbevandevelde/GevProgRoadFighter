//
// Created by thibaut on 17.12.18.
//

#include <sys/stat.h>
#include <iostream>

#include "HighScoreManager.h"
namespace roadfighter {
    void HighScoreManager::addHighScore(const std::string &name, unsigned int score) {
        std::vector<highScore> scores=gethighScores();

        //quick lambda function to sort the vector of highscores
       auto sortLambda=[](const highScore & a, const highScore & b) -> bool
             {
                 return a.score > b.score;
             };

       //add the new score, sort the vector adn then cutt of anything past index then before writing back to the file
        scores.emplace_back(name,score);
        std::sort(scores.begin(),scores.end(),sortLambda);
        while (scores.size()>10){
            scores.erase(scores.end());
        }
        writeHighScores(scores);


    }

    std::vector<highScore> HighScoreManager::gethighScores() {
        //test if the file exists
        std::vector<highScore> scores;
        struct stat buffer{};
        bool Exists(stat("highScores.json", &buffer) == 0);
        if (!Exists) { return scores;}

        //parsing using the nohlmann json parser
        std::ifstream i("highScores.json");
        json j;
        i >> j;
        for (const auto& it : j["Scores"].items()) {
            std::string name=it.value()["name"];
            unsigned int score=it.value()["score"];
            scores.emplace_back(name,score);
        }
        return scores;

    }

    void HighScoreManager::writeHighScores(std::vector<highScore> &towrite) {
        //checking if the file exists and then clearing it so we can wrtie all the scores to it
        struct stat buffer{};
        bool Exists(stat("highScores.json", &buffer) == 0);
        std::ofstream scoreFile;
        if (Exists) {
            scoreFile.open("highScores.json", std::ofstream::out | std::ofstream::trunc);
        }else{
            scoreFile=std::ofstream("highScores.json");
        }
        scoreFile<<"{\n"
                   "  \"Scores\":["<<std::endl;
        for(unsigned int i=0;i<towrite.size()-1;i++){
            scoreFile<< R"( {"name": ")" +towrite[i].name+ R"(","score":)" +std::to_string(towrite[i].score)+"},"<<std::endl;
        }
        scoreFile<< R"( {"name": ")" +towrite.back().name+ R"(","score":)" +std::to_string(towrite.back().score)+"}"<<std::endl;
        scoreFile<<"]\n"
                   "}";
    }

    highScore::highScore(const std::string &name, unsigned int score) : name(name), score(score) {}
}
