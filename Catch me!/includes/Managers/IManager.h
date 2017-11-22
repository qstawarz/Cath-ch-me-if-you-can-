//
// Created by Quentin on 11/14/2017.
//

#ifndef CATCH_ME_IMANAGER_H
#define CATCH_ME_IMANAGER_H

namespace Managers
{
    class IManager
    {
    public:
        virtual ~IManager() = default;

        virtual void Setup() = 0;
        virtual void Update() = 0;

    };
}

#endif //CATCH_ME_IMANAGER_H