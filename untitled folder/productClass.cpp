#include "productClass.h"


Product::Product(){ // sets to -1 for find function to signal if not found
    _numberStocked = -1;
}

Product::Product(std::string name, std::string pType, int msrp, int daysTillExpiration, int number){
    _name = name;
    _productType = pType;
    _price = msrp;
    _daysTillExpiration = daysTillExpiration;
    _numberStocked = number;
}

float Product::getPrice() const{
    
    // boxed and canned are not refridgerated
    double price = 0;
    if (_productType == "PRODUCE"){
        price = _price - (double)pow(7 - _daysTillExpiration, 2);
    } else if (_productType == "CANNED"){
        int maxDaysTillEx = 350;
        double slope = -(_price / (double)(maxDaysTillEx)) * .5;
        price = _price - (slope)*(maxDaysTillEx - _daysTillExpiration);
    } else if (_productType == "BOXED"){
        int maxDaysTillExB = 210;
        double slopeB = -(_price / (double)(maxDaysTillExB)) * .25;
        price = _price - (slopeB)*(maxDaysTillExB - _daysTillExpiration);
    }

    return price;
    // Produce
    // mathmatical function used: price = msrp - (larges days till exp for produce - daystillexpiration)^2
    // use this to keep price high during time when fruit is good and lower quickly right before they go bad to incentivize selling it
    
    
    // canned
    // mathmatical functions used : price = msrp - (largest days till exp for canned - daystillexpiration)(calculated to have price half of msrp by expiration)
    // boxed
    
    //boxed 
    // mathmatical functions used: price = msrp - (largest days till exp for boxed - daystillexpiration)(calculated to have price 3 quarters of msrp by expiration)
}

std::string Product::getName() const{
    return _name;
}

int Product::getNumStocked() const{
    return _numberStocked;
}

void Product::changeStock(int num, int direction){
    // branching determines direction of stock movement.
    if (direction == -1){
        _numberStocked -= num;
    } else if (direction == 1){
        _numberStocked += num;
    }
    
}