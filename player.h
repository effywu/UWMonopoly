/*
 *  player.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__player__
#define __bb7k__player__

#include <string>
#include <map>
#include "square.h"

class Game;

class Player {
    
    std::string name;
    char Char;
    int position;
    int cash;
    
    //player's owned properties
    Square * properties[28];
    int numberOfProperty;
    
    //count player owned each monopoly
    std::map<std::string, int> propertyList;
    
    //in DC Tims line
    bool timMode;
    int inTims;
    
    bool isbankrupt;
    
    //total Roll Up the Rim cup
    static int totalcups;
    
    int ownedcup;
    
public:
    Player(std::string name, char Char, int position, int cash,int ownedcup);

    std::string getName();
    char getChar();
    int getposition();
    void setPosition(int p);
    int getBalance();
    int getTotalProperty();
    bool getTimMode();
    void setTimMode();
    bool getBankruptStatus();
    int getTimTurn();
    int getCup();
    int getTotalCup();
    int getPropertyIndex(int i);
    
    //if the action is "add", add the property to player's owned list
    //if the action is "remove", remove the property from the player's owned list
    void ManageProperty(Square * property, std::string action);
    
    //Move steps
    void takeMovement(int steps);
    
    //Receive/Spend cash
    void cashFlow(int amount);
    
    //print information of owned property
    void printProperty();
    
    //declare bankrupt and set fields
    void bankrupt();
    
    //when player own a new property, update the block count in propertylist
    void addBlock(std::string block);
    
    //when player lose a property, update the block count in propertylist
    void deleteBlock(std::string block);
    
    //count property owned within a monopoly
    int countBlock(std::string block);
    
    //stay in Tims line for n turn
    void stayInTims(int turn=1);
    
    //set fields for player leave Tims line
    void leaveTims();
    
    void useCup();
    void receiveCup();
    
    //if player own the property
    int ownThis(std::string name);
    
    //if the player own the monopoly and has improvement
    bool hasImprove(std::string blockname);
    
    //if the player has sell all improvement and mortgage all properties
    bool canBankrupt();

    ~Player();

};

#endif /* defined(__bb7k__player__) */
