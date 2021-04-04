#include <iostream>
#include <vector>

template <typename T>

void selection_sort(std::vector<T> &A){
    int n = A.size();
    int smallest = 0;
    T temp;
    for (int j = 0; j < n - 1; j++){
        smallest = j;
        for (int i = j + 1; i < n; i++){
            if (A[i] < A[smallest]) {
                smallest = i;
            }
        }
        temp = A[smallest];
        A[j] = A[smallest];
        A[smallest] = A[j];
    }
}

int main(){
    std::vector<double> a;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(rand() * 3.14/19248);
    }
    selection_sort(a);
    std::cout << "[ " << a[0];
    for (int i = 1; i < a.size(); i++){
        std::cout << ", " << a[i];
    }
    std::cout << " ]" << std::endl;
}