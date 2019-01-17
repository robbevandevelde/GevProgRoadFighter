/**
* @file
* this file contains the implementation of the World class
 * @author Thibaut Van Goethem
*/
#include <Entities/World.h>

#include "../../include/Entities/World.h"
namespace roadfighter {

    /**
     * constructor for world were the transporter is given
     * @param m_Transporter an entity transporter used tio get entities in the world
     * @return none
     * @exception none
     */
    World::World(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter) : m_Transporter(m_Transporter) {}

    /**
    * takes all the entities that are currently in the transporter and puts them with the other entities
     * @return none
     * @exception none
    */
    void World::getNewEntities() {
        if(m_Transporter==nullptr){
            throw GllException("tried accessing entitytransporter in world but none found");
        }
        for(auto i:m_Transporter->getEntities()){
            m_roadEntities.emplace_back(i);
        }
    }

    /**
     * this function updates the movement of all entities in this world by dt ticks
     * @param dt the amount of a  tick the locations should be updated with
     * @return none
     * @exception none
     */
    void World::updateMovement(double dt){
        for(auto& i:m_roadEntities){
            i->updateMovement(dt);
        }
    }

    /**
     * updates the logic of this world and all the entities within
     * @return none
     * @exception none
     */
    void World::updateLogic() {
        deleteUnused();
        getNewEntities();
        for(auto& i:m_roadEntities){
            i->updateLogic();
        }
        checkCollision();
    }

    /**
     * this function subtracts the given parameter from all the y values of the m_roadEntities
     * @param setback the amount all entities should be setback
     * @return none
     * @exception none
     */
    void World::setBackY(double setback) {
        for(auto& i:m_roadEntities){
            auto temp=std::dynamic_pointer_cast<CollisionObject>(i);
            temp->vertMove(-setback);
        }
        m_tickMovement+=setback;
    }

    /**
     * calls the draw function on all entities
     * @return none
     * @exception none
     */
    void World::draw() {
        for(const auto& i:m_roadEntities){
            i->draw();
        }
        m_tickMovement=0;
    }

    /**
     * deletes all unused entities that are currently still in the entity vector
     * @return none
     * @exception none
     */
    void World::deleteUnused() {
        for(unsigned int i=0;i<m_roadEntities.size();i++){
            auto collision=std::dynamic_pointer_cast<CollisionObject>(m_roadEntities[i]);
            if(collision->mustDelete()){
                m_roadEntities.erase(m_roadEntities.begin()+i);
            }
        }

    }

    /**
     * check the collision for all the entities and does the apropiate action
     * @return none
     * @exception none
     */
    void World::checkCollision() {
        //in this function all the entitites get downcasted to collisionobject and if that is not possible we cant check collision for it
        for(auto& i:m_roadEntities){
            std::shared_ptr<CollisionObject> checkFor=std::dynamic_pointer_cast<CollisionObject>(i);
            if(checkFor!= nullptr){
                for(auto& j:m_roadEntities){
                    std::shared_ptr<CollisionObject> checkWith=std::dynamic_pointer_cast<CollisionObject>(j);
                    if(checkWith!= nullptr&&checkWith!=checkFor){
                        if(checkFor->checkCollision(checkWith)){
                            checkFor->collideWith(checkWith);
                        }
                    }
                }
            }
        }
    }

    /**
    * gets the amount of ticks that the world had to move last movementUpdate
    * @return a double
     * @exception none
    */
    double World::getTickMovement() const {
        return m_tickMovement;
    }

    /**
     * detach all observers from an entity if it can be downcasted to observable class
     * @return none
     * @excepiont none
     */
    void World::dettachAllObservers() {
        for(const auto &i:m_roadEntities){
            auto temp=std::dynamic_pointer_cast<Observable>(i);
            if(temp!= nullptr){
                temp->detach();
            }
        }
    }

}

