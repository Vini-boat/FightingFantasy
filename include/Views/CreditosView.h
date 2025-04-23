#ifndef CREDITOSVIEW_H
#define CREDITOSVIEW_H

#include <BaseView.h>


class CreditosView : public BaseView
{
    public:
        CreditosView();
        virtual ~CreditosView();
        void show() override;
        void handleInput() override;

    protected:

    private:
};

#endif // CREDITOSVIEW_H
