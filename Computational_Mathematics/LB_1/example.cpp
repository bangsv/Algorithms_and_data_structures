#include <iostream>
#include "class_Matrix\Matrix.h"
#include <ctime>  

#define SIZE 3

std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << " ";
    }
    os << std::endl;
    return os;
} 

int main() {

    Matrix matrix_1(SIZE, SIZE, 100);
    Matrix matrix_2(SIZE,SIZE,100);
    Matrix result;

    std::cout << "Matrix 1:\n " <<matrix_1 << std::endl; 

    std::cout << "Matrix 2:\n " << matrix_2 << std::endl; 

    std::cout << "==============" << std::endl;

   result = matrix_1 * matrix_2; 

    std::cout << "Result:\n " << result << std::endl;

    std::cout << "Determinant: " << matrix_1.det() << std::endl; 

    return 0;

}
