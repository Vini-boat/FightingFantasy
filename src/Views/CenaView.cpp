#include "CenaView.h"
#include "CenaController.h"

#include "../../include/Commands/ChangeCena.h"

#include <iostream>
#include <string>

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
    cout << "   Nome: " << this->controller->getCenaName() << endl;
    cout << endl;
    printOptions();
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
    for(string e: this->controller->getEscolhasCena())
    {
        addVariableOption(to_string(i), new ChangeCena(this->controller,e));
        i++;
    }
}
