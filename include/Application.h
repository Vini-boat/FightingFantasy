#ifndef APPLICATION_H
#define APPLICATION_H
#include "IRunner.h"
#include "IViewRouter.h"

#include <map>
#include <string>
#include <memory>

#include "BaseView.h"
#include "BaseController.h"
#include "BaseModel.h"

#include "SavedGamesModel.h"

using namespace std;
class Application: public IRunner, public IViewRouter
{
    public:
        Application();
        virtual ~Application();
        void run();
        void stop();

        void changeCurrentView(string view_name);
    protected:

    private:
        bool running;
        map<string,unique_ptr<BaseView>> views;
        //map<string,unique_ptr<BaseController>> controllers;
        //map<string,unique_ptr<BaseModel>> models;
        SavedGamesModel* saved_games_model;
        string current_view;
};

#endif // APPLICATION_H
