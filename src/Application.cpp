#include "Application.h"
#include "MenuView.h"
#include "SavedGamesModel.h"
#include "SavedGamesView.h"

#include <map>
#include <memory>
#include <string>

Application::Application()
{
    this->running - true;
    this->current_view = "menu";

    this->saved_games_model = new SavedGamesModel;

    this->views["menu"] = make_unique<MenuView>();
    this->views["savedgames"] = make_unique<SavedGamesView>(saved_games_model);
}

Application::~Application()
{
    //dtor
}


void Application::stop(){this->running = false;}

void Application::run()
{
    while(running)
    {
        this->views[current_view]->show();
        this->views[current_view]->handleInput();
    }
}

void Application::changeCurrentView(string view_name)
{
    this->current_view = view_name;
}
