#ifndef CHANGECENA_H
#define CHANGECENA_H

#include <ICommand.h>
#include "../../include/Interfaces/ICenaRouter.h"

#include <string>

using namespace std;
class ChangeCena : public ICommand
{
    public:
        ChangeCena(ICenaRouter* router, string dest_cena);
        virtual ~ChangeCena();
        void execute() override;

    private:
        ICenaRouter* router;
        string dest_cena;
};

#endif // CHANGECENA_H
