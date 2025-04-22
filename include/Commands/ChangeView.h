#ifndef CHANGEVIEW_H
#define CHANGEVIEW_H

#include <string>

#include <ICommand.h>
#include "IViewRouter.h"

using namespace std;
class ChangeView : public ICommand
{
    public:
        ChangeView(IViewRouter* router, string dest_view);
        virtual ~ChangeView();
        void execute() override;
    protected:

    private:
        IViewRouter* router;
        string dest_view;
};

#endif // CHANGEVIEW_H
