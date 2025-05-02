#ifndef CENAVIEW_H
#define CENAVIEW_H

#include <BaseView.h>
#include "../../include/Controllers/CenaController.h"
#include "../../include/Controllers/CombateController.h"
#include "../../include/Commands/ChangeView.h"

#include <memory>

using namespace std;
class CenaView : public BaseView
{
    public:
        CenaView(CenaController* controller, shared_ptr<ChangeView> change_to_combate_view, shared_ptr<CombateController> combate_controller);
        virtual ~CenaView();
        void show() override;
        void handleInput() override;
        void process() override;
    protected:
        void resetOpcoes();
    private:
        CenaController* controller;
        shared_ptr<ChangeView> change_to_combate_view;
        shared_ptr<CombateController> combate_controller;
};

#endif // CENAVIEW_H
