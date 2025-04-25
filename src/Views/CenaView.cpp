#include "CenaView.h"
#include "CenaController.h"

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
    limparTela();
    cout << "======== CENA =========" << endl;
    cout << endl;
    cout << "   Nome: " << this->controller->getCenaName() << endl;
    cout << endl;

}

void CenaView::handleInput()
{

}

void CenaView::resetOpcoes()
{

}
