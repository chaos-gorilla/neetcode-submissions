class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen_numbers: dict[int, int] = {}

        for index, num in enumerate(nums):
            to_find = target - num
            if to_find in seen_numbers:
                return [seen_numbers[to_find], index]
            seen_numbers[num] = index
        
        return [-1, -1]

        