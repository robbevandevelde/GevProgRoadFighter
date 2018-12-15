//
// Created by thibaut on 28.11.18.
//

#include <Observer/Observable.h>

#include "../../include/Observer/Observable.h"

void Observable::attach(std::shared_ptr<ObserverBase> toAttach) {
    m_observers.emplace_back(toAttach);
}

void Observable::detach() {
    m_observers.clear();
}

void Observable::notify(int amount) {
    for(auto i:m_observers){
        i->update(amount);
    }
}
