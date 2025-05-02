#include "CombateController.h"
#include "../../include/Controllers/MonstroController.h"
#include "../../include/Interfaces/ISetMonstro.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Commands/MultiCommand.h"
#include "../../include/Commands/ChangeCena.h"
#include "../../include/Commands/ChangeView.h"
#include "../../include/Commands/MultiCommand.h"
#include "../../include/Controllers/CenaController.h"
#include <memory>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
CombateController::CombateController(shared_ptr<MonstroController> monstro_controller, PersonagemModel* player, shared_ptr<ChangeView> change_to_cenas_view, CenaController* cena_controller)
{
    this->monstro_controller = monstro_controller;
    this->player = player;
    this->change_to_cenas_view = change_to_cenas_view;
    this->cena_controller = cena_controller;
    unsigned seed = time(0);
    srand(seed);
}

CombateController::~CombateController(){}

void CombateController::setMonstro(string monstro)
{
    this->monstro_atual = monstro;
    this->setEnergiaAtual(this->monstro_controller->getEnergia(monstro));
}

void CombateController::setEnergiaAtual(int energia)
{
    this->energia_atual = energia;
}

int CombateController::getEnergiaAtual()
{
    return this->energia_atual;
}

string CombateController::getNomeMonstro()
{
    return this->monstro_atual;
}

int CombateController::getEnergiaMaximaMonstro()
{
    return this->monstro_controller->getEnergia(monstro_atual);
}

int CombateController::getEnergiaPlayer()
{
    return this->player->getEnergia();
}

int CombateController::getEnergiaMaximaPlayer()
{
    return this->player->getEnergiaMaxima();
}

string CombateController::getPlayerName()
{
    return this->player->getNome();
}

int CombateController::getRandomInt(int low, int upp)
{
    return  1+rand()%upp;
}

void CombateController::ataque()
{
    int dano = 2;
    int fa_monstro = getRandomInt(1,10) + this->monstro_controller->getHabilidade(this->monstro_atual);
    int fa_player =  getRandomInt(1,10) + this->player->getHabilidade();

    if(fa_monstro > fa_player) this->player->setEnergia(this->player->getEnergia() - dano);
    if(fa_player > fa_monstro) this->setEnergiaAtual(this->energia_atual - dano);
    if(this->energia_atual <= 0)
    {
        this->change_to_cenas_view->execute();
        auto cmd = make_shared<ChangeCena>(this->cena_controller,to_string(this->monstro_controller->getCenaVitoria(this->monstro_atual)));
        cmd->execute();
    }
    if(this->player->getEnergia() <= 0)
    {
        this->change_to_cenas_view->execute();
        auto cmd = make_shared<ChangeCena>(this->cena_controller,to_string(this->monstro_controller->getCenaDerrota(this->monstro_atual)));
        cmd->execute();
    }
}
