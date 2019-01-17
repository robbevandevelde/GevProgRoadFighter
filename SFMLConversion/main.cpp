/**
 * @file
 * main class where the game gets made/started and possible leftover exceptions get caught
 * @author Thibaut Van Goethem
 */
#include <iostream>
#include "Include/SFMLRoadFighter.h"

#include <GllException.h>


int main(int argc, char *argv[]) {
    try {
        roadfighterSFML::SFMLRoadFighter game = roadfighterSFML::SFMLRoadFighter();
        game.rungame();
    }catch (roadfighter::GllException& e){
        std::cerr<<"an error occurred in the game logic library\n";
        std::cerr<<e.what();
    }catch(roadfighterSFML::SFMLConversionException& e){
        std::cerr<<"an error occurred in teh graphical conversion of the game\n";
        std::cerr<<e.what();
    }
}