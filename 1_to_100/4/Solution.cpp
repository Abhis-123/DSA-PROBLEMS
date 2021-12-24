#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray_brute_force(vector<int> & nums){
    // create a max variable to hold the sum
    int max = -1000000;
    // get the size of the array
    int size = nums.size();
    // produce all possible subarray values
    // first pointer to the elements of the array
    for(int i = 0; i < size;i++){
            // variable to hold the temporary sum
            int temp_sum=0;
            // variable to hold the temporary max sum
            int temp_max_sum = -1000000;
            // second pointer to the elements of the array
            for(int j = i; j < size;j++){
                temp_sum+=nums[j];
                if(temp_max_sum<temp_sum){
                    temp_max_sum=temp_sum;
                }
            }
            // check if the sum of subarray is greater than max value
            if(temp_max_sum>max){
                max = temp_max_sum;
            }
    }
    return max;
}



int max_sum_subarray_kdane(vector<int>& nums){
        // create a max variable to hold the sum
        int max = -1000000;
        // get the size of the array
        int n = nums.size();
        // create a new variable to hold the temporary sum
        int current_sum = 0;

}

int main(){
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    int x = max_sum_subarray_brute_force(nums);
    cout << x << endl;
}