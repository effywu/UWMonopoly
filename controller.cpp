/*
 *  controller.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "controller.h"
#include "TextDisplay.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//Contructor for new game with/without test mode
Controller::Controller(bool test) {
    
    //set test mode
    testMode = test;
    
    int n;
    rolled=false;
    while (true) {
        cout << "Please enter the number of players." << endl;
        cin>>n;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            continue;
        };
        if (n <= 1 || n > 8) {
            cout << "Please enter number between 2-8." << endl;
        } else {
            break;
        };
    };
    
    game = new Game(n, this);
    td = new TextDisplay();
    totalPlayers = n;
    players = new string[totalPlayers];
    td->initPlayers(n);
    
    //loop for get names of players
    for (int i = 0; i < totalPlayers; i++) {
        players[i] = game->getPlayerName(i);
    };
    
    char * tmp = new char[totalPlayers];
    
    //loop for get characters of players
    for (int i = 0; i < totalPlayers; i++) {
        tmp[i] = game->getPlayerChar(i);
    };
    
    td->setPlayerChar(tmp);
    delete [] tmp;
    currentPlayer = 0;
}

//Constructor to load game with/without test mode
Controller::Controller(ifstream &in,bool test) {
    
    //set test mode
    testMode=test;
    currentPlayer=0;
    rolled=false;
    int n;
    in>>n;
    td = new TextDisplay();
    totalPlayers = n;
    players = new string[totalPlayers];
    td->initPlayers(n);
    
    game = new Game(n, this, in);
    
    //loop for get names of players
    for (int i = 0; i < totalPlayers; i++) {
        players[i] = game->getPlayerName(i);
    };
    
    char * tmp = new char[totalPlayers];
    
    //loop for get characters of players
    for (int i = 0; i < totalPlayers; i++) {
        tmp[i] = game->getPlayerChar(i);
    }
    
    td->setPlayerChar(tmp);
    delete [] tmp;
    
    //loop to notify view the positions of each players
    for (int i = 0; i < n; i++) {
        
        notify(i,game->getPlayerPosition(i));
    };
    
    game->initialOwners(in);
}

//play the game
void Controller::play() {
    
    //print the initial board
    printBoard();
    string command;
    
    //If the current index player is bankrupt, skip until the next valid player
    while (game->isBankrupt(currentPlayer)) {
        currentPlayer++;
    };

    while (true) {//game start
        
        if (game->getValidPlayer() == 1) { // if only one player left
            cout << "Thanks for playing! See you again!" << endl;
            break;
        };
        
        if (game->isBankrupt(currentPlayer)) { //if the player bankrupt
            currentPlayer++;
            if (currentPlayer >= totalPlayers) {
                currentPlayer -= totalPlayers;
            };
            continue;
        };
        
        cout << "Player " << players[currentPlayer] <<" ( "<<game->getPlayerChar(currentPlayer)<<" ) "<< "'s turn." << endl;
        
        bool timMode = game->checkTimsMode(currentPlayer);
        
        if (timMode) { // if player is in DC Tims line
            
            if (!rolled) {
                cout << "( You have stay to in DC Tims Line for " << game->checkTimsTurn(currentPlayer) << " turn(s) )" << endl;
                cout << "( You have to roll doubles / pay $50 / use Roll Up the Rim cup to leave )" << endl;
                cout << "Please select a command: " << endl;
                cout << "| roll | pay | usecup | trade | improve | mortgage | unmortgage | assets | save | help |" << endl;
            } else {
                cout << "Please select a command: " << endl;
                cout << "| trade | improve | mortgage | unmortgage | assets | next | help |" << endl;
            };
            
        } else {
            
            cout << "Please select a command: " << endl;
            if (!rolled) {
                if (game->getCountDoubles()!=0){
                    cout << "| roll | pay | usecup | trade | improve | mortgage | unmortgage | assets | help |" << endl;
                } else {
                    
                    cout << "| roll | trade | improve | mortgage | unmortgage | assets | save | help |" << endl;};
            } else {
                cout << "| trade | improve | mortgage | unmortgage | assets | next | help |" << endl;
            };
        };
        
        cin>>command;
        if (cin.fail()){
            return;
        };
        
        if (command == "roll" && !rolled) { //roll
            rolled = true;
            if (!testMode) {
                game->roll(currentPlayer);
            } else {
                int dice1, dice2;
                cin >> dice1>>dice2;
                if (cin.fail()) {
                    cin.ignore();
                    cin.clear();
                    cout << "Please enter valid number: roll <0-6> <0-6>" << endl;
                    continue;
                }
                if ((dice1 <= 6 && dice1 >= 1)&&(dice2 <= 6 && dice2 >= 1)) {
                    game->roll(currentPlayer, dice1, dice2);
                } else {
                    cout << "Please enter valid number: roll <0-6> <0-6>" << endl;
                    continue;
                };
            };
            if (game->isBankrupt(currentPlayer)) {
                rolled=false;
                currentPlayer++;
                if (currentPlayer >= totalPlayers) {
                    currentPlayer -= totalPlayers;
                };
                continue;
            };
            
            continue;
            
        } else if (command == "pay" && timMode) { // pay to leave Tims
            
            game->leaveTims(currentPlayer, "pay");
            
        } else if (command == "usecup" && timMode) { // use cup to leave Tims
            
            game->leaveTims(currentPlayer, "usecup");
            
        } else if (command == "next" && rolled) { // To next player
            
            currentPlayer += 1;
            if (currentPlayer >= totalPlayers) {
                currentPlayer -= totalPlayers;
            };
            rolled = false;
            if (game->isBankrupt(currentPlayer)) {
                currentPlayer++;
                continue;
            };
            
        } else if (command == "trade") { //trade
            
            string player2;
            string give;
            string receive;
            
            cin>>player2;
            cin>>give;
            cin>>receive;
            if (cin.fail()) {
                cout << "( Invalid trade request )" << endl;
                cout << "( Please follow the format: trade <name> <give> <receive> " << endl;
                continue;
            };
            game->trade(currentPlayer, player2, give, receive);
            
            
        } else if (command == "improve") { //improve
            
            string name;
            string action;
            cin>>name;
            if (cin.fail()) {
                cout << "( Invalid improve request )" << endl;
                cout << "( Please follow the format: improve <property> buy/sell " << endl;
                continue;
            };
            cin>>action;
            if (cin.fail() || (action != "buy" && action != "sell")) {
                cout << "( Invalid improve request )" << endl;
                cout << "( Please follow the format: improve <property> buy/sell " << endl;
                continue;
            };
            game->improve(currentPlayer, name, action);
            
            
        } else if (command == "mortgage") { //mortgage
            
            string name;
            cin>>name;
            if (cin.fail()) {
                cout << "( Invalid mortgage request )" << endl;
                cout << "( Please follow the format: mortgage <property> " << endl;
                continue;
            };
            game->mortgage(currentPlayer, name);
            
        } else if (command == "unmortgage") { //unmortgage
            
            string name;
            cin>>name;
            if (cin.fail()) {
                cout << "( Invalid unmortgage request )" << endl;
                cout << "( Please follow the format: unmortgage <property> " << endl;
                continue;
            };
            game->unmortgage(currentPlayer, name);
            
            
        } else if (command == "assets") { //display assets
            
            game->displayAssets(currentPlayer);
            
        } else if (command == "save" && !rolled&&(game->getCountDoubles()==0)) { //save game to file
            string filename;
            
            while (true) {
                cin>>filename;
                if (cin.fail()){
                    cout<<"Please enter a name for saving file"<<endl;
                } else {
                    break;
                };
            };
            ofstream saveto;
            saveto.open(filename.c_str());
            game->save(currentPlayer,saveto);
            cout << "Thanks for playing! See you again!" << endl;
            break;
            
        } else if (command == "help") { // display help
            cout << "Commands format:" << endl;
            cout << "    trade <name> <give> <receive>" << endl;
            cout << "    improve <property> buy/sell" << endl;
            cout << "    mortgage <property>" << endl;
            cout << "    unmortgage <property>" << endl;
            cout << "    save <filename>" << endl;
            
        }
        else if (command=="getmoney"&&testMode){
            //a testing command that can only be used in testing mode: Current player get money instantly
            int cash;
            cin>>cash;
            game->getMoney(currentPlayer, cash);
        }
        else {
            cout << "( Invalid input )" << endl;
        };
    };
    
}; //play

//called by Game, notify View the new position of player
void Controller::notify(int player, int newPosition) {
    td->moveto(newPosition, player);
}

//called by Game, notify View the new owner of the building
void Controller::notifyNewOwner(int building, int p) {
    td->setOwner(building, p);
}

//called by Game, notify View the buy/sell of improvement for building
void Controller::notifyImprove(int building, int change) {
    td->Improve(building, change);
}

//called by Game, notify View mortgage/unmortgage of the building
void Controller::notifyMortgage(int building, int change) {
    td->Mortgage(building, change);
}

//called by Game, notify View the bankrupt of player
void Controller::notifyBankruptcy(int player) {
    td->Bankruptcy(player);
}

//called by Game, print the text display of board
void Controller::printBoard() {
    td->printBoard();
}

//called by Game, notify controller the player has rolled doubles
void Controller::notifyDoubles(){
    rolled=false;
}

Controller::~Controller() {
    delete game;
    delete td;
    delete [] players;
}