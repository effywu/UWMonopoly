/*
 *  SLCCard.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef SLCCARD_H
#define	SLCCARD_H

class SLCCard {
    int toMove;
public:
    SLCCard(int tomove);
    
    //return steps to move
    int move();
    
    ~SLCCard();

};

#endif	/* SLCCARD_H */

