// A Naive method to find maximum value of mat[d][e]
// - ma[a][b] such that d > a and e > b
#include <bits/stdc++.h>
using namespace std;

// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.
int findMaxValue(vector<vector<int>>& matrix)
{
	// stores maximum value
	int maxValue = INT_MIN;
    int n = matrix.size(), m = matrix[0].size();
    // create an array to hold the min value
    // we will iterate from top left to bottom right
    // let's first fill the 1st row of the array
    int curr_min = matrix[0][0];
    for (int i = 0; i < m; i++){curr_min = min(curr_min, matrix[0][i]); matrix[0][i] = curr_min;}
    // fill the first column of the array
    curr_min = matrix[0][0];
    for (int i = 0; i < n; i++){curr_min = min(curr_min, matrix[i][0]); matrix[i][0] = curr_min;}
    // iterate over the matrix
    for (int i = 1; i <n ; i++){
        for (int j = 1; j< m ; j++){
                // update the max difference between the elements of the array
                maxValue  = max(maxValue, matrix[i][j]- matrix[i-1][j-1]);
                // update the value of matrix 
                matrix[i][j] = min(matrix[i][j],matrix[i-1][j],matrix[i][j-1]);
        }
    }
    return maxValue;
}

// Driver program to test above function
int main()
{
vector<vector<int>> mat({{ 1, 2, -1, -4, -20 },{ -8, -3, 4, 2, 1 },{ 3, 8, 6, 1, 3 },{ -4, -1, 1, 7, -6 },{ 0, -4, 10, -5, 1 }});
	cout << "Maximum Value is "
		<< findMaxValue(mat);

	return 0;
}
