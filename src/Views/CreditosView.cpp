#include "CreditosView.h"
#include <iostream>

using namespace std;
CreditosView::CreditosView()
{
    //ctor
}

CreditosView::~CreditosView()
{
    //dtor
}

void CreditosView::show()
{
    limparTela();
    cout << "======== CREDITOS ========" << endl;
    cout << endl;
    cout << "   Desenvolvedores: " << endl;
    cout << "       Vinicius de Avila Bezerra" << endl;
    cout << "       Caua Amaral" << endl;
    cout << endl;
    cout << "   v: Voltar" << endl;
    cout << "------------------------------" << endl;
}

void CreditosView::handleInput()
{
    string t = getValidOption();
    executeOption(t);
}
