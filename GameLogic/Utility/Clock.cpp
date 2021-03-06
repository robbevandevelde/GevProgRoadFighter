/**
 * @file
 * implementation of the clock class
 * @author Thibaut Van Goethem
 */

#include "Clock.h"
namespace  roadfighter {
    Clock::Clock() {
        m_time = clock();
    }

    void Clock::restart() {
        m_time = clock();
    }

    double Clock::getTimeAsSeconds() {
        double toreturn = double(clock() - m_time) / CLOCKS_PER_SEC;
        if (toreturn < 0) {
            throw GllException("negative time occured in clock");
        }
        return toreturn;
    }
}
