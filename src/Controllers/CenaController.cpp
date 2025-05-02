#include "CenaController.h"
#include "../../include/Models/CenaViewModel.h"
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"

#include <vector>
#include <string>

using namespace std;
CenaController::CenaController(CenaViewModel* model, SaveModel* save, PersonagemModel* player)
{
    this->model = model;
    this->save = save;
    this->player = player;
}

CenaController::~CenaController()
{
    //dtor
}

void CenaController::changeCena(string cena)
{
    this->model->setCenaAtual(cena);
    this->save->addCenaPassada(cena);
    this->save->setCenaAtual(cena);
    this->salvar();

    this->addItensToPlayer();
    this->player->setTesouro(this->player->getTesouro() + this->model->getTesouroCenaAtual());
}

void CenaController::salvar()
{
    this->save->serializar("./data/saves/ex_savegame.txt");
}

string CenaController::getCenaText()
{
    return this->model->getTextoCenaAtual();
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

vector<string> CenaController::getDescricaoEscolhasCena()
{
    return this->model->getDescricaoEscolhasCenaAtual();
}

void CenaController::addItensToPlayer()
{
    for(string& i: this->model->getItensCenaAtual())
    {
        this->player->addItem(i);
    }
    this->player->salvar();
}

vector<string> CenaController::getMonstrosCombates()
{
    return this->model->getMonstrosCombatesCenaAtual();
}
vector<string> CenaController::getDescricaoCombates()
{
    return this->model->getDescricaoCombatesCenaAtual();
}
