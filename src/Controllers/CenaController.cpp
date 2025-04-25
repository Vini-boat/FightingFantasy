#include "CenaController.h"
#include "../../include/Models/CenaViewModel.h"


CenaController::CenaController(CenaViewModel* model)
{
    this->model = model;
}

CenaController::~CenaController()
{
    //dtor
}

void CenaController::changeCena(string cena)
{
    this->model->setCenaAtual(cena);
}

string CenaController::getCenaText()
{
    //return this->model->
}
string CenaController::getCenaName()
{
    return this->model->getNomeCenaAtual();
}
