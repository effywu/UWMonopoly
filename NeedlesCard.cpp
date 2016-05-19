/*
 *  NeedlesCard.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "NeedlesCard.h"

NeedlesCard::NeedlesCard(int change) : changeAmount(change) {};

//Return changeAmount
int NeedlesCard::changeCash() {
    
    return changeAmount;
    
}

NeedlesCard::~NeedlesCard() {};

