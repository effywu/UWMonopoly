/*
 *  TextDisplay.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "TextDisplay.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor:
// Initialize the play board for the games
TextDisplay::TextDisplay() {

    board = new char*[56];
    
    //loop for initialize each row
    for (int i = 0; i < 56; i++) {
        board[i] = new char [89];
    };// for
    
    string original = "-----------------------------------------------------------------------------------------";
    original += "|Goose  |       |NEEDLES|       |       |V1     |       |       |CIF    |       |GO TO  |";
    original += "|NESTING|-------|HALL   |-------|-------|       |-------|-------|       |-------|TIMS   |";
    original += "|       |EV1    |       |EV2    |EV3    |       |PHYS   |B1     |       |B2     |       |";
    original += "|       |       |       |       |       |       |       |       |       |       |       |";
    original += "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
    original += "|       |                                                                       |       |";
    original += "|-------|                                                                       |-------|";
    original += "|OPT    |                                                                       |EIT    |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|       |                                                                       |       |";
    original += "|-------|                                                                       |-------|";
    original += "|BMH    |                                                                       |ESC    |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|SLC    |                                                                       |SLC    |";
    original += "|       |                                                                       |       |";
    original += "|       |                                                                       |       |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|       |                                                                       |       |";
    original += "|-------|                                                                       |-------|";
    original += "|LHI    |                                                                       |C2     |";
    original += "|       |        ________________________________________________               |       |";
    original += "|_______|        |                                              |               |_______|";
    original += "|UWP    |        |    ###    ###    #####    ###    ###    ###  |               |REV    |";
    original += "|       |        |    #  #   #  #      #    #   #  #   #  #   # |               |       |";
    original += "|       |        |    ####   ####     #     #   #  #   #  #   # |               |       |";
    original += "|       |        |    #   #  #   #   #      #   #  #   #  #   # |               |       |";
    original += "|_______|        |    ####   ####   #        ###    ###    ###  |               |_______|";
    original += "|       |        |______________________________________________|               |NEEDLES|";
    original += "|-------|                                                                       |HALL   |";
    original += "|CPH    |                                                                       |       |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|       |                                                                       |       |";
    original += "|-------|                                                                       |-------|";
    original += "|DWE    |                                                                       |MC     |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|PAC    |                                                                       |COOP   |";
    original += "|       |                                                                       |FEE    |";
    original += "|       |                                                                       |       |";
    original += "|       |                                                                       |       |";
    original += "|_______|                                                                       |_______|";
    original += "|       |                                                                       |       |";
    original += "|-------|                                                                       |-------|";
    original += "|RCH    |                                                                       |DC     |";
    original += "|       |                                                                       |       |";
    original += "|_______|_______________________________________________________________________|_______|";
    original += "|DC Tims|       |       |NEEDLES|       |MKV    |TUITION|       |SLC    |       |COLLECT|";
    original += "|Line   |-------|-------|HALL   |-------|       |       |-------|       |-------|OSAP   |";
    original += "|       |HH     |PAS    |       |ECH    |       |       |ML     |       |AL     |       |";
    original += "|       |       |       |       |       |       |       |       |       |       |       |";
    original += "|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|_______|";
    
    //loop for set char in the 2D Array
    for (int i = 0, c = 0; i < 56; i++) {
        for (int j = 0; j < 89; j++) {
            board[i][j] = original[c];
            c++;
        };
    };// for
    
}// Constructor

//Initialize players and set current position at 0
void TextDisplay::initPlayers(int totalplayers) {

    players = totalplayers;
    playerchars = new char [totalplayers];
    playerposs = new int [totalplayers];
    
    //loop for set position of each players
    for (int i = 0; i < totalplayers; i++) {
        playerposs[i] = 0;
    };// for
    
}// initPlayers

// Set player's initial position on the board
void TextDisplay::setPlayerChar(char * c) {
    int posToChange = 82;
    
    //loop to set position for each players
    for (int i = 0; i < players; i++) {
        playerchars[i] = *(c + i);
        while (board[55][posToChange] != '_') {
            posToChange++;
        };
        board[55][posToChange] = playerchars[i];
    }; //for
    
}; //setPlayerChar

// move player to a new position
void TextDisplay::moveto(int building, int player) {

    int currentPosition = playerposs[player];
    char playerChar = playerchars[player];
    
    //Un set the previous position for the player
    
    if (currentPosition <= 10) { //if position <=10
        int posToChange = (10 - currentPosition)*8 + 2;
        
        //loop to find the char to change
        while (board[55][posToChange] != playerChar) {
            posToChange++;
        };
        
        board[55][posToChange] = '_';
        
    } else if (currentPosition <= 30 && currentPosition >= 20) { // if 20<=position<=30
        int posToChange = (currentPosition - 20)*8 + 2;
        
        while (board[5][posToChange] != playerChar) {
            posToChange++;
        };
        
        board[5][posToChange] = '_';
        
    } else if (currentPosition < 20 && currentPosition > 10) { // if 10<position<20
        
        int rowToChange = 55 - (currentPosition - 10)*5;
        int posToChange = 2;
        
        while (board[rowToChange][posToChange] != playerChar) {
            posToChange++;
        };
        
        board[rowToChange][posToChange] = '_';
        
    } else { //if position>30
        int rowToChange = 5 + (currentPosition - 30)*5;
        int posToChange = 82;
        
        while (board[rowToChange][posToChange] != playerChar) {
            posToChange++;
        };
        
        board[rowToChange][posToChange] = '_';
    };
    
    // set player's char to the current position
    if (building <= 10) { // if position<=10
        int posToChange = (10 - building)*8 + 2;
        
        //loop to find available space to display player's char
        while (board[55][posToChange] != '_') {
            posToChange++;
        };
        
        board[55][posToChange] = playerChar;
        
    } else if (building <= 30 && building >= 20) { // if 20<=position<=30
        int posToChange = (building - 20)*8 + 2;
        
        while (board[5][posToChange] != '_') {
            posToChange++;
        };
        
        board[5][posToChange] = playerChar;
        
    } else if (building < 20 && building > 10) { // if 10<position<20
        
        int rowToChange = 55 - (building - 10)*5;
        int posToChange = 2;
        
        while (board[rowToChange][posToChange] != '_') {
            posToChange++;
        };
        
        board[rowToChange][posToChange] = playerChar;
        
    } else { // if position>30
        int rowToChange = 5 + (building - 30)*5;
        int posToChange = 82;
        while (board[rowToChange][posToChange] != '_') {
            posToChange++;
        };
        board[rowToChange][posToChange] = playerChar;
    };
    playerposs[player] = building;
}; //tomove

// set the new owner of the building:
//   ie. display ( owner )
void TextDisplay::setOwner(int building, int p) {

    char playerChar = playerchars[p];
    
    if (building <= 10) {
        int posToChange = (10 - building)*8 + 2;
        board[54][posToChange] = '(';
        board[54][posToChange + 2] = playerChar;
        board[54][posToChange + 4] = ')';
    } else if (building <= 30 && building >= 20) {
        int posToChange = (building - 20)*8 + 2;
        board[4][posToChange] = '(';
        board[4][posToChange + 2] = playerChar;
        board[4][posToChange + 4] = ')';
    } else if (building < 20 && building > 10) {
        int rowToChange = 54 - (building - 10)*5;
        int posToChange = 2;
        board[rowToChange][posToChange] = '(';
        board[rowToChange][posToChange + 2] = playerChar;
        board[rowToChange][posToChange + 4] = ')';
    } else {
        int rowToChange = 4 + (building - 30)*5;
        int posToChange = 82;

        board[rowToChange][posToChange] = '(';
        board[rowToChange][posToChange + 2] = playerChar;
        board[rowToChange][posToChange + 4] = ')';
        ;
    };
}; //setOwner

//Improve the building if change >0
//     ie. 'I'->'II'
//Decreaase the improvement if change<0
//     ie. 'II'->'I'
void TextDisplay::Improve(int building, int change) {
    
    if (change > 0) { //Improve the building
        if (building <= 10) {
            int posToChange = (10 - building)*8 + 2;
            while (board[51][posToChange] != ' ') {
                posToChange++;
            };
            board[51][posToChange] = 'I';

        } else if (building <= 30 && building >= 20) {
            int posToChange = (building - 20)*8 + 2;
            while (board[1][posToChange] != ' ') {
                posToChange++;
            };
            board[1][posToChange] = 'I';

        } else if (building < 20 && building > 10) {
            int rowToChange = 51 - (building - 10)*5;
            int posToChange = 2;
            while (board[rowToChange][posToChange] != ' ') {
                posToChange++;
            };
            board[rowToChange][posToChange] = 'I';

        } else {
            int rowToChange = 1 + (building - 30)*5;
            int posToChange = 82;
            while (board[rowToChange][posToChange] != ' ') {
                posToChange++;
            };
            board[rowToChange][posToChange] = 'I';
        };
        
    } else { //Decrease the improvement

        if (building <= 10) {
            int posToChange = (10 - building)*8 + 6;
            while (board[51][posToChange] != 'I') {
                posToChange--;
            };
            board[51][posToChange] = ' ';

        } else if (building <= 30 && building >= 20) {
            int posToChange = (building - 20)*8 + 6;
            while (board[1][posToChange] != 'I') {
                posToChange--;
            };
            board[1][posToChange] = ' ';

        } else if (building < 20 && building > 10) {
            int rowToChange = 51 - (building - 10)*5;
            int posToChange = 6;
            while (board[rowToChange][posToChange] != 'I') {
                posToChange--;
            };
            board[rowToChange][posToChange] = ' ';

        } else {
            int rowToChange = 1 + (building - 30)*5;
            int posToChange = 86;
            while (board[rowToChange][posToChange] != 'I') {
                posToChange--;
            };
            board[rowToChange][posToChange] = ' ';
        };

    }
}; //Improve

//Mortgage the building if change>0
//Unmortgage the building if change<0
// ie. mortgaged building will display:
//    / owner/
//     unmortgaged building will display:
//    ( owner )
void TextDisplay::Mortgage(int building, int change) {
    
    char changeLeft;
    char changeRight;
    if (change > 0) {
        changeLeft = '/';
        changeRight = '/';
    } else {
        changeLeft = '(';
        changeRight = ')';
    }
    if (building <= 10) {
        int posToChange = (10 - building)*8 + 2;
        board[54][posToChange] = changeLeft;
        board[54][posToChange + 4] = changeRight;
    } else if (building <= 30 && building >= 20) {
        int posToChange = (building - 20)*8 + 2;
        board[4][posToChange] = changeLeft;
        board[4][posToChange + 4] = changeRight;
    } else if (building < 20 && building > 10) {
        int rowToChange = 54 - (building - 10)*5;
        int posToChange = 2;
        board[rowToChange][posToChange] = changeLeft;
        board[rowToChange][posToChange + 4] = changeRight;
    } else {
        int rowToChange = 4 + (building - 30)*5;
        int posToChange = 82;
        board[rowToChange][posToChange] = changeLeft;
        board[rowToChange][posToChange + 4] = changeRight;
        ;
    };
}; //Mortgage

// Clear the player's position on board
void TextDisplay::Bankruptcy(int player) {
    
    int currentPosition = playerposs[player];
    char playerChar = playerchars[player];

    if (currentPosition <= 10) {
        int posToChange = (10 - currentPosition)*8 + 2;
        while (board[55][posToChange] != playerChar) {
            posToChange++;
        };

        board[55][posToChange] = '_';
    } else if (currentPosition <= 30 && currentPosition >= 20) {
        int posToChange = (currentPosition - 20)*8 + 2;
        while (board[5][posToChange] != playerChar) {
            posToChange++;
        };
        board[5][posToChange] = '_';
    } else if (currentPosition < 20 && currentPosition > 10) {
        int rowToChange = 55 - (currentPosition - 10)*5;
        int posToChange = 2;
        while (board[rowToChange][posToChange] != playerChar) {
            posToChange++;
        };
        board[rowToChange][posToChange] = '_';
    } else {
        int rowToChange = 5 + (currentPosition - 30)*5;
        int posToChange = 82;
        while (board[rowToChange][posToChange] != playerChar) {
            posToChange++;
        };
        board[rowToChange][posToChange] = '_';
    };
}; //Bankruptcy

//Print the board
void TextDisplay::printBoard() {
    
    for (int i = 0; i < 56; i++) {
        for (int j = 0; j < 89; j++) {
            cout << board[i][j];
        };
        cout << endl;
    }
    
}; //printBoard

TextDisplay::~TextDisplay() {
    for (int i = 0; i < 56; i++) {

        delete [] board[i];
    };
    delete [] board;
    delete [] playerchars;
    delete [] playerposs;
}

