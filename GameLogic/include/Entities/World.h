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

namespace roadfighter {
    class World :Entity{
    public:
        /**
         * default constructor for World
         */
        World();

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

        /**
         * copy assigment for World
         * @param other the world that is being copied
         * @return a new world that is equal to the other one
         */
        World& operator=(World& other)= default;

        /**
         * move assignment for world
         * @param other other world that is being moved
         * @return a world that contains all the data of the first one
         */
        World& operator=(World&& other)= default;

        /**
         * destructor for World
         */
        virtual ~World();

        /**
         * this function subtracts the given paramater from all the y values of the m_roadEntities
         * @param setback the amount all entities should be setback
         */
        void setBackY(double setback);

        void addEntity(std::shared_ptr<CollisionObject> obj);

        void update() override;

    private:

        std::vector<std::shared_ptr<CollisionObject> > m_roadEntities;

    };
}


#endif //GEVPROGROADFIGHTER_WORLD_H
