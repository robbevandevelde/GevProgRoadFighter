/**
 * @file
 * implementation for the singleton Random number generator class
 * @author Thibaut Van Goethem
 */

#include "Random.h"

namespace roadfighter {
    Random &Random::getInstance() {
        //private instance here gets made staticly so there can only be made once
        static Random instance;
        return instance;
    }

    int Random::getRandom(const int to) const {
        //uniform random generator found on https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
        std::mt19937 rng;
        rng.seed(std::random_device()());
        std::uniform_int_distribution<std::mt19937::result_type> dist6(0, (unsigned long) to);
        return static_cast<int>(dist6(rng));
    }
}
