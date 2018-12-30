//
// Created by thibaut on 06.12.18.
//

#include <InputController.h>

#include "InputController.h"
namespace roadfighter{
    /**
     * setter for the verticalmove
     * @param move a EVertmove enum
     * @return none
     */
    void InputController::setVertMove(EVertMove move) {
        m_nextVertMove=move;
    }
    /**
    * setter for the horizontal move
    * @param move a EHorMove enum
    * @return none
    * @exception none
    */
    void InputController::setHorMove(EHorMove move) {
        m_nextHorMove=move;
    }
    /**
     * getter for the vertivalmove
     * @return an EVertMove enum
     * @exception none
     */
    EVertMove InputController::getNextVertMove() const {
        return m_nextVertMove;
    }
    /**
     * a getter for the horizontalmove
     * @return an EHorMove enum
     * @exception none
     */
    EHorMove InputController::getNextHorMove() const {
        return m_nextHorMove;
    }

    /**
     * a function that sets all movement types in the controller to none or empty
     * @return none
     * @exception none
     */
    void InputController::setNone() {
        m_nextVertMove=v_none;
        m_nextHorMove=h_none;
        m_shoot= false;
        m_textInput="";
    }

    /**
     * simple function that sets the shoot bool on true
     * @return none
     * @exception none
     */
    void InputController::shoot() {
        m_shoot=true;
    }
    /**
     * simple funtion that sets the shoot bool on false
     */
    void InputController::noShoot() {
        m_shoot=false;
    }

    /**
     * getter for the shoot bool
     * @return a bool
     * @exception none
     */
    bool InputController::mustShoot() const {
        return m_shoot;
    }

    /**
     * setter for the text
     * @param newtext a string that will become the new text
     * @return none
     * @exception none
     */
    void InputController::setText(const std::string &newtext) {
        m_textInput=newtext;
    }

    /**
     * getter for the tecxt
     * @return a string that is the text
     * @exception none
     */
    std::string InputController::getText() const {
        return m_textInput;
    }
}