/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& adj , int idx , vector<int>& visited, vector<int>& res){
        visited[idx] = 1;
        for(auto neighbor : adj[idx]){
            if(!visited[neighbor]){
                dfs(adj, neighbor, visited, res);
            }
        }
        res.push_back(idx);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses, vector<int>());
        for(auto pre: prerequisites){
            adj[pre[0]].push_back(pre[1]);
        }
        vector<int> order;
        vector<int> visited(numCourses, 0);
        for(int i =0 ; i<numCourses;i++){
                if(!visited[i]){
                    dfs(adj, i, visited,order);
                }
        }
        reverse(order.begin(), order.end());
        return order;

    }
};
// @lc code=end

