#ifndef BASEVIEW_H
#define BASEVIEW_H


class BaseView
{
    public:
        BaseView();
        virtual ~BaseView();
        virtual void show() = 0;
        virtual void handleInput() = 0;
    protected:

    private:
};

#endif // BASEVIEW_H
