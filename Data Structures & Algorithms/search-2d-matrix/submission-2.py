class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        total_rows, total_cols = len(matrix), len(matrix[0])
        begin, end = 0, len(matrix) - 1

        # find which row will our record be in?
        row_present_in = -1
        while begin <= end:
            mid_row = int((begin + end) / 2)
            if mid_row == total_rows - 1:
                row_present_in = mid_row
                break
            if matrix[mid_row][0] <= target < matrix[mid_row + 1][0]:
                row_present_in = mid_row
                break
            elif matrix[mid_row][0] > target:
                end = mid_row - 1
            else:
                begin = mid_row + 1
        
        return any(target == e for e in matrix[row_present_in])