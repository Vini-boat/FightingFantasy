#include "NewGameViewModel.h"

NewGameViewModel::NewGameViewModel()
{
    this->etapa_atual = 0;
}

NewGameViewModel::~NewGameViewModel()
{
    //dtor
}

void NewGameViewModel::setEtapa(int etapa)
{
    this->etapa_atual = etapa;
}
int NewGameViewModel::getEtapa()
{
    return etapa_atual;
}

void NewGameViewModel::setNome(string nome)
{
    this->nome = nome;
}
string NewGameViewModel::getNome()
{
    return nome;
}

void NewGameViewModel::setHabilidade(int habilidade)
{
    this->habilidade = habilidade;
}
int NewGameViewModel::getHabilidade()
{
    return habilidade;
}

void NewGameViewModel::setEnergia(int energia)
{
    this->energia = energia;
}
int NewGameViewModel::getEnergia()
{
    return energia;
}

void NewGameViewModel::setSorte(int sorte)
{
    this->sorte = sorte;
}
int NewGameViewModel::getSorte()
{
    return sorte;
}
