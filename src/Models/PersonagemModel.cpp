#include "../../include/Models/PersonagemModel.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

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

void PersonagemModel::addItem(string item)
{
    this->itens.push_back(item);
}

vector<string> PersonagemModel::getItens()
{
    return this->itens;
}

void PersonagemModel::setProvisoes(int provisoes)
{
    this->provisoes = provisoes;
}

int PersonagemModel::getProvisoes()
{
    return this->provisoes;
}

void PersonagemModel::setEnergiaMaxima(int energia_maxima)
{
    this->energia_maxima = energia_maxima;
}

int PersonagemModel::getEnergiaMaxima()
{
    return this->energia_maxima;
}

void PersonagemModel::setTesouro(int tesouro)
{
    this->tesouro = tesouro;
}

int PersonagemModel::getTesouro()
{
    return this->tesouro;
}

void PersonagemModel::serializar(string filename)
{
    ofstream arq;
    arq.open(filename);
    arq << "[NOME]" << endl;
    arq << this->nome << endl;
    arq << "[HABILIDADE]" << endl;
    arq << this->habilidade << endl;
    arq << "[ENERGIA]" << endl;
    arq << this->energia << endl;
    arq << "[ENERGIA_MAXIMA]" << endl;
    arq << this->energia_maxima << endl;
    arq << "[SORTE]" << endl;
    arq << this->sorte << endl;
    arq << "[TESOURO]" << endl;
    arq << this->tesouro << endl;
    arq << "[PROVISOES]" << endl;
    arq << this->provisoes << endl;
    arq << "[ITENS]" << endl;
    for(string& i: this->itens)
    {
        arq << i << endl;
    }
    arq << "[FINAL]" << endl;

    ofstream index;
    index.open("./data/index/saves.txt");
    index << this->nome << endl;
    index.close();
}
void PersonagemModel::salvar()
{
    this->serializar("./data/personagens/" + this->nome + ".txt");
}

void PersonagemModel::desserializar(string filename)
{
    this->itens.clear();

    ifstream arq;
    arq.open(filename);
    string prop;
    string line;
    while(getline(arq,line))
    {
        if(line == "[NOME]") {prop = "[NOME]"; continue;};
        if(line == "[HABILIDADE]") {prop = "[HABILIDADE]"; continue;};
        if(line == "[ENERGIA]") {prop = "[ENERGIA]"; continue;};
        if(line == "[ENERGIA_MAXIMA]") {prop = "[ENERGIA_MAXIMA]"; continue;};
        if(line == "[SORTE]") {prop = "[SORTE]"; continue;};
        if(line == "[TESOURO]") {prop = "[TESOURO]"; continue;};
        if(line == "[PROVISOES]") {prop = "[PROVISOES]"; continue;};
        if(line == "[ITENS]") {prop = "[ITENS]"; continue;};
        if(line == "[FINAL]") break;
        stringstream ss(line);
        if(prop == "[NOME]") this->nome = line;
        if(prop == "[HABILIDADE]") ss >> this->habilidade;
        if(prop == "[ENERGIA]") ss >> this->energia;
        if(prop == "[ENERGIA_MAXIMA]") ss >> this->energia_maxima;
        if(prop == "[SORTE]") ss >> this->sorte;
        if(prop == "[TESOURO]") ss >> this->tesouro;
        if(prop == "[PROVISOES]") ss >> this->provisoes;
        if(prop == "[ITENS]") this->itens.push_back(line);
    }
}
