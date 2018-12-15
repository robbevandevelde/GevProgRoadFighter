//
// Created by thibaut on 28.11.18.
//

#ifndef GEVPROGROADFIGHTER_OBSERVABLE_H
#define GEVPROGROADFIGHTER_OBSERVABLE_H

#include <memory>
#include <vector>
#include "ObserverBase.h"

class Observable {
    public:
        void attach(std::shared_ptr<ObserverBase> toAttach);

        void detach();

        virtual void notify(int amount);


    private:
        std::vector<std::shared_ptr<ObserverBase> > m_observers;
};


#endif //GEVPROGROADFIGHTER_OBSERVABLE_H
