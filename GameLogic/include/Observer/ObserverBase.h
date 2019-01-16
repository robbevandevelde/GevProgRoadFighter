/**
 * @file
 * This file contains the interface class for an observer
 */

#ifndef GEVPROGROADFIGHTER_OBSERVERBASE_H
#define GEVPROGROADFIGHTER_OBSERVERBASE_H

namespace roadfighter {
    class ObserverBase {
    public:
        virtual void update(int amount) = 0;
    };
}


#endif //GEVPROGROADFIGHTER_OBSERVERBASE_H
