/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()<1) return s.size();
        string last_word="";
        int idx = 0 ;
        while(idx<s.size()){
            string temp="";
            while(idx<s.size() && s[idx]!=' '){idx++; temp +=s[idx];} 
            if(temp.size()>0) last_word = temp;
            idx++;
        }
        return last_word.size();
    }
};
// @lc code=end

