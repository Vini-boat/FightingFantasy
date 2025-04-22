#include "ChangeView.h"
#include "IViewRouter.h"
#include <string>

using namespace std;
ChangeView::ChangeView(IViewRouter* router, string dest_view)
{
    this->router = router;
    this->dest_view = dest_view;
}

ChangeView::~ChangeView()
{
    //dtor
}

void ChangeView::execute()
{
    this->router->changeCurrentView(dest_view);
}
