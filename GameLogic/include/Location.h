//
// Created by thibaut on 21.11.18.
//

#ifndef GEVPROGROADFIGHTER_LOCATION_H
#define GEVPROGROADFIGHTER_LOCATION_H


#include <ostream>

class Location {
private:
    double x;
    double y;
public:

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    bool operator==(const Location &rhs) const;

    bool operator!=(const Location &rhs) const;

    bool operator<(const Location &rhs) const;

    bool operator>(const Location &rhs) const;

    bool operator<=(const Location &rhs) const;

    bool operator>=(const Location &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Location &location);

    virtual ~Location();

};


#endif //GEVPROGROADFIGHTER_LOCATION_H
