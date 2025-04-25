#ifndef CENAVIEWMODEL_H
#define CENAVIEWMODEL_H

#include <BaseModel.h>
#include "../../include/Models/CenaModel.h"

#include <string>
#include <map>
#include <memory>
#include <vector>

using namespace std;
class CenaViewModel : public BaseModel
{
    public:
        CenaViewModel();
        virtual ~CenaViewModel();

        void setCenaAtual(string cena);
        string getCenaAtual();

        vector<string> getNomesCenas();
        vector<string> getTextoCenas();
    protected:

    private:
        string cena_atual;
        map<string,unique_ptr<CenaModel>> cenas;

};

#endif // CENAVIEWMODEL_H
