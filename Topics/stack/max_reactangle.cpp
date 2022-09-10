class Solution {
public:
    
     vector<int> left_min_index(vector<int>& nums){
        vector<int> res(nums.size(),0);
        stack<int> st;
        int i = 0;
         while(i < nums.size()){
             while(st.size()>0 && nums[st.top()]>= nums[i]) st.pop();
             res[i] = st.size()?st.top()+1: 0;
             cout<<res[i]<<" ";
             st.push(i);
             i++;
         }
         return res;
     }
    
     vector<int> right_min_index(vector<int>& nums){
        vector<int> res(nums.size(),0);
        stack<int> st;
        int i = nums.size()-1;
         while(i>=0){
             while(st.size()>0 && nums[st.top()]>= nums[i]) st.pop();
             res[i] = st.size()?st.top()-1: nums.size()-1;
             cout<<res[i]<<" ";
             st.push(i);
             i--;
         }
         return res;
     }
    int largestRectangleArea(vector<int>& height) {
        vector<int> left_min = left_min_index(height);
        cout<<endl;
        vector<int> right_min = right_min_index( height);
        int max_area =0;
        for(int i =0;i < height.size(); i++){
            max_area = max(max_area, (right_min[i]-left_min[i])*height[i]);
        }
        return max_area;
    }
};