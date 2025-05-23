#ifndef COMBATECONTROLLER_H
#define COMBATECONTROLLER_H

#include <BaseController.h>
#include "../../include/Controllers/MonstroController.h"
#include "../../include/Interfaces/ISetMonstro.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Interfaces/IAtaque.h"
#include "../../include/Commands/ChangeCena.h"
#include "../../include/Commands/ChangeView.h"
#include "../../include/Controllers/CenaController.h"

#include <memory>
#include <string>
#include <random>

using namespace std;
class CombateController : public BaseController, public ISetMonstro, public IAtaque
{
    public:
        CombateController(shared_ptr<MonstroController> monstro_controller, PersonagemModel* player,shared_ptr<ChangeView> change_to_cenas_view, CenaController* cena_controller);
        virtual ~CombateController();
        void setMonstro(string nome_monstro) override;
        void setEnergiaAtual(int energia);
        int getEnergiaAtual();
        string getNomeMonstro();
        int getEnergiaMaximaMonstro();
        string getPlayerName();

        int getEnergiaPlayer();
        int getEnergiaMaximaPlayer();

        int getRandomInt(int low, int upp);
        void ataque() override;

    private:
        shared_ptr<MonstroController> monstro_controller;
        PersonagemModel* player;
        int energia_atual;
        string monstro_atual;
        shared_ptr<ChangeView> change_to_cenas_view;
        CenaController* cena_controller;

        unique_ptr<mt19937> gen;

};

#endif // COMBATECONTROLLER_H
