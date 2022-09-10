#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int min_swaps_to_bring1_together(vector<int>& nums){
    int total_ones =0, n= nums.size();
    for(int i =0; i < n; i++) if(nums[i]==1) total_ones++;
    int left=0, right=0, count=0;
    for(;right<total_ones; right++)if(nums[right]==1) count++;
    int max_ones_in_window = count;
    while(right<nums.size()){
        if(nums[right]==1) count++;
        if(nums[left]==1) count--;
        right++;left++;
        max_ones_in_window =  max(max_ones_in_window, count);
    }
    return total_ones-max_ones_in_window;
}

int main(){
    vector<int> nums;
    nums.push_back(1);nums.push_back(0);nums.push_back(0);nums.push_back(1);nums.push_back(0);nums.push_back(0);nums.push_back(1);
    cout<<min_swaps_to_bring1_together(nums);
}