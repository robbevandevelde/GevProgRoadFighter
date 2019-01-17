/**
 * @file
 * this file contains the implementation of the ScoreObserver class
 * @author Thibaut Van Goethem
 */

#include "../../include/Observer/ScoreObserver.h"
namespace  roadfighter {
    void ScoreObserver::update(int amount) {
        unsigned int temp = m_score;
        if (m_score + amount >= 0) {
            m_score += amount;
        }
        //underflow/overflow prevention
        if (amount < 0) {
            //if after substraction the score is higher then there is underflow
            if (m_score > temp) {
                m_score = 0;
            }
            //if after addition the score is lower than the start then there is overflow
            //this is unlikely to happen but you never know
        } else if (amount > 0) {
            if (m_score < temp) {
                m_score = std::numeric_limits<unsigned int>::max();
            }
        }
    }

    unsigned int ScoreObserver::getScore() const {
        return m_score;
    }

    ScoreObserver::ScoreObserver() : m_score(0) {}
}