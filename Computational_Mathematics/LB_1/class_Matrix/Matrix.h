#include<vector>
#include <algorithm> 
#include <iostream>
#include <initializer_list>
#include <cmath> 

/**
 * Matrix class
 * 
 * This class is used to represent a matrix of numbers. It provides methods for performing 
 * operations on the matrix such as addition, subtraction, multiplication, and division.
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
 * @return double  The determinant of the matrix
 */
    int Determinant ();

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

// *********************************************************************************************************************
   
   
    Matrix Matrix::Minor(int row, int column){
        Matrix result;
        for (int i = 0; i < matrix.size(); i++) {
            if (i == row) continue;
            std::vector<double> row;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (j == column) continue;
                row.push_back(matrix[i][j]);
            }
            result.matrix.push_back(row);
        }
        return result;
    }
    
    Matrix Matrix::Inverse(){
        Matrix result;
        double det = this->Determinant();
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<double> row;
            for (int j = 0; j < matrix[i].size(); j++) {
                row.push_back(pow(-1, i + j) * Minor(i, j).Determinant());
            }
            result.matrix.push_back(row);
        }
        result.T();
        result = result * (1 / det);
        return result;
    }


    bool  Matrix::check_Diagonal(){
        for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][i] == 0) return false;
        }
        return true;
    } 

    Matrix::Matrix(int rows, int columns, int r) {
        for (int i = 0; i < rows; i++) {
            std::vector<double> row;
            for (int j = 0; j < columns; j++) {
                row.push_back(rand() % r * (double)1);
            }
            matrix.push_back(row);
        }
    }

    Matrix::Matrix(int rows, int columns) {
        for (int i = 0; i < rows; i++) {
            std::vector<double> row;
            for (int j = 0; j < columns; j++) {
                row.push_back(0);
            }
            matrix.push_back(row);
        }
    }

    Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
        for (auto row : list) {
            std::vector<double> r;
            for (auto elem : row) {
                r.push_back(elem);
            }
            matrix.push_back(r);
        }
    }

    void Matrix::swap_matrix(Matrix& mat_1) {
        std::swap(matrix, mat_1.matrix);
    }

    void Matrix::pow_matrix(int x ){
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = pow(matrix[i][j], x);
            }
        }
    }


    int Matrix::Determinant() {
        int n = matrix.size();
        int det = 0;
        if (n == 1) {
            return matrix[0][0];
        }
        if (n == 2) {
            return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
        }
        for (int i = 0; i < n; i++) {
            Matrix mat = Minor(0, i);
            det += pow(-1, i) * matrix[0][i] * mat.Determinant();
        }
        return det;   
    }


    void Matrix::T () { // Transpose a matrix
        Matrix mat(matrix[0].size(), matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j <matrix[0].size(); j++) {
                mat.matrix[j][i] = matrix[i][j];
            }
        }
        swap_matrix(mat);
    }


    std::vector<double> Matrix::Gaussian_8(std::vector<double> b) {
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
            std::swap(matrix[i_max], matrix[k]);
            std::swap(b[i_max], b[k]);

            // Make all rows below this one 0 in current column 
            for (int i = k + 1; i < n; i++)
            {
                double c = -matrix[i][k] / matrix[k][k];
                for (int j = k; j < n; j++)
                {
                    if (k == j)
                        matrix[i][j] = 0;
                    else
                        matrix[i][j] += c * matrix[k][j];
                }
                b[i] += c * b[k];
            }
        }

        // Solve equation Ax=b for an upper triangular matrix A 
        std::vector<double> x(n);
        for (int i = n - 1; i >= 0; i--)
        {
            x[i] = b[i];
            for (int j = i + 1; j < n; j++)
                x[i] -= matrix[i][j] * x[j];
            x[i] /= matrix[i][i];
        }
        return x;
    }

    std::vector<double> Matrix::Straight_Gaussian_stroke() {
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


    std::vector<double> Matrix::Reverse_Gaussian_stroke() {
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


std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.matrix.size(); i++) {
        for (int j = 0; j < m.matrix[i].size(); j++) {
            os << m.matrix[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

Matrix operator * (Matrix one, Matrix two) {
    Matrix result(one.matrix.size(), one.matrix.size());
    for (int i = 0; i < one.matrix.size(); i++) {
        for (int k = 0; k < one.matrix.size(); k++) {
            for (int j = 0; j < one.matrix.size(); j++) 
                result.matrix[i][j] += one.matrix[i][k] * two.matrix[k][j];
        }
    }

        return result;
  }

    Matrix operator - (Matrix one, Matrix two) {
        Matrix result;
        for (int i = 0; i < one.matrix.size(); i++) {
            std::vector<double> row;
            // Subtract the elements of the given matrix from the elements of the current matrix
            for (int j = 0; j < one.matrix[i].size(); j++) {
                row.push_back(one.matrix[i][j] - two.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }
        return result;
    }

    Matrix operator + (Matrix one, Matrix two) {
        Matrix result;
        for (int i = 0; i < one.matrix.size(); i++) {
            std::vector<double> row;
            // Add the elements of the given matrix to the elements of the current matrix 
            for (int j = 0; j < one.matrix[i].size(); j++) {
                row.push_back(one.matrix[i][j] + two.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }
        return result;
    }


std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << "x"<< i +1<<": "<< vec[i] << std::endl;
    }
    os << std::endl;
    return os;
} // *********************************************************************************************************************