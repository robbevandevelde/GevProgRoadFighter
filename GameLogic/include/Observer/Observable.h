/**
 * @file
 * This file contains the declaration of the observable class and its members
 * this class is from the observer pattern
 * @author Thibaut Van Goethem
 */
#ifndef GEVPROGROADFIGHTER_OBSERVABLE_H
#define GEVPROGROADFIGHTER_OBSERVABLE_H

#include <memory>
#include <vector>
#include "ObserverBase.h"
namespace roadfighter {
    class Observable {
    public:
        //attaches an observer
        void attach(std::shared_ptr<ObserverBase> toAttach);

        //detaches all observers
        void detach();

        //notifies all observers
        virtual void notify(int amount);


    private:
        std::vector<std::shared_ptr<ObserverBase> > m_observers;
    };
}


#endif //GEVPROGROADFIGHTER_OBSERVABLE_H
