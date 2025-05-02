#ifndef SETMONSTERCOMMAND_H
#define SETMONSTERCOMMAND_H

#include <ICommand.h>
#include <string>
#include <memory>

#include "../../include/Interfaces/ISetMonstro.h"

using namespace std;
class SetMonsterCommand : public ICommand
{
    public:
        SetMonsterCommand(shared_ptr<ISetMonstro> set_monstro, string nome_monstro);
        virtual ~SetMonsterCommand();
        void execute() override;
    protected:

    private:
        shared_ptr<ISetMonstro> set_monstro;
        string nome_monstro;
};

#endif // SETMONSTERCOMMAND_H
