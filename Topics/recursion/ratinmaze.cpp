//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void sol(vector<vector<int>> &m, int n , vector<string>& res, string s, int  i, int j){
        if(i>=n || j >=n || i<0 || j<0 || m[i][j]==0) return;
        if(i==n-1 && j ==n-1){
            res.push_back(s);
        }
        m[i][j] =0;
        sol(m, n, res,s+'R', i, j+1);
        sol(m, n, res,s+'D', i+1, j);
        sol(m, n, res,s+'U', i-1, j);
        sol(m, n, res,s+'L', i, j-1);
        m[i][j] =1;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
         if(m[0][0] == 0 || m[n-1][n-1] == 0) return {"-1"};
        vector<string> res;
        sol(m, n, res ,"", 0,0);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends