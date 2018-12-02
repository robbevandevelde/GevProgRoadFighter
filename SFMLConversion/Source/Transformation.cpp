//
// Created by thibaut on 02.12.18.
//

#include "../Include/Transformation.h"
#include <iostream>

Transformation &Transformation::getInstance() {
    static Transformation instance(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height);
    return instance;
}

std::tuple<int,int> Transformation::locationTransformation(const roadfighter::Location& loc) {
    //eleminating the negative numbers
    double x=loc.getX()+3;
    double y=loc.getY()+4;

    double returnx=m_xSize/3;
    double returny=0;

    returnx+=(returnx/6)*x;
    returny+=(m_ySize/8)*y;

    //adding 0.5 so that the roundign when casting to int will be correct
    return std::make_tuple(returnx+0.5,returny+0.5);
}

Transformation::Transformation(int x, int y):m_xSize(x),m_ySize(y){}
