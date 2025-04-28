#include "ViewOption.h"
#include "../../include/Interfaces/ICommand.h"

#include <string>
#include <memory>

using namespace std;
ViewOption::ViewOption(string description, shared_ptr<ICommand> command)
{
    this->description = description;
    this->command = command;
}

ViewOption::~ViewOption()
{
    //dtor
}
string ViewOption::getDescription()
{
    return description;
}

void ViewOption::execute()
{
    this->command->execute();
}
