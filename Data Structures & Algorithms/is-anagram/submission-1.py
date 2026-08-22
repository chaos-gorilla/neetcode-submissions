class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        first_char_counts = dict()
        second_char_counts = dict()

        for ch in s:
            if ch not in first_char_counts:
                first_char_counts[ch] = 0
            first_char_counts[ch] = first_char_counts[ch] + 1
        
        for ch in t:
            if ch not in second_char_counts:
                second_char_counts[ch] = 0
            second_char_counts[ch] = second_char_counts[ch] + 1

        return second_char_counts == first_char_counts
        