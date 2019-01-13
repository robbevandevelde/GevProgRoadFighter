/**
 * @file
 * this file has a very simple 2d location class that is used in every collision object to represetn it's position
 */

#ifndef GEVPROGROADFIGHTER_LOCATION_H
#define GEVPROGROADFIGHTER_LOCATION_H


#include <ostream>
namespace roadfighter {
    class Location {
    private:
        double x{};
        double y{};
    public:
        /**
          * default constructor for Location
          */
        Location()= default;

        //constructor with 2 positions given
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
        * @exception none
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
        virtual ~Location()= default;

        //getter for x
        double getX() const;

        //setter for x
        void setX(double x);

        //getter for y
        double getY() const;

        //setter for y
        void setY(double y);

        /**
         * equality operators
         * @param rhs the location you are comparing to
         * @return a bool
         */
        bool operator==(const Location &rhs) const;

        bool operator!=(const Location &rhs) const;

        bool operator<(const Location &rhs) const;

        bool operator>(const Location &rhs) const;

        bool operator<=(const Location &rhs) const;

        bool operator>=(const Location &rhs) const;

        /**
         * ostream operator
         * @param os ostream object you are writing to
         * @param location the location you are writing on the ostream object
         * @return the sotream object with the location wrtiten on it
         */
        friend std::ostream &operator<<(std::ostream &os, const Location &location);


    };
}


#endif //GEVPROGROADFIGHTER_LOCATION_H
