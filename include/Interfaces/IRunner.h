#ifndef IRUNNER_H
#define IRUNNER_H


class IRunner
{
    public:
        IRunner() {}
        virtual ~IRunner() {}
        virtual void run() = 0;
        virtual void stop() = 0;
};

#endif // IRUNNER_H
