class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        ROWS, COLS = len(board), len(board[0])
        path = set()

        def dfs(r: int, c: int, pos: int) -> bool:
            if pos == len(word):
                return True

            # out of bounds check on the grid
            if (
                r < 0
                or c < 0
                or r >= ROWS
                or c >= COLS
                or (r, c) in path or board[r][c] != word[pos]
            ):
                return False

            path.add((r, c))  # add to the path
            res_of_further_steps = (
                dfs(r + 1, c, pos + 1)
                or dfs(r - 1, c, pos + 1)
                or dfs(r, c + 1, pos + 1)
                or dfs(r, c - 1, pos + 1)
            )
            path.discard((r, c))  # backtracking step
            return res_of_further_steps

        for i in range(ROWS):
            for j in range(COLS):
                if dfs(i, j, 0):
                    return True

        return False
