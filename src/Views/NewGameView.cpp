#include "NewGameView.h"
#include "../../include/Controllers/NewGameController.h"
#include "../../include/Models/NewGameViewModel.h"

#include <string>
#include <memory>
#include <iostream>

using namespace std;
NewGameView::NewGameView(NewGameController* controller, shared_ptr<NewGameViewModel> model)
{
    this->controller = controller;
    this->model = model;
}

NewGameView::~NewGameView()
{
    //dtor
}

void NewGameView::show()
{
    limparTela();
    cout << "========== NEW GAME ==========" << endl;
    cout << endl;
    cout << "   Pontos restantes: " << this->model->getPontosRestantes() << endl;
    cout << endl;
    switch(this->model->getEtapa())
    {
    case 0:
        cout << "   Habilidade (6 a 12): ";
        break;
    case 1:
        cout << "   Energia (12 a 24): ";
        break;
    case 2:
        cout << "   Sorte (6 a 12): ";
        break;
    case 3:
        cout << "   Nome do Personagem: ";
        break;
    case 4:
        cout << "   Nome:       " << this->model->getNome2() << endl;
        cout << endl;
        cout << "   Habilidade: " << this->model->getHabilidade() << endl;
        cout << "   Energia:    " << this->model->getEnergia() << endl;
        cout << "   Sorte:      " << this->model->getSorte() << endl;
        printOptions();
        cout << endl;
        cout << "--------------------------------" << endl;
        break;
    }
}

void NewGameView::handleInput()
{
    switch(this->model->getEtapa())
    {
    case 0:
        {
            int h;
            cin >> h;
            if(this->controller->validarHabilidade(h))
            {
                this->controller->setHabilidade(h);
                this->model->setEtapa(1);
            }
            break;
        }
    case 1:
        {
            int e;
            cin >> e;
            if(this->controller->validarEnergia(e))
            {
                this->controller->setEnergia(e);
                this->model->setEtapa(2);
            }
            break;
        }
    case 2:
        {
            int s;
            cin >> s;
            if(this->controller->validarSorte(s))
            {
                this->controller->setSorte(s);
                this->model->setEtapa(3);
            }
            break;
        }
    case 3:
        {
            string n;
            cin >> n;
            this->model->setNome(n);
            this->model->setEtapa(4);
            break;
        }
    case 4:
        {
            string t = getValidOption();
            executeOption(t);
            break;
        }
    }
}
