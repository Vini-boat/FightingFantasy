#ifndef NEWGAMEVIEW_H
#define NEWGAMEVIEW_H

#include <string>
#include <BaseView.h>

#include "../Models/NewGameViewModel.h"
#include "../Controllers/NewGameController.h"

using namespace std;
class NewGameView : public BaseView
{
    public:
        NewGameView(NewGameController* controller, NewGameViewModel* model);
        virtual ~NewGameView();
        void show() override;
        void handleInput() override;
    protected:

    private:
        NewGameController* controller;
        NewGameViewModel* model;
};

#endif // NEWGAMEVIEW_H
