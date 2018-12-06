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
    Clock();

    virtual ~Clock();

    void restart();

    double getTimeAsSeconds();

private:
    clock_t m_time;

};


#endif //GEVPROGROADFIGHTER_CLOCK_H
