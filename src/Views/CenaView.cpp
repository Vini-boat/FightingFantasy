#include "CenaView.h"
#include "CenaController.h"


CenaView::CenaView(CenaController* controller)
{
    this->controller = controller;
}

CenaView::~CenaView()
{
    //dtor
}

void CenaView::show()
{
    limparTela();


}

void CenaView::handleInput()
{

}
