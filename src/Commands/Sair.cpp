#include "Sair.h"

#include <ICommand.h>
#include <IRunner.h>


Sair::Sair(IRunner* runner)
{
    this->runner = runner;
}

Sair::~Sair()
{
    //dtor
}


void Sair::execute()
{
    this->runner->stop();
}

