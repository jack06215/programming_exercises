class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        char_arr = set()
        left = right = result = 0
        str_size = len(s)
        
        # scan through each character, and update set() as it goes
        # increment by 1 "right" if unique char is found
        # or increment by 1 "left" if repeated char is found        
        while right < str_size:
            if s[right] in char_arr:
                char_arr.remove(s[left])
                left = left + 1
            else:
                char_arr.add(s[right])
                right = right + 1
                # (right - left) gives the length of longest substring at current step
                # so, max(result, right - left) will return the longest substring
                result = max(result, right - left)
                
            # print('{}\nleft:{} right:{} result:{}\n\n'.format(characters, left, right, result))
        return result

solution = Solution()
input_str = 'abcabcbb'
print(solution.lengthOfLongestSubstring(input_str))