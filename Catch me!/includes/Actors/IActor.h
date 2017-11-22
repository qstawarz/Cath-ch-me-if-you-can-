//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_IACTOR_H
#define CATCH_ME_IACTOR_H

namespace Actors
{
    class IActor
    {
    public:
        virtual ~IActor() = default;

        virtual void Setup() = 0;
        virtual void Update() = 0;
        virtual void Display() = 0;
        virtual void Move() = 0;

    };
}

#endif //CATCH_ME_IACTOR_H