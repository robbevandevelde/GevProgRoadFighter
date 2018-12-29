/**
 * @file header for the singleton transformation class
 */

#ifndef GEVPROGROADFIGHTER_TRANSFORMATION_H
#define GEVPROGROADFIGHTER_TRANSFORMATION_H

#include <SFML/Graphics.hpp>
#include <Location.h>
namespace roadfighterSFML {
    class Transformation {
    public:
        //gets an instance of this class and if tehre is no instance it creates one
        static Transformation &getInstance();

        //transforms gll coordinates into a tuple of doubles that are sfml coordinates
        std::tuple<double, double> locationTransformation(const roadfighter::Location &loc);

        //bunch of deleted function to make sure no copy can be made of an instance
        Transformation(const Transformation &copy) = delete;

        Transformation(const Transformation &&move) = delete;

        Transformation operator=(const Transformation &other) = delete;

        Transformation operator=(const Transformation &&other) = delete;

    private:

        Transformation(int x, int y);

        int m_xSize;
        int m_ySize;

    };
}


#endif //GEVPROGROADFIGHTER_TRANSFORMATION_H
