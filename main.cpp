/*
 *  main.cpp
 *  bb7k
 *  arthur: r37wu, clzhong
 */

#include <iostream>
#include <fstream>
#include "controller.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    if (argc > 4 ){ // if too much command line arguments
        cout<<"Invalid Command"<<endl;
        cout << "Command line options:" << endl;
        cout << "       -load <filename>" << endl;
        cout << "       -testing" << endl;
    } else if (argc == 4) {
        
        string argument=argv[1];
        
        if (argument!="-load"&&argument!="-testing"){ // Invalid arguments
            cout<<"Invalid Command"<<endl;
            cout << "Command line options:" << endl;
            cout << "       -load <filename>" << endl;
            cout << "       -testing" << endl;
            
        } else {
            
            if (argument=="-testing"){
                
                string argument2=argv[2];
                
                if (argument2!="-load"){ // Invalid arguments
                    
                    cout<<"Invalid Command"<<endl;
                    cout << "Command line options:" << endl;
                    cout << "       -load <filename>" << endl;
                    cout << "       -testing" << endl;
                    
                } else { // Enter test mode and load file
                    cout << "( Enter test mode )" << endl;
                    cout << "( Loading file )" << endl;
                    ifstream savedFile;
                    string fileName(argv[3]);
                    savedFile.open(argv[3]);
                    Controller C(savedFile,true);
                    C.play();
                };
            } else {
                
                string argument3=argv[3];
                
                if (argument3!="-testing"){ //Invalid arguments
                    cout<<"Invalid Command"<<endl;
                    cout << "Command line options:" << endl;
                    cout << "       -load <filename>" << endl;
                    cout << "       -testing" << endl;
                    
                } else { //Enter test mode and load file
                    cout << "( Enter test mode )" << endl;
                    cout << "( Loading file )" << endl;
                        ifstream savedFile;
                        string fileName(argv[2]);
                        savedFile.open(argv[2]);
                        Controller C(savedFile,true);
                        C.play();
                    }
            }
        };
    } else if (argc < 2) { // new game
        Controller c;
        c.play();
        
    } else if (argc == 2) {
        
        string argument=argv[1];
        
        if (argument == "-testing") { //Enter test mode
            
            cout << "( Enter test mode )" << endl;
            Controller C(true);
            C.play();
            
        } else { //Invalid arguments
            cout<<"Invalid Command"<<endl;
            cout << "Command line options:" << endl;
            cout << "       -load <filename>" << endl;
            cout << "       -testing" << endl;
        };
        
    } else { // argc==3
        
        string argument=argv[1];
        
        if (argument == "-load") { //load file
            
            cout << "( Loading file )" << endl;
            ifstream savedFile;
            string fileName(argv[2]);
            savedFile.open(argv[2]);
            Controller C(savedFile);
            C.play();
            
        } else { //Invalid arguments
            cout<<"Invalid Command"<<endl;
            cout << "Command line options:" << endl;
            cout << "       -load <filename>" << endl;
            cout << "       -testing" << endl;
        };
    };
};
