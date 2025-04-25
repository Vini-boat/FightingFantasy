#include "SalvarCommand.h"
#include "../../include/Interfaces/ISalvavel.h"

SalvarCommand::SalvarCommand(ISalvavel* salvavel)
{
    this->salvavel = salvavel;
}

SalvarCommand::~SalvarCommand()
{
    //dtor
}

void SalvarCommand::execute()
{
    this->salvavel->salvar();
}
