/*
 *  gym.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__gym__
#define __bb7k__gym__

#include <string>
#include "building.h"


class Gym : public Building {
public:
    Gym(int index, std::string name, std::string owner, int purchaseCost, std::string block = "Gym");
    int getTuition();
    ~Gym();
};


#endif /* defined(__bb7k__gym__) */
