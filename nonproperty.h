/*
 *  nonproperty.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__nonproperty__
#define __bb7k__nonproperty__

#include "square.h"
#include <string>

class NonProperty : public Square {
public:
    
    NonProperty(int index, std::string name);
    
    std::string getOwner();
    void setOwner(std::string player);
    int getTuition();
    std::string getBlock();
    int getPurchaseCost();
    int getImproveCost();
    int getImprovement();
    bool getMortgageStatus();
    void setMortgageStatus();
    void improve(int change = 1);
    
    ~NonProperty() {
    };
};
#endif /* defined(__bb7k__nonproperty__) */
