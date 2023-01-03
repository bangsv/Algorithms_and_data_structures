#include <math.h>

int LineSearch(int* A, size_t size, int key) {
    for (int i = 0; i < size; i++)
        if (A[i] == key)
            return i;
    return -1;
}

int BinarySearch(int* arr, int left, int right, int key) {
    int midd = 0;
    while (1) {
        midd = (left + right) / 2;

        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;
        if (left > right)
            return -1;
    }
}

int BlockSearch(int* mass, int size, int a) {
    int X = sqrt(size);
    for (int i = X; i < size; i = i + X) {
        if (mass[i] >= a) {
            for (int j = i - X; j <= i; j++) {
                if (mass[j] == a) {
                    return j;
                }
            }
            return -1;
        }
    }
}
