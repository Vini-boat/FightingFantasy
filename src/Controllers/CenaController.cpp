#include "CenaController.h"
#include "../../include/Models/CenaViewModel.h"
#include "../../include/Models/SaveModel.h"

#include <vector>
#include <string>

using namespace std;
CenaController::CenaController(CenaViewModel* model, SaveModel* save)
{
    this->model = model;
    this->save = save;
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

void CenaController::carregarSave()
{
    this->model->setCenaAtual(this->save->getCenaAtual());
}

vector<string> CenaController::getEscolhasCena()
{
    return this->model->getCenasEscolhasCenaAtual();
}
