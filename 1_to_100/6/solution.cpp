#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str) { 
    int string_length = str.size();
    for (int i = 0; i < string_length/2;i++){
        if(str[i] != str[string_length-1-i]){
            return false;
        }
    }

    return true; 
    }

string longest_palindromic_substring(string str){
    // get length of string
    int length = str.size();
    // create variable for storing the substring 
    string s ="";
    // get all possible substrings
    // first pointer to track the elements of string
    for(int i = 0; i < length; i++){
        // second pointer to track the elements of string
        for(int j=i+1;j<length;j++){
            if(str[i]==str[j]){
                string temp_substring = str.substr(i,j+1);
                // cout<<i << temp_substring << j<<endl;
                if(isPalindrome(temp_substring) && (i-j+1)> s.size()){
                    s= temp_substring;
                }
            }
        }
    }
    return s;
}

string longest_palindromic_substring_optim1(string str){
    // map<int,vector<int>> characters_index_hash;
}

int main(){


    
   bool x = isPalindrome("bb");
   cout << x << endl;
}