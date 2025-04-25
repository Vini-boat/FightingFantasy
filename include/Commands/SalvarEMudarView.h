#ifndef SALVAREMUDARVIEW_H
#define SALVAREMUDARVIEW_H

#include <ICommand.h>
#include "../Interfaces/ISalvavel.h"
#include <string>
#include "IViewRouter.h"

using namespace std;
class SalvarEMudarView : public ICommand
{
    public:
        SalvarEMudarView(ISalvavel* salvavel, IViewRouter* router, string dest_view);
        virtual ~SalvarEMudarView();
        void execute() override;

    protected:

    private:
        ISalvavel* salvavel;
        IViewRouter* router;
        string dest_view;
};

#endif // SALVAREMUDARVIEW_H
