#ifndef ICURAVEL_H
#define ICURAVEL_H


class ICuravel
{
    public:
        ICuravel() {}
        virtual ~ICuravel() {}
        virtual void curar() =0;
};

#endif // ICURAVEL_H
