//
// Created by thibaut on 06.12.18.
//


#include "MoveController.h"
namespace roadfighter{
    void MoveController::setVertMove(EVertMove move) {
        m_nextVertMove=move;
    }

    void MoveController::setHorMove(EHorMove move) {
        m_nextHorMove=move;
    }

    EVertMove MoveController::getNextVertMove() const {
        return m_nextVertMove;
    }

    EHorMove MoveController::getNextHorMove() const {
        return m_nextHorMove;
    }

    void MoveController::setNone() {
        m_nextVertMove=v_none;
        m_nextHorMove=h_none;
        m_shoot= false;
    }

    void MoveController::shoot() {
        m_shoot=true;
    }

    void MoveController::noShoot() {
        m_shoot=false;
    }

    bool MoveController::mustShoot() const {
        return m_shoot;
    }
}