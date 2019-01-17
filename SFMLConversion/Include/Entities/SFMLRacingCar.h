/**
 * @file
 * header for SFMLRacingCar class
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_SFMLRACINGCAR_H
#define GEVPROGROADFIGHTER_SFMLRACINGCAR_H

#include "SFMLEntitySprite.h"
#include <Entities/RacingCar.h>
namespace roadfighterSFML {
    class SFMLRacingCar : public roadfighter::RacingCar, public SFMLEntitySprite {
    public:
        //constructor with parameters
        SFMLRacingCar(const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double m_maxVertSpeed,
                      double m_vertAccel, double m_horAccel,
                      const std::shared_ptr<sf::RenderWindow> &window);
        //draw function overrided from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLRACINGCAR_H
