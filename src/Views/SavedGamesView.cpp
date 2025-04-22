#include "SavedGamesView.h"
#include "SavedGamesModel.h"
#include <iostream>



using namespace std;
SavedGamesView::SavedGamesView(SavedGamesModel* model)
{
    this->model = model;
}

SavedGamesView::~SavedGamesView()
{
    //dtor
}

void SavedGamesView::show()
{
    cout << "===== SAVED GAMES =====" << endl;
    int i =0;
    for(string name: model->getSavedGamesNames())
    {
        cout << i << "- " << name << endl;
    }
}

void SavedGamesView::handleInput()
{

}
