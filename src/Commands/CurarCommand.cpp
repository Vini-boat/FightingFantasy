#include "CurarCommand.h"
#include "../../include/Interfaces/ICuravel.h"

#include <memory>

using namespace std;
CurarCommand::CurarCommand(ICuravel* curavel)
{
    this->curavel = curavel;
}

CurarCommand::~CurarCommand()
{
    //dtor
}

void CurarCommand::execute()
{
    this->curavel->curar();
}
