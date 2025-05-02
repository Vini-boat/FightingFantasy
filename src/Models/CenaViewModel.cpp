#include "CenaViewModel.h"
#include "CenaModel.h"
#include "../../include/Interfaces/ISerializavel.h"
#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;
CenaViewModel::CenaViewModel()
{

}

CenaViewModel::~CenaViewModel()
{
    this->cena_atual = "1";
}

void CenaViewModel::serializar(string filename)
{

}

void CenaViewModel::desserializar(string filename)
{
    ifstream arq;
    arq.open(filename);
    vector<string> nomes;
    string line;
    while(getline(arq,line))
    {
        nomes.push_back(line);
    }
    arq.close();

    for(string nome : nomes)
    {
        this->cenas[nome] = make_unique<CenaModel>();
        this->cenas[nome]->desserializar("./data/cenas/" + nome + ".txt");
    }
}

void CenaViewModel::carregarCenas()
{
    this->desserializar("./data/index/cenas.txt");
}

vector<string> CenaViewModel::getNomesCenas()
{
    vector<string> r;

    for(auto& o: this->cenas)
    {
        r.push_back(o.first);
    }
    return r;
}

vector<string> CenaViewModel::getTextoCenas()
{
    vector<string> r;

    for(auto& o: this->cenas)
    {
        r.push_back(o.second->getText());
    }
    return r;
}

void CenaViewModel::setCenaAtual(string cena)
{
    this->cena_atual = cena;
}

string CenaViewModel::getTextoCenaAtual()
{
    return this->cenas[this->cena_atual]->getText();
}

string CenaViewModel::getNomeCenaAtual()
{
    return cena_atual;
}

vector<string> CenaViewModel::getCenasEscolhasCenaAtual()
{
    return this->cenas[this->cena_atual]->getCenasEscolhas();
}
vector<string> CenaViewModel::getDescricaoEscolhasCenaAtual()
{
    return this->cenas[this->cena_atual]->getDescricaoEscolhas();
}

vector<string> CenaViewModel::getItensCenaAtual()
{
    return this->cenas[this->cena_atual]->getItens();
}

int CenaViewModel::getTesouroCenaAtual()
{
    return this->cenas[this->cena_atual]->getTesouro();
}
