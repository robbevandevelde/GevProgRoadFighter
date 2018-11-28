//
// Created by thibaut on 17.11.18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utility/Clock.h"
#include "GameLogic/include/Entity_Factory.h"
#include "Utility/Random.h"
#include <memory>

int main(int argc, char *argv[]) {
    Clock time=Clock();
    int amount=0;
    while(amount!=10) {
        if(time.getTimeAsSeconds()>1){
            std::cout << "ticking after " << time.getTimeAsSeconds() << " second" << std::endl;
            Random rand = Random::getInstance();
            std::cout << "random number is: " << rand.getRandom(10) << " coming from: " << &rand << std::endl;
            time.restart();
            amount++;
        }

    }



}