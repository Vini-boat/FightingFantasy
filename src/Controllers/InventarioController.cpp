#include "InventarioController.h"
#include "../../include/Models/PersonagemModel.h"

InventarioController::InventarioController(PersonagemModel* model)
{
    this->model = model;
}

InventarioController::~InventarioController()
{
    //dtor
}
