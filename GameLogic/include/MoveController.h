/**
 * @file
 * this file contains the movecontroller class that handles the acces of current keyboard input over the whole roadfighter game
 * it also contains 2 enums used to represent vertical and horizontal movement
 */

#ifndef GEVPROGROADFIGHTER_MOVECONTROLLER_H
#define GEVPROGROADFIGHTER_MOVECONTROLLER_H

enum EVertMove{v_none,v_accel,v_decel};
enum EHorMove{h_none,h_left,h_right};

namespace roadfighter {
    class MoveController {
    public:
        /**
         * default constructor
         */
        MoveController()= default;

        /**
         * setter for the verticalmove
         * @param move a EVertmove enum
         */
        void setVertMove(EVertMove move);

        /**
         * setter for the horizontal move
         * @param move a EHorMove enum
         */
        void setHorMove(EHorMove move);

        /**
         * getter for the vertivalmove
         * @return an EVertMove enum
         */
        EVertMove getNextVertMove() const;

        /**
         * a getter for the horizontalmove
         * @return an EHorMove enum
         */
        EHorMove getNextHorMove() const;

        /**
         * a function that sets both the vertival and horizontal mvoe to none
         */
        void setNone();

    private:
        EVertMove m_nextVertMove;

        EHorMove m_nextHorMove;
    };
}


#endif //GEVPROGROADFIGHTER_MOVECONTROLLER_H
