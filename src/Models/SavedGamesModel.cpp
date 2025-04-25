#include "../../include/Models/SavedGamesModel.h"
#include <string>
#include <vector>

#include <fstream>

using namespace std;
SavedGamesModel::SavedGamesModel()
{

}

SavedGamesModel::~SavedGamesModel()
{
    //dtor
}

vector<string> SavedGamesModel::getSavedGamesNames()
{
    ifstream arq;
    arq.open("./data/index/saves.txt");
    vector<string> names;
    string line;
    while(getline(arq, line))
    {
        names.push_back(line);
    }
    return names;
    arq.close();
}
