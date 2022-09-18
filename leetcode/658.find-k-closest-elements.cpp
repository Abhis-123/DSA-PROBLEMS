/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int>& nums, int key){
        int low =0,high = nums.size()-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(nums[mid]>=key){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size()==1) return arr;
        int idx = lower_bound(arr, x);
        int left = idx , right = idx+1;
        vector<int> res ;
        while(k--){
            int left_dist = left>=0?abs(arr[left]-x):INT_MAX;
            int right_dist = right<arr.size()?abs(arr[right]-x):INT_MAX;
            if(left_dist<=right_dist){
                res.push_back(arr[left]);left--;
            }else{
                res.push_back(arr[right]); right++;
            }
        }

        return res;
    }
};
// @lc code=end

