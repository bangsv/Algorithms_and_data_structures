#include "Header_Combin.h"

typedef std::vector<int> vec_int;

//Implementation of algorithms for geneating subsets.
void binary_subset(int k, int n, vec_int subset) {
    if (k == n + 1) {
        for (int i = 0; i < subset.size(); i++) {
            std::cout << subset[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        subset.push_back(1);
        binary_subset(k + 1, n, subset);
        subset.pop_back();
        subset.push_back(0);
        binary_subset(k + 1, n, subset);
    }
}

void number_subset(int k, int n, vec_int subset) {
    if (k == n + 1) {
        for (int i = 0; i < subset.size(); i++) {
            std::cout << subset[i] << " ";
        }
        std::cout << std::endl;
        subset.resize(0);
    }
    else {
        subset.push_back(k);
        number_subset(k + 1, n, subset);
        subset.pop_back();
        number_subset(k + 1, n, subset);
    }
}

// Generating combinations
bool Combinations(vec_int& a, int n, int m) {
    int k = m;
    for (int i = k - 1; i >= 0; --i)
        if (a[i] < n - k + i + 1)
        {
            ++a[i];
            for (int j = i + 1; j < k; ++j)
                a[j] = a[j - 1] + 1;
            return true;
        }
    return false;
}

// Print combinations
void Print(vec_int& a, int n) {
    static int num = 1;
    std::cout << num++ << ": ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}


// Generating permutations
void swap(vec_int& a, int i, int j){
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}


bool Permutations(vec_int& a, int n) {
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1]) j--;
    if (j == -1)
        return false;
    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1;
    while (l < r)
        swap(a, l++, r--);
    return true;
}
