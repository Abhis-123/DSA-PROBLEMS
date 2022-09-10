class Solution {
public:
    string longestPrefix(string s) {
        int i =0;
        int n = s.size();
        for(int j = 0; j < s.length(); j++) {
                if(s[j]==s[n-j-1]){
                    i++;
                }else{
                    break;
                }
        }
        return i;
    }
    int largestRectangleArea(vector<int>& heights) {

        int n = height.size()
        int min_left[n];
        min_left[0] = height[0];
        int min_right[n];
        min_right[n-1] = height[n-1];
        for(int i = 1;i<n;i++) {
            min_left[i] =min(min_left[i-1], height[i]);
            min_right[n-i-1] = min(min_right[n-i], height[n-i-1]);
        }
        int max_area=0;
        int low =0, high =n-1;
        while(high>=low){
            max_area = max(max_area,(high-low)* min(min_left[low], min_right[high]));
        }
        return max_area;
    }
};
