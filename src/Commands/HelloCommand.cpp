#include "HelloCommand.h"
#include <string>
#include <iostream>
using namespace std;
HelloCommand::HelloCommand(string hello)
{
    this->hello = hello;
}

HelloCommand::~HelloCommand()
{
    //dtor
}

void HelloCommand::execute()
{
    cout << this->hello << endl;
}
