#include <iostream>  
#include <bits/stdc++.h>
using namespace std;  

int longest_unique_substring_bruteforce(string str){
    // get length of string
    int string_length = str.size();
    // varia to store the longest_unique_subtring length
    int longest_unique_substring_length = 0;
    // iterate over all possible substrings
    // first pointer to track the elements of string
    for(int i = 0; i < string_length;i++){
        // second pointer to track the elements of string
        for(int j = 0; j < string_length; j++){
            // check weather the elements of string are unique or not
            bool is_unique = true;
            // a bool array to store the presence of a character in string
            vector<bool> presence(256);
            // iterate over the substring and count presence of each element
            for(int k=i;k<=j;k++){
                int temp_index = str[k];//-'a';
                if(temp_index<0){
                    temp_index = 255;
                }
                // cout<<" "<<temp_index<<endl;
                if(presence[temp_index]){
                    is_unique = false;
                    break;
                }else{
                    presence[temp_index] = true;
                }
            }

            // check is_unique
            if(is_unique){
                // update the max length of unique_subtring
                if (longest_unique_substring_length < j-i+1)
                {
                   longest_unique_substring_length = j-i+1;
                }
            }  
        }
    }

    return longest_unique_substring_length;

}

int longest_unique_substring_bruteforce_optim1(string str){
    // get length of string
    int string_length = str.size();
    // special case for size 1 string
    if(string_length ==1){
        return 1;
    }
    // variable to store the longest_unique_subtring length
    int longest_unique_substring_length = 0;
    // iterate over all possible substrings
    // first pointer to track the elements of string
    for(int i = 0; i < string_length;i++){
        // a vector array  to count occurrences of characters
        int char_occurrences[256] = {0};
        // iterate over all characters with second pointer
        for(int j = i; j < string_length; j++){
                int temp_index = str[j];
                // to capture whitespace characters
                if(temp_index < 0){
                    temp_index =255;
                }
            if (char_occurrences[temp_index]>0)
            {
                if(j-i>longest_unique_substring_length){
                    longest_unique_substring_length = j-i;
                }
                break;
            }else
            {
                char_occurrences[temp_index] = 1;
            }
            
        }
    }
    return longest_unique_substring_length;

}

int longest_unique_substring_bruteforce_hashing(string str){
    // get length of string
    int string_length = str.length();
    // special case for size 1 string
    if(string_length ==1){
        return 1;
    }
    // variable to store the longest unique subtring length
    int longest_unique_substring_length = 0;
    
}



int main(){
    int x = longest_unique_substring_bruteforce("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    cout << x << endl;
    x = longest_unique_substring_bruteforce_optim1("a");
    cout << x << endl;

}