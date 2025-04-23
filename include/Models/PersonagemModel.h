#ifndef PERSONAGEMMODEL_H
#define PERSONAGEMMODEL_H

#include <string>

#include <BaseModel.h>
#include "../Interfaces/ISerializavel.h"

using namespace std;
class PersonagemModel : public BaseModel, public ISerializavel
{
    public:
        PersonagemModel();
        virtual ~PersonagemModel();
        void serializar(string filename) override;
        void desserializar(string filename) override;

        void setNome(string nome);
        string getNome();

        void setHabilidade(int habilidade);
        int getHabilidade();

        void setEnergia(int energia);
        int getEnergia();

        void setSorte(int sorte);
        int getSorte();

    protected:

    private:
        string nome;
        int habilidade;
        int energia;
        int sorte;

};

#endif // PERSONAGEMMODEL_H
