//
// Created by thibaut on 21.11.18.
//

#ifndef GEVPROGROADFIGHTER_RANDOM_H
#define GEVPROGROADFIGHTER_RANDOM_H

#include <memory>
#include <random>

class Random {
private:
    /**
     * private initialisor to prevent the creation of another instance
     */
    Random(){};

public:

    /**
     * a method that gives you an instance
     * @return a weak ptr to the instance (which is a shared ptr)
     */
    static Random& getInstance();

    /**
     * function that returns a random variable ranging from  0 to "to"
     * @param to the max possible int that the random int will go to
     * @return a random int ranging from 0 to "to"
     */
    int getRandom(const int to) const;
};


#endif //GEVPROGROADFIGHTER_RANDOM_H
