/*
 *  nonproperty.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "nonproperty.h"

using namespace std;

NonProperty::NonProperty(int index, string name) : Square(name, false, index) {
}

string NonProperty::getOwner() {
    return "Bank";
}

void NonProperty::setOwner(string player) {
}

int NonProperty::getTuition() {
    return 0;
}

string NonProperty::getBlock() {
    return "";
}

int NonProperty::getPurchaseCost() {
    return 0;
}

int NonProperty::getImproveCost() {
    return 0;
}

int NonProperty::getImprovement() {
    return 0;
}

bool NonProperty::getMortgageStatus() {
    return 0;
}

void NonProperty::setMortgageStatus() {
}

void NonProperty::improve(int change) {

}




