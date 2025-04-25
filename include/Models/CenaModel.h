#ifndef CENAMODEL_H
#define CENAMODEL_H

#include <BaseModel.h>
#include <string>
#include <vector>
#include <utility>
#include "../../include/Interfaces/ISerializavel.h"

using namespace std;
class CenaModel : public BaseModel, public ISerializavel
{
    public:
        CenaModel();
        virtual ~CenaModel();

        void serializar(string filename);
        void desserializar(string filename);

        string getText();
        vector<string> getCenasEscolhas();
        vector<string> getDescricaoEscolhas();

    protected:

    private:
        string text;
        vector<pair<string,string>> escolhas;
};

#endif // CENAMODEL_H
