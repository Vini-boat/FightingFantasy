#ifndef SALVARCOMMAND_H
#define SALVARCOMMAND_H

#include <ICommand.h>
#include "../Interfaces/ISalvavel.h"

class SalvarCommand : public ICommand
{
    public:
        SalvarCommand(ISalvavel* salvavel);
        virtual ~SalvarCommand();
        void execute() override;
    protected:

    private:
        ISalvavel* salvavel;
};

#endif // SALVARCOMMAND_H
