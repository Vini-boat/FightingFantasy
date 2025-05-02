#ifndef MONSTROMODEL_H
#define MONSTROMODEL_H

#include <string>
#include <vector>
#include <BaseModel.h>
#include "../../include/Interfaces/ISerializavel.h"

using namespace std;
class MonstroModel : public BaseModel, public ISerializavel
{
    public:
        MonstroModel();
        virtual ~MonstroModel();

        void serializar(string filename) override;
        void desserializar(string filename) override;

        int getHabilidade();
        int getEnergia();
        int getTesouro();
        int getProvisoes();
        vector<string> getItens();
        int getCenaVitoria();
        int getCenaDerrota();

    private:
        string nome;
        int habilidade;
        int energia;
        int tesouro;
        int provisoes;
        vector<string> itens;
        int id_cena_vitoria;
        int id_cena_derrota;
};

#endif // MONSTROMODEL_H
