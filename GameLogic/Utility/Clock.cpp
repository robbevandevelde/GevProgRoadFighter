//
// Created by thibaut on 28.11.18.
//

#include "Clock.h"

Clock::Clock() {
    m_time=clock();
}

void Clock::restart() {
    m_time=clock();
}

double Clock::getTimeAsSeconds() {
    return  double(clock()-m_time)/CLOCKS_PER_SEC;
}
