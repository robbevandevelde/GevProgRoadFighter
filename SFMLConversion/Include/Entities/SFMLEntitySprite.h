
/**
 * @file header for the SFMLEntitySprite class
 */

#ifndef GEVPROGROADFIGHTER_SFMLENTITY_H
#define GEVPROGROADFIGHTER_SFMLENTITY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "../Transformation.h"
#include "../SFMLconversionException.h"
namespace roadfighterSFML {
    class SFMLEntitySprite : public sf::Sprite {
    public:

        //default constructor
        SFMLEntitySprite()= default;
        //constructor with parameters
        SFMLEntitySprite(const std::string &path, std::shared_ptr<sf::RenderWindow> window);
        //setter for sprite location
        void setSpriteLocation(double x, double y);
        //loads a sprite
        void loadSprite(const std::string &path);
        //getter for the gamewindow
        const std::shared_ptr<sf::RenderWindow> &getWindow() const;

    private:
        std::shared_ptr<sf::RenderWindow> m_window;

        sf::Texture *m_texture{};

    };
}


#endif //GEVPROGROADFIGHTER_SFMLENTITY_H
