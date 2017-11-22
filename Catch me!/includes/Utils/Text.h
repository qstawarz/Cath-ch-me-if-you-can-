//
// Created by Quentin on 11/16/2017.
//

#ifndef CATCH_ME_TEXT_H
#define CATCH_ME_TEXT_H

#include <SFML/Graphics.hpp>

namespace Utils
{
    class Text
    {
    private:
        sf::Font *m_font;
        sf::Text *m_text;

    public:
        explicit Text(const std::string &p_filename);
        ~Text();

        void loadText(const std::string &p_filename);

        sf::Text *getText() const;

    };
}

#endif //CATCH_ME_TEXT_H