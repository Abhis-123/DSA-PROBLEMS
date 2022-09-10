class Solution {
public:
    int dp[201][201];
    int lip(vector<vector<int>> &matrix, int i, int j, int prev) {
        if(i<0||j<0 || i>=matrix.size() || j>=matrix[0].size() || prev>=matrix[i][j]){return 0;}
        if(dp[i][j]) return dp[i][j];    
        int temp = matrix[i][j];    
        // matrix[i][j] =-1;
        int left = lip(matrix, i, j-1, matrix[i][j]);
        int right = lip(matrix, i, j+1, matrix[i][j]);
        int up = lip(matrix, i+1, j, matrix[i][j]);
        int down = lip(matrix, i-1, j, matrix[i][j]);
        // matrix[i][j] =temp;
        return dp[i][j] = 1 + max({up, down, left, right});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_length =0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j=0; j < matrix[0].size(); j++) {
                    max_length = max(max_length,lip(matrix, i,j, -1));
            }
        }
        return max_length;
    }
};