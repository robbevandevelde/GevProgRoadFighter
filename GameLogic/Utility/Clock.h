//
// Created by thibaut on 28.11.18.
//

#ifndef GEVPROGROADFIGHTER_CLOCK_H
#define GEVPROGROADFIGHTER_CLOCK_H
#include <time.h>

/**
 * an encapsulation for the c++ clock library to make it easier to use
 */
class Clock {
public:
    /**
     * default and only constructor, the time starts teh second this clock is created
     */
    Clock();

    virtual ~Clock()= default;

    /**
     * restart the clock
     */
    void restart();

    /**
     * gets the amount of time that has passed since construction or last reset
     * @return this time as seconds in a double
     */
    double getTimeAsSeconds();

private:
    clock_t m_time;

};


#endif //GEVPROGROADFIGHTER_CLOCK_H
