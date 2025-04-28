#ifndef VIEWOPTION_H
#define VIEWOPTION_H

#include "../../include/Interfaces/ICommand.h"

#include <string>
#include <memory>

using namespace std;
class ViewOption
{
    public:
        ViewOption(string description, shared_ptr<ICommand> command);
        virtual ~ViewOption();
        void execute();
        string getDescription();
    private:
        string description;
        shared_ptr<ICommand> command;
};

#endif // VIEWOPTION_H
