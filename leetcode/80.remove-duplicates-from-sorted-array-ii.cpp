/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int low =0,curr_idx = 0;
        int res=0;
        int n = nums.size();
        if(n<=2) return 2;
        while (curr_idx<nums.size()){
            int freq = 1;
            while(curr_idx<n-1 && nums[curr_idx]==nums[curr_idx+1]){freq++;curr_idx++;}
            if(freq==1){
                nums[low]=nums[curr_idx];
                res++;
                low++; 
            }else if(freq>=2){
                nums[low]=nums[low+1]=nums[curr_idx];
                low+=2;
                res+=2;
            }
            curr_idx++;
        }
        return res;
    }
};
// @lc code=end

