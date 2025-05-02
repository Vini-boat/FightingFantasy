#include "MonstroController.h"
#include "../../include/Models/MonstroModel.h"

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
MonstroController::MonstroController()
{
    //ctor
}

MonstroController::~MonstroController()
{
    //dtor
}

void MonstroController::carregarMonstros()
{
    ifstream arq;
    arq.open("./data/index/monstros.txt");
    string line;
    while(getline(arq,line))
    {
        this->monstros[line] = make_unique<MonstroModel>();
        this->monstros[line]->desserializar("./data/monstros/" + line + ".txt");
    }
}

int MonstroController::getHabilidade(string nome_monstro)
{
    return this->monstros[nome_monstro]->getHabilidade();
}
int MonstroController::getEnergia(string nome_monstro)
{
    return this->monstros[nome_monstro]->getEnergia();
}
int MonstroController::getTesouro(string nome_monstro)
{
    return this->monstros[nome_monstro]->getTesouro();
}
int MonstroController::getProvisoes(string nome_monstro)
{
    return this->monstros[nome_monstro]->getProvisoes();
}
vector<string> MonstroController::getItens(string nome_monstro)
{
    return this->monstros[nome_monstro]->getItens();
}
int MonstroController::getCenaVitoria(string nome_monstro)
{
    return this->monstros[nome_monstro]->getCenaVitoria();
}
int MonstroController::getCenaDerrota(string nome_monstro)
{
    return this->monstros[nome_monstro]->getCenaDerrota();
}
