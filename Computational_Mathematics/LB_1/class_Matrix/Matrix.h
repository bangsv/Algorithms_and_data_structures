#include<vector>
#include <algorithm> 
#include <iostream>
#include <initializer_list>
#include <cmath>

class Matrix {
public:
    Matrix() {}

    Matrix(int rows, int columns, int r) {
        for (int i = 0; i < rows; i++) {
            std::vector<double> row;
            for (int j = 0; j < columns; j++) {
                row.push_back(rand() % r * (double)1);
            }
            matrix.push_back(row);
        }
    }

    Matrix(int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            std::vector<double> row;
            for (int j = 0; j < columns; j++) {
                row.push_back(0);
            }
            matrix.push_back(row);
        }
    }

    Matrix(std::initializer_list<std::initializer_list<double>> list) {
        for (auto row : list) {
            std::vector<double> r;
            for (auto elem : row) {
                r.push_back(elem);
            }
            matrix.push_back(r);
        }
    }
/**
 * @brief Swaps the matrix with another matrix
 * 
 * @param mat_1 The matrix to be swapped with
 */
    void swap_matrix(Matrix& mat_1) {
        std::swap(matrix, mat_1.matrix);
    }

/**
 * pow_matrix()
 * 
 * This function takes an integer x as a parameter and raises each element of the matrix to the power of x.
 * 
 * @param x - the integer to raise each element of the matrix to
 */
    void pow_matrix(int x ){
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = pow(matrix[i][j], x);
            }
        }
    }
    
/**
 * Calculates the determinant of a matrix.
 * 
 * @return double  The determinant of the matrix
 */
    double det (){ 
        int n = matrix.size(); // size of the matrix
        double det = 1; // determinant
        // Search for maximum in this column
        for (int i = 0; i < n; i++) 
        {
            int k = i;
            for (int j = i + 1; j < n; j++)
                if (abs(matrix[j][i]) > abs(matrix[k][i]))
                    k = j;
            if (abs(matrix[k][i]) < 1e-9)
            {
                det = 0;
                break;
            }
            // Swap the maximum row with current row (column by column)
            std::swap(matrix[i], matrix[k]);
            if (i != k)
                det = -det;
            det *= matrix[i][i];
            // Make all rows below this one 0 in current column 
            for (int j = i + 1; j < n; j++)
                matrix[i][j] /= matrix[i][i];
            for (int j = 0; j < n; j++)
                if (j != i && abs(matrix[j][i]) > 1e-9)
                    for (int k = i + 1; k < n; k++)
                        matrix[j][k] -= matrix[i][k] * matrix[j][i];
        }
        return det;
    }

/**
* Straight_Gaussian_stroke()
* 
* This function performs Gaussian elimination on a matrix and returns a vector of the solutions. 
* 
* @param n The size of the matrix
* @param matrix The matrix to be solved
* @return x The vector of solutions
*/
    std::vector<double> Straight_Gaussian_stroke() {
        int n = matrix.size();
        // Search for maximum in this column 
        for (int k = 0; k < n; k++)
        {
        // Find the maximum element in the column 
            int i_max = k;
            int val_max = abs(matrix[k][k]);
            for (int i = k + 1; i < n; i++)
            {
                if (abs(matrix[i][k]) > val_max)
                {
                    i_max = i;
                    val_max = abs(matrix[i][k]);
                }
            }

            // Swap the maximum row with current row (column by column) 
            for (int j = 0; j < n + 1; j++)
            {
                int temp = matrix[k][j];
                matrix[k][j] = matrix[i_max][j];
                matrix[i_max][j] = temp;
            }
            // Make all rows below this one 0 in current column
            for (int i = k + 1; i < n; i++)
            {
                double factor = matrix[i][k] / matrix[k][k];
                for (int j = k; j < n + 1; j++)
                    matrix[i][j] -= factor * matrix[k][j];
            }
        }
        // Solve equation Ax=b for an upper triangular matrix A
        std::vector<double> x(n);

        // Start calculating from last equation up to the first
        for (int i = n - 1; i >= 0; i--)
        {   // x is an array whose values correspond to the values of x,y,z.. 
            x[i] = matrix[i][n] / matrix[i][i];
            for (int j = i - 1; j >= 0; j--)
            {
                matrix[j][n] -= matrix[j][i] * x[i];
            }
        }

        return x;
    }

/**
 * Reverse_Gaussian_stroke() is a function that takes a matrix and returns a vector of doubles.
 * It uses the Gaussian elimination method to solve a system of linear equations.
 * 
 * @param matrix The matrix to be solved
 * @return A vector of doubles containing the solution to the system of linear equations
 */
    std::vector<double> Reverse_Gaussian_stroke() {
        int n = matrix.size();
        // Search for maximum in this column 
        std::vector<double> x(n);
        // Start calculating from last equation up to the first
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = matrix[i][n] / matrix[i][i];
            for (int j = i - 1; j >= 0; j--)
            {
                matrix[j][n] -= matrix[j][i] * x[i];
            }
        }

        return x;
    }

/**
 * Adds two matrices together and returns the result
 * @param m The matrix to add to the current matrix
 * @return The result of the addition
 */
    Matrix operator+(const Matrix& m) {
        Matrix result;
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<double> row;
            // Add the elements of the given matrix to the elements of the current matrix 
            for (int j = 0; j < matrix[i].size(); j++) {
                row.push_back(matrix[i][j] + m.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }
        return result;
    } 

   
/**
 * Subtracts the elements of the given matrix from the elements of the current matrix.
 * 
 * @param m The matrix to subtract from the current matrix.
 * @return The matrix resulting from the subtraction of the two matrices.
 */
    Matrix operator - (const Matrix& m){
        Matrix result;
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<double> row;
            // Subtract the elements of the given matrix from the elements of the current matrix
            for (int j = 0; j < matrix[i].size(); j++) {
                row.push_back(matrix[i][j] - m.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }
        return result; 
    }
    
/**
 * This function multiplies two matrices and returns the result.
 * 
 * @param m The matrix to be multiplied with the current matrix.
 * @return The result of the multiplication.
 */
    Matrix operator * (const Matrix& m) {
    Matrix result(m.matrix.size(), m.matrix.size());
    for (int i = 0; i < m.matrix.size(); i++) {
        for (int k = 0; k < m.matrix.size(); k++) {
            for (int j = 0; j < m.matrix.size(); j++) 
                result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
        }
    }

        return result;
    } 
/**
 * Multiplies a matrix by a given number.
 * @param number The number to multiply the matrix by.
 * @return The resulting matrix after multiplication.
 */
    Matrix operator * (int number) {
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

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

private:
    std::vector<std::vector<double>> matrix;
};

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.matrix.size(); i++) {
        for (int j = 0; j < m.matrix[i].size(); j++) {
            os << m.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
