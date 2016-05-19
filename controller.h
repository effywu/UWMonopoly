/*
 *  controller.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__controller__
#define __bb7k__controller__

#include <iostream>
#include <string>
#include <fstream>
#include "gamenotification.h"
#include "player.h"
#include "game.h"
#include "View.h"

class Controller : public GameNotification {
    
    Game *game;
    int totalPlayers;
    
    //index of current player
    int currentPlayer;
    
    //textdisplay
    View *td;
    
    //names of players
    std::string * players;
    
    bool testMode;
    bool rolled;
    
public:
    //Constructor of new games with/without test mode
    Controller(bool testMode=false);
    //Constructor of load games with/without test mode
    Controller(std::ifstream &in,bool testMode=false);
    
    //play the game
    void play();
    
    //called by Game, notify View the movement of player
    void notify (int player, int newPosition);
    
    //called by Game, notify View the new owner of building
    void notifyNewOwner(int building, int p );
    
    //called by Game, notify View the buy/sell of improvement for a building
    void notifyImprove(int building,int change=1);
    
    //called by Game, notify View mortgage/unmortgage of a building
    void notifyMortgage(int building,int change=1);
    
    //called by Game, notify View the bankrupt of a player
    void notifyBankruptcy(int player);
    
    //called by Game, notify controller the player has rolled doubles
    void notifyDoubles();
    
    //called by Game, print the text display board
    void printBoard();
    ~Controller();
};



#endif /* defined(__bb7k__controller__) */
