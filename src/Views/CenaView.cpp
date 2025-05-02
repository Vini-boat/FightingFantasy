#include "CenaView.h"
#include "CenaController.h"

#include "../../include/Commands/ChangeCena.h"

#include <iostream>
#include <string>
#include <memory>

using namespace std;
CenaView::CenaView(CenaController* controller)
{
    this->controller = controller;
}

CenaView::~CenaView()
{
    //dtor
}

void CenaView::show()
{
    resetOpcoes();
    limparTela();
    cout << "======== CENA =========" << endl;
    cout << endl;
    cout << this->controller->getCenaText() << endl;
    cout << endl;
    printOptions();
    cout << "--------------------------------" << endl;
}

void CenaView::process()
{

}

void CenaView::handleInput()
{
    resetOpcoes();
    string t = getValidOption();
    executeOption(t);
}

void CenaView::resetOpcoes()
{
    resetVariableOptions();
    int i = 0;
    vector<string> descricoes = this->controller->getDescricaoEscolhasCena();
    for(string e: this->controller->getEscolhasCena())
    {
        addVariableOption(to_string(i), descricoes.at(i), make_shared<ChangeCena>(this->controller,e));
        i++;
    }
}
