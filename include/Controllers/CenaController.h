#ifndef CENACONTROLLER_H
#define CENACONTROLLER_H

#include <BaseController.h>
#include "../../include/Models/CenaViewModel.h"
#include "../../include/Interfaces/ICenaRouter.h"
#include "../../include/Models/SaveModel.h"

#include <vector>
#include <string>

using namespace std;
class CenaController : public BaseController, public ICenaRouter
{
    public:
        CenaController(CenaViewModel* model, SaveModel* save);
        virtual ~CenaController();

        virtual void changeCena(string cena) override;
        void salvar();
        string getCenaText();
        string getCenaName();
        vector<string> getEscolhasCena();
        vector<string> getDescricaoEscolhasCena();
        virtual void carregarSave() override;

    protected:

    private:
        CenaViewModel* model;
        SaveModel* save;
};

#endif // CENACONTROLLER_H
