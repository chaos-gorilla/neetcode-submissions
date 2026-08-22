class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # iterative approach, which number can be the starting point.
        nset = set()
        
        for num in nums:
            nset.add(num)

        longest_streak = 0
        for e in nums:
            if e - 1 not in nset:
                # then we can build a ladder from here
                begin = e
                streak = 1
                while begin + 1 in nset:
                    begin += 1
                    streak += 1
                longest_streak = max(longest_streak, streak)
        
        return longest_streak
        