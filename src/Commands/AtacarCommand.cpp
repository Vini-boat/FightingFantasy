#include "AtacarCommand.h"
#include "../../include/Interfaces/IAtaque.h"

#include <memory>

using namespace std;
AtacarCommand::AtacarCommand(shared_ptr<IAtaque> obj)
{
    this->obj = obj;
}

AtacarCommand::~AtacarCommand()
{
    //dtor
}

void AtacarCommand::execute()
{
    this->obj->ataque();
}
