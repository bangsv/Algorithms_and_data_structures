#include <iostream>
#include "Header_binMatrix.h"


void outputallRelations(Matrix one) {
    auto lymb = [](bool flag) {
        if (flag == 0)
            return "No";
        return "Yes"; };

    std::cout << "Reflexivity:\t " << lymb(one.reflexive()) << std::endl;
    std::cout << "Antireflexivity: " << lymb(one.anti_reflexive()) << std::endl;
    std::cout << "Symmetry:\t " << lymb(one.symmetric()) << std::endl;
    std::cout << "Antisymmetry:\t " << lymb(one.anti_symmetric()) << std::endl;
    std::cout << "Transitivity:\t " << lymb(one.transitive()) << std::endl;
    std::cout << "Equivalence:\t " << lymb(one.CheckEquivalence(one)) << std::endl;
    std::cout << "Order:\t\t " << lymb(one.CheckOrder(one)) << std::endl;
    std::cout << "Tolerance:\t " << lymb(one.CheckTolerance(one)) << std::endl;
}

int main() {

    srand(time(NULL));

    Matrix test = { { 1,0,0,1 }, {1,0,1,0} };
    Matrix A;
    Matrix B;
    Matrix C;

    A.rand_matrix(5);
    B.rand_matrix(5);

    std::cout << "test:\n" << test << std::endl;

    std::cout << "A:\n" << A << std::endl;
    std::cout << "B:\n" << B << std::endl;


    C = A ^ (B & A);

    std::cout << "Answer C: " << C << std::endl;
    std::cout << "!Answer C: " << !C << std::endl;

    std::cout << "Relations:\n" << "A: " << std::endl;
    outputallRelations(A);

    std::cout << std::endl << "B: " << std::endl;
    outputallRelations(B);

    std::cout << std::endl << "C: " << std::endl;
    outputallRelations(C);

}


