#ifndef ISERIALIZAVEL_H
#define ISERIALIZAVEL_H

#include <string>

using namespace std;
class ISerializavel
{
    public:
        virtual void serializar(string filename) =0;
        virtual void desserializar(string filename) =0;
};

#endif // ISERIALIZAVEL_H
