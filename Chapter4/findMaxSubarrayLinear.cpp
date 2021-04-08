#include <iostream>

typedef struct{
    int left;
    int right;
    int sum;
} MaxSubArray;

MaxSubArray findMaximumSubarrayLinear(int A[], int low, int high){
    MaxSubArray best = { 0, 0, 0 };
    MaxSubArray curr = { 0, 0, 0 };
    for (int i = low; i < high; i++){
        curr.sum += A[i];
        if (curr.sum > best.sum){
            best.sum = curr.sum;
            best.left = curr.left;
            best.right = i;
        }
        if (curr.sum < 0){
            curr.sum = 0;
            curr.left = i + 1;
        }
    }
    return best;
}

int main()
{
    int arr[] = { 13, -3, -25, 20, 3, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxSubArray s = findMaximumSubarrayLinear(arr, 0, n - 1);
    std::cout << "The sum of the maximum subarray is " << s.sum << std::endl;
}