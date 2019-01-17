/**
 * @file
 * this file contains the declaration of the singleton Random class
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_RANDOM_H
#define GEVPROGROADFIGHTER_RANDOM_H

#include <memory>
#include <random>
namespace  roadfighter {
    class Random {
    private:
        /**
         * private initialisor to prevent the creation of another instance
         */
        Random() = default;


    public:
        //all possible move/copy constructors have been deleted
        Random(const Random &copy) = delete;

        Random(const Random &&move) = delete;

        Random operator=(const Random &other) = delete;

        Random operator=(const Random &&other) = delete;

        /**
         * a method that gives you an instance
         * @return a weak ptr to the instance (which is a shared ptr)
         */
        static Random &getInstance();

        /**
         * function that returns a random variable ranging from  0 to "to"
         * @param to the max possible int that the random int will go to
         * @return a random int ranging from 0 to "to"
         */
        int getRandom(int to) const;
    };
}


#endif //GEVPROGROADFIGHTER_RANDOM_H
