#ifndef MULTICOMMAND_H
#define MULTICOMMAND_H

#include <ICommand.h>
#include <memory>

using namespace std;
class MultiCommand : public ICommand
{
    public:
        MultiCommand(shared_ptr<ICommand> first, shared_ptr<ICommand> second);
        virtual ~MultiCommand();
        void execute() override;
    private:
        shared_ptr<ICommand> first;
        shared_ptr<ICommand> second;
};

#endif // MULTICOMMAND_H
