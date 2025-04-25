#include "SalvarCommand.h"
#include "../../include/Interfaces/ISerializavel.h"

SalvarCommand::SalvarCommand(ISerializavel* serializavel)
{
    this->serializavel = serializavel;
}

SalvarCommand::~SalvarCommand()
{
    //dtor
}

void SalvarCommand::execute()
{
    this->serializavel->serializar("p1.txt");
}
