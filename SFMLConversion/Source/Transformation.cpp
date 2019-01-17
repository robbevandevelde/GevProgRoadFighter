/**
 *@file
 * implementation of the singleton Transformation class
 * @author Thibaut Van Goethem
 */

#include "../Include/Transformation.h"
#include <iostream>
namespace roadfighterSFML {
    /**
     * function that gets the instance of the transfomation class and creates one if it doesnt yet exist
     * @return reference to the Transformation
     * @exception none
     */
    Transformation &Transformation::getInstance() {
        static Transformation instance(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
        return instance;
    }

    /**
     *  function that does the transformation from gll locations to screen pixels
     * @param loc the roadfighter::location that will be transformed
     * @return std::tuple<double, double> containing the new screen coordinates
     * @exception none
     */
    std::tuple<double, double> Transformation::locationTransformation(const roadfighter::Location &loc) {
        //eleminating the negative numbers
        double x = loc.getX() + 3;
        double y = loc.getY() + 4;

        double returnx = m_xSize / 3.0;
        double returny = 0;

        returnx += (returnx / 6.0) * x;
        returny += (m_ySize / 8.0) * y;

        return std::make_tuple(returnx, returny);
    }

    /**
     * private constructor
     * @param x x size of the screen
     * @param y y size of the screen
     */
    Transformation::Transformation(int x, int y) : m_xSize(x), m_ySize(y) {}
}
