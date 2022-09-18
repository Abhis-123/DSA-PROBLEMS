/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> st;
        for(int i = nums2.size()-1 ; i>=0; i--){
            while(st.size()>0 && st.top()<nums2[i]) st.pop();
            map[nums2[i]] = st.size()>0?st.top():-1;
            st.push(nums2[i]);
        }
        vector<int> res ;
        for (auto i : nums1)
        {
                res.push_back(map[i]);            
        }
        return res;
        
    }
};
// @lc code=end

