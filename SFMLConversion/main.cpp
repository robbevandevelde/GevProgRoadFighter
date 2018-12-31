//
// Created by thibaut on 17.11.18.
//
#include <iostream>
#include "Include/SFMLRoadFighter.h"

#include <GllException.h>


int main(int argc, char *argv[]) {
    try {
        roadfighterSFML::SFMLRoadFighter game = roadfighterSFML::SFMLRoadFighter();
        game.rungame();
    }catch (roadfighter::GllException& e){
        std::cerr<<"an error occured in the game logic library\n";
        std::cerr<<e.what();
    }catch(roadfighterSFML::SFMLConversionException& e){
        std::cerr<<"an error occured in teh graphical conversion of the game\n";
        std::cerr<<e.what();
    }
}