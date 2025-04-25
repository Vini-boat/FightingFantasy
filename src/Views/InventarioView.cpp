#include "InventarioView.h"
#include "../../include/Controllers/InventarioController.h"
#include "../../include/Models/PersonagemModel.h"

#include <string>
#include <iostream>

using namespace std;
InventarioView::InventarioView(InventarioController* controller, PersonagemModel* model)
{
    this->controller = controller;
    this->model = model;
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
    cout << "   v: Voltar para a cena" << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
}
void InventarioView::handleInput()
{
    string t = getValidOption();
    executeOption(t);
}
