#ifndef NEWGAMECONTROLLER_H
#define NEWGAMECONTROLLER_H

#include <BaseController.h>
#include "../Models/PersonagemModel.h"


class NewGameController : public BaseController
{
    public:
        NewGameController(PersonagemModel* model);
        virtual ~NewGameController();

        void createNewPersonagem();
        void salvarPersonagem();

    protected:

    private:
        PersonagemModel* model;
};

#endif // NEWGAMECONTROLLER_H
