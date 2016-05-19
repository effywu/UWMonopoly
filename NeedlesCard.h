/*  
 *  NeedlesCard.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef NEEDLESCARD_H
#define	NEEDLESCARD_H

class NeedlesCard {
    int changeAmount;
public:
    NeedlesCard(int change);
    
    //return changeAmount
    int changeCash();
    ~NeedlesCard();
};

#endif	/* NEEDLESCARD_H */

