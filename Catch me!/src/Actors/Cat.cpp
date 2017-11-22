//
// Created by Quentin on 11/14/2017.
//
#include <iostream>

#include "../../includes/Actors/Cat.h"
#include "../../includes/Managers/DisplayManager.h"

using namespace Actors;
using namespace Managers;

Cat::Cat(sf::RenderWindow *p_window,
         Vector<float> *p_mouseVector,
         sf::Time *p_deltaTime,
         sf::Time *p_time) : m_window {p_window}, m_mousePos {p_mouseVector}, m_deltaTime {p_deltaTime}, m_time {p_time},
                             m_pos {rand()%DisplayManager::m_windowW, rand()%DisplayManager::m_windowH, true},
                             m_sprite {nullptr}, m_scale {0.5f}, m_maxVelocity {50.0f},
                             m_maxAcceleration {5.0f}, m_mass {1.0f}, m_jumpRange {20.0f}, m_isSatiated {false}
{
    std::cout << "Cat created" << std::endl;
}

Cat::~Cat()
{
    if (this->m_sprite != nullptr)
        delete this->m_sprite;

    std::cout << "Cat destroyed" << std::endl;
}

void Cat::Setup()
{
    this->m_sprite = new Sprite("../res/Assets/cat.png");

    float xBound = this->m_sprite->getSprite()->getTextureRect().width / 2.0f;
    float yBound = this->m_sprite->getSprite()->getTextureRect().height / 2.0f;

    while (this->m_mousePos->length(this->m_pos) < 500.0f)
    {
        this->m_pos.x() = rand()%DisplayManager::m_windowW;
        this->m_pos.y() = rand()%DisplayManager::m_windowH;
    }

    this->m_sprite->getSprite()->setOrigin(xBound, yBound);
    this->m_sprite->getSprite()->setPosition(this->m_pos.toSFML());
    this->m_sprite->getSprite()->scale(Vector<float>(this->m_scale, this->m_scale, true).toSFML());
}

void Cat::Update()
{
    //Velocity
    this->m_velocity += this->m_acceleration;
    if (this->m_velocity.magnitude() > this->m_maxVelocity)
    {
        this->m_velocity.normalize();
        this->m_velocity.scale(this->m_maxVelocity);
    }
    //Update pos
    this->m_pos += this->m_velocity * this->m_deltaTime->asSeconds();
    this->m_acceleration *= 0.0f;
    //Move
    this->Move();
    //LevelUp
    this->LevelUp();
    //Game Over
    if (this->m_mousePos->length(this->m_pos) < 50.0f)
        this->m_isSatiated = true;
}

void Cat::Display()
{
    this->m_window->draw(*this->m_sprite->getSprite());
}

void Cat::Move()
{   //Move
    Vector<float> force = (*this->m_mousePos - this->m_pos) / this->m_mass;
    float angle = force.angle2D(*this->m_mousePos);
    angle = angle / 180.0f * 5.0f;
    this->m_acceleration += force / angle;
    if (this->m_acceleration.magnitude() > this->m_maxAcceleration)
    {
        this->m_acceleration.normalize();
        this->m_acceleration.scale(this->m_maxAcceleration);
    }
    this->m_sprite->getSprite()->setPosition(this->m_pos.toSFML());
    //Rotate
    angle = this->m_velocity.atant2();
    this->m_sprite->getSprite()->setRotation(angle + 90.0f);
    //Jump
    if (this->m_mousePos->length(this->m_pos) < this->m_jumpRange)
    {
        this->m_acceleration += force * 2.0f;
        this->m_sprite->getSprite()->setPosition(this->m_pos.toSFML());
    }
}

void Cat::LevelUp()
{
    static sf::Time last_time = *this->m_time;
    //Each 2 seconds increase maxValue
    if (this->m_time->asSeconds() - last_time.asSeconds() >= 2.0f)
    {
        this->m_maxVelocity += 10.0f;
        this->m_maxAcceleration += 1.0f;
        this->m_jumpRange += 4.0f;
        last_time = *this->m_time;
    }
}

bool Cat::IsSatiated() const
{
    return this->m_isSatiated;
}