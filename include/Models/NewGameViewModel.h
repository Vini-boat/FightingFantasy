#ifndef NEWGAMEVIEWMODEL_H
#define NEWGAMEVIEWMODEL_H

#include "../Models/BaseModel.h"
#include "../Interfaces/IResetable.h"
#include <string>

using namespace std;
class NewGameViewModel : public BaseModel, public IResetable
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

        void setPontosRestantes(int pontos);
        int getPontosRestantes();

        void reset() override;
    private:
        int etapa_atual;
        int pontos_restantes;

        string nome;
        int habilidade;
        int energia;
        int sorte;
};

#endif // NEWGAMEVIEWMODEL_H
