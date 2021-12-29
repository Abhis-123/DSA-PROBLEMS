#include <iostream>
#include <bits/stdc++.h>  
#include <vector>  
using namespace std;  


vector<int> twoSum(vector<int> &nums, int target){
        // result vector to store the result
        vector<int> result;
        // size of nums array
        int size = nums.size();
        // first pointer to track the elements of input vector
        for(int i = 0;i<size;i++){
            /*second pointer to track the elements of output vector*/
            for(int j = i+1;j<size;j++){
                // match the sum of the two elements 
                if (nums[i]+nums[j]==target){
                    // break out of loop
                    // and push indexes in result vector
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
     return result;   
    }
vector<int> two_sum_hashing(vector<int> & nums, int target){
        // vector to store the result
        vector<int> result(2);
        // create a map object to store array elements and their indices
        map<int, int> num_map; 
        // get the size of the array
        int n = nums.size(), temp_find = 0;
        // iterate over the array
        for(int i=0; i<n;i++){
            // check for the compliment of the element in the array
            if(num_map.count(target-num_map[i])){
                result[0] =num_map[target-num_map[i]];
                result[1] = i;
                return result;
            }
            cout <<num_map[target-nums[i]]<<endl;
            // check for the element in the map 
            if(num_map[nums[i]]==0){
                    num_map[nums[i]]=i;
                    
            }
            
        }
        result[0] = 0;
        result[1] = 0;
        return result;
}
int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    // nums.push_back()
    vector<int> result = two_sum_hashing(nums, target);
    for(int i = 0; i < 2; i++){
           cout <<result[i] << endl;
    }


}