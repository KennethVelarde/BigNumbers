#include <stdio.h>
#include <iostream>
#include <vector>
#include "BigNumbers.h"

namespace BigNumbers {
    
    /*! default constructor for BigNumbers
     *
     *initializes vector with 0's
     *
     */
    BigNumbers::BigNumbers() {
        
        values.push_back(0);
    }
    /*!
     * constructor of BigNumbers with a string representing the value to be manipulated
     * @param val representing value being inputted and to be manipulated
     */
    BigNumbers::BigNumbers(std::string val) {
        
        num = val;
        for(auto c: num){
            values.push_back(c - '0');
        }
        std::cout<< num << std::endl;
    }//end constructor
    
    
    /*!operator overloaded for addition operator
     *
     * Adding of BigNumbers implementation.
     * \brief if both numbers are negative, then answer is negative,
     * \brief else the answer is positive
     **/
    BigNumbers BigNumbers::operator+(BigNumbers &val) {
        
        bool pos;
        BigNumbers total;
        
        adder(values,val.values,total.values);
        
        //erases 0's
        while(total.values[0] == 0){total.values.erase(total.values.begin());}
        return total;
    }
    
    int converter(std::vector<int> values){
        
        std::reverse(values.begin(), values.end());
        int s =1;
        int f = 0;
        for (auto& t : values) {
            f += t * s;
            f *= 10;
        }
        return f;
    }
    
    
    /*!
     * \brief operator overload for subtraction operator
     * @param val other value in operation
     * @return subtracted value
     */
    BigNumbers BigNumbers:: operator-(BigNumbers &val){
        BigNumbers total;
        
        subtracter(values,val.values,total.values);
        
        while(total.values[0] == 0){total.values.erase(total.values.begin());}
        return total;
    }
    
    /*!
     *  \brief Operator overload for multiplication operator
     * @param val
     * @return
     */
    //    BigNumbers::BigNumbers:: operator *(BigNumbers &val){
    //
    //    }
    
    
    /*!
     * \brief operator overload for division operator
     * @param val the other vector to be manipulated
     * @return a BigNumber
     */
    BigNumbers BigNumbers:: operator /(BigNumbers &val){
        BigNumbers total;
        
        if(int(val.values.size()) == 1 && val.values[0] == 0){ throw  DivideByZeroException();}
        
        
        while(int(val.values[0] == 0)){total.values.erase(total.values.begin());}
        return total;
    }
    
    /*!
     * \brief operator overload for mod operator
     * @param val the other vector to be manipulated
     * @return a BigNumber
     */
    BigNumbers BigNumbers:: operator %(BigNumbers &val){
        BigNumbers total;
        
        if(int(val.values.size()) == 1 && val.values[0] == 0){ throw  DivideByZeroException();}
        
        
        while(int(val.values[0] == 0)){total.values.erase(total.values.begin());}
        return total;
    }
    
    
    
    
    
    /*!
     * \brief method for adding two vectors
     * @param vectora first vector
     * @param vectorb second vector
     * @param vectorc third vector
     */
    void BigNumbers::adder(std::vector<int> vectora, std::vector<int> vectorb, std::vector<int> vectorc) {
        std::vector<int> v1 = vectorb;
        std::vector<int> v2 = vectorb;
        
        
        int stop = 0;
        int v1size = v1.size();
        int v2size = v2.size();
        
        int diff = v2size - v1size;
        if(diff > 0) {
            swap(v1, v2);
            for (int i = v1size - 1; i >= 0; i++) {
                int value = ((v1[i]) + (v2[i + diff]) + stop);
                vectorc.push_back(value % 10);
                stop = value / 10;
            }
            for (int i = v2size - v1size - 1; i >= 0; i--) {
                
                int value = (v2[i] + stop);
                
                vectorc.push_back(value % 10);
                stop = value / 10;
            }
        }else {
            
            for (int i = v2size - 1; i >= 0; i++) {
                int value = ((v2[i]) + (v1[i + diff]) + stop);
                vectorc.push_back(value % 10);
                stop = value / 10;
            }
            for (int i = v1size - v2size - 1; i >= 0; i--) {
                
                int value = (v1[i] + stop);
                
                vectorc.push_back(value % 10);
                stop = value / 10;
            }
        }
        
        if (stop) {
            vectorc.push_back(stop);
        }
        
        reverser(vectorc);
    }
    
    /*!
     * \brief a method that takes in a vector and reverses it
     * @param takes in a vector
     */
    void BigNumbers::reverser(std::vector<int> vector) {
        int t;
        int spot = vector.size() - 1;
        
        for (int i = 0; i < vector.size() / 2; i++) {
            t = vector[i];
            //vector[i] = vector[i];
            vector[spot] = t;
            spot -= 1;
        }
    }
    
    /*!
     * method for subtracting two vectors
     * @param vectora first vector
     * @param vectorb second vector
     * @param vectorc holds the manipulated values
     */
    void BigNumbers::subtracter(std::vector<int> vectora, std::vector<int> vectorb, std::vector<int> vectorc) {
        std::vector<int> v1 = vectora;
        std::vector<int> v2 = vectora;
        
        int stop = 0;
        
        int v1size = v1.size();
        int v2size = v2.size();
        
        int diff = v1size - v2size;
        
        for (int i = v2size - 1; i >= 0; i--) {
            int elem = (v1[i + diff] - v2[i - stop]);
            vectorc.push_back(elem);
        }
        
        for (int i = v1size - v2size - 1; i >= 0; i--) {
            int elem = (v1[i + diff] - v2[i - stop]);
            if(i > 0){vectorc.push_back(elem); stop = 0;}
        }
        
        reverser(vectorc);
        
    }
    
    
    /*!
     * Method that determines which vector is larger
     * @param first vector to be compared
     * @param second vector to be compared to the first
     * @return true if first vector is larger and false otherwise
     */
    bool BigNumbers::greater(std::vector<int> first, std::vector<int> second) {
        
        if (first.size() > second.size()) {
            return true;
        } else {
            return false;
        }
    }
    
    
    
    /*!
     * \brief method that compares the size of two vectors
     * @param v1 first vector
     * @param v2 second vector
     * @return bool determing whether v1 or v2 is of smaller size
     */
    //    bool BigNumbers::lesser(std::vector<int> v1, std::vector<int> v2) {
    //        int v1size = v1.size();
    //        int v2size = v2.size();
    //
    //        if (v2size < v1size) { return false; }
    //        for (int i = 0; i < v1size; i++){
    //                if (v1[i] > v2[i]) { return false; }
    //        }
    //        return false;
    //    }
    //
    
    
    
    
    
    
    
    
    
    
    
}//end namespace
