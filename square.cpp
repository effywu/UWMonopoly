/*
 *  square.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "square.h"

using namespace::std;

Square::Square(string name, bool ownable,int index) : name(name),index(index),isOwnable(ownable) {};

string Square::getName() {
    return name;
}

int Square::getIndex(){
    return index;
}

bool Square::getOwnable(){
    return isOwnable;
}

Square::~Square(){}