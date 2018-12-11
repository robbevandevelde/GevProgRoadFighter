//
// Created by thibaut on 20.11.18.
//

#include "Entity_Factory_base.h"
namespace roadfighter {

    void Entity_Factory_base::setController(const std::shared_ptr<MoveController> &m_controller) {
        Entity_Factory_base::m_controller = m_controller;
    }

    const std::shared_ptr<MoveController> &Entity_Factory_base::getController() const {
        return m_controller;
    }

    void Entity_Factory_base::setTransporter(const std::shared_ptr<EntityTransporter> &m_Transporter) {
        Entity_Factory_base::m_Transporter = m_Transporter;
    }

    const std::shared_ptr<EntityTransporter> &Entity_Factory_base::getTransporter() const {
        return m_Transporter;
    }

}