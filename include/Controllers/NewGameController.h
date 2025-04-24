#ifndef NEWGAMECONTROLLER_H
#define NEWGAMECONTROLLER_H

#include "../Controllers/BaseController.h"
#include "../Models/PersonagemModel.h"


#include <string>

using namespace std;
class NewGameController : public BaseController
{
    public:
        NewGameController(PersonagemModel* model);
        virtual ~NewGameController();

        void createNewPersonagem(string nome, int habilidade, int energia, int sorte);
        void salvarPersonagem();

        bool validarHabilidade(int habilidade);
        bool validarEnergia(int energia);
        bool validarSorte(int sorte);



    protected:

    private:
        PersonagemModel* model;
};

#endif // NEWGAMECONTROLLER_H
