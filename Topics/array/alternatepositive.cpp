//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
void swap(vector<int> & nums, int i , int j ){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
vector<int> rearrangeArray(vector<int>& nums) {
        
        int  n=nums.size();
        int pos = 0, neg = 1;
        while(pos<n && neg <n){
            if(nums[pos]<0){
                while(nums[neg]<0){
                    neg+=2;
                }
                swap(nums, pos, neg);
                pos+=2;
                neg+2;
            }else if(nums[neg]>=0){
                    while(nums[pos]>=0){
                        pos+=2;
                    }
                    swap(nums, pos, neg);
                    pos+=2;
                    neg+2;
            }else{
                pos+=2;
                neg+2;
            }
        }
        return nums;
        
}

//{ Driver Code Starts.

int main() {
    int arr[] = {1,2,4,5,-2,-4,-2,-4};
    int n = sizeof(arr) / sizeof(arr[0]);
  
    vector<int> vect(arr, arr + n);
    vect =rearrangeArray(vect);
    for (int i = 0; i < vect.size(); i++){
            cout << vect[i] << " ";
    }
    cout << "\n";
    return 0;
}

// } Driver Code Ends