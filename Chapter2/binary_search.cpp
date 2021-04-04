#include <iostream>

int binary_search(int A[], int v, int low, int high){
    if (low > high) { // Couldn't find
        return -1;
    }
    int mid = floor((low + high)/2);
    if (v == A[mid]){
        return mid;
    }
    else if (v > A[mid]){
        return binary_search(A, v, mid + 1, high); // Upper half of the array
    }
    else {
        return binary_search(A, v, low, mid - 1); // Lower half of the array
    }
}

int main(){
    int A[] = { 12, 29129, -1024, 20, 52, 15, 27, 22 };
    int A_size = sizeof(A)/sizeof(A[0]);
    int el = 12;
    if (binary_search(A, el, 0, A_size) == -1){
        std::cout << "Element not in array!" << std::endl;
    }
    else{
        std::cout << el << " is at index " << binary_search(A, 12, 0, A_size) << "." << std::endl;
    }
}