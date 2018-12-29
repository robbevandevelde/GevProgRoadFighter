/**
 * @file header for SFMLPassingCar class
 */


#ifndef GEVPROGROADFIGHTER_SFMLPASSINGCAR_H
#define GEVPROGROADFIGHTER_SFMLPASSINGCAR_H


#include <Entities/PassingCar.h>
#include "SFMLEntitySprite.h"
namespace roadfighterSFML {
    class SFMLPassingCar : public SFMLEntitySprite, public roadfighter::PassingCar {
    public:
        //constructor with parameters
        SFMLPassingCar(const std::shared_ptr<sf::RenderWindow> &window,
                       const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertSpeed);
        //draw function overrided from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLPASSINGCAR_H
