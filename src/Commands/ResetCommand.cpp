#include "ResetCommand.h"

#include "../../include/Interfaces/IResetable.h"

#include <memory>

using namespace std;
ResetCommand::ResetCommand(shared_ptr<IResetable> to_reset)
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
