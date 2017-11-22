//
// Created by Quentin on 11/14/2017.
//
#include <iostream>

#include "../../includes/Managers/InputManager.h"

using namespace Managers;

InputManager::InputManager(sf::RenderWindow *p_window) : m_window {p_window}, m_event {nullptr},
                                                         m_mouseLeft {false}, m_replay {false}
{
    std::cout << "InputManager created" << std::endl;
}

InputManager::~InputManager()
{
    if (this->m_event != nullptr)
        delete this->m_event;

    std::cout << "InputManager destroyed" << std::endl;
}

void InputManager::Setup()
{
    this->m_event = new sf::Event;
}

void InputManager::Update()
{
    this->checkInput(*this->m_window);
}

void InputManager::checkInput(sf::RenderWindow &p_window)
{
    while (p_window.pollEvent(*this->m_event))
    {
        if (this->m_event->type == sf::Event::Closed)
            p_window.close();

        if (this->m_event->key.code == sf::Keyboard::Escape)
            p_window.close();

        if (this->m_event->type == sf::Event::MouseLeft)
            this->m_mouseLeft = true;

        if (this->m_event->key.code == sf::Keyboard::Space)
            this->m_replay = true;
    }
}

sf::Event *InputManager::getEvent() const
{
    return this->m_event;
}

bool InputManager::MouseLeft() const
{
    return this->m_mouseLeft;
}

bool &InputManager::Replay()
{
    return this->m_replay;
}
