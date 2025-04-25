#ifndef SAVECONTROLLER_H
#define SAVECONTROLLER_H

#include <BaseController.h>
#include "../../include/Models/SaveModel.h"


class SaveController : public BaseController
{
    public:
        SaveController(SaveModel* model);
        virtual ~SaveController();

    protected:

    private:
        SaveModel* model;
};

#endif // SAVECONTROLLER_H
