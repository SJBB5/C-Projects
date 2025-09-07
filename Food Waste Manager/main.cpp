
#include <iostream>
#include <fstream>
#include "productClass.h"
#include "fridgeClass.h"

using namespace std;

// file input
// need while statement for interface to save data so customer can access it.

bool keepGoing(){
    char decision;
    cout << "Press E to exit and C to return to home: ";
    cin >> decision;
    if (decision == 'E'){
        return false;
    } else {
        return true;
    }
}


int main(){
    Fridge theFridge;
    bool interFace = true;

    while (interFace){

        int firstSelection;
        cout << "Welcome to the Fridge, are you a customer or employee? " << endl;
        cout << "\t 1.) Customer" << endl;
        cout << "\t 2.) Employee" << endl;
        cout << "Enter number: ";
        cin >> firstSelection;
        
        if (firstSelection == 1){
            
            /*
            Second Interface
            */
            int option;
            cout << "Please select an option:" << endl;
            cout << "\t 1.) Find item pricing" << endl;
            
            cout << "Selection: ";
            cin >> option;

            switch (option){
                case 1:
                    std::string iName;
                    cout << "Name of item: ";
                    cin >> iName;

                    if (theFridge.findItem(iName).getNumStocked() != -1){
                        std::cout << "Item Price: " << std::fixed << std::setprecision(2) << theFridge.findItem(iName).getPrice() << std::endl; 
                    } else {
                        cout << "Item not found" << endl;
                    }
                    interFace = keepGoing();
                    break;
                
            }

        } else if (firstSelection == 2){
            /*
            Third interface
            */
            
            int option2;
            cout << "Please select an option:" << endl;
            cout << "\t 1.) Remove item from stock" << endl;
            cout << "\t 2.) Input items to stock" << endl;
            cout << "Selection: ";
            cin >> option2;
            

            string name = "";// avoiding error
            switch (option2)
            {
                case 1: // maybe loops this
        
                    int count;
                    cout << "Enter item name: ";
                    cin >> name;
                    cout << "Enter item count: ";
                    cin >> count;
                    theFridge.removeItem(name,count);
                    interFace = keepGoing();
                    break;
            
                case 2:
                    
                    /*
                    Fourth interface
                    */
                    int inputType;
                    cout << "What type of input?" << endl;
                    cout << "\t 1.) Manual" << endl;
                    cout << "\t 2.) File" << endl;
                    cout << "Selection: ";
                    cin >> inputType;
                    switch (inputType){
                        case 1:
                            theFridge.inputItem();
                            interFace = keepGoing();
                            break;
                        
                        case 2:
                            string filName;
                            cout << "Name of the file: ";
                            cin >> filName;
                            ifstream fin(filName); // Open the file for reading
                            if (!fin.is_open()) {
                                cout << "Error opening the file!" << endl;
                                break;
                            }
                            theFridge.inputFile(fin); // Pass the input file stream to theFridge object's inputFile method
                            fin.close(); // Close the file after reading
                            interFace = keepGoing();
                            break;

                            
                    }
                    break;

            }


        }
    
    }
   
    
    
    
    return 0;
}




