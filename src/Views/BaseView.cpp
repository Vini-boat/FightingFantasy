#include "../../include/Views/BaseView.h"
#include "../../include/Models/ViewOption.h"

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

void BaseView::addStaticOption(string shortcut,string description, shared_ptr<ICommand> command)
{
    this->static_options[shortcut] = make_unique<ViewOption>(description,command);
}

void BaseView::printOptions()
{
    for(auto& o: this->variable_options)
    {
        cout << "   " << o.first << ": " << o.second->getDescription() << endl;
    }
    cout << endl;
    for(auto& o: this->static_options)
    {
        cout << "   " << o.first << ": " << o.second->getDescription() << endl;
    }
}

void BaseView::executeOption(string shortcut)
{
    for(auto& o: this->static_options)
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
        for(auto& o: this->static_options)
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

void BaseView::addVariableOption(string shortcut,string description, shared_ptr<ICommand> command)
{
        this->variable_options[shortcut] = make_unique<ViewOption>(description, command);
}
void BaseView::resetVariableOptions()
{
    this->variable_options.clear();
}
