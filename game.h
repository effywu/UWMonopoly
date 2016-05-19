/*
 *  game.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__game__
#define __bb7k__game__

#include <iostream>
#include <string>
#include <fstream>
#include "square.h"
#include "player.h"
#include "gamenotification.h"
#include "SLCCard.h"
#include "NeedlesCard.h"

class Game {
    
    int NumberOfPlayer;
    
    //players not bankrupt
    int validPlayer;
    
    Square * square[40];
    Player * player[8];
    SLCCard * slccards[24];
    NeedlesCard * needlescards[18];
    GameNotification *notification;
    
    //Doubles a player has roll in a row
    int countDoubles;
public:
    //Constructor for new games
    Game(int numOfP, GameNotification *noti,bool generatePlayer=true);
    //Constructor for load games
    Game(int numOfP, GameNotification *noti,std::ifstream &in);

    int getPlayerPosition(int p);
    char getPlayerChar(int p);
    std::string getPlayerName(int p);
    int getValidPlayer();
    int getCountDoubles();
    
    //take necessory action when player has landed on the position
    // ie. buy the property/pay the rent/move to DC Tims line,etc
    void takeAction(int player, int position);
    
    //Player p need to pay amount to the owner
    //when owner is -1, it is paid to Bank
    //Return: true if sucess
    //        false if bankrupt
    bool pay(int p,int amount,int owner=-1);
    
    //If player does not have enough money to pay
    //provide options for the player
    //Return: true if sucess
    //        false if bankrupt
    bool finance(int player,int amount,int owner);
    
    //check if player is in DC Tims line
    bool checkTimsMode(int p);
    
    //check turns player has stayed in DC Tims line
    int checkTimsTurn(int p);
    
    //If way is "pay", pay $50 to leave Tims line
    //If way is "usecup", use a Roll Up the Rim Cup to leave Tims line
    void leaveTims(int p,std::string way);
    
    //If dice=-1 and dice2 =-1, roll dices randomly
    //Else roll the sum of two dices
    void roll(int player,int dice1=-1, int dice2=-1);
    
    //Auction the building
    void auction(int building);
    
    //player1 requests trade with player2, exchange give and receive
    void trade(int player1, std::string player2, std::string give, std::string receive);
    
    //player requests to buy/sell improvement the property
    void improve(int player,std::string property,std::string action);
    
    //player requests to mortgage the property
    void mortgage(int player, std::string property);
    
    //player requests to unmortgage the property
    void unmortgage(int player, std::string property);
    
    //display the assets of the player
    void displayAssets(int player);
    
    //player is bankruptcy and owe money to owner
    //If owner is Bank, the properties of player will be auctioned
    //If owner is a player, the assets of the player will give to owner
    void bankruptcy(int player,int owner);
    
    //check if the player is bankrupt
    bool isBankrupt(int p);
    
    //check if the building can be improved
    bool canImprove(int building);
    
    //save the game to the out file
    void save(int p,std::ofstream &out);
    
    //read from in file to set owners of building and call notification to display
    void initialOwners(std::ifstream &in);
    
    void getMoney(int Player, int amount);
    ~Game();
};


#endif /* defined(__bb7k__game__) */
