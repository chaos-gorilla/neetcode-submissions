class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = -1
        n = len(heights)

        left = 0
        right = n - 1

        while left < right:
            breadth = right - left
            height = min(heights[left], heights[right])
            area = breadth * height
            max_area = max(area, max_area)

            if (heights[left] <= heights[right]):
                left += 1
            elif (heights[left] > heights[right]):
                right -= 1
        
        return max_area
