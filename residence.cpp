/*
 *  residence.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "residence.h"

using namespace std;

Residence::Residence(int index, string name, string owner, int purchaseCost, string block) : Building(index, name, owner, purchaseCost, block) {
}

int Residence::getTuition() {
    return 25;
}

Residence::~Residence() {
};

