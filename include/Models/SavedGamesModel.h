#ifndef SAVEDGAMESMODEL_H
#define SAVEDGAMESMODEL_H

#include <BaseModel.h>
#include <string>
#include <vector>

using namespace std;
class SavedGamesModel : public BaseModel
{
    public:
        SavedGamesModel();
        virtual ~SavedGamesModel();
        vector<string> getSavedGamesNames();
    protected:

    private:
        vector<string> names;
};

#endif // SAVEDGAMESMODEL_H
