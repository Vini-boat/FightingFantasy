#ifndef SAVEMODEL_H
#define SAVEMODEL_H

#include <BaseModel.h>

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

        string getNomePersonagem();
        string getCenaAtual();
        void addCenaPassada(string cena);
        void setCenaAtual(string cena);

    protected:

    private:
        string personagem;
        vector<string> cenas_passadas;
        string cena_atual;
};

#endif // SAVEMODEL_H
