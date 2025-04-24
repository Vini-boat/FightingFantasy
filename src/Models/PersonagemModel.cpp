#include "../../include/Models/PersonagemModel.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
PersonagemModel::PersonagemModel()
{

}

PersonagemModel::~PersonagemModel()
{
    //dtor
}

void PersonagemModel::setNome(string nome)
{
    this->nome = nome;
}
string PersonagemModel::getNome()
{
    return nome;
}

void PersonagemModel::setHabilidade(int habilidade)
{
    this->habilidade = habilidade;
}
int PersonagemModel::getHabilidade()
{
    return habilidade;
}

void PersonagemModel::setEnergia(int energia)
{
    this->energia = energia;
}
int PersonagemModel::getEnergia()
{
    return energia;
}

void PersonagemModel::setSorte(int sorte)
{
    this->sorte = sorte;
}
int PersonagemModel::getSorte()
{
    return sorte;
}

void PersonagemModel::serializar(string filename)
{
    ofstream arquivo;
    arquivo.open(filename);
    arquivo << this->nome << endl;
    arquivo << this->habilidade << endl;
    arquivo << this->energia << endl;
    arquivo << this->sorte << endl;
    arquivo.close();
}

void PersonagemModel::desserializar(string filename)
{
    ifstream arquivo;
    arquivo.open(filename);
    arquivo >> this->nome;
    arquivo >> this->habilidade;
    arquivo >> this->energia;
    arquivo >> this->sorte;
    arquivo.close();
}
