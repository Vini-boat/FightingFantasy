#ifndef INVENTARIOVIEW_H
#define INVENTARIOVIEW_H

#include <BaseView.h>

#include "../../include/Controllers/InventarioController.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Controllers/ItemController.h"

#include <memory>

using namespace std;
class InventarioView : public BaseView
{
    public:
        InventarioView(InventarioController* controller, PersonagemModel* model, shared_ptr<ItemController> item_controller);
        virtual ~InventarioView();

        void show() override;
        void handleInput() override;

    protected:

    private:
        InventarioController* controller;
        PersonagemModel* model;
        shared_ptr<ItemController> item_controller;
};

#endif // INVENTARIOVIEW_H
