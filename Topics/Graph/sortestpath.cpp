#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj, int n, int src)
{
    vector<int> distances(n, INT_MAX);
    queue<int> q;
    q.push(src);
    distances[src] = 0;

    while (q.size() > 0)
    {
        int curr = q.front();
        q.pop();
        for (auto neighbor : adj[curr])
        {
            if (distances[neighbor] > distances[curr] + 1)
            {
                distances[neighbor] = distances[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    return distances;
}

string fractionToDecimal(int numerator, int denominator)
{
    vector<int> quotient;
    unordered_set<string> rems;
    while (numerator != 0)
    {
        if (rems.find(to_string(numerator)) != rems.end())
            break;
        cout << numerator << endl;
        rems.insert(to_string(numerator));
        if (numerator >= denominator)
        {
            quotient.push_back(numerator / denominator);
            numerator = numerator % denominator;
            if (numerator != 0 && numerator < denominator)
                numerator *= 10;
        }
        else
        {
            numerator *= 10;
            quotient.push_back(0);
        }
    }
    string res = "" + to_string(quotient[0]);
    if (quotient.size() > 0 && quotient[0] == 0)
        res += ".";

    for (int i = 1; i < quotient.size(); i++)
    {
        res += to_string(quotient[i]);
    }
    return res;
}

bool connected_to_border(vector<vector<char>>& matrix,int i , int j){
    if(i<0||j<0 || i>=matrix.size() || j>=matrix[0].size()) return true;
    if(matrix[i][j]=='X') return false;
    bool q = true;
    q = q&connected_to_border(matrix, i-1, j);
    q = q&connected_to_border(matrix, i+1, j);
    q = q&connected_to_border(matrix, i, j-1);
    q = q&connected_to_border(matrix, i, j+1);
    if(q) matrix[i][j]='X';
    return q;
}

int main()
{


}