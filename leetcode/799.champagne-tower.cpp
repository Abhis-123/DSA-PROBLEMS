/*
 * @lc app=leetcode id=799 lang=cpp
 *
 * [799] Champagne Tower
 */

// @lc code=start
class Solution {
public:
    double max(double a, double b){
        return a<b?b:a;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> tower;
        tower.push_back({(double)poured});
        for(int i=1 ; i<=query_row; i++){
            vector<double> row(i+1, 0); 
            for(int j=0 ; j<=i ;j++){
                if(j-1>=0){
                    row[j] +=max(0, tower[i-1][j-1]-1)/2;
                }
                if(j<i){
                    row[j] += max(0, tower[i-1][j]-1)/2;
                }
            }
            tower.push_back(row);
        }
        if(tower[query_row][query_glass]>1) return 1;
        return tower[query_row][query_glass];
    }
};
// @lc code=end

