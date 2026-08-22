class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n

        # Pass 1: result[i] contains the product of all elements to the left of i
        prefix = 1
        for i in range(n):
            result[i] = prefix
            prefix *= nums[i]

        # Pass 2: Multiply by the product of all elements to the right of i
        suffix = 1
        for i in range(n - 1, -1, -1):
            result[i] *= suffix
            suffix *= nums[i]

        return result
            


                

                
        