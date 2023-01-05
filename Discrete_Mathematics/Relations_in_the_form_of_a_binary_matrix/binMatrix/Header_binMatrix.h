#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

typedef std::vector<std::vector<bool>> dataBin;

std::vector<bool> __time_vec;

class Matrix {
public:

    Matrix();

    Matrix(std::initializer_list<std::initializer_list<bool>> list);

    Matrix(dataBin vec);

    void rand_matrix(int n);

    bool reflexive();

    bool anti_reflexive();

    bool symmetric();

    bool anti_symmetric();

    bool transitive();

    bool CheckTolerance(Matrix one);

    bool CheckEquivalence(Matrix one);

    bool CheckOrder(Matrix one);

private:

    dataBin __data_matrix;
    std::vector<bool> __time;

    friend void check_size_assert(Matrix one, Matrix two);
    friend std::ostream& operator<<(std::ostream& os, Matrix data);
    friend bool operator == (Matrix one, Matrix two);
    friend Matrix operator | (Matrix one, Matrix two);
    friend Matrix operator & (Matrix one, Matrix two);
    friend Matrix operator - (Matrix one, Matrix two);
    friend Matrix operator ^ (Matrix one, Matrix two);
    friend Matrix operator ~ (Matrix one); // (-1)
    friend Matrix operator ! (Matrix one);
    friend Matrix operator * (Matrix one, Matrix two); // ( А o В )

};

Matrix::Matrix() {
    __data_matrix.resize(0);
}

Matrix::Matrix(std::initializer_list<std::initializer_list<bool>> list) {

    std::vector<bool> __time_var;
    for (auto x : list) {
        for (auto j : x) {
            __time_var.push_back(j);
        }
        __data_matrix.push_back(__time_var);
        __time_var.clear();
    }
}


Matrix::Matrix(dataBin vec) {
    __data_matrix = vec;
}

void Matrix::rand_matrix(int n) {
    __data_matrix.clear();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            __time.push_back(rand() % 2);
        }
        __data_matrix.push_back(__time);
        __time.clear();
    }
}

void check_size_assert(Matrix one, Matrix two) {
    bool size = one.__data_matrix.size() == two.__data_matrix.size();
    assert(size == true, "Different sizes of values");

}

std::ostream& operator<<(std::ostream& os, Matrix data) {
    std::cout << "{" << std::endl;
    for (int i = 0; i < data.__data_matrix.size(); i++) {
        std::cout << "{";
        for (int j = 0; j < data.__data_matrix[i].size(); j++) {
            if (j == data.__data_matrix[i].size() - 1) {
                std::cout << data.__data_matrix.at(i).at(j) << "},";
                break;
            }
            std::cout << data.__data_matrix.at(i).at(j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << "}" << std::endl;


    return os;
}

Matrix operator | (Matrix one, Matrix two) {
    check_size_assert(one, two);
    Matrix ret;
    for (int x = 0; x < one.__data_matrix.size(); x++) {
        for (int y = 0; y < two.__data_matrix.size(); y++) {
            __time_vec.push_back(one.__data_matrix.at(x).at(y) ||
                two.__data_matrix.at(x).at(y));
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;
}

Matrix operator & (Matrix one, Matrix two) {
    check_size_assert(one, two);
    Matrix ret;

    for (int x = 0; x < one.__data_matrix.size(); x++) {
        for (int y = 0; y < two.__data_matrix.size(); y++) {
            __time_vec.push_back(one.__data_matrix.at(x).at(y) &&
                two.__data_matrix.at(x).at(y));
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;

}

Matrix operator - (Matrix one, Matrix two) {
    check_size_assert(one, two);
    Matrix ret;

    for (int x = 0; x < one.__data_matrix.size(); x++) {
        for (int y = 0; y < two.__data_matrix.size(); y++) {
            __time_vec.push_back(one.__data_matrix.at(x).at(y) >
                two.__data_matrix.at(x).at(y));
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;
}

Matrix operator ^ (Matrix one, Matrix two) {
    check_size_assert(one, two);
    Matrix ret;

    for (int x = 0; x < one.__data_matrix.size(); x++) {
        for (int y = 0; y < two.__data_matrix.size(); y++) {
            __time_vec.push_back(one.__data_matrix.at(x).at(y) ^
                two.__data_matrix.at(x).at(y));
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;
}

Matrix operator ~ (Matrix one) {
    Matrix ret;
    for (int i = 0; i < one.__data_matrix.size(); i++) {
        for (int j = 0; j < one.__data_matrix.size(); j++) {
            __time_vec.push_back(one.__data_matrix.at(j).at(i));
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;
}

Matrix operator ! (Matrix one) {
    Matrix ret;
    for (auto x : one.__data_matrix) {
        for (auto y : x) {
            __time_vec.push_back(y ^ true);
        }
        ret.__data_matrix.push_back(__time_vec);
        __time_vec.clear();
    }
    return ret;
}

Matrix operator * (Matrix one, Matrix two) {
    check_size_assert(one, two);
    Matrix ret(one);
    for (int i = 0; i < one.__data_matrix.size(); i++) {
        for (int j = 0; j < two.__data_matrix.size(); j++) {
            ret.__data_matrix[i][j] = false;
            for (int z = 0; z < two.__data_matrix.size(); z++) {
                ret.__data_matrix[i][j] = ret.__data_matrix[i][j] ||
                    one.__data_matrix[i][z] && two.__data_matrix[z][j];
            }
        }
    }
    return ret;
}

bool operator == (Matrix one, Matrix two) {
    return one.__data_matrix == two.__data_matrix;
}

bool Matrix::reflexive() {
    bool bool_res = true;

    for (int i = 0; i < __data_matrix.size(); ++i) {
        bool_res = __data_matrix[i][i] == 1;
        if (!bool_res)
            return  bool_res;
    }
    return  bool_res;
}

bool Matrix::anti_reflexive() {
    bool bool_res = true;

    for (int i = 0; i < __data_matrix.size(); ++i) {
        bool_res = __data_matrix[i][i] == 0;
        if (!bool_res)
            return  bool_res;
    }
    return  bool_res;
}

bool Matrix::symmetric() {
    bool bool_res = true;
    for (int i = 0; i < __data_matrix.size(); ++i) {
        for (int j = i + 1; j < __data_matrix.size(); ++j) {
            bool_res = __data_matrix[i][j] == __data_matrix[j][i];
            if (!bool_res)
                return  bool_res;
        }
    }
    return  bool_res;
}

bool Matrix::anti_symmetric() {
    bool    bool_res = true;

    for (int i = 0; i < __data_matrix.size(); ++i)
    {
        for (int j = i + 1; j < __data_matrix.size(); ++j)
        {
            bool_res = __data_matrix[i][j] * __data_matrix[j][i] == 0;

            if (!bool_res)
                return  bool_res;
        }
    }
    return  bool_res;
}

bool Matrix::transitive() {
    bool    bool_res = true;
    for (int i = 0; i < __data_matrix.size(); ++i) {
        for (int j = 0; j < __data_matrix.size(); ++j) {
            for (int k = 0; k < __data_matrix.size(); ++k) {
                bool_res = __data_matrix[i][j] >= std::min
                (
                    __data_matrix[i][k],
                    __data_matrix[k][j]
                );
                if (!bool_res)
                    return  bool_res;
            }
        }
    }

    return  bool_res;
}

bool Matrix::CheckTolerance(Matrix one) { // Проверка на толерантность
    if (one.reflexive() && one.symmetric()) return true;
    return false;
}

bool Matrix::CheckEquivalence(Matrix one) { // Проверка на эквивалентность.
    if (((one.reflexive() && one.symmetric()) && one.transitive()))
        return true;
    return false;
}

bool Matrix::CheckOrder(Matrix one) { // Проверка на порядок
    if (one.anti_symmetric() && one.transitive()) return true;
    return false;
}