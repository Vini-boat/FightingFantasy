#ifndef MONSTROCONTROLLER_H
#define MONSTROCONTROLLER_H

#include <BaseController.h>

#include "../../include/Models/MonstroModel.h"

#include <map>
#include <memory>
#include <vector>
#include <string>

using namespace std;
class MonstroController : public BaseController
{
    public:
        MonstroController();
        virtual ~MonstroController();

        void carregarMonstros();

        int getHabilidade(string nome_monstro);
        int getEnergia(string nome_monstro);
        int getTesouro(string nome_monstro);
        int getProvisoes(string nome_monstro);
        vector<string> getItens(string nome_monstro);
        int getCenaVitoria(string nome_monstro);
        int getCenaDerrota(string nome_monstro);

    private:
        map<string,unique_ptr<MonstroModel>> monstros;
};

#endif // MONSTROCONTROLLER_H
