class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product_of_all_non_zeroes = 1
        total_elements = len(nums)

        indexes_of_zeroes = []
        for index, num in enumerate(nums):
            if num == 0:
                indexes_of_zeroes.append(index)
            else:
                product_of_all_non_zeroes = product_of_all_non_zeroes * num

        result = []
        total_zeroes_in_list = len(indexes_of_zeroes)
        if total_zeroes_in_list == 0:
            result = [e for e in nums]
            for i in range(total_elements):
                result[i] = int(product_of_all_non_zeroes / nums[i])
        else:
            result = [0] * total_elements
            if total_zeroes_in_list == 1:
                for i in range(len(result)):
                    if nums[i] == 0:
                        result[i] = product_of_all_non_zeroes
        
        return result

            


                

                
        