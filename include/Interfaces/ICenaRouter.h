#ifndef ICENAROUTER_H
#define ICENAROUTER_H

#include <string>

using namespace std;
class ICenaRouter
{
    public:
        ICenaRouter() {}
        virtual ~ICenaRouter() {}
        virtual void changeCena(string cena) = 0;
        virtual void carregarSave() = 0;
};

#endif // ICENAROUTER_H
