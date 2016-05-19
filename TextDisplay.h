/*
 *  TextDisplay.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef TEXTDISPLAY_H
#define	TEXTDISPLAY_H

#include "View.h"

class TextDisplay : public View {
    
    char ** board;
    int players;
    
    //player's characters
    char * playerchars;
    
    //player's current position
    int * playerposs;
    
public:
    
    TextDisplay();
    
    //Initialize players characters array and
    //set current position to 0
    void initPlayers(int totalplayers);
    
    //Set player's initial position 0 in the board
    void setPlayerChar(char * c);
    
    //Move player to the new position
    void moveto(int building, int player);
    
    //Set new owner of the building
    void setOwner(int building, int player);
    
    //If the change>0, improve the building
    //If the change<0, remove the improve
    void Improve(int building, int change);
    
    //If the change>0, mortgage the building
    //If the change<0, unmortgage the building
    void Mortgage(int building, int change);
    
    //Remove the player's position from the board
    void Bankruptcy(int player);
    
    //Print board
    void printBoard();
    
    ~TextDisplay();
};

#endif	/* TEXTDISPLAY_H */

