//
// Created by Quentin on 11/17/2017.
//

#ifndef CATCH_ME_STATEPLAYING_H
#define CATCH_ME_STATEPLAYING_H

#include "StateBase.h"

namespace States
{
    class StatePlaying : public StateBase
    {
    private:
        DisplayManager *m_displayManager;
        InputManager *m_inputManager;
        UIManager *m_uiManager;
        Mouse *m_mouse;
        Cat *m_cat;
        Box *m_box;

    public:
        explicit StatePlaying(Game& p_game);
        ~StatePlaying();

        void Setup() override;
        void Update() override;
        void Display() override;

    };
}

#endif //CATCH_ME_STATEPLAYING_H