#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int helper1(vector<int>& nums, int i , int j , unordered_map<int,vector<int>>& map,vector<vector<int>>& dp){
    if(dp[i][j]!=-1){ return dp[i][j]; }
    int diff = nums[j] - nums[i];
    int next_num =  nums[j]+diff;
    dp[i][j]= 1;
    if(map.find(next_num)!=map.end()){
        for(auto x : map[next_num]){
            if(x>j){
                dp[i][j]=max(dp[i][j],1+ helper1(nums, j,x, map, dp));
            }else{
                break;
            }
    }
    }
    return dp[i][j];
}
int longestArithSeqLength1(vector<int>& nums){
    if(nums.size()<=2) return nums.size();
    int max_length = 2;
     int n  = nums.size();
    unordered_map<int,vector<int>>  map;
    for(int i = n-1; i>=0; i++) map[nums[i]].push_back(i);
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));    
    for(int i =n-2; i>=0;i--){
        for(int j = n-1;j>=i+1; j--){
            max_length = max(max_length,1+helper1(nums, i,j , map, dp));
        }
    }
    return max_length;
}


int longestArithSeqLength(vector<int>& nums){
    int n = nums.size(), res = 2;
    if(n<=2) return 2; 
    // min_max difference
    int dp[n][500*2+2];//-500 and +500 is the minimum and maximum difference
    int res = 1;
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++){
        for(int j =0; j<i; j++){
            int diff = nums[i]-nums[j];
            dp[i][diff] = 1+dp[j][diff];
            res = max(res , dp[i][diff]);
        }
    }
    return res+1;
}

int main(){
    vector<int> nums = {24,13,1,100,0,94,3,0,3};
    cout<<longestArithSeqLength(nums)<<endl;
}
