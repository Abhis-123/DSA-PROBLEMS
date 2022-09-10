#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool dfs(int sv , vector<int> adj[] , vector<bool>&visited , int parent){

    visited[sv]=true;
    for(int i=0;i<adj[sv].size();i++){
        if(visited[adj[sv][i]]==false ){
            if(dfs(adj[sv][i] , adj, visited , sv)==true) return true;
        }else{
            if(adj[sv][i]!=parent){
                return true;
            }
        }
    }
        return false;
}



bool bfs(int v,int n, vector<int> adj[], vector<bool>& visited){
    queue<pair<int,int>> q;
    visited[v] = true;
    q.push({v, -1});
    while(!q.empty()){
        int node  = q.front().first;
        int parent = q.front().second;
        for(auto it : adj[node]){
                if(!visited[it){
                    visited[it] = true;
                    q.push({it, parent});
                }else{
                    if(adj[node][i] != parent){
                        return true;
                    }
                }
        }
    }
    return false;
}

int Solution::solve(int n, vector<vector<int>>& edges) {
    vector<bool> visited(n , false);
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++){
        int v=edges[i][0]-1;
        int u=edges[i][1]-1;
        if(v!=u){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false && dfs(i , adj , visited)==true){
            return true;
            }
    }
    return false;
}




int findNumberofLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> dp1(n,0), dp2(n,0);
    dp1[0] = 1;
    dp2[0] = 1;
    int max_length =1;
    for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                    if(nums[j]< nums[i]){
                        if(dp1[i]< dp1[j]+1){
                            dp1[i] = dp1[j]+1;
                            dp2[i] = dp2[j];
                        }else if(dp1[i]==dp1[j]+1){
                            dp2[i]+=dp2[j];
                        }
                    }
            }

        max_length = max(max_length,dp1[i]);
    }
    int count_LIS = 0;
    for(int  i =0; i < n; i++){
        if(dp1[i]==max_length){
            count_LIS+=dp2[i];
        }
    }

    return count_LIS;
    
}

int max_power(vector<int> powers){
    sort(powers.begin(), powers.end());
    int res = 0;
    int n = powers.size();
    for(int i = 0; i < powers.size(); i++){
        res = max(res, powers[i]*(n-i));
    }
    return res;
}
