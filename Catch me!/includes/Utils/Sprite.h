//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_SPRITE_H
#define CATCH_ME_SPRITE_H

#include <SFML/Graphics.hpp>

namespace Utils
{
    class Sprite
    {
    private:
        sf::Texture *m_texture;
        sf::Sprite *m_sprite;

    public:
        explicit Sprite(const std::string &p_filename);
        ~Sprite();

        void loadSprite(const std::string &p_filename);

        sf::Sprite *getSprite() const;

    };
}

#endif //CATCH_ME_SPRITE_H