#ifndef ATACARCOMMAND_H
#define ATACARCOMMAND_H

#include <ICommand.h>
#include "../../include/Interfaces/IAtaque.h"

#include <memory>

using namespace std;
class AtacarCommand : public ICommand
{
    public:
        AtacarCommand(shared_ptr<IAtaque> obj);
        virtual ~AtacarCommand();
        void execute() override;
    protected:

    private:
        shared_ptr<IAtaque> obj;
};

#endif // ATACARCOMMAND_H
