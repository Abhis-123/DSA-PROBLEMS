// If you carefully observe the below 3 codes.
// You will see that the DP Memoization is dervied from the Recursion code just by changing 3 lines and same is the case for DP Tabulation from Memoization.

// Recursion

class Solution {
public:
    int recursion(vector<int> wt, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        
        if (wt[n - 1] > w) 
            return 0 + recursion(wt, w - 0, n - 1);
        else 
            return min(0 + recursion(wt, w - 0, n - 1), 1 + recursion(wt, w - wt[n - 1], n));
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int minCoins = recursion(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};
// DP Memoization

class Solution {
public:
    int dp[10000 + 1][12 + 1];  // New Line Added
    
    int memoization(vector<int>& wt, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        
        if (dp[w][n] != -1) // New Line Added
            return dp[w][n];  // New Line Added
			
        if (wt[n - 1] > w) 
            return dp[w][n] = 0 + memoization(wt, w - 0, n - 1);
        else 
            return dp[w][n] = min(0 + memoization(wt, w - 0, n - 1), 1 + memoization(wt, w - wt[n - 1], n));
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp)); // New Line Added
        int minCoins = memoization(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};
// DP Tabulation

class Solution {
public:
    int dp[10000 + 1][12 + 1];
    
    int tabulation(vector<int> wt, int w, int n)
    {
        for (int i = 0; i < w + 1; i++)
            for (int j = 0; j < n + 1; j++)
                if (i == 0 || j == 0)
                    dp[i][j] = (i == 0) ? 0 : INT_MAX - 1;
        
        for (int i = 1; i < w + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (wt[j - 1] > i) 
                    dp[i][j] = 0 + dp[i - 0][j - 1];
                else 
                    dp[i][j] = min(0 + dp[i - 0][j - 1], 1 + dp[i - wt[j - 1]][j - 0]);
            }
        }
        
        return dp[w][n];
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        memset(dp, -1, sizeof(dp));
        int minCoins = tabulation(coins, amount, coins.size());
        return minCoins == INT_MAX - 1 ? -1 : minCoins;    
    }
};
// Update: Since this post has recieved a lot of upvotes, 
// I want to mention that the techniques that I have used to solve this problem.
//  I learnt it from the DP series by Aditya Verma on Youtube. I will highly suggest it to anyone who wants to learn DP.

// Note:
// In my code, wt = The array/coins that is under consideration,
//  w = The amount/money we have left remaining and n = The current element index under consideration.
// These abbreviations are basically derived from the knapsack question; wt = weight array, w = left weight and so on...