#ifndef CARREGARSAVE_H
#define CARREGARSAVE_H

#include <ICommand.h>


class CarregarSave : public ICommand
{
    public:
        CarregarSave();
        virtual ~CarregarSave();
        void execute() override;
    protected:

    private:
};

#endif // CARREGARSAVE_H
