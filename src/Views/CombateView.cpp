#include "CombateView.h"
#include "../Controllers/MonstroController.h"

#include <memory>
#include <iostream>
#include <string>

using namespace std;
CombateView::CombateView(shared_ptr<MonstroController> monstro_controller)
{
    this->monstro_controller = monstro_controller;
}

CombateView::~CombateView()
{
    //dtor
}

void CombateView::show()
{
    limparTela();
    cout << "========== COMBATE ==========" << endl;
    cout << endl;
    printOptions();
}

void CombateView::handleInput()
{
    resetOpcoes();
    string t = getValidOption();
    executeOption(t);
}
