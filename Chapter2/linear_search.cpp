#include <iostream>
#include <vector>

template <typename T>

int linear_search(std::vector<T> a, T v){
    for (int i = 0; i < a.size(); i++){
        if (a[i] == v){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<double> a;
    a.push_back(1.239);
    a.push_back(2.129);
    a.push_back(412);
    a.push_back(3.1415);
    std::cout << linear_search(a, (double) 5) << std::endl;
}