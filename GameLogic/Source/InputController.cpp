//
// Created by thibaut on 06.12.18.
//

#include <InputController.h>

#include "InputController.h"
namespace roadfighter{
    void InputController::setVertMove(EVertMove move) {
        m_nextVertMove=move;
    }

    void InputController::setHorMove(EHorMove move) {
        m_nextHorMove=move;
    }

    EVertMove InputController::getNextVertMove() const {
        return m_nextVertMove;
    }

    EHorMove InputController::getNextHorMove() const {
        return m_nextHorMove;
    }

    void InputController::setNone() {
        m_nextVertMove=v_none;
        m_nextHorMove=h_none;
        m_shoot= false;
        m_textInput="";
    }

    void InputController::shoot() {
        m_shoot=true;
    }

    void InputController::noShoot() {
        m_shoot=false;
    }

    bool InputController::mustShoot() const {
        return m_shoot;
    }

    void InputController::setText(const std::string &newtext) {
        m_textInput=newtext;
    }

    std::string InputController::getText() const {
        return m_textInput;
    }
}