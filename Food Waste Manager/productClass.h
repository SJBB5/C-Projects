#ifndef PRODUCT_CLASS_H
#define PRODUCT_CLASS_H

#include <string>
#include <cmath>

/**
 * @brief 
 * 
 */
class Product {
    public: 
        /**
         * @brief Construct a new Product object
         * 
         */
        Product();
        
        /**
         * @brief Construct a new Product object
         *  just paramiterized version
         */
        Product(std::string,std::string, int, int, int);
        
        /**
         * @brief Get the Price object
         * This is where most of the complexity is. For each type of good a different pricing function is used as it nears expiration.
         * THIS MAY SEEM LIKE JUST A GETTER BUT LOOK AT IMPLEMENTATION.
         * @return float 
         */
        float getPrice() const;
        
        /**
         * @brief Get the Name object
         * 
         * @return std::string 
         */
        std::string getName() const;
        
        /**
         * @brief Get the Num Stocked object
         * 
         * @return int 
         */
        int getNumStocked() const;
        
        /**
         * @brief changes the number stocked 
         * @param num that is getting added or subtracted
         * @param secondnum is eather 1 or -1 and corresponds to whether it is added or subtracted.
         */
        void changeStock(int, int); // second pos or neg 1 for add or subtract
        

    
    private:
        double _price;
        unsigned int _daysTillExpiration;
        unsigned int _numberStocked;
        std::string _name;
        std::string _productType;

};





#endif
