class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        begin_ptr = 0
        end_ptr = len(numbers) - 1

        while begin_ptr < end_ptr:
            sum = numbers[begin_ptr] + numbers[end_ptr]
            if sum == target:
                return [begin_ptr + 1, end_ptr + 1]
            elif sum < target:
                begin_ptr += 1
            else:
                end_ptr -= 1

        return [-1, -1]