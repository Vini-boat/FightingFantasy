#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <BaseView.h>


class MenuView : public BaseView
{
    public:
        MenuView();
        virtual ~MenuView();

        void show() override;
        void handleInput() override;

    protected:

    private:
};

#endif // MENUVIEW_H
