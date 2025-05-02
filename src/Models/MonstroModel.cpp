#include "MonstroModel.h"

#include <fstream>
#include <string>
#include <sstream>

using namespace std;
MonstroModel::MonstroModel()
{
    //ctor
}

MonstroModel::~MonstroModel()
{
    //dtor
}

void MonstroModel::serializar(string filename)
{

}

void MonstroModel::desserializar(string filename)
{
    ifstream arq;
    arq.open(filename);
    string prop;
    string line;
    while(getline(arq,line))
    {
        if(line == "[NOME]") {prop = "[NOME]"; continue;};
        if(line == "[HABILIDADE]") {prop = "[HABILIDADE]"; continue;};
        if(line == "[ENERGIA]") {prop = "[ENERGIA]"; continue;};
        if(line == "[TESOURO]") {prop = "[TESOURO]"; continue;};
        if(line == "[PROVISOES]") {prop = "[PROVISOES]"; continue;};
        if(line == "[ITENS]") {prop = "[ITENS]"; continue;};
        if(line == "[CENA_VITORIA]") {prop = "[CENA_VITORIA]"; continue;};
        if(line == "[CENA_DERROTA]") {prop = "[CENA_DERROTA]"; continue;};
        if(line == "[FINAL]") break;
        stringstream ss(line);
        if(prop == "[NOME]") this->nome = line;
        if(prop == "[HABILIDADE]") ss >> this->habilidade;
        if(prop == "[ENERGIA]") ss >> this->energia;
        if(prop == "[TESOURO]") ss >> this->tesouro;
        if(prop == "[PROVISOES]") ss >> this->provisoes;
        if(prop == "[ITENS]") this->itens.push_back(line);
        if(prop == "[CENA_VITORIA]") ss >> this->id_cena_vitoria;
        if(prop == "[CENA_DERROTA]") ss >> this->id_cena_derrota;
    }
}

int MonstroModel::getHabilidade()
{
    return this->habilidade;
}
int MonstroModel::getEnergia()
{
    return this->energia;
}
int MonstroModel::getTesouro()
{
    return this->tesouro;
}
int MonstroModel::getProvisoes()
{
    return this->provisoes;
}
vector<string> MonstroModel::getItens()
{
    return this->itens;
}
int MonstroModel::getCenaVitoria()
{
    return this->id_cena_vitoria;
}
int MonstroModel::getCenaDerrota()

{
    return this->id_cena_derrota;
}
