#ifndef APPLICATION_H
#define APPLICATION_H
#include "../include/Interfaces/IRunner.h"
#include "../include/Interfaces/IViewRouter.h"

#include <map>
#include <memory>
#include <string>

#include "../include/Controllers/BaseController.h"
#include "../include/Models/BaseModel.h"
#include "../include/Models/PersonagemModel.h"
#include "../include/Views/BaseView.h"

#include "../include/Models/SavedGamesModel.h"

using namespace std;
class Application: public IRunner, public IViewRouter
{
    public:
        Application();
        virtual ~Application() override;
        void run() override;
        void stop() override;

        void changeCurrentView(string view_name) override;
    protected:

    private:
        bool running;
        map<string,unique_ptr<BaseView>> views;
        //map<string,unique_ptr<BaseController>> controllers;
        //map<string,unique_ptr<BaseModel>> models;
        SavedGamesModel* saved_games_model;
        string current_view;
        PersonagemModel* personagem_atual;

};

#endif // APPLICATION_H
