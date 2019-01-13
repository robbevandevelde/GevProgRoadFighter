//
// Created by thibaut on 21.11.18.
//

#include "../include/Location.h"
namespace roadfighter {

    /**
   * getter for the x coordinate
   * @return a double
     * @exception none
   */
    double Location::getX() const {
        return x;
    }
    /**
     * setter for the x coordinate
     * @param x a double
     * @return none
     * @exception none
     */
    void Location::setX(double x) {
        Location::x = x;
    }

    /**
    * getter for the y coordinate
    * @return a double
     * @exception none
    */
    double Location::getY() const {
        return y;
    }

    /**
     * setter for the y coordinate
     * @param y a double
     * @return none
     * @exception none
     */
    void Location::setY(double y) {
        Location::y = y;
    }

    bool Location::operator==(const Location &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool Location::operator!=(const Location &rhs) const {
        return !(rhs == *this);
    }

    bool Location::operator<(const Location &rhs) const {
        if (x < rhs.x)
            return true;
        if (rhs.x < x)
            return false;
        return y < rhs.y;
    }

    bool Location::operator>(const Location &rhs) const {
        return rhs < *this;
    }

    bool Location::operator<=(const Location &rhs) const {
        return !(rhs < *this);
    }

    bool Location::operator>=(const Location &rhs) const {
        return !(*this < rhs);
    }

    std::ostream &operator<<(std::ostream &os, const Location &location) {
        os << "x: " << location.x << " y: " << location.y;
        return os;
    }

    /**
     * constructor by value
     * @param x
     * @param y
     * @return none
     * @excetpion none
     */
    Location::Location(double x, double y) : x(x), y(y) {}

    /**
     * copy assigment for Location
     * @param other the Location that is being copied
     * @return a new Location that is equal to the other one
     * @exception none
     */
    Location &Location::operator=(const Location &other) {
        x=other.x;
        y=other.y;
        return *this;
    }

    /**
     * move assignment for Location
     * @param other other Location that is being moved
     * @return a Location
     * that contains all the data of the first one
     * @exception none
     */
    Location &Location::operator=(Location &&other) noexcept{
        x= other.x;
        y= other.y;
        return *this;
    }



}