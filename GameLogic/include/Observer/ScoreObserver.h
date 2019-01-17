/**
 * @file
 * this file contains the declartaion of a scoreobserver which is derived from teh observerbase
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_SCOREOBSERVER_H
#define GEVPROGROADFIGHTER_SCOREOBSERVER_H

#include "ObserverBase.h"
#include <limits>
namespace  roadfighter {
    class ScoreObserver : public ObserverBase {
    public:
        /**
         * default constructor
         */
        ScoreObserver();

        /**
         * update function overidden from observerbase
         * @param amount the amount of score that gets added
         */
        void update(int amount) override;

        /**
         * getter for m_score
         * @return the score stored in this observer
         */
        unsigned int getScore() const;

    private:
        unsigned int m_score;
    };
}


#endif //GEVPROGROADFIGHTER_SCOREOBSERVER_H
