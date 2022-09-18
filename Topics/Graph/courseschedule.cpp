#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj , int idx , vector<int>& visited, vector<int>& res){
    visited[idx] = 1;
    for(auto neighbor : adj[idx]){
        if(!visited[neighbor]){
            dfs(adj, neighbor, visited, res);
        }
    }
    res.push_back(idx);
}

