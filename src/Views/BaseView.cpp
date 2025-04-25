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
    for(auto& o: this->variable_options)
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
    for(auto& o: this->variable_options)
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

string BaseView::getValidOption()
{
    while(true)
    {
        string option;
        cout << "> ";
        cin >> option;
        for(auto& o: this->options)
        {
            if(option == o.first)
            {
                return option;
            }
        }
        for(auto& o: this->variable_options)
        {
            if(option == o.first)
            {
                return option;
            }
        }
        cout << "Opcao invalida, tente novamente" << endl;
    }
}

void BaseView::addVariableOption(string shortcut, ICommand* command)
{
        this->variable_options[shortcut] = command;
}
void BaseView::resetVariableOptions()
{
    this->variable_options.clear();
}
