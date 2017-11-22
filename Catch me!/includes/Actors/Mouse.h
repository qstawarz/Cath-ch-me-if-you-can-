//
// Created by Quentin on 11/15/2017.
//

#ifndef CATCH_ME_MOUSE_H
#define CATCH_ME_MOUSE_H

#include <SFML/Graphics.hpp>

#include "IActor.h"
#include "../Utils/Vector.h"
#include "../Utils/Sprite.h"

using namespace Utils;

namespace Actors
{
    class Mouse : public IActor
    {
    private:
        sf::RenderWindow *m_window;

        Vector<float> *m_pos;

        Sprite *m_sprite;

        float m_scale;

    public:
        explicit Mouse(sf::RenderWindow *p_window);
        ~Mouse();

        void Setup() override;
        void Update() override;
        void Display() override;
        void Move() override;

        Vector<float> *getPos() const;

    };
}

#endif //CATCH_ME_PLAYER_H