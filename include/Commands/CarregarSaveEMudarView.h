#ifndef CARREGARSAVEEMUDARVIEW_H
#define CARREGARSAVEEMUDARVIEW_H

#include <ICommand.h>
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Interfaces/IViewRouter.h"
#include "../../include/Interfaces/ICenaRouter.h"
#include <string>

using namespace std;
class CarregarSaveEMudarView : public ICommand
{
    public:
        CarregarSaveEMudarView(ICenaRouter* c_router, SaveModel * save_model, PersonagemModel* personagem_model, string save_name, IViewRouter* router, string dest_view);
        virtual ~CarregarSaveEMudarView();
        void execute() override;
    protected:

    private:
        SaveModel * save_model;
        PersonagemModel* personagem_model;
        string save_name;
        IViewRouter* router;
        string dest_view;
        ICenaRouter* c_router;
};

#endif // CARREGARSAVEEMUDARVIEW_H
