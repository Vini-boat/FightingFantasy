#include "../include/Application.h"
#include "../include/Views/MenuView.h"
#include "../include/Models/SavedGamesModel.h"
#include "../include/Models/PersonagemModel.h"
#include "../include/Views/SavedGamesView.h"
#include "../include/Views/NewGameView.h"
#include "../include/Models/NewGameViewModel.h"
#include "../include/Models/CenaModel.h"
#include "../include/Views/CreditosView.h"

#include "../include/Controllers/NewGameController.h"

#include "../include/Commands/Sair.h"
#include "../include/Commands/ChangeView.h"
#include "../include/Commands/SalvarCommand.h"
#include "../include/Commands/SalvarEMudarView.h"
#include "../include/Commands/CarregarSaveEMudarView.h"
#include "../include/Commands/CarregarSave.h"

#include "../include/Views/CenaView.h"

#include "../include/Models/CenaViewModel.h"
#include "../include/Models/SaveModel.h"

#include <map>
#include <memory>
#include <string>
#include <iostream>

using namespace std;
Application::Application()
{
    this->running = true;
    this->current_view = "menu";

    this->saved_games_model = new SavedGamesModel;

    this->save = new SaveModel;
    this->personagem_atual = new PersonagemModel;

    this->views["menu"] = make_unique<MenuView>();
    this->views["menu"]->addOption("n", new ChangeView(this, "newgame"));
    this->views["menu"]->addOption("s", new ChangeView(this, "savedgames"));
    this->views["menu"]->addOption("c", new ChangeView(this, "credits"));
    this->views["menu"]->addOption("q", new Sair(this));

    NewGameViewModel* new_game_view_model = new NewGameViewModel;
    NewGameController* new_game_controller = new NewGameController(save, new_game_view_model, this->personagem_atual);
    this->views["newgame"] = make_unique<NewGameView>(new_game_controller, new_game_view_model);

    this->views["newgame"]->addOption("s",new SalvarEMudarView(new_game_controller,this,"savedgames"));
    this->views["newgame"]->addOption("v", new ChangeView(this, "menu"));

    this->views["credits"] = make_unique<CreditosView>();
    this->views["credits"]->addOption("v", new ChangeView(this, "menu"));

    CenaViewModel* cena_view_model = new CenaViewModel;
    cena_view_model->carregarCenas();
    CenaController* cena_controller = new CenaController(cena_view_model,save);
    this->views["cenas"] = make_unique<CenaView>(cena_controller);
    this->views["cenas"]->addOption("m", new ChangeView(this, "menu"));

    this->views["savedgames"] = make_unique<SavedGamesView>(saved_games_model);
    this->views["savedgames"]->addOption("c", new CarregarSaveEMudarView(cena_controller, save,personagem_atual,"ex_savegame",this,"cenas"));
    this->views["savedgames"]->addOption("v", new ChangeView(this, "menu"));


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

void Application::debug()
{
    save = new SaveModel;
    personagem_atual = new PersonagemModel;
    //ICommand* carregar = new CarregarSave(save,personagem_atual,"ex_savegame");
    //carregar->execute();
}
