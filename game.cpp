/*
 *  game.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <time.h>

#include "game.h"
#include "academicbuilding.h"
#include "nonproperty.h"
#include "residence.h"
#include "gym.h"

using namespace std;

//Constructor for new games
Game::Game(int numOfP, GameNotification *noti, ifstream &in): NumberOfPlayer(numOfP),validPlayer(numOfP), notification(noti), countDoubles(0){
    //initiate the 40 square:
    square[0] = new NonProperty(0, "COLLECT OSAP");
    //Academic Buildings:
    square[1] = new AcademicBuilding(1, "AL", "Bank", 40, 50, 2, 10, 30, 90, 160, 250, "Arts1");
    square[3] = new AcademicBuilding(3, "ML", "Bank", 60, 50, 4, 20, 60, 180, 320, 450, "Arts1");
    square[6] = new AcademicBuilding(6, "ECH", "Bank", 100, 50, 6, 30, 90, 270, 400, 550, "Arts2");
    square[8] = new AcademicBuilding(8, "PAS", "Bank", 100, 50, 6, 30, 90, 270, 400, 550, "Arts2");
    square[9] = new AcademicBuilding(9, "HH", "Bank", 120, 50, 8, 40, 100, 300, 450, 600, "Arts2");
    square[11] = new AcademicBuilding(11, "RCH", "Bank", 140, 100, 10, 50, 150, 450, 625, 750, "Eng");
    square[13] = new AcademicBuilding(13, "DWE", "Bank", 140, 100, 10, 50, 150, 450, 625, 750, "Eng");
    square[14] = new AcademicBuilding(14, "CPH", "Bank", 160, 100, 12, 60, 180, 500, 700, 900, "Eng");
    square[16] = new AcademicBuilding(16, "LHI", "Bank", 180, 100, 14, 70, 200, 550, 750, 950, "Health");
    square[18] = new AcademicBuilding(18, "BMH", "Bank", 180, 100, 14, 70, 200, 550, 750, 950, "Health");
    square[19] = new AcademicBuilding(19, "OPT", "Bank", 200, 100, 16, 80, 220, 600, 800, 1000, "Health");
    square[21] = new AcademicBuilding(21, "EV1", "Bank", 220, 150, 18, 90, 250, 700, 875, 1050, "Env");
    square[23] = new AcademicBuilding(23, "EV2", "Bank", 220, 150, 18, 90, 250, 700, 875, 1050, "Env");
    square[24] = new AcademicBuilding(24, "EV3", "Bank", 240, 150, 20, 100, 300, 750, 925, 1100, "Env");
    square[26] = new AcademicBuilding(26, "PHYS", "Bank", 260, 150, 22, 110, 330, 800, 975, 1150, "Sci1");
    square[27] = new AcademicBuilding(27, "B1", "Bank", 260, 150, 22, 110, 330, 800, 975, 1150, "Sci1");
    square[29] = new AcademicBuilding(29, "B2", "Bank", 280, 150, 24, 120, 360, 850, 1025, 1200, "Sci1");
    square[31] = new AcademicBuilding(31, "EIT", "Bank", 300, 200, 26, 130, 390, 900, 1100, 1275, "Sci2");
    square[32] = new AcademicBuilding(32, "ESC", "Bank", 300, 200, 26, 130, 390, 900, 1100, 1275, "Sci2");
    square[34] = new AcademicBuilding(34, "C2", "Bank", 320, 200, 28, 150, 450, 1000, 1200, 1400, "Sci2");
    square[37] = new AcademicBuilding(37, "MC", "Bank", 350, 200, 35, 175, 500, 1100, 1300, 1500, "Math");
    square[39] = new AcademicBuilding(39, "DC", "Bank", 400, 200, 50, 200, 600, 1400, 1700, 2000, "Math");
    //SLC:
    square[2] = new NonProperty(2, "SLC");
    square[17] = new NonProperty(17, "SLC");
    square[33] = new NonProperty(33, "SLC");
    //Needle Hall:
    square[7] = new NonProperty(7, "NEEDLES HALL");
    square[22] = new NonProperty(22, "NEEDLES HALL");
    square[36] = new NonProperty(36, "NEEDLES HALL");
    //DC Tims Line:
    square[10] = new NonProperty(10, "DC Tims Line");
    //Goose Nesting:
    square[20] = new NonProperty(20, "Goose Nesting");
    //Go to Tims:
    square[30] = new NonProperty(30, "GO TO TIMS");
    //Tuition:
    square[4] = new NonProperty(4, "TUITION");
    //Coop:
    square[38] = new NonProperty(38, "COOP FEE");
    //Residence:
    square[5] = new Residence(5, "MKV", "Bank", 200);
    square[15] = new Residence(15, "UWP", "Bank", 200);
    square[25] = new Residence(25, "V1", "Bank", 200);
    square[35] = new Residence(35, "REV", "Bank", 200);
    //Gym:
    square[12] = new Gym(12, "PAC", "Bank", 150);
    square[28] = new Gym(28, "CIF", "Bank", 150);
    
    //SLCCARDS
    
    //Back 3
    slccards[0] = new SLCCard(-3);
    slccards[1] = new SLCCard(-3);
    slccards[2] = new SLCCard(-3);
    //Back 2
    slccards[3] = new SLCCard(-2);
    slccards[4] = new SLCCard(-2);
    slccards[5] = new SLCCard(-2);
    slccards[6] = new SLCCard(-2);
    //Back 1
    slccards[7] = new SLCCard(-1);
    slccards[8] = new SLCCard(-1);
    slccards[9] = new SLCCard(-1);
    slccards[10] = new SLCCard(-1);
    //forward 1
    slccards[11] = new SLCCard(1);
    slccards[12] = new SLCCard(1);
    slccards[13] = new SLCCard(1);
    //forward 2
    slccards[14] = new SLCCard(2);
    slccards[15] = new SLCCard(2);
    slccards[16] = new SLCCard(2);
    slccards[17] = new SLCCard(2);
    //forward 3
    slccards[18] = new SLCCard(3);
    slccards[19] = new SLCCard(3);
    slccards[20] = new SLCCard(3);
    slccards[21] = new SLCCard(2);
    //Go to Tims Line
    slccards[22] = new SLCCard(10);
    //Advance to collect OSAP
    slccards[23] = new SLCCard(0);

    //NeedlesCards
    //-200
    needlescards[0] = new NeedlesCard(-200);
    //-100
    needlescards[1] = new NeedlesCard(-100);
    needlescards[2] = new NeedlesCard(-100);
    //-50
    needlescards[3] = new NeedlesCard(-50);
    needlescards[4] = new NeedlesCard(-50);
    needlescards[5] = new NeedlesCard(-50);
    //25
    needlescards[6] = new NeedlesCard(25);
    needlescards[7] = new NeedlesCard(25);
    needlescards[8] = new NeedlesCard(25);
    needlescards[9] = new NeedlesCard(25);
    needlescards[10] = new NeedlesCard(25);
    needlescards[11] = new NeedlesCard(25);
    //50
    needlescards[12] = new NeedlesCard(50);
    needlescards[13] = new NeedlesCard(50);
    needlescards[14] = new NeedlesCard(50);
    //100
    needlescards[15] = new NeedlesCard(100);
    needlescards[16] = new NeedlesCard(100);
    //200
    needlescards[17] = new NeedlesCard(200);

    //loop to read information for each players
    for (int i = 0; i < numOfP; i++) {
        string tmpname;
        char tmpchar;
        int cup;
        int tmpmoney;
        int tmpposition;
        in >> tmpname >> tmpchar >> cup >> tmpmoney>>tmpposition;
        player[i] = new Player(tmpname, tmpchar, tmpposition, tmpmoney, cup);
        int stayintim;
        int turn;
        if (tmpposition == 10) {
            in>>stayintim;
            if (stayintim != 0) {
                in>>turn;
                player[i]->setTimMode();
                if (turn != 0) {
                    player[i]->stayInTims(turn);
                };
            };
        };
    };

}

//Constructor for load games
Game::Game(int numOfP, GameNotification *noti, bool generatePlayer) : NumberOfPlayer(numOfP),  validPlayer(numOfP),notification(noti), countDoubles(0) {
    //initiate the 40 square:
    square[0] = new NonProperty(0, "COLLECT OSAP");
    //Academic Buildings:
    square[1] = new AcademicBuilding(1, "AL", "Bank", 40, 50, 2, 10, 30, 90, 160, 250, "Arts1");
    square[3] = new AcademicBuilding(3, "ML", "Bank", 60, 50, 4, 20, 60, 180, 320, 450, "Arts1");
    square[6] = new AcademicBuilding(6, "ECH", "Bank", 100, 50, 6, 30, 90, 270, 400, 550, "Arts2");
    square[8] = new AcademicBuilding(8, "PAS", "Bank", 100, 50, 6, 30, 90, 270, 400, 550, "Arts2");
    square[9] = new AcademicBuilding(9, "HH", "Bank", 120, 50, 8, 40, 100, 300, 450, 600, "Arts2");
    square[11] = new AcademicBuilding(11, "RCH", "Bank", 140, 100, 10, 50, 150, 450, 625, 750, "Eng");
    square[13] = new AcademicBuilding(13, "DWE", "Bank", 140, 100, 10, 50, 150, 450, 625, 750, "Eng");
    square[14] = new AcademicBuilding(14, "CPH", "Bank", 160, 100, 12, 60, 180, 500, 700, 900, "Eng");
    square[16] = new AcademicBuilding(16, "LHI", "Bank", 180, 100, 14, 70, 200, 550, 750, 950, "Health");
    square[18] = new AcademicBuilding(18, "BMH", "Bank", 180, 100, 14, 70, 200, 550, 750, 950, "Health");
    square[19] = new AcademicBuilding(19, "OPT", "Bank", 200, 100, 16, 80, 220, 600, 800, 1000, "Health");
    square[21] = new AcademicBuilding(21, "EV1", "Bank", 220, 150, 18, 90, 250, 700, 875, 1050, "Env");
    square[23] = new AcademicBuilding(23, "EV2", "Bank", 220, 150, 18, 90, 250, 700, 875, 1050, "Env");
    square[24] = new AcademicBuilding(24, "EV3", "Bank", 240, 150, 20, 100, 300, 750, 925, 1100, "Env");
    square[26] = new AcademicBuilding(26, "PHYS", "Bank", 260, 150, 22, 110, 330, 800, 975, 1150, "Sci1");
    square[27] = new AcademicBuilding(27, "B1", "Bank", 260, 150, 22, 110, 330, 800, 975, 1150, "Sci1");
    square[29] = new AcademicBuilding(29, "B2", "Bank", 280, 150, 24, 120, 360, 850, 1025, 1200, "Sci1");
    square[31] = new AcademicBuilding(31, "EIT", "Bank", 300, 200, 26, 130, 390, 900, 1100, 1275, "Sci2");
    square[32] = new AcademicBuilding(32, "ESC", "Bank", 300, 200, 26, 130, 390, 900, 1100, 1275, "Sci2");
    square[34] = new AcademicBuilding(34, "C2", "Bank", 320, 200, 28, 150, 450, 1000, 1200, 1400, "Sci2");
    square[37] = new AcademicBuilding(37, "MC", "Bank", 350, 200, 35, 175, 500, 1100, 1300, 1500, "Math");
    square[39] = new AcademicBuilding(39, "DC", "Bank", 400, 200, 50, 200, 600, 1400, 1700, 2000, "Math");
    //SLC:
    square[2] = new NonProperty(2, "SLC");
    square[17] = new NonProperty(17, "SLC");
    square[33] = new NonProperty(33, "SLC");
    //Needle Hall:
    square[7] = new NonProperty(7, "NEEDLES HALL");
    square[22] = new NonProperty(22, "NEEDLES HALL");
    square[36] = new NonProperty(36, "NEEDLES HALL");
    //DC Tims Line:
    square[10] = new NonProperty(10, "DC Tims Line");
    //Goose Nesting:
    square[20] = new NonProperty(20, "Goose Nesting");
    //Go to Tims:
    square[30] = new NonProperty(30, "GO TO TIMS");
    //Tuition:
    square[4] = new NonProperty(4, "TUITION");
    //Coop:
    square[38] = new NonProperty(38, "COOP FEE");
    //Residence:
    square[5] = new Residence(5, "MKV", "Bank", 200);
    square[15] = new Residence(15, "UWP", "Bank", 200);
    square[25] = new Residence(25, "V1", "Bank", 200);
    square[35] = new Residence(35, "REV", "Bank", 200);
    //Gym:
    square[12] = new Gym(12, "PAC", "Bank", 150);
    square[28] = new Gym(28, "CIF", "Bank", 150);

    //SLCCards
    //Back 3
    slccards[0] = new SLCCard(-3);
    slccards[1] = new SLCCard(-3);
    slccards[2] = new SLCCard(-3);
    //Back 2
    slccards[3] = new SLCCard(-2);
    slccards[4] = new SLCCard(-2);
    slccards[5] = new SLCCard(-2);
    slccards[6] = new SLCCard(-2);
    //Back 1
    slccards[7] = new SLCCard(-1);
    slccards[8] = new SLCCard(-1);
    slccards[9] = new SLCCard(-1);
    slccards[10] = new SLCCard(-1);
    //forward 1
    slccards[11] = new SLCCard(1);
    slccards[12] = new SLCCard(1);
    slccards[13] = new SLCCard(1);
    //forward 2
    slccards[14] = new SLCCard(2);
    slccards[15] = new SLCCard(2);
    slccards[16] = new SLCCard(2);
    slccards[17] = new SLCCard(2);
    //forward 3
    slccards[18] = new SLCCard(3);
    slccards[19] = new SLCCard(3);
    slccards[20] = new SLCCard(3);
    slccards[21] = new SLCCard(2);
    //Go to Tims Line
    slccards[22] = new SLCCard(10);
    //Advance to collect OSAP
    slccards[23] = new SLCCard(0);
    
    //NeedlesCards
    //-200
    needlescards[0] = new NeedlesCard(-200);
    //-100
    needlescards[1] = new NeedlesCard(-100);
    needlescards[2] = new NeedlesCard(-100);
    //-50
    needlescards[3] = new NeedlesCard(-50);
    needlescards[4] = new NeedlesCard(-50);
    needlescards[5] = new NeedlesCard(-50);
    //25
    needlescards[6] = new NeedlesCard(25);
    needlescards[7] = new NeedlesCard(25);
    needlescards[8] = new NeedlesCard(25);
    needlescards[9] = new NeedlesCard(25);
    needlescards[10] = new NeedlesCard(25);
    needlescards[11] = new NeedlesCard(25);
    //50
    needlescards[12] = new NeedlesCard(50);
    needlescards[13] = new NeedlesCard(50);
    needlescards[14] = new NeedlesCard(50);
    //100
    needlescards[15] = new NeedlesCard(100);
    needlescards[16] = new NeedlesCard(100);
    //200
    needlescards[17] = new NeedlesCard(200);

    if (generatePlayer) { // read from cin for information of players

        string selected = "";
        string available = "| Goose(G) | GRT Bus(B) | Tim Hortons Doughnut(D)| Professor(P) | Student(S) | Money($) | Laptop(L) | Pink tie(T) |";
        for (int i = 0; i < NumberOfPlayer; i++) {
            cout << "Please Enter the Name of Player " << i + 1 << ":" << endl;

            string tmpname;
            cin>>tmpname;
            char tmpchar;

            while (true) {
                cout << "Available characters:" << endl;
                cout << available << endl;
                cout << "Please Enter the Character you wish to represent: ( G/B/D/P/S/$/L/T )" << endl;

                cin>>tmpchar;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    continue;
                };
                if (tmpchar != 'G' && tmpchar != 'B' && tmpchar != 'D' && tmpchar != 'P'
                        && tmpchar != 'S' && tmpchar != '$' && tmpchar != 'L' && tmpchar != 'T') {
                    cout << "( Invalid character. )" << endl;
                    continue;
                } else {
                    if (selected.find(tmpchar) != string::npos) {
                        cout << "( The character is selected by other." << endl;
                    } else {
                        break;
                    };
                };
            };
            selected += tmpchar;
            available = "";
            if (selected.find('G') == string::npos) {
                available += "| Goose(G) ";
            };
            if (selected.find('B') == string::npos)available += "| GRT Bus(B) ";
            if (selected.find('D') == string::npos)available += "| Tim Hortons Doughnut(D) ";
            if (selected.find('P') == string::npos)available += "| Professor(P) ";
            if (selected.find('S') == string::npos)available += "| Student(S) ";
            if (selected.find('$') == string::npos)available += "| Money($) ";
            if (selected.find('L') == string::npos)available += "| Laptop(L) ";
            if (selected.find('T') == string::npos)available += "| Pink tie(T) ";
            available += " |";
            player[i] = new Player(tmpname, tmpchar, 0, 1500, 0);
        }
    };

}

//read from in file to set owners of building and call notification to display
void Game::initialOwners(ifstream &in) {
    
    //loop to read information for each ownable squares
    for (int i = 0; i < 40; i++) {
        if (square[i]->getOwnable()) {
            string name;
            string owner;
            int improve;
            in >> name >> owner>>improve;
            if (name == square[i]->getName()) {
                if (owner != "BANK") {
                    square[i]->setOwner(owner);
                    int ownerIndex = -1;
                    for (int j = 0; j < NumberOfPlayer; j++) {
                        if (player[j]->getName() == owner) {
                            ownerIndex = j;
                            break;
                        };
                    };
                    player[ownerIndex]->ManageProperty(square[i],"add");
                    notification->notifyNewOwner(i, ownerIndex);
                    if (improve == -1) {
                        square[i]->setMortgageStatus();
                        notification->notifyMortgage(i);
                    } else if (improve > 0) {
                        square[i]->improve(improve);
                        for (int x = 0; x < improve; x++) {
                            notification->notifyImprove(i);
                        };
                    };
                };
            };
        };
    }
}

int Game::getPlayerPosition(int p) {
    return player[p]->getposition();
}

char Game::getPlayerChar(int p) {

    return player[p]->getChar();
}

string Game::getPlayerName(int p) {

    return player[p]->getName();
}

int Game::getValidPlayer() {
    return validPlayer;
}

int Game::getCountDoubles(){
    return countDoubles;
}

//take necessory action when player has landed on the position
// ie. buy the property/pay the rent/move to DC Tims line,etc
void Game::takeAction(int p, int position) {
    if (position == 0) {//Collect OSAP
        pay(p, 200);
        cout << "(You have collected $200 )" << endl;
    } else if (position == 7 || position == 22 || position == 36) {//Needles Hall
        srand(time(NULL));
        
        if (player[p]->getTotalCup() < 4) { //chance to get Cup
            int luck = rand() % 100 + 1;
            if (luck == 100) {
                player[p]->receiveCup();
                return;
            };
        };
        
        int selectedcard = rand() % 18;
        int topay = needlescards[selectedcard]->changeCash();

        if (pay(p, topay)) {
            if (topay < 0) {
                cout << "( Lose $" << -topay << " )" << endl;
            } else {
                cout << "( Collect $" << topay << " )" << endl;
            };

        } else {
            return;
        }

    } else if (position == 2 || position == 17 || position == 33) { //SLC
        srand(time(NULL));
        if (player[p]->getTotalCup() < 4) { //chance to get Cup
            int luck = rand() % 100 + 1;
            if (luck == 100) {
                player[p]->receiveCup();
                return;
            };
        };
        int selectedcard = rand() % 24;
        int tomove = slccards[selectedcard]->move();
        if (tomove == 0) { //Go to Collecto OSAP
            cout << "( Advanced to Collect OSAP )" << endl;
            player[p]->setPosition(0);
            notification->notify(p, player[p]->getposition());
            notification->printBoard();
            takeAction(p, 0);
        } else if (tomove == 10) { // Go to DC Tims line
            takeAction(p, 30);
            return;
        } else {
            if (tomove < 0) {
                cout << "( Back " << -tomove << " )" << endl;
            } else {
                cout << "( Forward " << tomove << " )" << endl;
            }
            int currentpos = player[p]->getposition();
            currentpos += tomove;
            player[p]->setPosition(currentpos);
            notification->notify(p, player[p]->getposition());
            notification->printBoard();

            cout << "(You have landed on: " << square[currentpos]->getName() << " )" << endl;
            if (currentpos == 0) return;
            takeAction(p, currentpos);
        };

    } else if (position == 20) { //Goose Nesting:Nothing happened
        cout << "( You are attacked by geese )" << endl;

    } else if (position == 10) {
        cout << "( You don't need a coffee right now )" << endl;

    } else if (position == 30) {//Go to Tims
        player[p]->setPosition(10);
        cout << "( Go to DC Tims Line )" << endl;
        player[p]->setTimMode();
        notification->notify(p, player[p]->getposition());
        notification->printBoard();
        cout << "( You have moved to DC Tims Line )" << endl;

    } else if (position == 4) {//Tuition

        //choose pay $300 or 10% of money
        cout << "Please choose your option: $300 / 10% of your cash ($300/10%)" << endl;
        cout << "( Your holding cash: $" << player[p]->getBalance() << " )" << endl;

        string option;
        int debt = 0;
        while (true) {
            cin >>option;
            if (option == "$300") {
                debt = 300;
                break;
            } else if (option == "10%") {
                debt = (int) (player[p]->getBalance()) / 10;
                break;
            } else {
                cout << "Please enter a valid command. ( $300 / 10% )" << endl;
            };
        };

        if (pay(p, -debt)) {
            cout << "( You have paid tuition $ " << debt << " )" << endl;
        } else {
            return;
        };

    } else if (position == 38) { //Pay Coop fee

        if (pay(p, -150)) {
            cout << "( You have paid Co-op Fee $150 )" << endl;
        } else {
            return;
        }
    } else { // Academic Building
        
        if (square[position]->getOwner() != "Bank") { // Pay Tuition
            
            if (square[position]->getMortgageStatus()) { // if the building is mortgaged
                cout << "( Lucky! The property is being mortgage! You don't need to pay! )" << endl;
                return;
            };
            
            int debt;
            int ownerIndex;
            
            //loop to get owner index
            for (ownerIndex = 0; ownerIndex < NumberOfPlayer; ownerIndex++) {
                if (player[ownerIndex]->getName() == square[position]->getOwner()) break;
            };

            if (square[position]->getBlock() == "Residence") {
                int count = 0;
                count = player[ownerIndex]->countBlock("Residence");
                debt = 25;
                for (int i = 1; i < count; i++) {
                    debt *= 2;
                };
            } else if (square[position]->getBlock() == "Gym") {
                debt = square[position]->getTuition();
                int count = 0;
                count = player[ownerIndex]->countBlock("Gym");
                if (count == 1) debt *= 4;
                if (count == 2) debt *= 10;
            } else {
                if (canImprove(position)&&(square[position]->getImprovement() == 0)) {
                    debt = square[position]->getTuition()*2;
                } else {
                    debt = square[position]->getTuition();
                };
            };

            if (pay(p, -debt, ownerIndex)) {
                pay(ownerIndex, debt);
                cout << "( You have paid $" << debt << " to " << square[position]->getOwner() << " )" << endl;
            } else {
                return;
            };

        } else { // Player can buy the property
            
            int price = square[position]->getPurchaseCost();
            cout << "( Price of " << square[position]->getName() << " is: $" << price << " )" << endl;
            cout << "( Your holding cash: $" << player[p]->getBalance() << " )" << endl;
            cout << "Do you want to buy it? (y/n)" << endl;
            char c;
            cin>>c;
            if (c == 'y') {
                if (pay(p, -price)) {
                    square[position]->setOwner(player[p]->getName());
                    player[p]->ManageProperty(square[position], "add");
                    notification->notifyNewOwner(position, p);
                    notification->printBoard();
                    cout << "( You have bought " << square[position]->getName() << " )" << endl;
                } else {
                    return;
                };
            } else {

                auction(position);
                notification->printBoard();
            };
        };
    }
}

//Player p need to pay amount to the owner
//when owner is -1, it is paid to Bank
//Return: true if sucess
//        false if bankrupt
bool Game::pay(int p, int amount, int owner) {
    bool succeed = true;
    if (-amount > player[p]->getBalance()) { // if player does not have that much cash
        succeed = finance(p, -amount, owner);
    };
    if (succeed) {
        player[p]->cashFlow(amount);
        return true;
    } else {
        return false;
    }
}

//If player does not have enough money to pay
//provide options for the player
//Return: true if sucess
//        false if bankrupt
bool Game::finance(int p, int amount, int owner) {
    
    cout << "You don't have $" << amount << endl;
    string option;
    while (true) {
        if (player[p]->getBalance() >= amount){
            cout<<"( You have enough cash to pay $"<<amount<<" now )"<<endl;
            return true;
        };
        
        cout << "Please select commands:" << endl;
        cout << "| trade | improve | mortgage |  assets | bankrupt | help |" << endl;
        cin >> option;
        if (option == "trade") { //trade
            string player2;
            string give;
            string receive;

            cin>>player2;
            if (cin.fail()) {
                cout << "( Invalid trade request )" << endl;
                cout << "( Please follow the format: trade <name> <give> <receive> " << endl;
                continue;
            };
            cin>>give;
            if (cin.fail()) {
                cout << "( Invalid trade request )" << endl;
                cout << "( Please follow the format: trade <name> <give> <receive> " << endl;
                continue;
            };
            cin>>receive;
            if (cin.fail()) {
                cout << "( Invalid trade request )" << endl;
                cout << "( Please follow the format: trade <name> <give> <receive> " << endl;
                continue;
            };
            trade(p, player2, give, receive);
        } else if (option == "improve") { //improve
            string name;
            string action;

            cin>>name;
            if (cin.fail()) {
                cout << "( Invalid improve request )" << endl;
                cout << "( Please follow the format: improve <property> sell " << endl;
                continue;
            };
            cin>>action;

            if (cin.fail() || (action != "sell")) {
                cout << "( Invalid improve request )" << endl;
                cout << "( Please follow the format: improve <property> sell " << endl;
                continue;
            };

            improve(p, name, "sell");
        } else if (option == "mortgage") { //mortgage
            string name;

            cin>>name;
            if (cin.fail()) {
                cout << "( Invalid mortgage request )" << endl;
                cout << "( Please follow the format: mortgage <property> " << endl;
                continue;
            };

            mortgage(p, name);

        } else if (option == "assets") { //display assets
            displayAssets(p);

        } else if (option == "bankrupt") { //declare bankrupt
            
            if (!player[p]->canBankrupt()) { // if can not bankrupt
                cout << "( Don't give up! )" << endl;
                cout << "( Please try sell any improvement and mortgage properties )" << endl;
                continue;
            } else {
                bankruptcy(p, owner);
                return false;};
            
        } else if (option == "help") { // display help
            cout << "Commands format:" << endl;
            cout << "    trade <name> <give> <receive>" << endl;
            cout << "    improve <property> buy/sell" << endl;
            cout << "    mortgage <property>" << endl;
            cout << "    unmortgage <property>" << endl;
            cout << "    save <filename>" << endl;

        } else {

            cout << "( Invalid input )" << endl;
        };
    };
}; //finance

bool Game::checkTimsMode(int p) {

    return player[p]->getTimMode();
}

int Game::checkTimsTurn(int p) {

    return player[p]->getTimTurn();
}

//If way is "pay", pay $50 to leave Tims line
//If way is "usecup", use a Roll Up the Rim Cup to leave Tims line
void Game::leaveTims(int p, string way) {
    if (way == "pay") { //pay to leave
        if (pay(p, -50)) {
            cout << "( You have paid $50 to leave )" << endl;
        } else {
            return;
        };
    } else { // use cup to leave
        if (player[p]->getCup() < 1) {
            cout << "( You don't have Roll Up the Rim cup )" << endl;

            return;
        };
        player[p]->useCup();
        cout << "( You have used a Roll Up the Rim cup )" << endl;
    }
    cout << "( You can leave Tims Line now ! )" << endl;
    player[p]->leaveTims();
}; //leaveTims

//If dice=-1 and dice2 =-1, roll dices randomly
//Else roll the sum of two dices
void Game::roll(int p, int dice1, int dice2) {
    int toMove1 = -1;
    int toMove2 = -1;
    if (dice1 == -1 && dice2 == -1) { //random generate
        srand(time(NULL));
        toMove1 = rand() % 6 + 1;
        toMove2 = rand() % 6 + 1;
    } else {
        toMove1 = dice1;
        toMove2 = dice2;
    };

    bool timMode = checkTimsMode(p);

    if (timMode) { // Player in DC Tims line
        
        cout << "( You have rolled: " << toMove1 << " and " << toMove2 << " )" << endl;
        if (toMove1 != toMove2) {
            if (checkTimsTurn(p) < 2) {
                cout << "( Failed to leave Tims Line )" << endl;
                player[p]->stayInTims();
                notification->notify(p, player[p]->getposition());
                return;
            } else {

                cout << "( Failed to roll doubles for 3 turns )" << endl;
                string command;
                while (true) {

                    cout << "( You have to pay $50 OR use Roll Up the Rim cup to leave )" << endl;
                    cout << "Please select a command: " << endl;
                    cout << "| pay | usecup | trade | improve | mortgage | unmortgage | assets | help |" << endl;
                    cin>>command;
                    if (command == "pay") { // pay to leave
                        if (pay(p, -50)) {
                            cout << "( You have paid $50 to leave )" << endl;
                            break;
                        } else {
                            return;
                        }
                        
                    } else if (command == "usecup") { // use cup to leave
                        if (player[p]->getCup() < 1) {
                            cout << "( You don't have Roll Up the Rim cup )" << endl;
                            continue;
                        };
                        player[p]->useCup();
                        cout << "( You have used a Roll Up the Rim cup )" << endl;
                        break;
                    } else if (command == "trade") {// trade
                        string player2;
                        string give;
                        string receive;

                        cin>>player2;
                        cin>>give;
                        cin>>receive;
                        if (cin.fail()) {
                            cout << "( Invalid trade request )" << endl;
                            cout << "( Please follow the format: trade <name> <give> <receive> " << endl;
                            continue;
                        };
                        trade(p, player2, give, receive);
                    } else if (command == "improve") { //improve
                        string name;
                        string action;
                        cin>>name;
                        if (cin.fail()) {
                            cout << "( Invalid improve request )" << endl;
                            cout << "( Please follow the format: improve <property> buy/sell " << endl;
                            continue;
                        };
                        cin>>action;
                        if (cin.fail() || (action != "buy" && action != "sell")) {
                            cout << "( Invalid improve request )" << endl;
                            cout << "( Please follow the format: improve <property> buy/sell " << endl;
                            continue;
                        };
                        improve(p, name, action);
                    } else if (command == "mortgage") { //mortgage
                        string name;
                        cin>>name;
                        if (cin.fail()) {
                            cout << "( Invalid mortgage request )" << endl;
                            cout << "( Please follow the format: mortgage <property> " << endl;
                            continue;
                        };
                        mortgage(p, name);
                    } else if (command == "unmortgage") {//unmortgage

                        string name;
                        cin>>name;
                        if (cin.fail()) {
                            cout << "( Invalid unmortgage request )" << endl;
                            cout << "( Please follow the format: unmortgage <property> " << endl;
                            continue;
                        };
                        unmortgage(p, name);
                    } else if (command == "assets") { //display assets
                        displayAssets(p);
                        
                    } else if (command == "help") { //display assets
                        cout << "Commands format:" << endl;
                        cout << "    trade <name> <give> <receive>" << endl;
                        cout << "    improve <property> buy/sell" << endl;
                        cout << "    mortgage <property>" << endl;
                        cout << "    unmortgage <property>" << endl;
                        cout << "    save <filename>" << endl;
                    } else {
                        cout << "( Invalid input )" << endl;
                    };
                };
            };
        };
        cout << "( You can leave Tims Line now ! )" << endl;
        player[p]->leaveTims();
    };
    int sum = toMove1 + toMove2;
    cout << "( You have rolled: " << toMove1 << " + " << toMove2 << " = " << sum << " )" << endl;
    
    if (toMove1 == toMove2&&!timMode) { // if player rolled doubles and not in Tims
        countDoubles++;
        if (countDoubles != 3) {
            player[p]->takeMovement(sum);
            int position = player[p]->getposition();
            notification->notify(p, player[p]->getposition());
            notification->printBoard();
            cout << "( You have landed on: " << square[position]->getName() << " )" << endl;
            
            if (square[position]->getOwner() != player[p]->getName()) {
                
                takeAction(p, position);
            };

            cout << "( You have rolled doubles, you can roll again! )" << endl;
            notification->notifyDoubles();
            
        } else { // if player roll 3 doubles in a row
            cout << "( You have rolled doubles 3 times in a roll, please grab a coffee and take a rest )" << endl;
            cout << "( You have moved to DC Tims Line )" << endl;
            takeAction(p, 30);
        };
    } else {
        countDoubles = 0;
        player[p]->takeMovement(sum);
        int position = player[p]->getposition();
        notification->notify(p, player[p]->getposition());
        notification->printBoard();
        cout << "( You have landed on: " << square[position]->getName() << " )" << endl;
        
        if (square[position]->getOwner() != player[p]->getName()) {
            
            takeAction(p, position);
        };
    };
}; //roll

//Auction the building
void Game::auction(int building) {
    
    cout << square[building]->getName() << " is being auctioned:" << endl;
    int bid = square[building]->getPurchaseCost();
    int playerInAuction = NumberOfPlayer;
    bool withdraw[8];
    
    //loop to set withdraw status to false;
    for (int j = 0; j < NumberOfPlayer; j++) {
        withdraw[j] = false;
    };
    
    for (int i = 0; i < NumberOfPlayer; i++) {
        if (player[i]->getBankruptStatus()) {
            withdraw[i] = true;
            playerInAuction--;
        };
    };
    
    //loop to start auction
    while (playerInAuction != 1) {
        
        //loop for ask option from each players
        for (int i = 0; i < NumberOfPlayer; i++) {
            if (withdraw[i]) continue;
            string playername = player[i]->getName();
            cout << "Player " << playername << "'s turn" << endl;
            cout << "Current bid is $" << bid << endl;
            cout << "( Your holding cash: $" << player[i]->getBalance() << " )" << endl;

            cout << "Please select action:" << endl;
            cout << "| raise | withdraw |" << endl;
            string option;
            
            while (true) {
                cin>>option;
                if (option == "raise") {
                    int temp;
                    while (true) {
                        cout << " Please the value you want to raise to: (ie.300)" << endl;
                        cin>>temp;
                        if (cin.fail()) {
                            cout << "( Please enter a valid integer )" << endl;
                            continue;
                        } else if (temp <= bid) {
                            cout << "( Please enter a integer greater than current bid )" << endl;
                            continue;
                        } else {
                            bid = temp;
                            cout << "( You have raised the bid )" << endl;
                            break;
                        }
                    };
                    break;

                } else if (option == "withdraw") {
                    cout << "( Player " << playername << " has withdrew )" << endl;
                    withdraw[i] = true;
                    playerInAuction--;
                    break;
                } else {
                    cout << "( Invalid input )" << endl;
                };
            };
            if (playerInAuction == 1) break;
        };
    };
    int Winner = 0;
    for (int j = 0; j < NumberOfPlayer; j++) {
        if (withdraw[j] == false) {
            Winner = j;

            break;
        };
    };
    string winnerName = player[Winner]->getName();
    cout << "Congratulations! Player " << winnerName << " is the winner" << endl;

    if (pay(Winner, -bid)) {
        square[building]->setOwner(winnerName);
        player[Winner]->ManageProperty(square[building], "add");


        notification->notifyNewOwner(building, Winner);
        cout << "( Player " << winnerName << " have paid $" << bid << " for " << square[building]->getName() << " )" << endl;
    } else {

        auction(building);
    };
}

//player1 requests trade with player2, exchange give and receive
void Game::trade(int player1, string player2, string give, string receive) {

    istringstream sgive(give);
    int giveamount;
    istringstream sreceive(receive);
    int receiveamount;
    int player2Index = -1;
    int giveIndex = -1;
    int receiveIndex = -1;
    
    //loop to find player2's index
    for (int i = 0; i < NumberOfPlayer; i++) {
        if (player2 == player[i]->getName()) {
            player2Index = i;
            break;
        };
    };
    
    if (player2Index == -1 || isBankrupt(player2Index)) { //if name not valid
        cout << "( Invalid trade request )" << endl;
        cout << "( Please enter a valid player's name. )" << endl;
        return;
    };
    if (player2Index == player1) { // if trade with yourself
        cout << "( Invalid trade request )" << endl;
        cout << "( You cannot trade with yourself)" << endl;
        return;
    };
    if (sgive >> giveamount) { // if give exceed your cash
        if (player[player1]->getBalance() < giveamount) {
            cout << "( Invalid trade request )" << endl;
            cout << "( You don't have $" << giveamount << " )" << endl;
            return;
        };
        if (sreceive >> receiveamount) { // if trade cash to cash
            cout << "( Invalid trade request )" << endl;
            cout << "( Please not trade cash to cash. )" << endl;
            return;
        } else {

            receiveIndex = player[player2Index]->ownThis(receive);

            if (receiveIndex == -1) { //if player2 does not own receive
                cout << "( Invalid trade request )" << endl;
                cout << "( Player " << player2 << " does not own " << receive << " )" << endl;
                return;
            } else {
                bool ownBlock = canImprove(receiveIndex);
                if (ownBlock) {
                    string blockname = square[receiveIndex]->getBlock();
                    if (player[player2Index]->hasImprove(blockname)) {
                        cout << "( Invalid trade request )" << endl;
                        cout << "( Cannot trade " << receive << " because of improvement within the monopoly );" << endl;
                        return;
                    };
                };
                cout << "Player " << player2 << " :" << endl;
                cout << "Do you accept to trade " << player[player1]->getName();
                cout << "'s $" << giveamount << " with " << receive << "? (accept/reject)" << endl;

                string response;
                while (true) {
                    cin>>response;
                    if (response == "accept") { //player2 accept the trade

                        if (pay(player1, -giveamount, player2Index)) {
                            pay(player2Index, giveamount);

                            square[receiveIndex]->setOwner(player[player1]->getName());
                            player[player2Index]->ManageProperty(square[receiveIndex], "remove");
                            player[player1]->ManageProperty(square[receiveIndex], "add");

                            notification->notifyNewOwner(receiveIndex, player1);
                            notification->printBoard();
                            cout << "( The trade is succeed )" << endl;
                            return;
                        } else {
                            return;
                        }
                    } else if (response == "reject") { //player2 reject the trade
                        cout << "( Player " << player2 << " rejected the request )" << endl;
                        return;
                    } else {
                        cout << "Please enter a valid response: (accept/reject)" << endl;
                        continue;
                    };
                };
            };
        };
    } else { // player1 give a property
        giveIndex = player[player1]->ownThis(give);
        if (giveIndex == -1) { //if player1 does not own give
            cout << "( Invalid trade request )" << endl;
            cout << "( You don't own " << give << " )" << endl;
            return;
        } else {
            bool ownBlock = canImprove(giveIndex);
            if (ownBlock) {
                string blockname = square[giveIndex]->getBlock();
                if (player[player2Index]->hasImprove(blockname)) { // if the property cannot be trade
                    cout << "( Invalid trade request )" << endl;
                    cout << "( Cannot trade " << give << " because of improvement within the monopoly );" << endl;
                    cout << "( Please sell any improvement before trade )" << endl;
                    return;
                };
            };
            if (sreceive >> receiveamount) {
                if (player[player2Index]->getBalance() < receiveamount) { // if player2 does not have enough money
                    cout << "( Invalid trade request )" << endl;
                    cout << "( Player " << player2 << " doesn't have $" << receiveamount << " )" << endl;
                    return;
                };


                cout << "Player " << player2 << " :" << endl;
                cout << "Do you accept to trade " << player[player1]->getName();
                cout << "'s " << give << " with $" << receiveamount << "? (accept/reject)" << endl;
                string response;
                while (true) {
                    cin>>response;
                    if (response == "accept") { // if player2 accepts the request

                        if (pay(player2Index, -receiveamount, player1)) {
                            pay(player1, receiveamount);

                            square[giveIndex]->setOwner(player[player2Index]->getName());
                            player[player2Index]->ManageProperty(square[giveIndex], "add");
                            ;
                            player[player1]->ManageProperty(square[giveIndex], "remove");

                            notification->notifyNewOwner(giveIndex, player2Index);
                            notification->printBoard();
                            cout << "( The trade is succeed )" << endl;
                            return;
                        } else {
                            return;
                        };
                    } else if (response == "reject") { // if player2 rejects the request
                        cout << "( Player " << player2 << " rejected the request )" << endl;
                        return;

                    } else {
                        cout << "Please enter a valid response: (accpet/reject)" << endl;
                        continue;
                    };
                };
            } else { // if player1 trade property to property
                receiveIndex = player[player2Index]->ownThis(receive);
                if (receiveIndex == -1) {
                    cout << "( Invalid trade request )" << endl;
                    cout << "( Player " << player2 << " does not own " << receive << endl;
                    return;
                } else {
                    bool ownBlock = canImprove(receiveIndex);
                    if (ownBlock) {
                        string blockname = square[receiveIndex]->getBlock();
                        if (player[player2Index]->hasImprove(blockname)) {
                            cout << "( Invalid trade request )" << endl;
                            cout << "( Cannot trade " << receive << " because of improvement within the monopoly );" << endl;
                            return;
                        };
                    };
                    cout << "Player " << player2 << " :" << endl;
                    cout << "Do you accept to trade " << player[player1]->getName();
                    cout << "'s " << give << " with " << receive << "? (accept/reject)" << endl;
                    string response;
                    while (true) {
                        cin>>response;
                        if (response == "accept") {

                            square[giveIndex]->setOwner(player[player2Index]->getName());
                            player[player2Index]->ManageProperty(square[giveIndex], "add");
                            player[player1]->ManageProperty(square[giveIndex], "remove");

                            square[receiveIndex]->setOwner(player[player1]->getName());
                            player[player1]->ManageProperty(square[receiveIndex], "add");
                            player[player2Index]->ManageProperty(square[receiveIndex], "remove");

                            notification->notifyNewOwner(giveIndex, player2Index);
                            notification->notifyNewOwner(receiveIndex, player1);
                            notification->printBoard();
                            cout << "( The trade is succeed )" << endl;
                            return;

                        } else if (response == "reject") {
                            cout << "( Player " << player2 << " rejected the request )" << endl;
                            return;

                        } else {
                            cout << "Please enter a valid response: (accpet/reject)" << endl;

                            continue;
                        };
                    };
                };

            };
        }
    }

}; //trade

 //player requests to buy/sell improvement the property
void Game::improve(int p, string property, string action) {
    int propertyIndex = -1;
    propertyIndex = player[p]->ownThis(property);
    
    if (propertyIndex == -1) { // if player does not own the property
        cout << "( Invalid improve request )" << endl;
        cout << "( You don't own " << property << " )" << endl;
        return;
    };
    string block = square[propertyIndex]->getBlock();
    if (block == "Residence") {
        cout << "( Invalid improve request )" << endl;
        cout << "( You cannot improve residence )" << endl;
        return;
    };
    if (block == "Gym") {
        cout << "( Invalid improve request )" << endl;
        cout << "( You cannot improve Gym )" << endl;
        return;
    };
    if (!canImprove(propertyIndex)) {
        cout << "( Invalid improve request )" << endl;
        cout << "( You don't own the monopoly: " << block << " )" << endl;
        return;
    }

    if (action == "buy") { //if player is buying improvement

        int improvefee = square[propertyIndex]->getImproveCost();
        int improvement = square[propertyIndex]->getImprovement();
        if (improvement == 5) {// maximum level
            cout << "( Invalid improve request )" << endl;
            cout << "( " << property << " is already improved to the maximum level )" << endl;
            return;
        } else {

            if (pay(p, -improvefee)) {
                square[propertyIndex]->improve();
                notification->notifyImprove(propertyIndex);
                notification->printBoard();
                cout << "( " << property << " is successfully improved )" << endl;
            };
            return;
        }
    } else { // if player is selling improvement
        int improvefee = square[propertyIndex]->getImproveCost();
        int improvement = square[propertyIndex]->getImprovement();
        
        if (improvement == 0) { //no improvement
            cout << "( Invalid improve request )" << endl;
            cout << "( " << property << " hasn't been improved )" << endl;
            return;
        } else {

            pay(p, improvefee / 2);
            square[propertyIndex]->improve(-1);
            notification->notifyImprove(propertyIndex, -1);
            notification->printBoard();
            cout << "( " << property << "'s improvement is successfully decreased )" << endl;
        }
    }

};//improve

//player requests to mortgage the property
void Game::mortgage(int p, string property) {
    int propertyIndex = -1;
    propertyIndex = player[p]->ownThis(property);
    
    if (propertyIndex == -1) { //if player does not own the property
        cout << "( Invalid mortgage request )" << endl;
        cout << "( You don't own " << property << " )" << endl;
        return;
    };
    if (square[propertyIndex]->getImprovement() != 0) {
        cout << "( Invalid mortgage request )" << endl;
        cout << "( You sell any improvement before mortgage )" << endl;
        return;
    };
    if (square[propertyIndex]->getMortgageStatus()) {
        cout << "( Invalid mortgage request )" << endl;
        cout << "( " << property << "is already mortgaged )" << endl;

        return;
    };
    int fee = (int) square[propertyIndex]->getPurchaseCost() / 2;
    pay(p, fee);
    square[propertyIndex]->setMortgageStatus();
    notification->notifyMortgage(propertyIndex);
    notification->printBoard();
    cout << "( " << property << " is successfully mortgaged )" << endl;
    cout<<"( You have receive $"<<fee<<" )"<<endl;

};//mortgage

//player requests to unmortgage the property
void Game::unmortgage(int p, string property) {
    int propertyIndex = -1;
    propertyIndex = player[p]->ownThis(property);
    if (propertyIndex == -1) { //if player does not own the property
        cout << "( Invalid unmortgage request )" << endl;
        cout << "( You don't own " << property << " )" << endl;
        return;
    };
    if (!square[propertyIndex]->getMortgageStatus()) { // if the property is not mortgaged
        cout << "( Invalid unmortgage request )" << endl;
        cout << "( " << property << "is not mortgaged )" << endl;

        return;
    };
    int fee = (int) square[propertyIndex]->getPurchaseCost()*6 / 10;
    if (pay(p, -fee)) {
        square[propertyIndex]->setMortgageStatus();
        notification->notifyMortgage(propertyIndex, -1);
        notification->printBoard();
        cout << "( " << property << " is successfully unmortgaged )" << endl;
    } else {
        return;
    }

}; //unmortgage

//display the assets of the player
void Game::displayAssets(int p) {

    cout << "Cash: $" << player[p]->getBalance() << endl;
    cout << "Roll Up the Rim Cup: " << player[p]->getCup() << endl;
    cout << endl;

    player[p]->printProperty();
};//displayAssets

//player is bankruptcy and owe money to owner
//If owner is Bank, the properties of player will be auctioned
//If owner is a player, the assets of the player will give to owner
void Game::bankruptcy(int p, int owner) {
    
    cout << "Player " << player[p]->getName() << " has declared bankrupt " << endl;
    validPlayer--;
    if (validPlayer == 1) { // if only one player left, he/she win !
        for (int i = 0; i < NumberOfPlayer; i++) {
            if (!player[i]->getBankruptStatus()) {
                cout << "Congratulation! Player " << player[i]->getName() << " is the final winner!" << endl;
                break;
            };
        };
        return;
    };
    
    int ownedProperty = player[p]->getTotalProperty();
    //int propertyIndex[ownedProperty];
	int propertyIndex[29];
    
    //loop to get index of properties the player owned
    for (int i = 0; i < ownedProperty; i++) {
        propertyIndex[i] = player[p]->getPropertyIndex(i);
    };
    
    if (owner == -1) { // if the player owe Bank money
        
        while (player[p]->getCup() > 0) {
            player[p]->useCup();
        };
        
    } else { // if player owe "owner" money
        while (player[p]->getCup() > 0) {
            player[owner]->receiveCup();
            player[p]->useCup();
        };
        pay(owner, player[p]->getBalance());
    };
    player[p]->bankrupt();

    
    if (owner == -1) { // if the player owe Bank money
        
        //loop to unmortgage each properties and auction
        for (int j = 0; j < ownedProperty; j++) {
            int index = propertyIndex[j];
            if (square[index]->getMortgageStatus()) {
                square[index]->setMortgageStatus();
            };
            auction(square[index]->getIndex());
        };
        notification->notifyBankruptcy(p);
        notification->printBoard();

    } else {//if the player owe "owner" money
        
        cout<<"( "<<player[owner]->getName()<<" has received "<<player[p]->getName()<<"'s all assets )"<<endl;
        cout<<"Player "<<player[owner]->getName()<<" :"<<endl;
	    notification->notifyBankruptcy(p);
        
        //loop to give each properties to "owner"
        for (int j = 0; j < ownedProperty; j++) {

            int index = propertyIndex[j];

            if (square[index]->getMortgageStatus()) {
                
                cout << "( "<<player[owner]->getName()<<" have received a mortgaged building: " << square[index]->getName() << " )" << endl;
                int cost = (int) square[index]->getPurchaseCost() / 10;
                cout << "( "<<player[owner]->getName()<<" need to pay $" << cost << " )" << endl;
                
                if (pay(owner, -cost)) { // owner pay the 10%
                    
                    square[index]->setOwner(player[owner]->getName());
                    player[owner]->ManageProperty(square[index], "add");
                    cout << "Do you want to pay half of the purchase cost: $" << cost * 5 << " to unmortgage the property now? (y/n)" << endl;
                    cout << "( Your holding cash: $" << player[owner]->getBalance() << " )" << endl;
                    string option;
                    while (true) {
                        cin>>option;
                        if (option == "y") {
                            if (pay(owner, -(cost * 5))) {
                                square[index]->setMortgageStatus();
                                notification->notifyMortgage(index, -1);
                                //notification->printBoard();
                                cout << "( " << square[index]->getName() << " is successfully unmortgaged )" << endl;
                                break;
                            } else {
                                break;
                            };
                        } else if (option == "n") {
                            notification->printBoard();
                            cout << "( " << square[index]->getName() << " is left mortgaged )" << endl;
                            break;

                        } else {
                            cout << "( Invalid input )" << endl;
                        };
                    };
                    notification->notifyNewOwner(index, owner);;
                };
            };
            notification->printBoard();
        };
    }

};//bankruptcy

bool Game::isBankrupt(int p) {
    return player[p]->getBankruptStatus();
}

//check if the building can be improved
bool Game::canImprove(int building) {
    string block = square[building]->getBlock();
    string owner = square[building]->getOwner();
    int p = -1;
    
    //find the index of the owner
    for (int i = 0; i < NumberOfPlayer; i++) {
        if (player[i]->getName() == owner) {
            p = i;
            break;
        };
    };
    int count = player[p]->countBlock(block);
    
    if (block == "Arts1" || block == "Math") {
        if (count < 2) {
            return false;
        };
    } else if (block == "Arts2" || block == "Eng" || block == "Health" || block == "Env" || block == "Sci1" || block == "Sci2") {
        if (count < 3) {
            return false;
        };
    };
    return true;
};

//save the game to the out file
void Game::save(int p, ofstream &out) {
    
    out << validPlayer << "\r\n";
    int i = p;
    
    //loop to save each players' information
    for(int x=0;x<NumberOfPlayer;x++) {
        out << player[i]->getName() << " " << player[i]->getChar() << " " << player[i]->getCup() << " ";
        out << player[i]->getBalance() << " " << player[i]->getposition();
        if (player[i]->getposition() == 10) {
            if (!player[i]->getTimMode()) {
                out << " 0\r\n";
            } else {
                out << " 1 ";
                out << player[i]->getTimTurn() << "\r\n";
            };
        } else {
            out << "\r\n";
        };
        if (i+1>= NumberOfPlayer) {
            i -= NumberOfPlayer-1;
            
        } else {
            i++;
        }
        while (true) {
            if (player[i]->getBankruptStatus()) {
                i++;
                x++;
                continue;
            } else {
                break;
            }
        };
    };
    //loop to save owners of each ownable buildings
    for (int i = 0; i < 40; i++) {
        if (square[i]->getOwnable()) {
            out << square[i]->getName() << " ";
            if (square[i]->getOwner() == "Bank") {
                out << "BANK ";
            } else {
                out << square[i]->getOwner() << " ";
            };
            if (square[i]->getMortgageStatus()) {
                out << -1;
            } else {
                out << square[i]->getImprovement();
            };
            out << "\r\n";
        };
    }
    out.close();
};//save

void  Game::getMoney(int p, int amount){
    player[p]->cashFlow(amount);
}

Game::~Game() {
    for (int i = 0; i < 40; i++) {
        delete square[i];
    };
    //delete []square;
    for (int i = 0; i < NumberOfPlayer; i++) {
        delete player[i];
    };
    //delete []player;
    for (int i = 0; i < 24; i++) {
        delete slccards[i];
    };
    for (int i = 0; i < 18; i++) {
        delete needlescards[i];
    };

}
