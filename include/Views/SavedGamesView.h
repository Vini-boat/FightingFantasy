#ifndef SAVEDGAMESVIEW_H
#define SAVEDGAMESVIEW_H

#include "../Views/BaseView.h"

#include "../Models/SavedGamesModel.h"

using namespace std;
class SavedGamesView : public BaseView
{
    public:
        explicit SavedGamesView(SavedGamesModel* model);
        virtual ~SavedGamesView();
        virtual void show() override;
        virtual void handleInput() override;
    protected:

    private:
        SavedGamesModel* model;
};

#endif // SAVEDGAMESVIEW_H
