#ifndef CURARCOMMAND_H
#define CURARCOMMAND_H

#include <ICommand.h>
#include "../../include/Interfaces/ICuravel.h"

class CurarCommand : public ICommand
{
    public:
        CurarCommand(ICuravel* curavel);
        virtual ~CurarCommand();
        void execute() override;
    private:
        ICuravel* curavel;
};

#endif // CURARCOMMAND_H
