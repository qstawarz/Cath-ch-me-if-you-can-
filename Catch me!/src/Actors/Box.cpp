//
// Created by Quentin on 11/17/2017.
//
#include <iostream>

#include "../../includes/Actors/Box.h"
#include "../../includes/Managers/DisplayManager.h"


using namespace Actors;
using namespace Managers;

Box::Box(sf::RenderWindow *p_window,
         Vector<float> *p_mouseVector,
         sf::Time *p_time) : m_window {p_window}, m_mousePos {p_mouseVector}, m_time {p_time},
                             m_pos {rand()%DisplayManager::m_windowW, rand()%DisplayManager::m_windowH, true},
                             m_sprite {nullptr}, m_scale {0.3f}, m_IsHidingAMouse {false}
{
    std::cout << "Box created" << std::endl;
}

Box::~Box()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    std::cout << "Box destroyed" << std::endl;
}

void Box::Setup()
{
    this->m_sprite = new Sprite("../res/Assets/box.png");

    float xBound = this->m_sprite->getSprite()->getTextureRect().width / 2.0f;
    float yBound = this->m_sprite->getSprite()->getTextureRect().height / 2.0f;

    this->m_sprite->getSprite()->setOrigin(xBound, yBound);
    this->m_sprite->getSprite()->setPosition(this->m_pos.toSFML());
    this->m_sprite->getSprite()->scale(Vector<float>(this->m_scale, this->m_scale, true).toSFML());
}

void Box::Update()
{
    this->m_pos.x() = this->m_sprite->getSprite()->getPosition().x;
    this->m_pos.y() = this->m_sprite->getSprite()->getPosition().y;

    this->Move();

    this->m_IsHidingAMouse = this->m_mousePos->length(this->m_pos) < 10.0f;
}

void Box::Display()
{
    this->m_window->draw(*this->m_sprite->getSprite());
}

void Box::Move()
{
    static sf::Time last_time = *this->m_time;
    //Each 2 seconds reSet the box position
    if (this->m_time->asSeconds() - last_time.asSeconds() >= 10.0f)
    {
        this->m_sprite->getSprite()->setPosition(rand()%DisplayManager::m_windowW, rand()%DisplayManager::m_windowH);
        last_time = *this->m_time;
    }
}

bool Box::IsHidingAMouse() const
{
    return this->m_IsHidingAMouse;
}