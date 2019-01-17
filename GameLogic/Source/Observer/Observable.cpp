/**
 * @file
 * this file contains the implementation of the Observable car class
 * @author Thibaut Van Goethem
 */

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
     * @param amount the amount you are notifying them with
     */
    void Observable::notify(int amount) {
        for (const auto &i:m_observers) {
            i->update(amount);
        }
    }
}
