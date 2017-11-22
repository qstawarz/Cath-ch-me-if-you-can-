//
// Created by Quentin on 11/17/2017.
//

#ifndef CATCH_ME_STATEGAMEOVER_H
#define CATCH_ME_STATEGAMEOVER_H

#include "StateBase.h"

namespace States
{
    class StateGameOver : public StateBase
    {
    private:
        DisplayManager *m_displayManager;
        InputManager *m_inputManager;
        UIManager *m_uiManager;

    public:
        explicit StateGameOver(Game& p_game);
        ~StateGameOver();

        void Setup() override;
        void Update() override;
        void Display() override;

    };
}

#endif //CATCH_ME_STATEGAMEOVER_H