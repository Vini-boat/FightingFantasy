#ifndef CENACONTROLLER_H
#define CENACONTROLLER_H

#include <BaseController.h>
#include "../../include/Models/CenaViewModel.h"
#include "../../include/Interfaces/ICenaRouter.h"


class CenaController : public BaseController, public ICenaRouter
{
    public:
        CenaController(CenaViewModel* model);
        virtual ~CenaController();

        virtual void changeCena(string cena) override;
        string getCenaText();
        string getCenaName();
        //vector<string>


    protected:

    private:
        CenaViewModel* model;
};

#endif // CENACONTROLLER_H
