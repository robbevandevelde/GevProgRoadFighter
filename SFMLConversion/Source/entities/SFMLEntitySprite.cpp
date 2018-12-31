#include <utility>

/**
 *@file
 * implementation of the SFMLEntitySprite class
 */

#include "../../Include/Entities/SFMLEntitySprite.h"
namespace roadfighterSFML {

    /**
     * constructor with parameters given
     * @param path a string that will be the path of the texture
     * @param window the window that is used to draw on
     * @return none
     * @exception none
     */
    SFMLEntitySprite::SFMLEntitySprite(const std::string &path, std::shared_ptr<sf::RenderWindow> window) : m_window(
            std::move(
                    window)) {
        m_texture = new sf::Texture();
        if(!m_texture->loadFromFile(path)) throw SFMLConversionException("could not load the image from "+path);

        setTexture(*m_texture);
    }

    /**
     * function that sets the sprite location
     * @param x balue of location
     * @param y value of location
     * @return none
     * @exception none
     */
    void SFMLEntitySprite::setSpriteLocation(double x, double y) {
        this->setPosition(static_cast<float>(x), static_cast<float>(y));
    }

    /**
     * function that loads in a new texture for the sprite
     * @param path the path of the texture file
     * @return none
     * @exception none
     */
    void SFMLEntitySprite::loadSprite(const std::string &path) {
        if(m_texture->loadFromFile(path)) this->setTexture(*m_texture);

    }

    /**
     * getter for the renderwindow
     * @return std::shared_ptr<sf::RenderWindow>
     * @exception none
     */
    const std::shared_ptr<sf::RenderWindow> &SFMLEntitySprite::getWindow() const {
        return m_window;
    }
}
