//
// Created by thibaut on 06.12.18.
//

#include "../../Include/Entities/SFMLWorld.h"

SFMLWorld::SFMLWorld(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter,
                     const std::shared_ptr<sf::RenderWindow> &window) : World(m_Transporter),
                                                                        SFMLEntitySprite("../../SFMLConversion/resources/sprites/background.png", window) {

    std::tuple<int,int> sfmlpos1=std::make_tuple(0,0);
    std::tuple<int,int> sfmlpos2=Transformation::getInstance().locationTransformation(roadfighter::Location(3,4));

    SFMLEntitySprite::scale(sf::Vector2f(
            ((std::get<0>(sfmlpos2)-std::get<0>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().width*1.10),
            ((std::get<1>(sfmlpos2)-std::get<1>(sfmlpos1))/SFMLEntitySprite::getGlobalBounds().height)));
}

void SFMLWorld::draw() {
    //puts the tickmovement into the y value of a roadfighter location so we get the amount of y pixels have been moved on the screen
    double tickmovemnt=std::get<1>(Transformation::getInstance().locationTransformation(roadfighter::Location(0,getTickMovement()-4)));

    //if the postion of the sprite is larger than teh height of the sprite it means that a full revolution of the sprite has been done thus we set the location back 1 spriteheight
    if(getPosition().y>getGlobalBounds().height)setPosition(getPosition().x,getPosition().y-getGlobalBounds().height);
    //move the sprite with the amount the playercar has moved since last drawing
    setPosition(getPosition().x,(getPosition().y-tickmovemnt));
    getWindow()->draw(*this);

    //make a copy of the sprite only by splicing so we can draw another one above the current one
    SFMLEntitySprite temp=*this;

    //add a spriteheight to the copied sprite so they match up as they should
    temp.setPosition(getPosition().x,temp.getPosition().y-getGlobalBounds().height);
    getWindow()->draw(temp);

    //drawing the rest of the sprite on top
    World::draw();
}
