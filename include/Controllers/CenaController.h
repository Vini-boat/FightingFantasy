#ifndef CENACONTROLLER_H
#define CENACONTROLLER_H

#include <BaseController.h>
#include "../../include/Models/CenaViewModel.h"
#include "../../include/Interfaces/ICenaRouter.h"
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"

#include <vector>
#include <string>

using namespace std;
class CenaController : public BaseController, public ICenaRouter
{
    public:
        CenaController(CenaViewModel* model, SaveModel* save, PersonagemModel* player);
        virtual ~CenaController();

        virtual void changeCena(string cena) override;
        void salvar();
        string getCenaText();
        string getCenaName();
        vector<string> getEscolhasCena();
        vector<string> getDescricaoEscolhasCena();
        void carregarSave() override;
        void addItensToPlayer();

    protected:

    private:
        CenaViewModel* model;
        SaveModel* save;
        PersonagemModel* player;
};

#endif // CENACONTROLLER_H
