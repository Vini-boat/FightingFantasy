#include "MultiCommand.h"
#include "../../include/Interfaces/ICommand.h"

#include <iostream>

MultiCommand::MultiCommand(ICommand* fisrt, ICommand* seccond)
{
    this->first = first;
    this->seccond = seccond;
}

MultiCommand::~MultiCommand()
{
    //dtor
}

void MultiCommand::execute()
{
    std::cout << "MULTI" << std::endl;
    std::cout << this->first << std::endl;
    if (this->first) this->first->execute();
    std::cout << this->seccond << std::endl;
    if (this->seccond) this->seccond->execute();
}
