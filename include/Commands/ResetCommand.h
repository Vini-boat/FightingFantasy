#ifndef RESETCOMMAND_H
#define RESETCOMMAND_H

#include <ICommand.h>
#include "../../include/Interfaces/IResetable.h"

class ResetCommand : public ICommand
{
    public:
        ResetCommand(IResetable* to_reset);
        virtual ~ResetCommand();
        void execute() override;
    private:
        IResetable* to_reset;
};

#endif // RESETCOMMAND_H
