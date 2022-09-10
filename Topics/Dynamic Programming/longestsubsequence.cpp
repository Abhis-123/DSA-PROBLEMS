//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int nums[]){
        vector<int> seq(n+1,0);
        int max_length =1;
        seq[0] = 1;
        for(int i=0; i<n ; i++){
                for(int j=0; j<i;j++){
                    if(nums[i]-nums[j] ==1 ||nums[i]-nums[j] ==-1){
                        dp[i] = max(dp[i], dp[j]);
                    }
                }
                dp[i]++;

                max_length = max(max_length, dp[i]);
        }
        return max_length;    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends