//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_CAT_H
#define CATCH_ME_CAT_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../Utils/Vector.h"
#include "../Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Cat : public IActor
    {
    private:
        sf::RenderWindow *m_window;
        sf::Time *m_deltaTime;
        sf::Time *m_time;

        Vector<float> *m_mousePos;
        Vector<float> m_pos;
        Vector<float> m_velocity;
        Vector<float> m_acceleration;

        Sprite *m_sprite;

        float m_scale;
        float m_maxVelocity;
        float m_maxAcceleration;
        float m_mass;
        float m_jumpRange;

        bool m_isSatiated;

    public:
        explicit Cat(sf::RenderWindow *p_window, Vector<float> *p_mouseVector, sf::Time *p_deltaTime, sf::Time *p_time);
        ~Cat();

        void Setup() override;
        void Update() override;
        void Display() override;
        void Move() override;

        void LevelUp();

        bool IsSatiated() const;

    };
}

#endif //CATCH_ME_PLAYER_H