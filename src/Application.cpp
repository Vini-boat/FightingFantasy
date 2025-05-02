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
#include "../include/Commands/CarregarSave.h"
#include "../include/Commands/MultiCommand.h"
#include "../include/Commands/HelloCommand.h"
#include "../include/Commands/ResetCommand.h"

#include "../include/Views/InventarioView.h"
#include "../include/Controllers/InventarioController.h"

#include "../include/Views/CenaView.h"

#include "../include/Models/CenaViewModel.h"
#include "../include/Models/SaveModel.h"
#include "../include/Models/MonstroModel.h"
#include "../include/Models/ItemModel.h"

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

    NewGameViewModel* new_game_view_model = new NewGameViewModel;
    NewGameController* new_game_controller = new NewGameController(save, new_game_view_model, this->personagem_atual);

    CenaViewModel* cena_view_model = new CenaViewModel;
    cena_view_model->carregarCenas();

    CenaController* cena_controller = new CenaController(cena_view_model,save);
    this->views["menu"] = make_unique<MenuView>();
    this->views["menu"]->addStaticOption("n","Novo jogo", make_shared<ChangeView>(this, "newgame"));
    this->views["menu"]->addStaticOption("s","Carregar Jogo",make_shared<ChangeView>(this, "savedgames"));
    this->views["menu"]->addStaticOption("c","Creditos",make_shared<ChangeView>(this, "credits"));
    this->views["menu"]->addStaticOption("z","Sair",make_shared<Sair>(this));

    this->views["newgame"] = make_unique<NewGameView>(new_game_controller, new_game_view_model);

    this->views["newgame"]->addStaticOption("s","Confirmar Personagem", make_shared<MultiCommand>(
                                                            make_shared<MultiCommand>(
                                                                make_shared<SalvarCommand>(new_game_controller),
                                                                make_shared<CarregarSave>(cena_controller,save,personagem_atual,"ex_savegame")
                                                            ),
                                                            make_shared<ChangeView>(this,"inventario")
                                                            )
                                      );
    this->views["newgame"]->addStaticOption("v","Voltar", make_shared<MultiCommand>(
                                                        make_shared<ResetCommand>(new_game_view_model),
                                                        make_shared<ChangeView>(this, "menu")
                                                        )
                                            );

    this->views["credits"] = make_unique<CreditosView>();
    this->views["credits"]->addStaticOption("v","Voltar",make_shared<ChangeView>(this, "menu"));


    this->views["cenas"] = make_unique<CenaView>(cena_controller);
    this->views["cenas"]->addStaticOption("i","Inventario",make_shared<ChangeView>(this, "inventario"));
    this->views["cenas"]->addStaticOption("m","Voltar para o Menu", make_shared<ChangeView>(this, "menu"));

    this->views["savedgames"] = make_unique<SavedGamesView>(saved_games_model);
    this->views["savedgames"]->addStaticOption("c","Carregar Jogo", make_shared<MultiCommand>(
                                                               make_shared<CarregarSave>(cena_controller,save,personagem_atual,"ex_savegame"),
                                                               make_shared<ChangeView>(this,"cenas")
                                                               )
                                         );
    this->views["savedgames"]->addStaticOption("v","Voltar", make_shared<ChangeView>(this, "menu"));

    this->views["inventario"] = make_unique<InventarioView>(new InventarioController(this->personagem_atual),this->personagem_atual);
    this->views["inventario"]->addStaticOption("v","Voltar", make_shared<ChangeView>(this, "cenas"));


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
    ItemModel item;
    item.desserializar("ex_item.txt");

}
