//
// Created by thibaut on 02.12.18.
//

#ifndef GEVPROGROADFIGHTER_TRANSFORMATION_H
#define GEVPROGROADFIGHTER_TRANSFORMATION_H

#include <SFML/Graphics.hpp>
#include <Location.h>

class Transformation {
public:
    static Transformation& getInstance();

    std::tuple<int,int> locationTransformation(const roadfighter::Location& loc);
private:
    Transformation(int x,int y);
    int m_xSize;
    int m_ySize;

};


#endif //GEVPROGROADFIGHTER_TRANSFORMATION_H