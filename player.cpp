/*
 *  player.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include <iostream>
#include <iomanip>
#include "player.h"
#include "building.h"

using namespace std;

int Player::totalcups = 0;

Player::Player(string name, char Char, int position, int cash,int ownedcup) : name(name), Char(Char), position(position), cash(cash), numberOfProperty(0),ownedcup(ownedcup) {
    for (int i = 0; i < 28; i++) {
        properties[i] = NULL;
    }
    timMode = false;
    inTims = 0;
    isbankrupt=false;
}

string Player::getName() {
    return name;
}

char Player::getChar() {
    return Char;
}

int Player::getposition() {
    return position;
}

void Player::setPosition(int p) {
    
    if (p < 0) {
        position = 40 + p;
    } else if (p >= 40) {
        position = p - 40;
    } else {
        position = p;
    };
    
}

int Player::getBalance() {
    return cash;
}

int Player::getTotalProperty(){
    return numberOfProperty;
}

bool Player::getTimMode() {
    return timMode;
}

void Player::setTimMode() {
    timMode = !timMode;
}

bool Player::getBankruptStatus(){

    return isbankrupt;
}

int Player::getTimTurn() {
    return inTims;
}

int Player::getCup() {
    return ownedcup;
}

int Player::getTotalCup() {
    return totalcups;
}

int Player::getPropertyIndex(int i){
    return properties[i]->getIndex();
}

//if the action is "add", add the property to player's owned list
//if the action is "remove", remove the property from the player's owned list
void Player::ManageProperty(Square* property, string action) {
    
    if (action == "add") {
        
        properties[numberOfProperty] = property;
        numberOfProperty += 1;
        
        //add count for the monopoly
        addBlock(property->getBlock());
        
    } else if (action == "remove") {
        
        int index = -1;
        
        //loop to find the property index to remove
        for (int i = 0; i < numberOfProperty; i++) {
            if (properties[i] == property) {
                index = i;
                break;
            };
        };
        
        //decrease count for the monopoly
        deleteBlock(property->getBlock());
        
        while (index < numberOfProperty) {
            if (index != numberOfProperty - 1) {
                properties[index] = properties[index + 1];
            }
            index++;
        }
        properties[numberOfProperty - 1] = NULL;
        numberOfProperty -= 1;
        
    }
}; //ManageProperty

//Move steps
void Player::takeMovement(int steps) {

    position += steps;
    if (position >= 40) {
        cout << "( You have collected $200 )" << endl;
        this->cashFlow(200);
        position -= 40;
    }
    if (position < 0) position += 40;

}; //takeMovement

//Receive/Spend cash
void Player::cashFlow(int amount) {
    cash += amount;
};//cashFlow

//set player's status to bankrupt
//and remove properties
void Player::bankrupt(){
    
    cash=0;
    for (int i=numberOfProperty-1;i>=0;i--){
        ManageProperty(properties[i],"remove");
    };
    isbankrupt=true;
    
}

//print information of player's owned properties
void Player::printProperty() {
    if (numberOfProperty > 0) {
        cout << setw(10) << right << "Properties" << setw(10) << right << "Improve" << setw(13) << right << "Monopoly"<<setw(12)<<right<<"Mortgaged"<< endl;
        cout << endl;
    };
    
    //loop for print info for each property is properties
    for (int i = 0; i < numberOfProperty; i++) {

        cout << setw(10) << right << properties[i]->getName() << setw(10) << right << properties[i]->getImprovement();
        string mortgage="NO";
        if (properties[i]->getMortgageStatus()){
            mortgage="YES";
        };
        cout << setw(13) << right << properties[i]->getBlock() <<setw(12)<<right<<mortgage<< endl;
    };
}; //printProperty

//when player own a new property, update the block count in propertylist
void Player::addBlock(string block) {
    
    map<string, int>::iterator it;
    it = propertyList.find(block);
    if (it != propertyList.end()) {
        propertyList[block]++;
    } else {
        propertyList[block] = 1;
    }
    
};

//when player lose a property, update the block count in propertylist
void Player::deleteBlock(string block) {
    map<string, int>::iterator it;
    it = propertyList.find(block);
    if (it != propertyList.end()) {
        propertyList.erase(it);
    };
}

//count property owned within a monopoly
int Player::countBlock(string block) {
    int count;
    count = propertyList[block];
    return count;
}

//stay in Tims line for turn
void Player::stayInTims(int turn) {
    inTims+=turn;
}

//set tim mode to false and intims to 0
void Player::leaveTims() {
    inTims = 0;
    setTimMode();
}

void Player::useCup() {
    totalcups--;
    ownedcup--;
}

void Player::receiveCup() {
    cout << "( You got a Roll Up the Rim Cup )" << endl;
    totalcups++;
    ownedcup++;
}

//if player own the property
int Player::ownThis(string name) {
    for (int i = 0; i < numberOfProperty; i++) {
        if (properties[i]->getName() == name) return properties[i]->getIndex();
    };
    return -1;
};

//if the player own the monopoly and has improvement
bool Player::hasImprove(string blockname){
    
    //loop to check improvement for each property player owned
    for (int i=0;i<numberOfProperty;i++){
        if (properties[i]->getBlock()==blockname){
            if (properties[i]->getImprovement()!=0){
                return true;
            };
        };
    };
    return false;
}

//if the player has sell all improvement and mortgage all properties
bool Player::canBankrupt(){
    
    //loop to check improvement and mortgage status for each property player owned
    for (int i=0;i<numberOfProperty;i++){
        if (properties[i]->getImprovement()!=0){
            return false;
        };
        if (!properties[i]->getMortgageStatus()){
            return false;
        };
    };
    return true;
}
Player::~Player() {
}
