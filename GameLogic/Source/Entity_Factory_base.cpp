/**
 * @file
 * this file contains the implementation of the Base Entity Factory class
 * @author Thibaut Van Goethem
 */
#include "Entity_Factory_base.h"
namespace roadfighter {

    /**
     * sets the controller of the factory
     * @param m_controller a movecontroller that will be given to all playercars created with this factory
     */
    void Entity_Factory_base::setController(const std::shared_ptr<InputController> &m_controller) {
        Entity_Factory_base::m_controller = m_controller;
    }

    /**
     * getter for the controller
     * @return a shared pointer to the movecontroller
     */
    const std::shared_ptr<InputController> &Entity_Factory_base::getController() const {
        return m_controller;
    }

    /**
     * setter for the transporter
     * @param m_Transporter an entitytransporter that will be given to the world
     */
    void Entity_Factory_base::setTransporter(const std::shared_ptr<EntityTransporter> &m_Transporter) {
        Entity_Factory_base::m_Transporter = m_Transporter;
    }

    /**
     * getter for the transporter
     * @return a shared pointer to the entitytransporter
     * @exception none
     */
    const std::shared_ptr<EntityTransporter> &Entity_Factory_base::getTransporter() const {
        return m_Transporter;
    }

    /**
     * setter for the score observer
     * @param m_scoreObserver the new scoreobserver
     * @return none
     * @exception none
     */
    void Entity_Factory_base::setScoreObserver(const std::shared_ptr<ObserverBase> &m_scoreObserver) {
        Entity_Factory_base::m_scoreObserver = m_scoreObserver;
    }

    /**
     * getter for the scoreobserver
     * @return reference to std::shared_ptr<ObserverBase>
     * @exception none
     */
    const std::shared_ptr<ObserverBase> &Entity_Factory_base::getScoreObserver() const {
        return m_scoreObserver;
    }

    /**
     * constructor for base entity factory
     * @return none
     * @exception none
     */
    Entity_Factory_base::Entity_Factory_base() {
        m_Transporter=std::make_shared<EntityTransporter>(EntityTransporter());
        m_controller=std::make_shared<InputController>(InputController());
        m_scoreObserver=std::make_shared<ScoreObserver>(ScoreObserver());
    }

}