#include "../../include/Controllers/NewGameController.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Models/NewGameViewModel.h"

#include <string>

using namespace std;
NewGameController::NewGameController(NewGameViewModel* view_model, PersonagemModel* model)
{
    this->view_model = view_model;
    this->model = model;
}

NewGameController::~NewGameController()
{
    //dtor
}

void NewGameController::createNewPersonagem()
{
    this->model->setNome(this->view_model->getNome());
    this->model->setHabilidade(this->view_model->getHabilidade());
    this->model->setEnergia(this->view_model->getEnergia());
    this->model->setSorte(this->view_model->getSorte());
    //this->salvarPersonagem();
}

void NewGameController::salvar()
{
    this->createNewPersonagem();
    this->model->serializar("./data/personagens/p1.txt");
}


bool NewGameController::validarHabilidade(int habilidade)
{
    return true;
}
bool NewGameController::validarEnergia(int energia)
{
    return true;
}
bool NewGameController::validarSorte(int sorte)
{
    return true;
}
