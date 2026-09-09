class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # base condition, return empty string.
        if not s or len(s) < len(t):
            return ""

        char_counts_t = defaultdict(int)
        unique_chars = 0

        # populate the t dictionary
        for ch in t:
            if ch not in char_counts_t:
                unique_chars += 1
            char_counts_t[ch] += 1

        left = 0
        min_length = float("infinity")
        starting_index = -1
        char_counts_s = defaultdict(int)
        satisfied_chars = 0

        # expand the window to the right
        for right in range(len(s)):
            ch = s[right]
            char_counts_s[ch] += 1

            if char_counts_t[ch] > 0 and char_counts_s[ch] == char_counts_t[ch]:
                satisfied_chars += 1
            
            # shrink the window by moving the left pointer
            while satisfied_chars == unique_chars:
                char_left = s[left]
                # move the left pointer, update the answer.
                current_window_length = right - left + 1
                if current_window_length < min_length:
                    min_length = current_window_length
                    starting_index = left
                
                # remove left char from the window
                char_counts_s[char_left] -= 1
                # we check the conditions again, to see if a valid char was removed from the 
                # window.
                if char_counts_t[char_left] > 0 and char_counts_s[char_left] < char_counts_t[char_left]:
                    satisfied_chars -= 1
                
                left += 1
            
        return "" if starting_index == -1 else s[starting_index:starting_index + min_length]




        
        