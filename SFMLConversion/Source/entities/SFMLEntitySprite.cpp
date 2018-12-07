//
// Created by thibaut on 01.12.18.
//

#include "../../Include/Entities/SFMLEntitySprite.h"

SFMLEntitySprite::SFMLEntitySprite() {}

SFMLEntitySprite::SFMLEntitySprite(const std::string& path,std::shared_ptr<sf::RenderWindow> window):m_window(window){
    m_texture=new sf::Texture();
    m_texture->loadFromFile(path);
    setTexture(*m_texture);
}



void SFMLEntitySprite::setSpriteLocation(double x, double y) {
   this->setPosition(x,y);
}

void SFMLEntitySprite::setSpriteSize(double width, double height) {

}

void SFMLEntitySprite::loadSprite(const std::string &path) {
//    if(m_texture->loadFromFile(path)) this->setTexture(*m_texture);
}

const std::shared_ptr<sf::RenderWindow> &SFMLEntitySprite::getWindow() const {
    return m_window;
}
