class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_numbers = {}
        
        for index, n in enumerate(nums):
            to_find = target - n
            if to_find in seen_numbers:
                return [seen_numbers[to_find], index]
            seen_numbers[n] = index
        
        return [-1, -1]
            
