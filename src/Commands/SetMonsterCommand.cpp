#include "SetMonsterCommand.h"

#include <string>
#include <memory>

#include "../../include/Interfaces/ISetMonstro.h"

using namespace std;
SetMonsterCommand::SetMonsterCommand(shared_ptr<ISetMonstro> set_monstro, string nome_monstro)
{
    this->set_monstro = set_monstro;
    this->nome_monstro = nome_monstro;
}

SetMonsterCommand::~SetMonsterCommand()
{
    //dtor
}

void SetMonsterCommand::execute()
{
    this->set_monstro->setMonstro(nome_monstro);
}
