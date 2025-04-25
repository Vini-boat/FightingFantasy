#ifndef NEWGAMEVIEWMODEL_H
#define NEWGAMEVIEWMODEL_H

#include "../Models/BaseModel.h"
#include <string>

using namespace std;
class NewGameViewModel : public BaseModel
{
    public:
        NewGameViewModel();
        virtual ~NewGameViewModel();

        void setEtapa(int etapa);
        int getEtapa();

        void setNome(string nome);
        string getNome();

        void setHabilidade(int habilidade);
        int getHabilidade();

        void setEnergia(int energia);
        int getEnergia();

        void setSorte(int sorte);
        int getSorte();
    private:
        int etapa_atual;
        string nome;
        int habilidade;
        int energia;
        int sorte;
};

#endif // NEWGAMEVIEWMODEL_H
