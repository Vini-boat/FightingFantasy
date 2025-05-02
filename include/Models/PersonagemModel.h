#ifndef PERSONAGEMMODEL_H
#define PERSONAGEMMODEL_H

#include <string>
#include <vector>

#include "../Models/BaseModel.h"
#include "../Interfaces/ISerializavel.h"

using namespace std;
class PersonagemModel : public BaseModel, public ISerializavel
{
    public:
        PersonagemModel();
        virtual ~PersonagemModel();
        void serializar(string filename) override;
        void desserializar(string filename) override;
        void salvar();

        void setNome(string nome);
        string getNome();

        void setHabilidade(int habilidade);
        int getHabilidade();

        void setEnergia(int energia);
        int getEnergia();

        void setSorte(int sorte);
        int getSorte();

        void addItem(string item);
        vector<string> getItens();

        void setProvisoes(int provisoes);
        int getProvisoes();

        void setEnergiaMaxima(int energia_maxima);
        int getEnergiaMaxima();

        void setTesouro(int tesouro);
        int getTesouro();

    protected:

    private:
        string nome;
        int habilidade;
        int energia;
        int energia_maxima;
        int sorte;
        int tesouro;
        int provisoes;
        vector<string> itens;
};

#endif // PERSONAGEMMODEL_H
