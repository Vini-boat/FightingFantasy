#ifndef CENAVIEW_H
#define CENAVIEW_H

#include <BaseView.h>
#include "../../include/Controllers/CenaController.h"

class CenaView : public BaseView
{
    public:
        CenaView(CenaController* controller);
        virtual ~CenaView();
        void show() override;
        void handleInput() override;
        void process() override;
    protected:
        void resetOpcoes();
    private:
        CenaController* controller;
};

#endif // CENAVIEW_H
