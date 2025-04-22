#include "../../include/Views/BaseView.h"

#include <map>
#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>

#include "ICommand.h"

using namespace std;
BaseView::BaseView()
{
    //ctor
}

BaseView::~BaseView()
{
    //dtor
}

void BaseView::limparTela()
{
    system("cls");
}

void BaseView::addOption(string shortcut,ICommand* command)
{
    this->options[shortcut] = command;
}

void BaseView::printOptions()
{
    for(auto& o: this->options)
    {
        cout << o.first << endl;
    }
}

void BaseView::executeOption(string shortcut)
{
    for(auto& o: this->options)
    {
        if(shortcut == o.first)
        {
            o.second->execute();
        }
    }
}

void BaseView::showCursor()
{
    cout << endl;
    cout << "------------------------------" << endl;
    cout << "> ";
}
