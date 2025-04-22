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
    cout << endl;
    cout << "   n: Novo Jogo" << endl;
    cout << "   c: Carregar Jogo" << endl;
    cout << "   s: Sair" << endl;
    showCursor();
}

void MenuView::handleInput()
{
    string t;
    cin >> t;
    executeOption(t);
}
