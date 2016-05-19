/*
 *  square.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__square__
#define __bb7k__square__

#include <string>

class Square {
    
    std::string name;
    //position of the square
    int index;
    bool isOwnable;
public:
    Square(std::string name, bool ownable, int index);
    std::string getName();
    int getIndex();
    bool getOwnable();
    virtual void setOwner(std::string player) = 0;
    virtual bool getMortgageStatus() = 0;
    virtual void setMortgageStatus() = 0;
    virtual std::string getOwner() = 0;
    virtual int getTuition() = 0;
    virtual int getPurchaseCost() = 0;
    virtual int getImproveCost() = 0;
    virtual int getImprovement() = 0;
    virtual std::string getBlock() = 0;
    virtual void improve(int change = 1) = 0;
    virtual ~Square();
};

#endif /* defined(__bb7k__square__) */
