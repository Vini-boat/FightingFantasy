#include "ResetCommand.h"

#include "../../include/Interfaces/IResetable.h"

ResetCommand::ResetCommand(IResetable* to_reset)
{
    this->to_reset = to_reset;
}

ResetCommand::~ResetCommand()
{
    //dtor
}

void ResetCommand::execute()
{
    this->to_reset->reset();
}
