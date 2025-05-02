#include "InventarioView.h"
#include "../../include/Controllers/InventarioController.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Controllers/ItemController.h"

#include <string>
#include <iostream>
#include <memory>

using namespace std;
InventarioView::InventarioView(InventarioController* controller, PersonagemModel* model, shared_ptr<ItemController> item_controller)
{
    this->controller = controller;
    this->model = model;
    this->item_controller = item_controller;
}

InventarioView::~InventarioView()
{
    //dtor
}


void InventarioView::show()
{
    limparTela();
    cout << "========== INVENTARIO ===========" << endl;
    cout << endl;
    cout << "   Nome:       " << this->model->getNome() << endl;
    cout << endl;
    cout << "   Habilidade: " << this->model->getHabilidade() << endl;
    cout << "   Energia:    " << this->model->getEnergia() << endl;
    cout << "   Sorte:      " << this->model->getSorte() << endl;
    cout << endl;
    cout << "   Itens: " << endl;
    int i=0;
    for(string& item: this->model->getItens())
    {
        cout << "   " << i << ": " << item << " | " << this->item_controller->getItemDescription(item) << endl;
        i++;
    }
    cout << endl;
    cout << "   v: Voltar para a cena" << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
}
void InventarioView::handleInput()
{
    string t = getValidOption();
    executeOption(t);
}
