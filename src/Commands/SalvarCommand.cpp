#include "SalvarCommand.h"
#include "../../include/Interfaces/ISalvavel.h"

#include <iostream>

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
    std::cout << "SALVAR" << std::endl;

    //std::cout << this->salvavel << std::endl;
    if (this->salvavel) this->salvavel->salvar();
}
