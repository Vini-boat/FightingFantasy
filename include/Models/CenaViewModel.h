#ifndef CENAVIEWMODEL_H
#define CENAVIEWMODEL_H

#include <BaseModel.h>
#include "../../include/Models/CenaModel.h"

#include "../../include/Interfaces/ISerializavel.h"

#include <string>
#include <map>
#include <memory>
#include <vector>

using namespace std;
class CenaViewModel : public BaseModel, public ISerializavel
{
    public:
        CenaViewModel();
        virtual ~CenaViewModel();

        void serializar(string filename) override;
        void desserializar(string filename) override;

        void carregarCenas();
        void setCenaAtual(string cena);
        string getNomeCenaAtual();
        string getTextoCenaAtual();
        vector<string> getCenasEscolhasCenaAtual();
        vector<string> getDescricaoEscolhasCenaAtual();
        vector<string> getItensCenaAtual();
        int getTesouroCenaAtual();

        vector<string> getMonstrosCombatesCenaAtual();
        vector<string> getDescricaoCombatesCenaAtual();

        vector<string> getNomesCenas();
        vector<string> getTextoCenas();



    protected:

    private:
        string cena_atual;
        map<string,unique_ptr<CenaModel>> cenas;

};

#endif // CENAVIEWMODEL_H
