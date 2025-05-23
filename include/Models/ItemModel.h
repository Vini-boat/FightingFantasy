#ifndef ITEMMODEL_H
#define ITEMMODEL_H

#include <BaseModel.h>
#include "../../include/Interfaces/ISerializavel.h"

#include <string>

using namespace std;
class ItemModel : public BaseModel, public ISerializavel
{
    public:
        ItemModel();
        virtual ~ItemModel();

        void serializar(string filename) override;
        void desserializar(string filename) override;

        string getType();
        string getDescricao();
    private:
        string nome;
        string descricao;
        string tipo;
        int bonus_combate;
        int modificador;

};

#endif // ITEMMODEL_H
