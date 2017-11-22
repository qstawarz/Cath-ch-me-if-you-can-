//
// Created by Quentin on 11/17/2017.
//
#include <iostream>

#include "../../includes/States/StateGameOver.h"

using namespace States;

StateGameOver::StateGameOver(Game &p_game) : StateBase(p_game), m_displayManager {nullptr}, m_inputManager {nullptr},
                                             m_uiManager {nullptr}
{
    std::cout << "StateGameOver created" << std::endl;
}

StateGameOver::~StateGameOver()
{
    std::cout << "StateGameOver destroyed" << std::endl;
}

void StateGameOver::Setup()
{
    this->m_displayManager = this->m_game.getDisplayManager();
    this->m_inputManager = this->m_game.getInputManager();
    this->m_uiManager = this->m_game.getUIManager();
}

void StateGameOver::Update()
{
    this->m_displayManager->Update();

    this->m_inputManager->Update();

    this->m_uiManager->Update();
}

void StateGameOver::Display()
{
    this->m_uiManager->Display();
    this->m_uiManager->Score();
    this->m_uiManager->GameOver();

    this->m_displayManager->getWindow()->display();
}