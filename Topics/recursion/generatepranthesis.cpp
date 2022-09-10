#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

vector<string> generate_parantheses(int n){

    vector<string> res;
    if(n==1){
        res.push_back("()");
        return res;
    }
    vector<string> prev = generate_parantheses(n-1);

    for(int i =0; i < prev.size(); i++){
        string s = "(" + prev[i] + ")";
        res.push_back(s);
        s = "()"+prev[i];
        res.push_back(s);
         if(s !=prev[i]+"()"){
                res.push_back(prev[i]+"()");
            }
    }
    return res;
}

int main(){
    int n=4;
    vector<string> res = generate_parantheses(n);
    for(int i = 0; i<res.size(); i++){
        temp.erase(res[i]);
    }

}