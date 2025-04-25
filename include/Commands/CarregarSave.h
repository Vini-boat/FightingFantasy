#ifndef CARREGARSAVE_H
#define CARREGARSAVE_H

#include <ICommand.h>
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Interfaces/ICenaRouter.h"

#include <string>

using namespace std;
class CarregarSave : public ICommand
{
    public:
        CarregarSave(ICenaRouter* router, SaveModel * save_model, PersonagemModel* personagem_model, string save_name);
        virtual ~CarregarSave();
        void execute() override;
    protected:

    private:
        SaveModel* save_model;
        PersonagemModel* personagem_model;
        string save_name;
        ICenaRouter* router;

};

#endif // CARREGARSAVE_H
