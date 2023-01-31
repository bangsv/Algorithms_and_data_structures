#include "Matrix.h"

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


// Input matrix 
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

    double Matrix::Determinant_Gausse() {
        double det = 1;

        for (int i = 0; i < matrix.size(); i++) {
            int pivot = i;
            for (int j = i + 1; j < matrix.size(); j++) {
                if (fabs(matrix[j][i]) > fabs(matrix[pivot][i])) {
                    pivot = j;
                }
            }
            std::swap(matrix[i], matrix[pivot]);
            if (pivot != i) {
                det *= -1;
            }

            det *= matrix[i][i];
            for (int j = i + 1; j < matrix.size(); j++) {
                double t = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k < matrix.size(); k++) {
                    matrix[j][k] -= t * matrix[i][k];
                }
                matrix[j][i] = 0;
            }
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
       // Reduction to a triangular form
        for (int i = 0; i < matrix.size(); i++) {
            int pivot = i;
            for (int j = i + 1; j < matrix.size(); j++) {
                if (fabs(matrix[j][i]) > fabs(matrix[pivot][i])) {
                    pivot = j;
                }
            }
            std::swap(matrix[i], matrix[pivot]);
            std::swap(b[i], b[pivot]);

            for (int j = i + 1; j < matrix.size(); j++) {
                double t = matrix[j][i] / matrix[i][i];
                for (int k = i + 1; k < matrix.size(); k++) {
                    matrix[j][k] -= t * matrix[i][k];
                }
                b[j] -= t * b[i];
                matrix[j][i] = 0;
            }
        }

        // reverse motion
        std::vector<double> x(matrix.size());
        for (int i = matrix.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < matrix.size(); j++) {
                b[i] -= matrix[i][j] * x[j];
            }
            x[i] = b[i] / matrix[i][i];
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
        for (int j = 0; j < m.matrix[i].size(); j++)
            os << m.matrix[i][j] << "\t";
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
        for(int i = 0; i < one.matrix.size(); i++){
            std::vector<double>  temporary_vec;
            std::transform(one.matrix[i].begin(), one.matrix[i].end(), two.matrix[i].begin(), 
            std::back_inserter(temporary_vec), std::minus<double>());
            result.matrix.push_back(temporary_vec);
        }
        return result;
    }

            /**
 * This code uses the std::transform function to add the elements of two matrices, 
 * one and two, and store the result in a third matrix, result.
 * The std::plus<double>() function is used to add the elements of the matrices.
 * The result is stored in a temporary vector, temporary_vec, which is then pushed back into the result matrix.
 */
    Matrix operator + (Matrix one, Matrix two) {
        Matrix result;
        for(int i = 0; i < one.matrix.size(); i++){
            std::vector<double>  temporary_vec; // temporary vector for each row 
            std::transform(one.matrix[i].begin(), one.matrix[i].end(), two.matrix[i].begin(), 
            std::back_inserter(temporary_vec), std::plus<double>());
            result.matrix.push_back(temporary_vec);
        }
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const std::vector<double>& vec) {
        for (int i = 0; i < vec.size(); i++) 
            os << "x"<< i +1<<": "<< vec[i] << std::endl;
        os << std::endl;
        return os;
} // *********************************************************************************************************************
