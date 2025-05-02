#ifndef NEWGAMEVIEW_H
#define NEWGAMEVIEW_H

#include <string>
#include <memory>
#include <BaseView.h>

#include "../Models/NewGameViewModel.h"
#include "../Controllers/NewGameController.h"

using namespace std;
class NewGameView : public BaseView
{
    public:
        NewGameView(NewGameController* controller, shared_ptr<NewGameViewModel> model);
        virtual ~NewGameView();
        void show() override;
        void handleInput() override;
    protected:

    private:
        NewGameController* controller;
        shared_ptr<NewGameViewModel> model;
};

#endif // NEWGAMEVIEW_H
