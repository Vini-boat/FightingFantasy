#include "SalvarEMudarView.h"
#include <ICommand.h>
#include "../Interfaces/ISalvavel.h"
#include <string>
#include "../Interfaces/IViewRouter.h"

SalvarEMudarView::SalvarEMudarView(ISalvavel* salvavel, IViewRouter* router, string dest_view)
{
    this->salvavel = salvavel;
    this->router = router;
    this->dest_view = dest_view;
}

SalvarEMudarView::~SalvarEMudarView()
{
    //dtor
}

void SalvarEMudarView::execute()
{
    this->salvavel->salvar();
    this->router->changeCurrentView(this->dest_view);
}
