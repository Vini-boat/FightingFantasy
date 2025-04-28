#include "../../include/Views/MenuView.h"
#include <iostream>
#include <string>

using namespace std;
MenuView::MenuView()
{
    //ctor
}

MenuView::~MenuView()
{
    //dtor
}

void MenuView::show()
{
    limparTela();
    cout << "========== MENU ==========" << endl;
    //cout << endl;
    //cout << "   n: Novo Jogo" << endl;
    //cout << "   s: Carregar Jogo" << endl;
    //cout << "   c: Creditos" << endl;
    //cout << "   q: Sair" << endl;
    printOptions();
    cout << endl;
    cout << "---------------------------" << endl;
}

void MenuView::handleInput()
{
    string t = getValidOption();
    executeOption(t);
}
