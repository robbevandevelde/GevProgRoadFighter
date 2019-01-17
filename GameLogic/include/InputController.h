/**
 * @file
 * this file contains the movecontroller class that handles the access of current keyboard input over the whole roadfighter game
 * it also contains 2 enums used to represent vertical and horizontal movement
 * @author Thibaut Van Goethem
 */

#ifndef GEVPROGROADFIGHTER_MOVECONTROLLER_H
#define GEVPROGROADFIGHTER_MOVECONTROLLER_H

#include <iostream>
enum EVertMove{v_none,v_accel,v_decel};
enum EHorMove{h_none,h_left,h_right};

namespace roadfighter {
    class InputController {
    public:
        /**
         * default constructor
         */
        InputController()= default;

        //function to set vertical movement
        void setVertMove(EVertMove move);

        //function to set horizontal movement
        void setHorMove(EHorMove move);

        //function to get next vertical move
        EVertMove getNextVertMove() const;

        //function to get next horizontal move
        EHorMove getNextHorMove() const;

        //function to clear all current input
        void setNone();

        //simple function that sets the shoot bool to true
        void shoot();

        // simple function that sets the shoot bool on false
        void noShoot();

        //getter for the shoot bool
        bool mustShoot() const;

        //setter for the text string
        void setText(const std::string& newtext);

        //getter for the text string
        std::string getText() const;

    private:
        EVertMove m_nextVertMove;

        EHorMove m_nextHorMove;

        bool m_shoot{};

        std::string m_textInput;
    };
}


#endif //GEVPROGROADFIGHTER_MOVECONTROLLER_H
