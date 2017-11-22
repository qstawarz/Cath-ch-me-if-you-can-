//
// Created by Quentin on 11/17/2017.
//

#ifndef CATCH_ME_STATEBASE_H
#define CATCH_ME_STATEBASE_H

#include "../Managers/Game.h"

namespace Managers
{
    class Game;
}

using namespace Managers;

namespace States
{
    class StateBase
    {
    protected:
        Game &m_game;

    public:
        explicit StateBase(Game &p_game) : m_game(p_game) {}
        virtual ~StateBase() = default;

        virtual void Setup() = 0;
        virtual void Update() = 0;
        virtual void Display() = 0;

    };
}

#endif //CATCH_ME_STATEBASE_H