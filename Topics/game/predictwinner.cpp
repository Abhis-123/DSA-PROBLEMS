#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>& nums, int i ,int j){
    if ((i > j) || (i >= nums.size()) || (j < 0)) return 0;;
    if(i==j) return nums[i];

    int way1 = nums[i] + min(helper(nums,i+2,j), helper(nums, i+1,j-1));
    int way2 = nums[j] + min(helper(nums,i+1,j-1),helper(nums,i,j-2));
    return max(way1,way2);
}

bool PredictTheWinner(vector<int>& nums){
    int  sum = 0;
    for(auto x : nums) sum += x;
    int ourscore = helper(nums,0,nums.size()-1);
    if(sum - ourscore> ourscore) return false;
    return true;
}

int main(){
    vector<int> nums = {1,5,7};
    cout<<PredictTheWinner(nums)<<endl;
}