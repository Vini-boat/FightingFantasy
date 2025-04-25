#include "ChangeCena.h"
#include "../../include/Interfaces/ICenaRouter.h"

#include <string>

using namespace std;
ChangeCena::ChangeCena(ICenaRouter* router, string dest_cena)
{
    this->router = router;
    this->dest_cena = dest_cena;
}

ChangeCena::~ChangeCena()
{
    //dtor
}

void ChangeCena::execute()
{
    this->router->changeCena(this->dest_cena);
}
