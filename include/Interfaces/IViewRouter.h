#ifndef IVIEWROUTER_H
#define IVIEWROUTER_H
#include <string>

using namespace std;
class IViewRouter
{
    public:
        IViewRouter() {}
        virtual ~IViewRouter() {}
        virtual void changeCurrentView(string view_name) = 0;
    protected:

    private:
};

#endif // IVIEWROUTER_H
