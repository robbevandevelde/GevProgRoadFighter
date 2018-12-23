//
// Created by thibaut on 01.12.18.
//

#ifndef GEVPROGROADFIGHTER_SFMLENTITY_H
#define GEVPROGROADFIGHTER_SFMLENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Transformation.h"
namespace roadfighterSFML {
    class SFMLEntitySprite : public sf::Sprite {
    public:

        SFMLEntitySprite();

        SFMLEntitySprite(const std::string &path, std::shared_ptr<sf::RenderWindow> window);

        void setSpriteLocation(double x, double y);

        void setSpriteSize(double width, double height);

        void loadSprite(const std::string &path);

        const std::shared_ptr<sf::RenderWindow> &getWindow() const;

    private:
        std::shared_ptr<sf::RenderWindow> m_window;

        sf::Texture *m_texture;

    };
}


#endif //GEVPROGROADFIGHTER_SFMLENTITY_H
