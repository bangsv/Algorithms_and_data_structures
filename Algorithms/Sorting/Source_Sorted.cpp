#include "Header_Sorted.h"

void swap(int& one, int& two) {
    int tmp = one;
    one = two;
    two = tmp;
}

void bubbleSort(int* data, int size) {
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        for (int j = size - 1; j >= (i + 1); j--) {
            if (data[j] < data[j - 1]) {
                swap(data[j], data[j - 1]);
            }
        }
    }
}

void selectionSort(int* data, int size) {
    int j = 0;
    int tmp = 0;
    for (int i = 0; i < size; i++) {
        j = i;
        for (int k = i; k < size; k++) {
            if (data[j] > data[k]) {
                j = k;
            }
        }
        swap(data[i], data[j]);
    }
}

void insertionSort(int* data, int size) {
    int key = 0;
    int i = 0;
    for (int j = 1; j < size; j++) {
        key = data[j];
        i = j - 1;
        while (i >= 0 && data[i] > key) {
            data[i + 1] = data[i];
            i = i - 1;
            data[i + 1] = key;
        }
    }
}

void qSort(int* data, int const size) {
    int const lenD = size;
    int pivot = 0;
    int ind = lenD / 2;
    int i, j = 0, k = 0;
    if (lenD > 1) {
        int* L = new int[lenD];
        int* R = new int[lenD];
        pivot = data[ind];
        for (i = 0; i < lenD; i++) {
            if (i != ind) {
                if (data[i] < pivot) {
                    L[j] = data[i];
                    j++;
                }
                else {
                    R[k] = data[i];
                    k++;
                }
            }
        }
        qSort(L, j);
        qSort(R, k);
        for (int cnt = 0; cnt < lenD; cnt++) {
            if (cnt < j) {
                data[cnt] = L[cnt];;
            }
            else if (cnt == j) {
                data[cnt] = pivot;
            }
            else {
                data[cnt] = R[cnt - (j + 1)];
            }
        }
    }
}

void merge(int merged[], int lenD, int L[], int lenL, int R[], int lenR) {
    int i = 0;
    int j = 0;
    while (i < lenL || j < lenR) {
        if (i < lenL & j < lenR) {
            if (L[i] <= R[j]) {
                merged[i + j] = L[i];
                i++;
            }
            else {
                merged[i + j] = R[j];
                j++;
            }
        }
        else if (i < lenL) {
            merged[i + j] = L[i];
            i++;
        }
        else if (j < lenR) {
            merged[i + j] = R[j];
            j++;
        }
    }
}

void mergeSort(int data[], int lenD) {
    if (lenD > 1) {
        int middle = lenD / 2;
        int rem = lenD - middle;
        int* L = new int[middle];
        int* R = new int[rem];
        for (int i = 0; i < lenD; i++) {
            if (i < middle) {
                L[i] = data[i];
            }
            else {
                R[i - middle] = data[i];
            }
        }
        mergeSort(L, middle);
        mergeSort(R, rem);
        merge(data, lenD, L, middle, R, rem);
    }
}

void shellSort(int* A, int n) {
    int i, j, d, count;
    d = n;
    d = d / 2;
    while (d > 0)
    {
        for (i = 0; i < n - d; i++)
        {
            j = i;
            while (j >= 0 && A[j] > A[j + d])
            {
                count = A[j];
                A[j] = A[j + d];
                A[j + d] = count;
                j--;
            }
        }
        d = d / 2;
    }
}