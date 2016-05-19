/*
 *  gamenotification.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef __bb7k__gamenotification__
#define __bb7k__gamenotification__

class GameNotification {
public:
    virtual void notify(int player, int newPosition) = 0;
    virtual void notifyNewOwner(int building, int newOwner) = 0;
    virtual void notifyImprove(int building, int change = 1) = 0;
    virtual void notifyMortgage(int building, int change = 1) = 0;
    virtual void notifyBankruptcy(int player) = 0;
    virtual void notifyDoubles()=0;
    virtual void printBoard() = 0;
    virtual ~GameNotification() {
    };
};
#endif /* defined(__bb7k__gamenotification__) */
