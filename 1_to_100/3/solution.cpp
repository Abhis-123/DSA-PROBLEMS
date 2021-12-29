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
        for(int j = i+1; j < string_length; j++){
           
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
                // updating the longest_unique_substring_length
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

int longest_unique_substring_hashing(string str){
    // get length of string
    int string_length = str.length();
    // special case for size 1 string
    if(string_length ==1){
        return 1;
    }
    // variable to store the longest unique subtring length
    int longest_unique_substring_length = 0;
    // as each char can  be represented by a int (ASCII code) , it means
    // the indexes of the array elements can be used as hashes of characters
    // the actual hashmap can also be used to store the hashes and the elements indexes
    int character_hash[256] = {-1};
    // create two pointers to the array elements
    // start index of the temptorary subarray
    int start_inidex = 0;
    // end index of the temptorary subarray
    int end_inidex = 1;
    // store the length of temporary substring
    int temp_unique = 0;
    // the 0th element in the hashmap 
    character_hash[str[start_inidex]] = start_inidex;
    // run two pointers
    while(end_inidex<=string_length){

        // check if the character exist in the hashmap 
        // else append that in  the hashmap
        if(character_hash[end_inidex]!=-1){
            int idx  = character_hash[str[end_inidex]];
            // get the temporary substring till this pointer
            // which is having all the characters unique
            temp_unique = end_inidex - start_inidex;
            // update longest unique substring
            if(temp_unique> longest_unique_substring_length){
                longest_unique_substring_length = temp_unique;
            } 
            // move the start index to one step after the repeated character
            start_inidex = idx + 1;
            // move the end index to one step after the start index of new substring
            end_inidex = start_inidex +1;
            // reset the hashmap
            memset(character_hash,-1,256);
            // add the start index character to the hashmap
            character_hash[str[start_inidex]] = start_inidex;

        }else{
            character_hash[str[end_inidex]] = end_inidex;
            end_inidex++;
        }
        
    } 
    // check the end substring length once again
    if(temp_unique> longest_unique_substring_length){
        longest_unique_substring_length = temp_unique;
    }
    return longest_unique_substring_length;
    
}



int main(){
    int x = longest_unique_substring_bruteforce("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    cout << x << endl;
    x = longest_unique_substring_hashing("hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
    cout << x << endl;

}