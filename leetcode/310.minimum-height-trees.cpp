/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:

    int height(vector<vector<int>>& adj, int idx){
        int res = 0;
        for(auto neighbor: adj[idx]){
            if(neighbor!=idx){
                res = max(res, 1 + height(adj, neighbor));
            }
        }
        return res;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n , vector<int>());
        for(auto pair : edges){
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }
        unordered_map<int, vector<int>> height_map;
        int min_height=INT_MAX;
        for(int i=0 ; i< n; i++){
            int h = height(adj, i);
            height_map[h].push_back(i);
            min_height = min(h, min_height);
        }
        return height_map[min_height];
    }
};
// @lc code=end

