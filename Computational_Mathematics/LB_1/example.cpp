#include <iostream>
#include "class_Matrix\Matrix.h"
#include <ctime>  

/** 
* @brief This is the main function of the program
* @return int
*/
int main() {

    Matrix exis_1({{1,1,1,-10}, {1,1,1,-20}, {1,1,1,-30}});
    Matrix exis_1_2 = exis_1;
    
    Matrix exis_2({{5,-2,3},{3,-5,3},{8,-4,0}});
    Matrix exis_2_check = exis_2.Inverse(), res_check,answer;
    
    Matrix exis_3_A({{4,0,-6},{1,-1,5},{7,8,-4}}),
    exis_3_B({{-3,2,1},{7,-7,2},{6,4,5}});
    
    std::cout << "====================" << std::endl;
    std::cout << "Task 1: 0.5 * A + B*A + 2B" << std::endl;
    answer =  (exis_3_A * 0.5) + exis_3_B * exis_3_A + (exis_3_B * 2) ;
    std::cout << "Answer:\n" << answer << std::endl; 

    std::cout << "====================" << std::endl;
    std::cout << "Task 2" << std::endl;
    std::cout << "====================" << std::endl;
    std::cout << "1)Det: " << exis_2.Determinant() << std::endl;
    std::cout << "2)A^-1:\n" << exis_2_check << std::endl;
    res_check = exis_2_check * exis_2;
    std::cout << "Check answer: " << (res_check.check_Diagonal() ? "True" : "False") << std::endl; 
    std::cout << "====================" << std::endl;
    std::vector<double> x_straight,x_reverse; 
    std::cout << "Task 3" << std::endl;
    std::cout << "====================" << std::endl;
    //x_straight = exis_1.Reverse_Gaussian_stroke(); 
    x_reverse = exis_1_2.Straight_Gaussian_stroke();

    std::cout << "x_straight: " << std::endl << x_straight; 
    std::cout << "x_reverse: " << std::endl << x_reverse << std::endl ; 
    std::cout << "====================" << std::endl;
}