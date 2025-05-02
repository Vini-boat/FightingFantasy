#include "ItemController.h"

#include <string>
#include <fstream>
#include <iostream>
#include <memory>

using namespace std;
ItemController::ItemController()
{
    //ctor
}

ItemController::~ItemController()
{
    //dtor
}

void ItemController::carregarItens()
{
    ifstream arq;
    arq.open("./data/index/itens.txt");
    string line;
    while(getline(arq,line))
    {
        this->itens[line] = make_unique<ItemModel>();
        this->itens[line]->desserializar("./data/itens/" + line + ".txt");
    }
}

string ItemController::getItemType(string nome)
{
    return this->itens[nome]->getType();
}
