#include "../../include/Views/SavedGamesView.h"
#include "../../include/Models/SavedGamesModel.h"
#include <iostream>
#include <string>


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
    limparTela();
    cout << "======= SAVED GAMES ======" << endl;
    cout << endl;
    int i =0;
    for(string name: model->getSavedGamesNames())
    {
        cout << "   " << i << "- " << name << endl;
        i++;
    }
    cout << endl;
    cout << "   v: Voltar" << endl;
    cout << "------------------------------" << endl;
}

void SavedGamesView::handleInput()
{
    string t = getValidOption();
    executeOption(t);
}
