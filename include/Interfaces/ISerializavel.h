#ifndef ISERIALIZAVEL_H
#define ISERIALIZAVEL_H

#include <string>

using namespace std;
class ISerializavel
{
    public:
        virtual void serializar(string filename);
        virtual void desserializar(string filename);
};

#endif // ISERIALIZAVEL_H
