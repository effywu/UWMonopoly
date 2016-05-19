/*
 *  View.h
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#ifndef VIEW_H
#define	VIEW_H

class View {
public:
    View();
    virtual void initPlayers(int totalplayers) = 0;
    virtual void setPlayerChar(char * c) = 0;
    virtual void moveto(int building, int player) = 0;
    virtual void setOwner(int building, int player) = 0;
    virtual void Improve(int building, int change) = 0;
    virtual void Mortgage(int building, int change) = 0;
    virtual void Bankruptcy(int player) = 0;
    virtual void printBoard() = 0;
    virtual ~View();
};

#endif	/* VIEW_H */

