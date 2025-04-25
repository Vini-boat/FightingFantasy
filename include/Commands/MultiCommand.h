#ifndef MULTICOMMAND_H
#define MULTICOMMAND_H

#include <ICommand.h>


class MultiCommand : public ICommand
{
    public:
        MultiCommand(ICommand* first, ICommand* seccond);
        virtual ~MultiCommand();
        void execute() override;
    private:
        ICommand* first;
        ICommand* seccond;
};

#endif // MULTICOMMAND_H
