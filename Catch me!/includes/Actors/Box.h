//
// Created by Quentin on 11/17/2017.
//

#ifndef CATCH_ME_BOX_H
#define CATCH_ME_BOX_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../Utils/Vector.h"
#include "../Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Box : public IActor
    {
    public:

    private:
        sf::RenderWindow *m_window;
        sf::Time *m_time;

        Vector<float> *m_mousePos;
        Vector<float> m_pos;

        Sprite *m_sprite;

        float m_scale;

        bool m_IsHidingAMouse;

    public:
        explicit Box(sf::RenderWindow *p_window, Vector<float> *p_mouseVector, sf::Time *p_time);
        ~Box();

        void Setup() override;
        void Update() override;
        void Display() override;
        void Move() override;

        bool IsHidingAMouse() const;

    };
}

#endif //CATCH_ME_BOX_H