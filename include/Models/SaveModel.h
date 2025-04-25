#ifndef SAVEMODEL_H
#define SAVEMODEL_H

#include <BaseModel.h>
#include "../../include/Models/PersonagemModel.h"

#include "../../include/Interfaces/ISerializavel.h"

#include <string>
#include <vector>

using namespace std;
class SaveModel : public BaseModel, public ISerializavel
{
    public:
        SaveModel();
        virtual ~SaveModel();

        void serializar(string filename) override;
        void desserializar(string filename) override;

    protected:

    private:
        PersonagemModel* personagem;
        vector<string> cenas_passadas;
        string cena_atual;
};

#endif // SAVEMODEL_H
