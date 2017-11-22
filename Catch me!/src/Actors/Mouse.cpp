//
// Created by Quentin on 11/15/2017.
//
#include <iostream>

#include "../../includes/Actors/Mouse.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Actors;
using namespace Managers;

Mouse::Mouse(sf::RenderWindow *p_window) : m_window {p_window}, m_pos {nullptr}, m_sprite {nullptr}, m_scale {0.3f}
{
    std::cout << "Mouse created" << std::endl;
}

Mouse::~Mouse()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    if (this->m_pos != nullptr)
        delete this->m_pos;

    std::cout << "Mouse destroyed" << std::endl;
}

void Mouse::Setup()
{   //TODO Check why the window closed on y axe for x = 0
    this->m_sprite = new Sprite("../res/Assets/mouse.png");

    float xBound = this->m_sprite->getSprite()->getTextureRect().width / 2.0f;
    float yBound = this->m_sprite->getSprite()->getTextureRect().height / 2.0f;

    this->m_pos = new Vector<float>(DisplayManager::m_windowW / 2.0f, DisplayManager::m_windowH / 2.0f, true);

    this->m_sprite->getSprite()->setOrigin(xBound, yBound);
    this->m_sprite->getSprite()->setPosition(this->m_pos->toSFML());
    this->m_sprite->getSprite()->scale(Vector<float>(this->m_scale, this->m_scale, true).toSFML());
}

void Mouse::Update()
{
    this->m_pos->x() = sf::Mouse::getPosition(*this->m_window).x;
    this->m_pos->y() = sf::Mouse::getPosition(*this->m_window).y;

    this->Move();
}

void Mouse::Display()
{
    this->m_window->draw(*this->m_sprite->getSprite());
}

void Mouse::Move()
{
    this->m_sprite->getSprite()->setPosition(this->m_pos->toSFML());
}

Vector<float> *Mouse::getPos() const
{
    return this->m_pos;
}