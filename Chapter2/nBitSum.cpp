#include <iostream>
#include <vector>

std::vector<int> nBit_sum(std::vector<int> A, std::vector<int> B){
    std::vector<int> C (A.size() + 1);
    for (int i = 0; i < A.size(); i ++){
        if (A[i] + B[i] + C[i] == 2){
            C[i] = 0;
            C[i+1] = 1;
        }
        else if (A[i] + B[i] + C[i] == 3){
            C[i] = 1;
            C[i+1] = 1;
        }
        else {
            C[i] = A[i] + B[i] + C[i];
        }
    }
    return C;
}

int main(){
    std::vector<int> A (3, 1);
    std::vector<int> B;
    B.push_back(0);
    B.push_back(0);
    B.push_back(1);
    std::vector<int> C;
    C = nBit_sum(A, A);
    for (int i = C.size() - 1; i >= 0; i --){
        std::cout << C[i];
    }
    std::cout << std::endl;
}