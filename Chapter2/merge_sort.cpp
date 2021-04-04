#include <iostream>
#include <vector>

void merge(int A[], int p, int q, int r){
    int n1 = q - p + 1; // Size of the first subarray (A[p..q])
    int n2 = r - q;     // Size of the second subarray (A[q+1..r])
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; i ++){
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = A[q + 1 + j];
    }
    
    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int p, int r) {
    if (p >= r) {
        return; // Returns recursively
    }
    int q = p + (r - p)/2;
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
}

void printArray(int A[], int size){
    for (int i = 0; i < size; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int A[] = { 12, 29129, -1024, 20, 52, 15, 27, 22 };
    int A_size = sizeof(A)/sizeof(A[0]);
    std::cout << "Given array is ";
    printArray(A, A_size);

    merge_sort(A, 0, A_size - 1);
    std::cout << "Sorted array is ";
    printArray(A, A_size);
}