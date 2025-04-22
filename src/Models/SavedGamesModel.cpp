#include "SavedGamesModel.h"
#include <string>
#include <vector>

using namespace std;
SavedGamesModel::SavedGamesModel()
{
    //ctor
}

SavedGamesModel::~SavedGamesModel()
{
    //dtor
}

vector<string> SavedGamesModel::getSavedGamesNames()
{
    return names;
}
