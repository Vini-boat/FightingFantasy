#ifndef COMBATEVIEW_H
#define COMBATEVIEW_H

#include <BaseView.h>
#include "../Controllers/MonstroController.h"

#include <memory>
#include <iostream>
#include <string>

using namespace std;
class CombateView : public BaseView
{
    public:
        CombateView(shared_ptr<MonstroController> monstro_controller);
        virtual ~CombateView();
        void show() override;
        void handleInput() override;

    private:
        shared_ptr<MonstroController> monstro_controller;
};

#endif // COMBATEVIEW_H
