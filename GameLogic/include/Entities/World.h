//
// Created by thibaut on 20.11.18.
//

#ifndef GEVPROGROADFIGHTER_WORLD_H
#define GEVPROGROADFIGHTER_WORLD_H

#include <memory>
#include <vector>
#include "Entity.h"
#include "PlayerCar.h"
#include "CollisionObject.h"
#include "EntityTransporter.h"

namespace roadfighter {
    class World :public Entity{
    public:
        /**
         * default constructor for World
         */
        World()= default;

        /**
         * copy constructor
         * @param copy the other world that is being copied
         */
        World(const World &copy)= default;

        /**
         * move constructor
         * @param Move the other world that is being moved in this one
         */
        World(World &&move)= default;

        explicit World(const std::shared_ptr<roadfighter::EntityTransporter> &m_Transporter);

        /**
         * copy assigment for World
         * @param other the world that is being copied
         * @return a new world that is equal to the other one
         */
        World& operator=(const World& other)= default;

        /**
         * move assignment for world
         * @param other other world that is being moved
         * @return a world that contains all the data of the first one
         */
        World& operator=(World&& other)= default;

        /**
         * destructor for World
         */
        virtual ~World()= default;

        /**
         * this function subtracts the given paramater from all the y values of the m_roadEntities
         * @param setback the amount all entities should be setback
         */
        void setBackY(double setback);

        /**
         * this function updates the movement of all entities in this world by dt ticks
         * @param dt the amount of a  tick the locations should be updated with
         */
        void updateMovement(double dt) override;

        /**
         * takes all the entities that are currently in the transporter and puts them with the other entities
         */
        void getNewEntities();

        /**
         * check the collision for all the entities and does the apropiate action
         */
        void checkCollision();

        /**
         * calls the draw function on all entities
         */
        void draw() override;

        /**
         * updates the logic of this world and all the entities within
         */
        void updateLogic() override;

        /**
         * deletes all unused entities that are currently still in the entitie vectot
         */
        void deleteUnused();

        /**
         * gets the amount of ticks that the world had to move loast movementUpdate
         * @return a double
         */
        double getTickMovement() const;

    private:

        std::vector<std::shared_ptr<Entity> > m_roadEntities;

        std::shared_ptr<roadfighter::EntityTransporter> m_Transporter;

        double m_tickMovement;

    };
}


#endif //GEVPROGROADFIGHTER_WORLD_H
