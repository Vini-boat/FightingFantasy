#ifndef NEWGAMECONTROLLER_H
#define NEWGAMECONTROLLER_H

#include "../Controllers/BaseController.h"
#include "../Models/PersonagemModel.h"
#include "../Models/NewGameViewModel.h"
#include "../Interfaces/ISalvavel.h"
#include "../Models/SaveModel.h"


#include <string>
#include <memory>

using namespace std;
class NewGameController : public BaseController, public ISalvavel
{
    public:
        NewGameController(SaveModel* save, shared_ptr<NewGameViewModel> view_model, PersonagemModel* model);
        virtual ~NewGameController();

        void createNewPersonagem();
        void salvar() override;

        bool validarHabilidade(int habilidade);
        bool validarEnergia(int energia);
        bool validarSorte(int sorte);

        void setHabilidade(int habilidade);
        void setEnergia(int energia);
        void setSorte(int sorte);

    protected:

    private:
        SaveModel* save;
        shared_ptr<NewGameViewModel> view_model;
        PersonagemModel* model;
};

#endif // NEWGAMECONTROLLER_H
