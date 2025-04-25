#ifndef NEWGAMECONTROLLER_H
#define NEWGAMECONTROLLER_H

#include "../Controllers/BaseController.h"
#include "../Models/PersonagemModel.h"
#include "../Models/NewGameViewModel.h"
#include "../Interfaces/ISalvavel.h"


#include <string>

using namespace std;
class NewGameController : public BaseController, public ISalvavel
{
    public:
        NewGameController(NewGameViewModel* view_model, PersonagemModel* model);
        virtual ~NewGameController();

        void createNewPersonagem();
        void salvar() override;

        bool validarHabilidade(int habilidade);
        bool validarEnergia(int energia);
        bool validarSorte(int sorte);



    protected:

    private:
        NewGameViewModel* view_model;
        PersonagemModel* model;
};

#endif // NEWGAMECONTROLLER_H
