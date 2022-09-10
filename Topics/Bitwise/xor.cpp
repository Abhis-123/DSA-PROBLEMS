#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string longestSubsequenceRepeatedK(string s, int k) {
        string res= "";
        for(int i=0;i<s.size();i++){
            int count =1;
            for(int j =i+1 ; j<s.size();j++){
                if(s[i]==s[j]) {
                    // cout<<count<< "\n";
                    count++;
                    }
            }
            // cout<<count<<endl;
            if(count>=k){
                res= res+s[i];
                }
        }
        return res;
    }
int main(int argc, char **argv){

    cout<<longestSubsequenceRepeatedK("bb",2)<<endl;
    return 0;
}