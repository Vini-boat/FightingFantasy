#ifndef IRESETABLE_H
#define IRESETABLE_H

class IResetable
{
    public:
        IResetable() {}
        virtual ~IResetable() {}
        virtual void reset() = 0;
};

#endif // IRESETABLE_H
