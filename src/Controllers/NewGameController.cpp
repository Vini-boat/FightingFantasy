#include "../../include/Controllers/NewGameController.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Models/NewGameViewModel.h"
#include "../../include/Models/SaveModel.h"

#include <string>
#include <memory>

using namespace std;
NewGameController::NewGameController(SaveModel* save, shared_ptr<NewGameViewModel> view_model, PersonagemModel* model)
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
    this->model->setNome(this->view_model->getNome2());
    this->model->setHabilidade(this->view_model->getHabilidade());
    this->model->setEnergia(this->view_model->getEnergia());
    this->model->setSorte(this->view_model->getSorte());
    //this->salvarPersonagem();
}

void NewGameController::salvar()
{
    string nome = this->view_model->getNome2();
    this->createNewPersonagem();
    string filename = "./data/personagens/" + nome + ".txt";
    this->model->serializar(filename);
    this->save->reset();
    this->save->setPersonagem(nome);
    this->save->serializar("./data/saves/ex_savegame.txt");
    this->view_model->reset();
}


bool NewGameController::validarHabilidade(int habilidade)
{
    if(habilidade < 6) return false;
    if(habilidade > 12) return false;
    int diff = this->view_model->getPontosRestantes() - (habilidade - 6);
    if(diff < 0) return false;
    return true;
}
bool NewGameController::validarEnergia(int energia)
{
    if(energia < 12) return false;
    if(energia > 24) return false;
    int diff = this->view_model->getPontosRestantes() - (energia - 12);
    if(diff < 0) return false;
    return true;
}
bool NewGameController::validarSorte(int sorte)
{
    if(sorte < 6) return false;
    if(sorte > 12) return false;
    int diff = this->view_model->getPontosRestantes() - (sorte - 6);
    if(diff < 0) return false;
    return true;
}

void NewGameController::setHabilidade(int habilidade)
{
    this->view_model->setPontosRestantes(this->view_model->getPontosRestantes() - habilidade + 6);
    this->view_model->setHabilidade(habilidade);
}

void NewGameController::setEnergia(int energia)
{
    this->view_model->setPontosRestantes(this->view_model->getPontosRestantes() - energia + 12);
    this->view_model->setEnergia(energia);
}

void NewGameController::setSorte(int sorte)
{
    this->view_model->setPontosRestantes(this->view_model->getPontosRestantes() - sorte + 6);
    this->view_model->setSorte(sorte);
}
