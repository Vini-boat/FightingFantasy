#include "CarregarSave.h"
#include "../../include/Models/SaveModel.h"
#include "../../include/Models/PersonagemModel.h"
#include "../../include/Interfaces/ICenaRouter.h"

#include <string>

using namespace std;
CarregarSave::CarregarSave(ICenaRouter* router, SaveModel * save_model, PersonagemModel* personagem_model, string save_name)
{
    this->personagem_model = personagem_model;
    this->save_model = save_model;
    this->save_name = save_name;
    this->router = router;
}

CarregarSave::~CarregarSave()
{
    //dtor
}

void CarregarSave::execute()
{
    this->save_model->desserializar("./data/saves/" + this->save_name + ".txt");
    this->personagem_model->desserializar("./data/personagens/" + this->save_model->getNomePersonagem() + ".txt");
    this->router->carregarSave();
}
