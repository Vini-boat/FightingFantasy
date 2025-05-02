#ifndef ITEMCONTROLLER_H
#define ITEMCONTROLLER_H

#include <BaseController.h>
#include <map>
#include <string>
#include <memory>

#include "../Models/ItemModel.h"

using namespace std;
class ItemController : public BaseController
{
    public:
        ItemController();
        virtual ~ItemController();
        void carregarItens();
        string getItemType(string nome);
    private:
        map<string,unique_ptr<ItemModel>> itens;
};

#endif // ITEMCONTROLLER_H
