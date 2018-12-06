#include <utility>

//
// Created by thibaut on 01.12.18.
//
#include <RoadFighterGame.h>

namespace roadfighter{
    RoadFighterGame::RoadFighterGame() {
        m_Factory=std::make_shared<GLL_Entity_Factory>(GLL_Entity_Factory());
        initialize();
    }

    RoadFighterGame::RoadFighterGame(std::shared_ptr<Entity_Factory_base> factory) {
        m_Factory= std::move(factory);
        initialize();
    }


    void RoadFighterGame::tick() {
        m_world->update();
    }


    void RoadFighterGame::drawWorld() {
        m_world->draw();
    }

    void RoadFighterGame::moveLeft() {
        m_MoveController->setHorMove(h_left);
    }

    void RoadFighterGame::moveRight() {
        m_MoveController->setHorMove(h_right);
    }

    void RoadFighterGame::accelerate() {
        m_MoveController->setVertMove(v_accel);
    }

    void RoadFighterGame::decelerate() {
        m_MoveController->setVertMove(v_decel);
    }

    void RoadFighterGame::initialize() {
        m_Transporter=std::make_shared<EntityTransporter>(EntityTransporter());
        m_MoveController=std::make_shared<MoveController>(MoveController());
        m_Factory->setController(m_MoveController);
        m_Factory->setTransporter(m_Transporter);

        m_world=m_Factory->createWorld();
        m_Transporter->addEntity(m_Factory->createPlayerCar());

    }


}