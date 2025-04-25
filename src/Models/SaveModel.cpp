#include "SaveModel.h"
#include "../../include/Models/PersonagemModel.h"

#include "../../include/Interfaces/ISerializavel.h"

#include <string>
#include <vector>

#include <fstream>

using namespace std;
SaveModel::SaveModel()
{
    //ctor
}

SaveModel::~SaveModel()
{
    //dtor
}

string SaveModel::getNomePersonagem()
{
    return this->personagem;
}


string SaveModel::getCenaAtual()
{
    return cena_atual;
}

void SaveModel::addCenaPassada(string cena)
{
    this->cenas_passadas.push_back(cena);
}

void SaveModel::setCenaAtual(string cena)
{
    this->cena_atual = cena;
}

void SaveModel::reset()
{
    this->personagem = "";
    this->cenas_passadas.clear();
    this->cenas_passadas.push_back("1");
    this->cena_atual = "1";
}

void SaveModel::setPersonagem(string personagem)
{
    this->personagem = personagem;
}

void SaveModel::serializar(string filename)
{
    ofstream arq;
    arq.open(filename);
    arq << "[PERSONAGEM]" << endl << this->personagem<< endl;
    arq << "[CENAS_PASSADAS]" << endl;
    for(string cena : this->cenas_passadas)
    {
        arq << cena << endl;
    }
    arq << "[CENA_ATUAL]" << endl << this->cena_atual << endl;
    arq.close();
}
void SaveModel::desserializar(string filename)
{
    ifstream arq;
    arq.open(filename);
    string prop;
    string line;
    while(getline(arq,line))
    {
        if(line == "[PERSONAGEM]")
        {
            prop = "personagem";
            continue;
        }
        if(line == "[CENAS_PASSADAS]")
        {
            prop = "cenas_passadas";
            continue;
        }
        if(line == "[CENA_ATUAL]")
        {
            prop = "cena_atual";
            continue;
        }

        if(prop == "personagem")
        {
            this->personagem = line;
        }
        if(prop == "cenas_passadas")
        {
            this->cenas_passadas.push_back(line);
        }
        if(prop == "cena_atual")
        {
            this->cena_atual = line;
        }
    }
    arq.close();
}
