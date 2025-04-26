#include "MultiCommand.h"
#include "../../include/Interfaces/ICommand.h"

#include <iostream>
#include <memory>

using namespace std;
MultiCommand::MultiCommand(shared_ptr<ICommand> first, shared_ptr<ICommand> second)
{
    this->first = first;
    this->second = second;
}

MultiCommand::~MultiCommand()
{
    //dtor
}

void MultiCommand::execute()
{
    this->first->execute();
    this->second->execute();
}
