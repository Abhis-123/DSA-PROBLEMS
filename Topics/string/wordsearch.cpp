//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(vector<vector<char>>& grid, string word,int idx, int row, int col, int row_d , int col_d){
        if(word.size()==idx) return true;
        if(row<0 || row >=grid.size())     return false;
        if(col<0 || col>= grid[0].size()) return false;
        
        if(grid[row][col]==word[idx]){
            return  search(grid, word, idx+1, row+row_d, col+col_d, row_d, col_d);
        }
        return false;
    }

	vector<vector<int>>  searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> res;
        int n = grid.size(), m = grid[0].size();
        for(int row=0; row< n ; row++){
            for(int col=0; col<m ; col++){
                // generate all directions 
                for(int i=-1; i<2; i++){
                    for( int j = -1; j<2; j++){
                        if(!(i==0 &&j==0) &&search(grid, word, 0, row, col, i , j)){
                            vector<int> temp= {row, col};
                            res.push_back(temp);
                            break;
                            break;
                        }
                    }
                }
            }
        }
        
        return res;

	}
        bool dfs(vector<vector<char>>& board, string word, int  indexex, int row, int col, unordered_set<string>& set){
        
        if(word.size()==indexex) return true;
        if(row>=board.size() || row<0) return false;
        if(col>=board[0].size() || col<0) return false;
        if(board[row][col]!=word[indexex]) return false;
        string temp= to_string(row)+ "-"+ to_string(col);
        // cout<<temp<<endl;
        if(set.findex(temp)!=set.end()) return false;
        set.insert(temp);
        bool q = dfs(board, word, indexex+1, row+1, col, set)||dfs(board, word, indexex+1, row-1, col, set)||dfs(board, word, indexex+1, row, col+1, set)||dfs(board, word, indexex+1, row, col-1, set);
        if(!q){
            set.erase(temp);
        }
        return q;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        unordered_set<string> set;
        int n = board.size(),  m= board[0].size();
        for(int i =0; i<n ; i++){
            for(int j =0; j<m ; j++){
                if(dfs(board, word, 0, i , j ,set)){
                 return true;   
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
};







#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n , k ;
    cin>>n>>k;
    vector<int> arr(2*n+1, 0);
    string str;
    cin>>str;
    int z = n-k +1;
    int count=0;
    for(int i =0; i<z ; i++){
        if((str[i]+count)%2==1){count++;arr[i+k-1]=1;}
        count=count-arr[i];
        str[i] = 48;
    }
   for(int i =z; i<n ; i++){
       str[i] = 48 + (str[i]+count)%2;
       count-=arr[i];
   }
   for(int i =0; i<n ; i++){
       cout<<str[i];
   }
}
int main() {
	// your code goes here
	int t ;
	std::cin >> t;
	while(t--){
	    solve();
	    cout<<'\n';
	}
	return 0;
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& numbuy, vector<int>& numsell) {\


        int n = numbuy.size(), m = numsell.size();

        if(n>m){return findMedianSortedArrays(numsell,numbuy);}

        int start = 0, end = n;

        int  mid_after_merging = (n+m+1)/2;

        while(start < end){
            int left1size = (start+end)/2;
            int left2size =  mid_after_merging - left1size;
            int left1max = left1size>0? numbuy[left1size-1] : INT_MIN;
            int left2max = left2size>0? numsell[left2size-1] : INT_MIN;
            int right1min = left1size<n? numbuy[left1size] : INT_MAX;
            int right2min = left2size<m?numsell[left2size] : INT_MAX;
            if(left1max<right2min && left2max<right1min){
                    if((m+n)%2==0){
                        return (double)(max(left1max, left2max)+ min(right1min, right2min))/2.0;
                    }
                    return (double)(max(left1max, left2max));
            }else if(left1max>right2min){
                    end = left1size - 1;
            }else{
                start = start + 1;
            }
        }
        return 0.0;
    }
};



class Solution {
public:
	int maxProfit(vector<int>& prices){
		if (prices.size() <= 1) return 0;
		vector<int> rest(prices.size(), 0);
		vector<int> buy(prices.size(), 0);
		vector<int> sell(prices.size(), 0);
		buy[0] = -prices[0];
		rest[0] = 0;
		sell[0] = INT_MIN;
		for (int i = 1; i < prices.size(); i++) {
			rest[i] = max(rest[i - 1], sell[i - 1]);
			buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
			sell[i] = buy[i - 1] + prices[i];
		}
		return max(rest[prices.size() - 1], sell[prices.size() - 1]);
	}
};