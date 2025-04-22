#include "MenuView.h"
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
    cout << "MENU" << endl;
}

void MenuView::handleInput()
{
    string t;
    cin >> t;
}
