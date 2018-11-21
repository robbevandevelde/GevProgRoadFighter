//
// Created by thibaut on 17.11.18.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameLogic/include/Entity_Factory.h"
#include "Singletons/Random.h"
#include <memory>

int main(int argc, char *argv[]) {
    for(unsigned int i=0;i<10;i++) {
        Random rand=Random::getInstance();
        std::cout << "random number is: " << rand.getRandom(10) <<" coming from: "<<&rand<< std::endl;
    }
}