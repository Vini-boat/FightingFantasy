#include "CenaModel.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
CenaModel::CenaModel()
{
    //ctor
}

CenaModel::~CenaModel()
{
    //dtor
}

string CenaModel::getText()
{
    return text;
}

vector<string> CenaModel::getCenasEscolhas()
{
    vector<string> resultado;
    for (const auto& escolha : this->escolhas)
    {
        resultado.push_back(escolha.first);
    }

    return resultado;
}

vector<string> CenaModel::getDescricaoEscolhas()
{
    vector<string> resultado;
    for (const auto& escolha : this->escolhas)
    {
        resultado.push_back(escolha.second);
    }

    return resultado;
}

void CenaModel::serializar(string filename)
{

}

void CenaModel::desserializar(string filename)
{
    this->escolhas.clear();
    this->itens.clear();
    this->tesouro = 0;
    ifstream arq;
    arq.open(filename);
    string line;
    string atributo;
    while(getline(arq,line))
    {
        if(line == "[TEXTO]"){atributo = "[TEXTO]";continue;};
        if(line == "[ESCOLHAS]"){atributo = "[ESCOLHAS]";continue;};
        if(line == "[ITENS]"){atributo = "[ITENS]";continue;};
        if(line == "[TESOURO]"){atributo = "[TESOURO]";continue;};
        if(line == "[FINAL]") break;
        sstream ss(line);
        if(atributo == "[TEXTO]") this->text += line += '\n';
        if(atributo == "[TESOURO]"){int i; ss >> i; this->tesouro = i;};
        if(atributo == "[ESCOLHAS]")
        {
            size_t pos_separator = line.find(':');
            string cena = line.substr(0,pos_separator);
            string desc = line.substr(pos_separator + 2) ;
            this->escolhas.push_back(pair<string,string>(cena,desc));
        }
        if(atributo == "[ITENS]")
        {
            this->itens.push_back(line);
        }
    }
    arq.close();
}

vector<string> CenaModel::getItens()
{
    return this->itens;
}
