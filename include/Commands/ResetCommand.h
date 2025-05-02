#ifndef RESETCOMMAND_H
#define RESETCOMMAND_H

#include <ICommand.h>
#include "../../include/Interfaces/IResetable.h"

#include <memory>

using namespace std;
class ResetCommand : public ICommand
{
    public:
        ResetCommand(shared_ptr<IResetable> to_reset);
        virtual ~ResetCommand();
        void execute() override;
    private:
        shared_ptr<IResetable> to_reset;
};

#endif // RESETCOMMAND_H
