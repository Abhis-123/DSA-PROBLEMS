def lengthOfLongestSubstring(s: str) -> int:
        if len(s)<2:
          return len(s)
        max_str = 1
        chars_hash = {}
        start_idx = 0 
        end_idx = 1
        chars_hash[s[0]] = 0
        length_of_string = len(s)
        while end_idx<length_of_string:
            print(f"{chars_hash} -> {start_idx}, {end_idx}")
            try :
                idx  = chars_hash[s[end_idx]]
                temp = end_idx-start_idx
                if temp>max_str:
                    max_str = temp
                start_idx= idx+1
                chars_hash = {}
                chars_hash[s[start_idx]] = start_idx
                end_idx = start_idx 
            except KeyError:
                chars_hash[s[end_idx]]= end_idx
            end_idx = end_idx+1
        temp = end_idx-start_idx
        if temp>max_str:
            max_str = temp 
        return max_str
                    


if __name__ == "__main__":
    print(lengthOfLongestSubstring("bbbbb"))