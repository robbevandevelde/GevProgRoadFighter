//
// Created by thibaut on 01.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLENTITY_H
#define GEVPROGROADFIGHTER_SFMLENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Transformation.h"

class SFMLEntity: public sf::Sprite {
public:

    SFMLEntity();

    SFMLEntity(const std::string& path);

    virtual void draw(sf::RenderWindow& window)=0;

    void setSpriteLocation(double x,double y);

    void setSpriteSize(double width,double height);

    void loadSprite(const std::string& path);


private:
    sf::Texture* m_texture;

};


#endif //GEVPROGROADFIGHTER_SFMLENTITY_H
