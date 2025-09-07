#ifndef FRIDGE_CLASS_H
#define FRIDGE_CLASS_H
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

#include "productClass.h"
class Fridge{
    public:
        /**
         * @brief Construct a new Fridge object
         * 
         */
        Fridge();
        
        /**
         * @brief inputs a file of products and then adds instances of product to member lits
         * @param file 
         */
        void inputFile(std::istream&);
        
        /**
         * @brief Prompts user and inputs item manually, can add as many items as desired (in loop)
         * 
         */
        void inputItem();
        
        /**
         * @brief Removes item
         * @param name 
         * @param num number being removed
         */
        void removeItem(std::string, int);
        
        /**
         * @brief Using the name of a product it returns the instance of the product class
         * 
         * @return Product 
         */
        Product findItem(std::string) const;
    private:
        unsigned int _itemNum;
        std::vector<Product> _itemList;


};


#endif
