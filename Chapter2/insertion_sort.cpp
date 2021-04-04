#include <iostream>
#include <vector>
#include <stdlib.h>

template <typename T>

void insertion_sort(std::vector<T> &a){
    for (int j = 1; j < a.size(); j++){
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key){ // To make it in non-increasing order, a[i] < key
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main(){
    std::vector<float> a;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(rand() / 12492);
    }
    insertion_sort(a);
    std::cout << "[ " << a[0];
    for (int i = 1; i < a.size(); i++){
        std::cout << ", " << a[i];
    }
    std::cout << " ]" << std::endl;
}