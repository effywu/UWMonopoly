/*
 *  SLCCard.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "SLCCard.h"

SLCCard::SLCCard(int tomove) : toMove(tomove) {};

//Return steps to move
int SLCCard::move() {
    
    return toMove;
    
};

SLCCard::~SLCCard() {};

