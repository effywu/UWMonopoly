/*
 *  academicbuilding.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__academicbuilding__
#define __bb7k__academicbuilding__

#include <string>
#include "building.h"

class AcademicBuilding : public Building {
    
    //tuition for each improvement level
    int tuition [6];
    int improveCost;
    
    //improvement level
    int improvement;
public:
    AcademicBuilding(int index, std::string name, std::string owner, int purchaseCost,int improveCost, int tuition1, int tuition2, int tuition3, int tuition4, int tuition5,int tuition6, std::string block);
    int getTuition();
    int getImprovement();
    int getImproveCost();
    
    //if change<0, decrease the improvement level
    //if change>0, increase the improvement by change
    void improve(int change = 1);
    
    ~AcademicBuilding();
};

#endif /* defined(__bb7k__academicbuilding__) */
