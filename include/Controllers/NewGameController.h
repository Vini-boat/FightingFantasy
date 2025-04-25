#ifndef NEWGAMECONTROLLER_H
#define NEWGAMECONTROLLER_H

#include "../Controllers/BaseController.h"
#include "../Models/PersonagemModel.h"
#include "../Models/NewGameViewModel.h"
#include "../Interfaces/ISalvavel.h"
#include "../Models/SaveModel.h"


#include <string>

using namespace std;
class NewGameController : public BaseController, public ISalvavel
{
    public:
        NewGameController(SaveModel* save, NewGameViewModel* view_model, PersonagemModel* model);
        virtual ~NewGameController();

        void createNewPersonagem();
        void salvar() override;

        bool validarHabilidade(int habilidade);
        bool validarEnergia(int energia);
        bool validarSorte(int sorte);



    protected:

    private:
        SaveModel* save;
        NewGameViewModel* view_model;
        PersonagemModel* model;
};

#endif // NEWGAMECONTROLLER_H
