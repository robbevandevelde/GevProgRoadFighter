/**
 * @file
 * this file is the declaration of the class World and all it members
 * @author Thibaut Van Goethem
 */
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

        //constructor with entity transporter
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

        //function that sets back all the entities in world with double setback
        void setBackY(double setback);

        //function that updates the movement for all the entities
        void updateMovement(double dt) override;

        //gets new entities out of the transporter
        void getNewEntities();

        //checks collision for all entities
        void checkCollision();

        //calls draw funtion on all entities
        void draw() override;

        //updates all logic for the entities
        void updateLogic() override;

        //deletes all entities whose mustdelete function returns true
        void deleteUnused();

        //get the amount of y variance has been moved since last movementtick
        //this can be used to make the background scroll
        double getTickMovement() const;

        //function that calls the dettach function on all entities that inherit from the observable class
        void dettachAllObservers();

    private:

        std::vector<std::shared_ptr<Entity> > m_roadEntities;

        std::shared_ptr<roadfighter::EntityTransporter> m_Transporter;

        double m_tickMovement;

    };
}


#endif //GEVPROGROADFIGHTER_WORLD_H
