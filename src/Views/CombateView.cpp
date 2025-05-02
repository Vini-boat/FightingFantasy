#include "CombateView.h"
#include "../Controllers/CombateController.h"

#include <memory>
#include <iostream>
#include <string>

using namespace std;
CombateView::CombateView(shared_ptr<CombateController> combate_controller)
{
    this->combate_controller = combate_controller;
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
    cout << "   " << this->combate_controller->getNomeMonstro() << endl;
    cout << "   Energia: " << this->combate_controller->getEnergiaAtual() << "/" << this->combate_controller->getEnergiaMaximaMonstro() << endl;
    cout << endl;
    cout << "   " << this->combate_controller->getPlayerName() << endl;
    cout << "   Energia: " << this->combate_controller->getEnergiaPlayer() << "/" << this->combate_controller->getEnergiaMaximaPlayer() << endl;
    printOptions();
}

void CombateView::handleInput()
{
    //resetOpcoes();
    string t = getValidOption();
    executeOption(t);
}
