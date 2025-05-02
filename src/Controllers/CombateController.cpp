#include "CombateController.h"
#include "../../include/Controllers/MonstroController.h"
#include "../../include/Interfaces/ISetMonstro.h"
#include "../../include/Models/PersonagemModel.h"
#include <memory>
#include <random>

using namespace std;
CombateController::CombateController(shared_ptr<MonstroController> monstro_controller, PersonagemModel* player)
{
    this->monstro_controller = monstro_controller;
    this->player = player;
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
    random_device rd;                         // fonte de aleatoriedade
    mt19937 gen(rd());                        // motor Mersenne Twister
    uniform_int_distribution<> distr(low, upp);  // intervalo [1, 12]

    return  distr(gen);
}

void CombateController::ataque()
{
    int dano = 2;
    int fa_monstro = getRandomInt(1,10) + this->monstro_controller->getHabilidade(this->monstro_atual);
    int fa_player =  getRandomInt(1,10) + this->player->getHabilidade();
    if(fa_monstro > fa_player) this->player->setEnergia(this->player->getEnergia() - dano);
    if(fa_player > fa_monstro) this->setEnergiaAtual(this->energia_atual - dano);
}
