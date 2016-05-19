/*
 *  residence.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__residence__
#define __bb7k__residence__

#include <string>
#include "building.h"

class Residence : public Building {
public:
    Residence(int index, std::string name, std::string owner, int purchaseCost, std::string block = "Residence");
    int getTuition();
    ~Residence();
};


#endif /* defined(__bb7k__residence__) */
