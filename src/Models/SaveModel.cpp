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


void SaveModel::serializar(string filename)
{
    this->personagem->serializar(this->personagem->getNome());
    ofstream arq;
    arq.open(filename);
    arq << "[PERSONAGEM]" << endl << this->personagem->getNome()<< endl;
    arq << "[CENAS_PASSADAS]";
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
            this->personagem = new PersonagemModel;
            this->personagem->desserializar("./data/personagens/" + line + ".txt");
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
