#include <bits/stdc++.h>
using namespace std;


// kmp
int match_string(string s1, string s2) {
        // get the length of the strings
        int n1 = s1.size(), n2 = s2.size();
        vector<int> table(n2+1, 0);
        return 0;
}

// is string s2 a shuffled substring of s1
bool is_string_substring(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if(n2>n1) return false;
    vector<int> table(256, 0);
    for(int i= 0; i <n2; i++) {
        table[s2[i]]++;
    }
    int start = 0, end = s2.size()-1;
    while(end<n1) {
        vector<int> temp_map= table;
        for(int i=start; i<end; i++) {
                temp_map[s1[i]]--;
        }
        bool q = true;
        for(int i=0; i<256; i++) {
            cout <<temp_map[s1[i]]<<" ";
                if(temp_map[i]!=0){
                    q = false;
                    break;
                }
        }
        cout <<endl;
        if (q) return true;
        start++; 
        end++;

    }
    return false;
}

int main(){
    cout <<is_string_substring("hellofourtwooneworld","onetwofour")<<endl;
    return 0;
}