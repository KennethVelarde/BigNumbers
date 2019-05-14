
//
// Created by Kenneth-Matthew Velarde on 2019-05-13.
//

#ifndef BIGNUMBERS_BIGNUMBERS_H
#define BIGNUMBERS_BIGNUMBERS_H

//
// Created by Kenneth-Matthew Velarde on 2019-05-13.
//

#include<vector>
#include <stdio.h>
#include <iostream>



namespace BigNumbers{
    class BigNumbers{
        
        /*! exception class
         * \brief thrown if number of digits is over 1000
         *
         */
        class DigitOverflowException{};
        class DivideByZeroException{};
        
    private:
        
        std::vector<int> values;
        //            std::vector<int> values2;
        //            std::vector<int> values3;
        
        std:: string num;
        
        
    public:
        //constructors
        BigNumbers();
        BigNumbers(std::string);
        
        /*!operator overload for addition operator
         *
         **/
        BigNumbers operator +(BigNumbers &val);
        
        /*!operator overload for subtraction operator
         *
         **/
        BigNumbers operator -(BigNumbers &val);
        
        /*!operator overload for multiplication operator
         *
         **/
        BigNumbers operator *(BigNumbers &val);
        
        /*!operator overload for division operator
         *
         **/
        BigNumbers operator /(BigNumbers &val);
        
        /*!operator overload for mod operator
         *
         **/
        BigNumbers operator %(BigNumbers &val);
        
        void adder(std::vector<int> vector, std::vector<int> values, std::vector<int> vector1);
        
        void reverser(std::vector<int> vector);
        
        bool greater(std::vector<int> vector, std::vector<int> values);
        
        void subtracter(std::vector<int> vector, std::vector<int> values, std::vector<int> vector1);
        
        bool lesser(std::vector<int> vector, std::vector<int> v2);
        
    };
    
    
    
}



#endif //BIGNUMBERS_BIGNUMBERS_H
