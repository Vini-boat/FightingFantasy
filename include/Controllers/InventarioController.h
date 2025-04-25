#ifndef INVENTARIOCONTROLLER_H
#define INVENTARIOCONTROLLER_H

#include <BaseController.h>
#include "../../include/Models/PersonagemModel.h"

class InventarioController : public BaseController
{
    public:
        InventarioController(PersonagemModel* model);
        virtual ~InventarioController();

    protected:

    private:
        PersonagemModel* model;
};

#endif // INVENTARIOCONTROLLER_H
