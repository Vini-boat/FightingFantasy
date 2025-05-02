#include "CenaView.h"
#include "CenaController.h"

#include "../../include/Commands/ChangeView.h"
#include "../../include/Commands/ChangeCena.h"
#include "../../include/Commands/MultiCommand.h"
#include "../../include/Commands/SetMonsterCommand.h"
#include "../../include/Controllers/CombateController.h"

#include <iostream>
#include <string>
#include <memory>

using namespace std;
CenaView::CenaView(CenaController* controller, shared_ptr<ChangeView> change_to_combate_view, shared_ptr<CombateController> combate_controller)
{
    this->controller = controller;
    this->change_to_combate_view = change_to_combate_view;
    this->combate_controller = combate_controller;
}

CenaView::~CenaView()
{
    //dtor
}

void CenaView::show()
{
    resetOpcoes();
    limparTela();
    cout << "======== CENA =========" << endl;
    cout << endl;
    cout << this->controller->getCenaText() << endl;
    cout << endl;
    printOptions();
    cout << "--------------------------------" << endl;
}

void CenaView::process()
{

}

void CenaView::handleInput()
{
    resetOpcoes();
    string t = getValidOption();
    executeOption(t);
}

void CenaView::resetOpcoes()
{
    resetVariableOptions();
    int j =0;
    int i = 0;
    vector<string> desc_combates = this->controller->getDescricaoCombates();
    for(string m: this->controller->getMonstrosCombates())
    {
        addVariableOption(to_string(j), desc_combates.at(i), make_shared<MultiCommand>(
                                                            make_shared<SetMonsterCommand>(this->combate_controller,m),
                                                            this->change_to_combate_view
                                                            )
                          );
        j++;
        i++;
    }

    i = 0;
    vector<string> descricoes = this->controller->getDescricaoEscolhasCena();
    for(string e: this->controller->getEscolhasCena())
    {
        addVariableOption(to_string(j), descricoes.at(i), make_shared<ChangeCena>(this->controller,e));
        j++;
        i++;
    }
}
