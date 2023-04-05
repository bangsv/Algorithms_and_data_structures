#include <vector>
#include <algorithm> 
#include <iostream>
#include <initializer_list>
#include <cmath> 

/**
 * Matrix class
 * 
 * This class is used to represent a matrix of numbers. It provides methods for performing 
 * operations on the matrix such as addition, subtraction, multiplication, and etc.
 */
class Matrix {
public:
/**
 * Matrix() is a constructor that creates a new Matrix object.
 */
    Matrix() {}

/**
 * Constructor for Matrix class
 * @param rows - number of rows in the matrix
 * @param columns - number of columns in the matrix
 * @param r - maximum random value for each element in the matrix
 */
    Matrix(int rows, int columns, int r);

/**
 * Constructor for Matrix object.
 * 
 * @param rows The number of rows in the matrix.
 * @param columns The number of columns in the matrix.
 */
    Matrix(int rows, int columns);

/**
 * Constructor for the Matrix class.
 * 
 * Creates a Matrix object from a given initializer list.
 * 
 * @param list The initializer list to create the Matrix from.
 */
    Matrix(std::initializer_list<std::initializer_list<double>> list);

/**
 * @brief Swaps the matrix with another matrix
 * 
 * @param mat_1 The matrix to be swapped with
 */
    void swap_matrix(Matrix& mat_1);

/**
 * pow_matrix()
 * 
 * This function takes an integer x as a parameter and raises each element of the matrix to the power of x.
 * 
 * @param x - the integer to raise each element of the matrix to
 */
    void pow_matrix(int x );
    
/**
 * Calculates the determinant of a matrix.
 * 
 * @return int  The determinant of the matrix
 */
    int Determinant ();

/**
 * Calculates the determinant of a matrix using the Gaussian elimination method.
 * 
 * @returns The determinant of the matrix as a double.
 */
    double Determinant_Gausse();

/**
 * T() is a function that transposes a matrix and swaps it with the original matrix.
 * 
 * @param matrix The matrix to be transposed and swapped.
 */
    void T ();

/**
 * Calculates the minor of a matrix at a given row and column
 * 
 * @param row The row of the matrix to calculate the minor of
 * @param column The column of the matrix to calculate the minor of
 * 
 * @return The minor of the matrix at the given row and column
 */

    Matrix Minor(int row, int column);

/**
 * Calculates the inverse of a matrix.
 * 
 * @return the inverse of the matrix
 */
    Matrix Inverse();

/**
 * check_Diagonal()
 * 
 * Checks if the elements in the diagonal of a matrix are equal.
 * 
 * @return bool - Returns true if the elements in the diagonal are equal, false otherwise.
 */
    bool check_Diagonal();

/**
 * Gaussian_8() is a function that implements the Gaussian elimination algorithm to solve a system of linear equations.
 * 
 * @param b The vector of constants from the linear equations.
 * @return A vector of the solutions to the linear equations.
 */
    std::vector<double> Gaussian_8(std::vector<double> b);
    
/**
* Straight_Gaussian_stroke()
* 
* This function performs Gaussian elimination on a matrix and returns a vector of the solutions. 
* 
* @param n The size of the matrix
* @param matrix The matrix to be solved
* @return x The vector of solutions
*/
    std::vector<double> Straight_Gaussian_stroke();

/**
 * Reverse_Gaussian_stroke() is a function that takes a matrix and returns a vector of doubles.
 * It uses the Gaussian elimination method to solve a system of linear equations.
 * 
 * @param matrix The matrix to be solved
 * @return A vector of doubles containing the solution to the system of linear equations
 */
    std::vector<double> Reverse_Gaussian_stroke();

/**
 * @brief Checks if a vector contains infinity
 * 
 * @param x Vector to be checked
 * @return True if vector contains infinity, false otherwise
 */
    friend bool check_inf(std::vector<double> x);

/**
 * Adds two matrices together and returns the result
 * @param m The matrix to add to the current matrix
 * @return The result of the addition
 */
    friend Matrix operator + (Matrix one, Matrix two);
/**
 * Subtracts the elements of the given matrix from the elements of the current matrix.
 * 
 * @param m The matrix to subtract from the current matrix.
 * @return The matrix resulting from the subtraction of the two matrices.
 */
    friend Matrix operator - (Matrix one, Matrix two);

/**
 * This function multiplies two matrices and returns the result.
 * 
 * @param m The matrix to be multiplied with the current matrix.
 * @return The result of the multiplication.
 */
  friend Matrix operator * (Matrix one, Matrix two);

/**
 * Multiplies a matrix by a given number.
 * @param number The number to multiply the matrix by.
 * @return The resulting matrix after multiplication.
 */
    Matrix operator * (double number) {
        Matrix result;
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<double> row;
            for (int j = 0; j < matrix[i].size(); j++) {
                row.push_back(matrix[i][j] * number);
            }
            result.matrix.push_back(row);
        }
        return result;
    } 

/**
 * @brief Overloaded operator for outputting a Matrix object to an output stream
 * 
 * @param os The output stream to output the Matrix object to
 * @param m The Matrix object to be outputted
 * 
 * @return A reference to the output stream
 */
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

private:
    std::vector<std::vector<double>> matrix;
};

std::ostream& operator<<(std::ostream& os, std::vector<double> m);
