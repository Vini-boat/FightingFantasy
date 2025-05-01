#include "../../include/Controllers/NewGameController.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Models/NewGameViewModel.h"
#include "../../include/Models/SaveModel.h"

#include <string>

using namespace std;
NewGameController::NewGameController(SaveModel* save, NewGameViewModel* view_model, PersonagemModel* model)
{
    this->save = save;
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
    this->view_model->reset();
}

void NewGameController::salvar()
{
    this->createNewPersonagem();
    string filename = "./data/personagens/" + this->view_model->getNome() + ".txt";
    this->model->serializar(filename);
    this->save->reset();
    this->save->setPersonagem(this->view_model->getNome());
    this->save->serializar("./data/saves/ex_savegame.txt");
}


bool NewGameController::validarHabilidade(int habilidade)
{
    if(habilidade < 6) return false;
    if(habilidade > 12) return false;
    return true;
}
bool NewGameController::validarEnergia(int energia)
{
    if(energia < 12) return false;
    if(energia > 24) return false;
    return true;
}
bool NewGameController::validarSorte(int sorte)
{
    if(sorte < 6) return false;
    if(sorte > 12) return false;
    return true;
}

void NewGameController::setHabilidade(int habilidade)
{
    this->view_model->setHabilidade(habilidade);
}

void NewGameController::setEnergia(int energia)
{
    this->view_model->setEnergia(energia);
}

void NewGameController::setSorte(int sorte)
{
    this->view_model->setSorte(sorte);
}
