#ifndef SAIR_H
#define SAIR_H

#include <ICommand.h>
#include <IRunner.h>

using namespace std;
class Sair : public ICommand
{
    public:
        Sair(IRunner* runner);
        virtual ~Sair();
        void execute() override;
    protected:

    private:
    IRunner* runner;

};

#endif // SAIR_H
