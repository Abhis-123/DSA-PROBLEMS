#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
            // check for lenght of strings 
            if(s.size()==0 || t.size()==0) return "";
            vector<int> mapt(128,0) ;
            for(int i=0; i<t.size(); i++) mapt[t[i]]++; //
            // get number of unique characters in string t 
            int count =0; for(int i= 0 ; i< 128 ; i++) if(mapt[i]>0)count++;
            // get the size of string s 
            int n = s.size();
            // an ans variable to keep track of minimum window
            vector<int> ans = {0,n};
            int l = 0, r =0;
            // a map to keep track of the number of characters in window
            vector<int> mapw(128,0) ;
            // a count of the number of unique characters in window
            int countw=0;
            while(r<n){
                mapw[s[r]]++;
                if(mapw[s[r]]==mapt[s[r]]){
                    countw++;
                }
                while(l<=r && countw==count){
                        if(ans[1]-ans[0]> r-l) ans = {l,r};
                        mapw[s[l]]--;
                        if(mapw[s[l]]<mapt[s[l]]){
                            countw--;
                        }
                        l++;
                }
                r++;
            }
            return s.substr(ans[0], ans[1]-ans[0]+1);
    }

int main(){
    cout<<minWindow("helloworld","helo");
}


