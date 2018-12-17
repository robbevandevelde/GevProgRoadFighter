//
// Created by thibaut on 20.11.18.
//

#include "Entity_Factory_base.h"
namespace roadfighter {

    void Entity_Factory_base::setController(const std::shared_ptr<InputController> &m_controller) {
        Entity_Factory_base::m_controller = m_controller;
    }

    const std::shared_ptr<InputController> &Entity_Factory_base::getController() const {
        return m_controller;
    }

    void Entity_Factory_base::setTransporter(const std::shared_ptr<EntityTransporter> &m_Transporter) {
        Entity_Factory_base::m_Transporter = m_Transporter;
    }

    const std::shared_ptr<EntityTransporter> &Entity_Factory_base::getTransporter() const {
        return m_Transporter;
    }

    void Entity_Factory_base::setScoreObserver(const std::shared_ptr<ObserverBase> &m_scoreObserver) {
        Entity_Factory_base::m_scoreObserver = m_scoreObserver;
    }

    const std::shared_ptr<ObserverBase> &Entity_Factory_base::getScoreObserver() const {
        return m_scoreObserver;
    }

    Entity_Factory_base::Entity_Factory_base() {
        m_Transporter=std::make_shared<EntityTransporter>(EntityTransporter());
        m_controller=std::make_shared<InputController>(InputController());
        m_scoreObserver=std::make_shared<ScoreObserver>(ScoreObserver());
    }

}