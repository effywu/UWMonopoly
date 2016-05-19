/*
 *  building.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__building__
#define __bb7k__building__

#include <string>
#include "square.h"

class Building : public Square {
    
    std::string owner;
    int purchaseCost;
    bool isMortgaged;
    
    //the monopoly
    std::string block;
public:
    
    Building(int index,std::string name, std::string owner, int purchaseCost,std::string block);
    std::string getOwner();
    void setOwner(std::string playerName);
    int getPurchaseCost();
    std::string getBlock();
    bool getMortgageStatus();
    void setMortgageStatus();
    
    virtual int getTuition() = 0;
    int getImproveCost();
    int getImprovement();
    void improve(int change=1); 
    virtual ~Building();
};

#endif /* defined(__bb7k__building__) */
