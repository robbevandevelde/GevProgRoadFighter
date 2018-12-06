//
// Created by thibaut on 06.12.18.
//

#ifndef GEVPROGROADFIGHTER_MOVECONTROLLER_H
#define GEVPROGROADFIGHTER_MOVECONTROLLER_H

enum EVertMove{v_none,v_accel,v_decel};
enum EHorMove{h_none,h_left,h_right};

namespace roadfighter {
    class MoveController {
    public:
        MoveController()= default;

        void setVertMove(EVertMove move);

        void setHorMove(EHorMove move);

        EVertMove getNextVertMove() const;

        EHorMove getNextHorMove() const;

        void setNone();

    private:
        EVertMove m_nextVertMove;

        EHorMove m_nextHorMove;
    };
}


#endif //GEVPROGROADFIGHTER_MOVECONTROLLER_H
