/**
 * @file header for SFMLBonusCar class
 */

#ifndef GEVPROGROADFIGHTER_SFMLBONUSCAR_H
#define GEVPROGROADFIGHTER_SFMLBONUSCAR_H


#include "SFMLEntitySprite.h"
#include <Entities/BonusCar.h>
namespace roadfighterSFML {
    class SFMLBonusCar : public SFMLEntitySprite, public roadfighter::BonusCar {
    public:
        //constructor with parameters
        SFMLBonusCar(const std::shared_ptr<sf::RenderWindow> &window,
                     const roadfighter::Location &m_loc1, const roadfighter::Location &m_loc2, double vertSpeed);
        //draw function overrided from roadfighter::entity
        void draw() override;
    };
}


#endif //GEVPROGROADFIGHTER_SFMLBONUSCAR_H
