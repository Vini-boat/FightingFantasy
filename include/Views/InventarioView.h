#ifndef INVENTARIOVIEW_H
#define INVENTARIOVIEW_H

#include <BaseView.h>

#include "../../include/Controllers/InventarioController.h"
#include "../../include/Models/PersonagemModel.h"

class InventarioView : public BaseView
{
    public:
        InventarioView(InventarioController* controller, PersonagemModel* model);
        virtual ~InventarioView();

        void show() override;
        void handleInput() override;

    protected:

    private:
        InventarioController* controller;
        PersonagemModel* model;
};

#endif // INVENTARIOVIEW_H
