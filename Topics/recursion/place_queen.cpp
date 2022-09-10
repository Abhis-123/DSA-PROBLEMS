#include <iostream>
using namespace std;

void printSolution(vector<vector<int>>& board){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
}

bool place_queen(vector<vector<int>>& board){

}

void solve(){
    int x,y;
    cin>>x>>y;
    x-=1;
    y-=1;
    vector<vector<int>> grid(8, vector<int>(8, 0));
    

}

int main() {
	// your code goes here
	int t ;
	std::cin >> t;
	while(t--){
	    solve();
	    cout<<"\n";
	}
	return 0;
}
