//
// Created by thibaut on 21.11.18.
//

#ifndef GEVPROGROADFIGHTER_RANDOM_H
#define GEVPROGROADFIGHTER_RANDOM_H

#include <memory>

class Random {
private:
    /**
     * privately stored instance of the class
     */
    static std::shared_ptr<Random> m_instance;

    /**
     * private initialisor to prevent the creation of another instance
     */
    Random();

public:

    /**
     * a method that gives you an instance
     * @return a weak ptr to the instance (which is a shared ptr)
     */
    static std::weak_ptr<Random> getInstance();

    int getRandom(const int to) const;
};


#endif //GEVPROGROADFIGHTER_RANDOM_H
