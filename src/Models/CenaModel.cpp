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

vector<string> CenaModel::getMonstrosCombates()
{
    vector<string> resultado;
    for (const auto& combate : this->combates)
    {
        resultado.push_back(combate.first);
    }
    return resultado;
}

vector<string> CenaModel::getDescricaoCombates()
{
    vector<string> resultado;
    for (const auto& combate : this->combates)
    {
        resultado.push_back(combate.second);
    }
    return resultado;
}

int CenaModel::getTesouro()
{
    return this->tesouro;
}

int CenaModel::getProvisoes()
{
    return this->provisoes;
}

void CenaModel::serializar(string filename)
{

}

void CenaModel::desserializar(string filename)
{
    this->escolhas.clear();
    this->combates.clear();
    this->itens.clear();
    this->tesouro = 0;
    this->provisoes = 0;
    ifstream arq;
    arq.open(filename);
    string line;
    string atributo;
    while(getline(arq,line))
    {
        if(line == "[TEXTO]"){atributo = "[TEXTO]";continue;};
        if(line == "[ESCOLHAS]"){atributo = "[ESCOLHAS]";continue;};
        if(line == "[COMBATES]"){atributo = "[COMBATES]";continue;};
        if(line == "[ITENS]"){atributo = "[ITENS]";continue;};
        if(line == "[TESOURO]"){atributo = "[TESOURO]";continue;};
        if(line == "[PROVISOES]"){atributo = "[PROVISOES]";continue;};
        if(line == "[FINAL]") break;
        stringstream ss(line);
        if(atributo == "[TEXTO]") this->text += line += '\n';
        if(atributo == "[TESOURO]") ss >> this->tesouro;
        if(atributo == "[PROVISOES]") ss >> this->provisoes;
        if(atributo == "[ESCOLHAS]")
        {
            size_t pos_separator = line.find(':');
            string cena = line.substr(0,pos_separator);
            string desc = line.substr(pos_separator + 2) ;
            this->escolhas.push_back(pair<string,string>(cena,desc));
        }
        if(atributo == "[COMBATES]")
        {
            size_t pos_separator = line.find(':');
            string monstro = line.substr(0,pos_separator);
            string desc = line.substr(pos_separator + 2) ;
            this->combates.push_back(pair<string,string>(monstro,desc));
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
