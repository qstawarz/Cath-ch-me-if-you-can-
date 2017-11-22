//
// Created by Quentin on 11/17/2017.
//
#include <iostream>

#include "../../includes/States/StatePlaying.h"

using namespace States;

StatePlaying::StatePlaying(Game &p_game) : StateBase(p_game), m_displayManager {nullptr}, m_inputManager {nullptr},
                                           m_uiManager {nullptr}, m_mouse {nullptr}, m_cat {nullptr}, m_box {nullptr}
{
    std::cout << "StatePlaying created" << std::endl;
}

StatePlaying::~StatePlaying()
{
    std::cout << "StatePlaying destroyed" << std::endl;
}

void StatePlaying::Setup()
{
    this->m_displayManager = this->m_game.getDisplayManager();
    this->m_inputManager = this->m_game.getInputManager();
    this->m_uiManager = this->m_game.getUIManager();
    this->m_mouse = this->m_game.getMouse();
    this->m_cat = this->m_game.getCat();
    this->m_box = this->m_game.getBox();
}

void StatePlaying::Update()
{
    this->m_displayManager->Update();

    this->m_inputManager->Update();

    this->m_uiManager->Update();

    this->m_mouse->Update();

    if (!this->m_box->IsHidingAMouse())
        this->m_cat->Update();

    this->m_box->Update();
}

void StatePlaying::Display()
{
    this->m_mouse->Display();

    this->m_box->Display();

    this->m_cat->Display();

    this->m_uiManager->Display();
    this->m_uiManager->Score();

    this->m_displayManager->getWindow()->display();
}