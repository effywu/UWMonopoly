/*
 *  gym.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "gym.h"

using namespace std;

Gym::Gym(int index, string name, string owner, int purchaseCost, string block) : Building(index, name, owner, purchaseCost, block) {
}

int Gym::getTuition() {
    cout << "( Two dices are rolled )" << endl;
    srand(time(NULL));
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    cout << "(You have rolled: " << dice1 << " + " << dice2 << " = " << dice1 + dice2 << " )" << endl;
    return dice1 + dice2;
}

Gym::~Gym() {
};
