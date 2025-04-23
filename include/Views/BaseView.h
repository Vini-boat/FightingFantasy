#ifndef BASEVIEW_H
#define BASEVIEW_H

#include <map>
#include <memory>
#include <string>

#include "ICommand.h"

using namespace std;
class BaseView
{
    public:
        BaseView();
        virtual ~BaseView();
        virtual void show() = 0;
        virtual void handleInput() = 0;
        void limparTela();
        void addOption(string shortcut, ICommand* command);
        void printOptions();
        void showCursor();
        string getValidOption();
        void executeOption(string shortcut);
    protected:
        map<string,ICommand*> options;
    private:
};

#endif // BASEVIEW_H
