#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <map>
#include <memory>
#include <string>

#include "../Interfaces/ICommand.h"
#include "../../include/Models/ViewOption.h"

using namespace std;
class BaseView
{
    public:
        BaseView();
        virtual ~BaseView();
        virtual void show() = 0;
        virtual void handleInput() = 0;
        virtual void process();
        void limparTela();
        void addStaticOption(string shortcut, string description, shared_ptr<ICommand> command);
        void printOptions();
        void showCursor();
        string getValidOption();
        void executeOption(string shortcut);

    protected:
        map<string,unique_ptr<ViewOption>> static_options;
        map<string,unique_ptr<ViewOption>> variable_options;

        void addVariableOption(string shortcut,string description, shared_ptr<ICommand> command);
        void resetVariableOptions();

    private:
};

#endif // BASEVIEW_H
