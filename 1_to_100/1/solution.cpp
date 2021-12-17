#include <iostream>  
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
int main(){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    int target = 9;
    // nums.push_back()
    vector<int> result = twoSum(nums, target);
    for(int i = 0; i < result.size(); i++){
           cout <<result[i] << endl;
    }


}