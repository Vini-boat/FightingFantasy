#include "CarregarSaveEMudarView.h"
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Interfaces/IViewRouter.h"
#include "../../include/Interfaces/ICenaRouter.h"

#include "../../include/Commands/CarregarSave.h"
#include "../../include/Commands/ChangeView.h"

#include <string>

using namespace std;
CarregarSaveEMudarView::CarregarSaveEMudarView(ICenaRouter* c_router, SaveModel* save_model, PersonagemModel* personagem_model, string save_name, IViewRouter* router, string dest_view)
{
        this->c_router = c_router;
        this->save_model = save_model;
        this->personagem_model = personagem_model;
        this->save_name = save_name;
        this->router = router;
        this->dest_view = dest_view;
}

CarregarSaveEMudarView::~CarregarSaveEMudarView()
{
    //dtor
}

void CarregarSaveEMudarView::execute()
{
    CarregarSave first(c_router,save_model,personagem_model,save_name);
    ChangeView second(router,dest_view);
    first.execute();
    second.execute();
}
