#include "../../include/Models/SavedGamesModel.h"
#include <string>
#include <vector>

using namespace std;
SavedGamesModel::SavedGamesModel()
{
    names.push_back("teste1");
    names.push_back("teste2");
    names.push_back("teste3");
}

SavedGamesModel::~SavedGamesModel()
{
    //dtor
}

vector<string> SavedGamesModel::getSavedGamesNames()
{
    return names;
}
