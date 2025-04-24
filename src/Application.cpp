#include "../include/Application.h"
#include "../include/Views/MenuView.h"
#include "../include/Models/SavedGamesModel.h"
#include "../include/Models/PersonagemModel.h"
#include "../include/Views/SavedGamesView.h"
#include "../include/Views/NewGameView.h"
#include "../include/Models/NewGameViewModel.h"
#include "../include/Views/CreditosView.h"

#include "../include/Controllers/NewGameController.h"

#include "../include/Commands/Sair.h"
#include "../include/Commands/ChangeView.h"

#include <map>
#include <memory>
#include <string>

using namespace std;
Application::Application()
{
    this->running = true;
    this->current_view = "menu";

    this->saved_games_model = new SavedGamesModel;

    this->personagem_atual = new PersonagemModel;

    this->views["menu"] = make_unique<MenuView>();
    this->views["menu"]->addOption("n", new ChangeView(this, "newgame"));
    this->views["menu"]->addOption("s", new ChangeView(this, "savedgames"));
    this->views["menu"]->addOption("c", new ChangeView(this, "credits"));
    this->views["menu"]->addOption("q", new Sair(this));

    this->views["newgame"] = make_unique<NewGameView>( new NewGameController(this->personagem_atual), new NewGameViewModel);

    this->views["newgame"]->addOption("v", new ChangeView(this, "menu"));

    this->views["savedgames"] = make_unique<SavedGamesView>(saved_games_model);
    this->views["savedgames"]->addOption("v", new ChangeView(this, "menu"));

    this->views["credits"] = make_unique<CreditosView>();
    this->views["credits"]->addOption("v", new ChangeView(this, "menu"));
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
