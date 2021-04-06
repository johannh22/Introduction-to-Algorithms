// Divide and Conquer approach to solve the maximum subarray sum problem
#include <iostream>

// Auxiliary function to find maximum of two integers
int max(int a, int b){
    return (a >= b) ? a : b;
}

// Auxiliary function to find maximum of three integers
int max(int a, int b, int c){
    return max(max(a, b), c);
}

// Find the maximum subarray that crosses the midpoint
int maxCrossingSubarray(int arr[], int low, int mid, int high){
    // Checks right half
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--){
        sum += arr[i];
        if (sum > left_sum){
            left_sum = sum;
        }
    }

    // Checks right half
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid + 1; j <= high; j++){
        sum += arr[j];
        if (sum > right_sum){
            right_sum = sum;
        }
    }
    // Note: in case of [-5, 3], left_sum + right_sum < right_sum
    return max(left_sum, right_sum, left_sum + right_sum);
}

int findMaximumSubarray(int arr[], int low, int high){
    if (high == low)
    { 
        return arr[high];
    }
    else
    {
        int mid = floor( (low + high) / 2 );
        int left_sum = findMaximumSubarray(arr, low, mid); // Search for right half
        int right_sum = findMaximumSubarray(arr, mid + 1, high); // Search for left half
        int cross_sum = maxCrossingSubarray(arr, low, mid, high); // Search one that crosses
        /* Three possible cases:
            1. Maximum subarray in left half;
            2. Maximum subarray in right half;
            3. Maximum subarray crosses the middle; */
        return max(left_sum, right_sum, cross_sum);
    }
}

// Testing program
int main()
{
    int arr[] = { 13, -3, -25, 20, 3, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = findMaximumSubarray(arr, 0, n - 1);
    std::cout << "The sum of the maximum subarray is " << sum << std::endl;
}