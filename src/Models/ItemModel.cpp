#include "ItemModel.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
ItemModel::ItemModel()
{
    //ctor
}

ItemModel::~ItemModel()
{
    //dtor
}


void ItemModel::serializar(string filename)
{

}

void ItemModel::desserializar(string filename)
{
    ifstream arq;
    arq.open(filename);
    string prop;
    string line;
    while(getline(arq,line))
    {
        if(line == "[NOME]") {prop = "[NOME]"; continue;};
        if(line == "[DESCRICAO]") {prop = "[DESCRICAO]"; continue;};
        if(line == "[TIPO]") {prop = "[TIPO]"; continue;};
        if(line == "[COMBATE]") {prop = "[COMBATE]"; continue;};
        if(line == "[MODIFICADOR]") {prop = "[MODIFICADOR]"; continue;};
        if(line == "[FINAL]") break;
        stringstream ss(line);
        if(prop == "[NOME]") this->nome = line;
        if(prop == "[DESCRICAO]") this->descricao = line;
        if(prop == "[TIPO]") this->tipo = line;
        if(prop == "[COMBATE]") ss >> this->bonus_combate;
        if(prop == "[MODIFICADOR]") ss >> this->modificador;
    }
}

string ItemModel::getType()
{
    return this->tipo;
}

string ItemModel::getDescricao()
{
    return this->descricao;
}
