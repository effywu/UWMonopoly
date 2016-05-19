/*
 *  academicbuilding.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include "academicbuilding.h"

using namespace std;

AcademicBuilding::AcademicBuilding(int index, string name, string owner, int purchaseCost, int improveCost,int tuition1, int tuition2, int tuition3, int tuition4, int tuition5, int tuition6, string block) :Building(index, name, owner, purchaseCost, block), improveCost(improveCost) {
    tuition[0] = tuition1;
    tuition[1] = tuition2;
    tuition[2] = tuition3;
    tuition[3] = tuition4;
    tuition[4] = tuition5;
    tuition[5] = tuition6;
    improvement = 0;
}

int AcademicBuilding::getTuition() {
    return tuition[improvement];
}

int AcademicBuilding::getImproveCost() {
    return improveCost;
}

int AcademicBuilding::getImprovement() {
    return improvement;
}

//Improve the building if change>0
//    improve(2)-> improvement increase 2
//Decrease the improvement if change<=0
//    improve(-1)-> improvement decrease 1
void AcademicBuilding::improve(int change) {
    if (change > 0) {
        improvement+=change;
    } else {
        improvement--;
    }
}

AcademicBuilding::~AcademicBuilding() {
}


