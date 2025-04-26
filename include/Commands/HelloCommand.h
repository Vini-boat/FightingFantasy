#ifndef HELLOCOMMAND_H
#define HELLOCOMMAND_H

#include <ICommand.h>
#include <string>

using namespace std;
class HelloCommand : public ICommand
{
    public:
        HelloCommand(string hello);
        virtual ~HelloCommand();
        void execute();
    protected:

    private:
        string hello;
};

#endif // HELLOCOMMAND_H
