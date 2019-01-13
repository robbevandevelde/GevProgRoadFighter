#ifndef GEVPROGROADFIGHTER_RACINGCAR_H
#define GEVPROGROADFIGHTER_RACINGCAR_H

#include "MovingObject.h"
#include "Observer/Observable.h"
#include "../../Utility/Random.h"
namespace roadfighter {
    class RacingCar :public MovingObject{
    public:
        /**
       * default constructor for RacingCar
       */
        RacingCar()= default;

        /**
         * copy constructor
         * @param copy the other RacingCar that is being copied
         */
        RacingCar(const RacingCar &copy)= default;

        /**
         * move constructor
         * @param Move the other RacingCar that is being moved in this one
         */
        RacingCar(RacingCar &&move)= default;

        //constructor with all the variables given
        RacingCar(const Location &m_loc1, const Location &m_loc2, double m_maxVertSpeed, double m_vertAccel,
                  double m_horAccel);

        /**
         * copy assigment for RacingCar
         * @param other the RacingCar that is being copied
         * @return a new RacingCar that is equal to the other one
         */
        RacingCar& operator=(const RacingCar& other)= default;

        /**
         * move assignment for RacingCar
         * @param other other RacingCar that is being moved
         * @return a RacingCar
         * that contains all the data of the first one
         */
        RacingCar& operator=(RacingCar&& other)= default;

        /**
         * destructor for RacingCar
         */
        ~RacingCar() override = default;

       //updates the movement of this class by dt ticks
        void updateMovement(double dt) override;

       //updates the logic of the car
        void updateLogic() override;

        //a function that says wether this car must be deletete or not
        bool mustDelete() const override;

        //an overidden fucntion that says what must happen if this car wins
        void win() override;

        //functiont hat handles the logic for wath happens when something collides with this
        void collideWith(std::shared_ptr<CollisionObject> &collided) override;

        //handles the crashing for this car
        void crash() override;

        //handles getting shot for this car
        void shot() override;

        //handles the bonus for this car
        void bonus() override;
    };
}


#endif //GEVPROGROADFIGHTER_RACINGCAR_H
