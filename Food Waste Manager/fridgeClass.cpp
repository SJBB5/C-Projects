#include "fridgeClass.h"



Fridge::Fridge(){
    _itemNum = 0;

}

void Fridge::inputFile(std::istream& fin){ // figure out file type of input
    std::string name;
    std::string type;
    double msrp;
    int daysTillExpiration;
    int numberStocked;
    
    std::string line;

    while (std::getline(fin, line)) {
        std::istringstream iss(line);
        

        if (!(iss >> name >> type >> msrp >> daysTillExpiration >> numberStocked)) {
            std::cerr << "Error parsing line: " << line << std::endl; // error tracing
            continue; // Skip to the next line if parsing fails
        }
        Product product(name, type, msrp, daysTillExpiration, numberStocked);


        _itemList.push_back(product);
        

    }

    

    

}

void Fridge::inputItem(){
    bool inputting = true;
    while (inputting){ // loop that continues the manual entering process until user is done
        std::string name;
        std::string type;
        float priced;
        int daysTillEx;
        int num;
        std::cout << "Enter Product Name: ";
        std::cin >> name;
        std::cout << "Enter Product Type: ";
        std::cin >> type;
        std::cout << "Enter Product price: ";
        std::cin >> priced;
        std::cout << "Enter days till expiration: ";
        std::cin >> daysTillEx;
        std::cout << "Enter Product count: ";
        std::cin >> num;

        _itemList.push_back(Product(name,type,priced,daysTillEx, num));
        _itemNum += num;

        std::string decision;
        std::cout << "Do you have more items to input? (Y/N)";
        std::cin >> decision;
        if (decision == "Y"){
            inputting = true;
        } else if (decision == "N"){
            inputting = false;
        } else {
            std::cout << "Invalid input";
            inputting = false;
        }

    }
}

void Fridge::removeItem(std::string name, int num){
    for (size_t i = 0; i < _itemList.size(); i++){// parses through items in fridge
        if(_itemList[i].getName() == name){
            Product instance = _itemList[i];
            if (instance.getNumStocked() == 1 && num == 1)// branching checks to see if removing the amount removes the item from stock entirely
                _itemList.erase(_itemList.begin()+i);
            else if (num > 1){
                if (instance.getNumStocked() > num){
                    instance.changeStock(num, -1);
                }
            }
        }
    }
}


Product Fridge::findItem(std::string name) const{ 
    
    for (size_t i = 0; i < _itemList.size(); i++){// parses through list of items and returns instance.
        if(_itemList[i].getName() == name){
            return _itemList[i];
            
        }

    }
    
    return Product();
}