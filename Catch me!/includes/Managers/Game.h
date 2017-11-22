//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_GAME_H
#define CATCH_ME_GAME_H

#include "IManager.h"
#include "DisplayManager.h"
#include "InputManager.h"
#include "UIManager.h"
#include "../Actors/Cat.h"
#include "../Actors/Mouse.h"
#include "../Actors/Box.h"
//#include "../States/StateBase.h"

namespace States
{
    class StateBase;
}

using namespace Actors;
using namespace States;

namespace Managers
{
    class Game : public IManager
    {
    private:
        DisplayManager *m_displayManager;
        InputManager *m_inputManager;
        UIManager *m_uiManager;
        Mouse *m_mouse;
        Cat *m_cat;
        Box *m_box;

        sf::Clock m_clock;
        sf::Time m_deltaTime;
        sf::Time m_time;
    //TODO Container of states
//        std::vector<std::unique_ptr<StateBase>> m_states;

    public:
        Game();
        ~Game();

        void Setup() override;
        void Update() override;

        void Display();
        void Run();
    //TODO PushState
//        template<typename T, typename... Args>
//        void PushState(Args && ... args);
    //TODO Get current State
//        StateBase &GetCurrentState();

        DisplayManager *getDisplayManager() const;
        InputManager *getInputManager() const;
        UIManager *getUIManager() const;
        Mouse *getMouse() const;
        Cat *getCat() const;
        Box *getBox() const;

        sf::Time &getDeltaTime();
        sf::Time &getTime();

    };
    //TODO Try to understand std::make_unique (Why doesn't work)
//    template <typename T, typename ... Args>
//    void Game::PushState(Args&&... args)
//    {
//        this->m_states.push_back(std::make_unique<T>(std::forward<Args>(args)...));
//    }
}

#endif //CATCH_ME_GAME_H