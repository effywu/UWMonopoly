//
/*
 *  building.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "building.h"

using namespace std;

Building::Building(int index, string name, string owner, int purchaseCost, string block)
: Square(name, true, index), owner(owner), purchaseCost(purchaseCost), isMortgaged(false), block(block) {
}

string Building::getOwner() {
    return owner;
}

void Building::setOwner(string playerName) {
    owner = playerName;
}

int Building::getPurchaseCost() {
    return purchaseCost;
}

string Building::getBlock() {
    return block;
}

bool Building::getMortgageStatus() {
    return isMortgaged;
}

void Building::setMortgageStatus() {
    isMortgaged = !isMortgaged;
}

int Building::getImproveCost() {
    return 0;
}

int Building::getImprovement() {
    return 0;
}

void Building::improve(int change) {

}

Building::~Building() {
};