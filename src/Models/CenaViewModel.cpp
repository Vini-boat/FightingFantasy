#include "CenaViewModel.h"
#include "CenaModel.h"
#include <string>
#include <fstream>
#include <memory>
#include <vector>

using namespace std;
CenaViewModel::CenaViewModel()
{
    ifstream arq;
    arq.open("./data/index/cenas.txt");
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

CenaViewModel::~CenaViewModel()
{
    //dtor
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

string CenaViewModel::getCenaAtual()
{
    return cena_atual;
}

