#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& dp){
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    int res = n; 
    for(int i =1 ; i<n ; i++){
        res = max(res, i*solve(n-i, dp));
    }
    return dp[n]= res;
}

void dfs(string s , int idx, unordered_set<string>& words,vector<string>& sent,vector<string>& res){
    if(idx>=s.size()){
        string sentence =sent[0]; 
        for(int i = 1 ; i< sent.size(); i++) sentence+=" "+sent[i];
        res.push_back(sentence); 
        return;
    }
    for(int i = idx+1;i<=s.size(); i++){
        if(words.find(s.substr(idx, i-idx))!=words.end()){
            sent.push_back(s.substr(idx, i-idx));
            dfs(s,i,words,sent, res);
            sent.pop_back();
        }
    }
}

vector<string> wordBreak(string s,vector<string>& wordDict) {
        vector<string> res ; 
        unordered_set<string> words; 
        vector<string> sent;
        for(int i  = 0 ; i < wordDict.size();i++) words.insert(wordDict[i]);
        dfs(s, 0 ,words,sent,res);
        sort(res.begin(), res.end());
        return res;
}

bool can_cross_helper(vector<int>& stones, int index , int k, unordered_map<int, int>& num_idx, vector<vector<int>>& dp){
    if(index==stones.size()-1) return true;
    if(dp[index][k]!=-1) return dp[index][k];
    if(k==0) return dp[index][k]=false;
    if(num_idx.find(stones[index]+k+1)!=num_idx.end() && can_cross_helper(stones,num_idx[stones[index]+k+1],k+1,num_idx, dp)) return dp[index][k]=true;
    if(num_idx.find(stones[index]+k)!=num_idx.end() && can_cross_helper(stones,num_idx[stones[index]+k],k,num_idx, dp)) return dp[index][k]=true;
    if(num_idx.find(stones[index]+k-1)!=num_idx.end() && can_cross_helper(stones,num_idx[stones[index]+k-1],k-1,num_idx, dp)) return dp[index][k]=true;
    return dp[index][k]=false;
}

bool canCross(vector<int>& stones) {
        unordered_map<int, int> hashmap;
        for(int i=0 ; i<stones.size(); i++) hashmap[stones[i]] = i;
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return can_cross_helper(stones,1,1,hashmap, dp);
}
int main(){
    // int n = 10; 
    // vector<int> dp(n+1, -1);
    // cout<<solve(n, dp);
    // string s = "catsanddog";
    // vector<string> wordDict = {"cat","cats","and","sand","dog"};
    // wordBreak(s,wordDict);
    vector<int> stones= {0,1,2,3,4,8,9,11};
    cout<<canCross(stones);
}