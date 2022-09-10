class Solution {
public:
    vector<int> next_greater_to_right(vector<int>& nums) {
            vector<int> result;
            stack<int> st;
            int n = nums.size()-1;
            while(n>=0){
                while(st.size()>0 && st.top()<nums[n]){
                    st.pop();
                }
            }
            result[n] = st.size()?st.top():-1;
            return result;
    }

    vector<int> next_greater_to_left(vector<int>& nums){
        
        stack<int> st;
        int n = nums.size()-1;
        vector<int> result(n+1,0);
        int i = 0;
        while(i<n){
            while(st.size()>0 && st.top()<nums[i]) st.pop();
            result[i] = st.size()?st.top():-1;
        }
        return result;
    }
    vector<int> next_greater_element(vector<int>& nums){
        stack<int> st;
        int n = nums.size();
        nums.insert(nums.end(),nums.begin(),nums.end());
        vector<int> res(nums.size(), -1);
        int i= 2*n-1;
        while(i>=0){
            while(st.size()>0 && st.top()<=nums[i]){st.pop();}
            res[i] = (st.size()==0)?-1:st.top();
            st.push(nums[i]);
        }       

        vector<int> v(res.begin(), res.begin()+n);
        return v;
    }

};