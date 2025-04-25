#include "../../include/Controllers/NewGameController.h"
#include "../../include/Models/PersonagemModel.h"

#include <string>

using namespace std;
NewGameController::NewGameController(PersonagemModel* model)
{
    this->model = model;
}

NewGameController::~NewGameController()
{
    //dtor
}

void NewGameController::createNewPersonagem(string nome, int habilidade, int energia, int sorte)
{
    this->model->setNome(nome);
    this->model->setHabilidade(habilidade);
    this->model->setEnergia(energia);
    this->model->setSorte(sorte);
    //this->salvarPersonagem();
}

void NewGameController::salvarPersonagem()
{
    this->model->serializar("./Personagens/p1.txt");
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
