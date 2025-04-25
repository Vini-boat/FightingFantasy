#ifndef SALVARCOMMAND_H
#define SALVARCOMMAND_H

#include <ICommand.h>
#include "../Interfaces/Iserializavel.h"

class SalvarCommand : public ICommand
{
    public:
        SalvarCommand(ISerializavel* serializavel);
        virtual ~SalvarCommand();
        void execute() override;
    protected:

    private:
        ISerializavel* serializavel;
};

#endif // SALVARCOMMAND_H
