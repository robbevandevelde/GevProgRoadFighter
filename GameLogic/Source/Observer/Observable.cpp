//
// Created by thibaut on 28.11.18.
//

#include <Observer/Observable.h>

#include "../../include/Observer/Observable.h"
namespace  roadfighter {
    /**
     * function of the observer design patter where an observer is attached to the observable object
     * @param toAttach the observer that you are attaching
     * @return none
     * @exception none
     */
    void Observable::attach(std::shared_ptr<ObserverBase> toAttach) {
        m_observers.emplace_back(toAttach);
    }

    /**
     * function that detaches all observers
     * @return none
     * @exception none
     */
    void Observable::detach() {
        m_observers.clear();
    }

    /**
     * function that notifies all the observers with a certain amount
     * @param amount the amount you are notfying them with
     */
    void Observable::notify(int amount) {
        for (auto i:m_observers) {
            i->update(amount);
        }
    }
}
