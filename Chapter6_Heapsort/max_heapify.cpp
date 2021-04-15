#include <iostream>

// Receives an array A, the array size n, and the index i
void max_heapify(int A[], int i, int n){
    int largest = i; // Initialize largest as the root
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int temp = 0;

    if (l < n && A[l] > A[i])
        largest = l;
    if (r < n && A[r] > A[largest])
        largest = r;

    if (largest != i){
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        //std::swap(A[i], A[largest]);
        max_heapify(A, largest, n);
    }
}

void max_heapify_iterative(int A[], int i, int n){
    int largest = i;
    int r = 0, l = 0;
    while (i < n / 2) { // Once i hits n/2, A[i] will be a leaf
        l = 2 * i + 1;
        r = 2 * i + 2;
        i = largest;
        if (l < n && A[l] > A[largest])
            largest = l;
        if (r < n && A[r] > A[largest])
            largest = r;
        if (largest != i)
            std::swap(A[i], A[largest]);
        else break;
    }
}

void print_array(int A[], int n){
    std::cout << "Began printing:" << std::endl;

    for (int i = 0; i < n; i ++)
        std::cout << A[i] << std::endl;
    
    std::cout << "Ended printing" << std::endl;
}

int main() {
    int A[14] = { 27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0 };
    int n = sizeof(A)/sizeof(A[0]);
    int A1[14];
    for (int i = 0; i < n; i ++)
        A1[i] = A[i];
    print_array(A, n);
    print_array(A1, n);
    max_heapify(A, 2, n);
    max_heapify_iterative(A1, 2, n);
    print_array(A, n);
    print_array(A1, n);
}