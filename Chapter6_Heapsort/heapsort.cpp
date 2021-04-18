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
        //temp = A[i];
        //A[i] = A[largest];
        //A[largest] = temp;
        std::swap(A[i], A[largest]);
        max_heapify(A, largest, n);
    }
}

// A is an array and n is its size
void build_max_heap(int A[], int n){
    for (int i = floor(n/2) - 1; i >= 0; i--)
        max_heapify(A, i, n);
}

void print_array(int A[], int n){
    for (int i = 0; i < n; i ++)
        std::cout << A[i] << " ";
    
    std::cout << std::endl;
}

void heapsort(int A[], int n){
    build_max_heap(A, n);
    for (int i = n - 1; i >= 0; i--){
        std::swap(A[0], A[i]);
        max_heapify(A, 0, i);
    }
}

int main(){
    int A[] = { 5, 13, 2, 25, 7, 17, 20, 8, 4 };
    int n = sizeof(A)/sizeof(A[0]);
    heapsort(A, n);
    print_array(A, n);
}