//
// Created by thibaut on 21.11.18.
//

#ifndef GEVPROGROADFIGHTER_LOCATION_H
#define GEVPROGROADFIGHTER_LOCATION_H


#include <ostream>
namespace roadfighter {
    class Location {
    private:
        double x;
        double y;
    public:
        /**
           * default constructor for Location
           */
        Location();
        /**
         * constructor by value
         * @param x
         * @param y
         */
        Location(double x, double y);


        /**
         * copy constructor
         * @param copy the other Location that is being copied
         */
        Location(const Location &copy) = default;

        /**
         * move constructor
         * @param Move the other Location that is being moved in this one
         */
        Location(Location &&move) = default;

        /**
         * copy assigment for Location
         * @param other the Location that is being copied
         * @return a new Location that is equal to the other one
         */
        Location &operator=(const Location &other);

        /**
         * move assignment for Location
         * @param other other Location that is being moved
         * @return a Location
         * that contains all the data of the first one
         */
        Location &operator=(Location &&other) noexcept;

        /**
         * destructor for Location
         */
        virtual ~Location();

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


    };
}


#endif //GEVPROGROADFIGHTER_LOCATION_H
