//
// Created by thibaut on 21.11.18.
//

#include "../include/Location.h"
namespace roadfighter {

    double Location::getX() const {
        return x;
    }

    void Location::setX(double x) {
        Location::x = x;
    }

    double Location::getY() const {
        return y;
    }

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

    Location::~Location() {}

    Location::Location(double x, double y) : x(x), y(y) {}

    Location::Location() {}

}