def lengthOfLongestSubstring(s: str) -> int:
        if len(s)<2:
          return len(s)
        # max str variable to store global longest string of unique chars
        max_substring_length = 1
        chars_hash = {}
        start_idx = 0 
        end_idx = 1
        chars_hash[s[0]] = 0
        length_of_string = len(s)
        while end_idx<length_of_string: #
            print(f"{chars_hash} -> {start_idx}, {end_idx}")
            try :
                idx  = chars_hash[s[end_idx]]
                temp = end_idx-start_idx
                if temp>max_substring_length:
                    max_substring_length = temp

                start_idx= idx+1
                chars_hash = {}
                chars_hash[s[start_idx]] = start_idx
                end_idx = start_idx 
            except KeyError:
                chars_hash[s[end_idx]]= end_idx
            end_idx = end_idx+1
        temp = end_idx-start_idx
        if temp>max_substring_length:
            max_substring_length = temp 
        return max_substring_length
                    


if __name__ == "__main__":
    print(lengthOfLongestSubstring("bbbbb"))