/**
 * @file
 * this file contains the implementation of the InputController class
 * @author Thibaut Van Goethem
 */
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
     * simple function that sets the shoot bool on false
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
     * getter for the text
     * @return a string that is the text
     * @exception none
     */
    std::string InputController::getText() const {
        return m_textInput;
    }

    /**
     * this function sets the horizontal move to left
     * @return none
     * @exception none
     */
    void InputController::moveLeft() {
        setHorMove(h_left);
    }

    /**
     * this function sets the horizontal move to the right
     * @return none
     * @exception none
     */
    void InputController::moveRight() {
        setHorMove(h_right);
    }

    /**
     * this function sets the vertical move to accelerate
     * @return none
     * @exception none
     */
    void InputController::accelerate() {
        setVertMove(v_accel);
    }

    /**
     * this function sets the horizontal move to decelerate
     * @return none
     * @exception none
     */
    void InputController::decelerate() {
        setVertMove(v_decel);
    }

    /**
     * this function sets the horizontal move to h_none
     * @return none
     * @exception none
     */
    void InputController::stopHorizontalMove() {
        setHorMove(h_none);
    }

    /**
     * this function sets the vertical move to v_none
     * @return none
     * @exception none
     */
    void InputController::stopVerticalMove() {
        setVertMove(v_none);
    }

}