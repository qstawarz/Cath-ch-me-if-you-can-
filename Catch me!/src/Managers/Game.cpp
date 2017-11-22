//
// Created by Quentin on 11/14/2017.
//
#include "../../includes/Managers/Game.h"
//#include "../../includes/States/StatePlaying.h"
//#include "../../includes/States/StateGameOver.h"

using namespace Managers;

Game::Game() : m_displayManager {nullptr}, m_inputManager {nullptr}, m_uiManager {nullptr},
               m_mouse {nullptr}, m_cat {nullptr}, m_box {nullptr},
               m_clock {}, m_time {}, m_deltaTime {}
{   //TODO Pushing states
//    this->PushState<StatePlaying>(*this);
//    this->PushState<StateGameOver>(*this);

    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    if (this->m_box != nullptr)
        delete this->m_box;

    if (this->m_cat != nullptr)
        delete this->m_cat;

    if (this->m_mouse != nullptr)
        delete this->m_mouse;

    if (this->m_uiManager != nullptr)
        delete this->m_uiManager;

    if (this->m_inputManager != nullptr)
        delete this->m_inputManager;

    if (this->m_displayManager != nullptr)
        delete this->m_displayManager;

    std::cout << "Game destroyed" << std::endl;
}

void Game::Setup()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    //DisplayManager
    this->m_displayManager = new DisplayManager;
    if (this->m_displayManager != nullptr)
        this->m_displayManager->Setup();
    //InputManager
    if (this->m_displayManager->IsStarted());
        this->m_inputManager = new InputManager(this->m_displayManager->getWindow());
    if (this->m_inputManager != nullptr)
        this->m_inputManager->Setup();
    //UIManager
    if (this->m_displayManager->IsStarted());
    this->m_uiManager = new UIManager(this->m_displayManager->getWindow(), &this->m_time);
    if (this->m_uiManager != nullptr)
        this->m_uiManager->Setup();
    //Mouse
    if (this->m_displayManager->IsStarted())
        this->m_mouse = new Mouse(this->m_displayManager->getWindow());
    if (this->m_mouse != nullptr)
        this->m_mouse->Setup();
    //Cat
    if (this->m_displayManager->IsStarted())
        this->m_cat = new Cat(this->m_displayManager->getWindow(), this->m_mouse->getPos(), &this->m_deltaTime, &this->m_time);
    if (this->m_cat != nullptr)
        this->m_cat->Setup();
    //Box
    if (this->m_displayManager->IsStarted())
        this->m_box = new Box(this->m_displayManager->getWindow(), this->m_mouse->getPos(), &this->m_time);
    if (this->m_box != nullptr)
        this->m_box->Setup();
}

void Game::Update()
{   //TODO Setup, Update, Display current State
//    StateBase &state = this->GetCurrentState();
//
//    state.Setup();
//    state.Update();
//    state.Display();

    this->m_displayManager->Update();

    this->m_inputManager->Update();

    this->m_uiManager->Update();

    this->m_mouse->Update();

    if (!this->m_box->IsHidingAMouse())
        this->m_cat->Update();

    this->m_box->Update();
}

void Game::Display()
{
    this->m_mouse->Display();

    this->m_box->Display();

    this->m_cat->Display();

    this->m_uiManager->Display();
    this->m_uiManager->Score();

    this->m_displayManager->getWindow()->display();
}

void Game::Run()
{
    while (this->m_displayManager->IsRunning())
    {
        this->Update();

        this->Display();

        if (this->m_inputManager->MouseLeft() || this->m_cat->IsSatiated())
        {   //TODO Try to not loop here (StateBase ?)
            while (this->m_displayManager->IsRunning())
            {
                this->m_inputManager->checkInput(*this->m_displayManager->getWindow());

                this->m_displayManager->getWindow()->clear();

                this->m_uiManager->Display();
                this->m_uiManager->Score();
                this->m_uiManager->GameOver();

                this->m_displayManager->getWindow()->display();
            }
        }

        this->m_deltaTime = this->m_clock.restart();
        this->m_time += this->m_deltaTime;
    }
}

//StateBase &Game::GetCurrentState()
//{
//    return *this->m_states.back();
//}

DisplayManager *Game::getDisplayManager() const
{
    return this->m_displayManager;
}

InputManager *Game::getInputManager() const
{
    return this->m_inputManager;
}

UIManager *Game::getUIManager() const
{
    return this->m_uiManager;
}

Mouse *Game::getMouse() const
{
    return this->m_mouse;
}

Cat *Game::getCat() const
{
    return this->m_cat;
}

Box *Game::getBox() const
{
    return this->m_box;
}

sf::Time &Game::getDeltaTime()
{
    return this->m_deltaTime;
}

sf::Time &Game::getTime()
{
    return this->m_time;
}