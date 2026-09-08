class Solution {
    const int TOTAL_ROWS = 9;
    const int TOTAL_COLS = 9;
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /**
            State Tracking
            -> rows: stores the characters seen row wise.
            -> cols: stores the set of characters seen in a given col.
            -> squares: normalised storage of the characters seen in each blocks.
        */
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> square_blocks;

        for (int row = 0; row < TOTAL_ROWS; row++) {
            for (int col = 0; col < TOTAL_COLS; col++) {
                char ch = board[row][col];

                if (ch == '.') {
                    continue;
                }

                // 1. Check the rows and cols, if they contain duplicate characters in the same line.
                if (rows[row].find(ch) != rows[row].end() or cols[col].find(ch) != cols[col].end()) {
                    return false;
                }
                
                const pair<int, int> sudoku_block_index = {row / 3, col / 3};
                // 2. Check the square brackets, and see if there are duplicate elements in the same block.
                if (square_blocks[sudoku_block_index].find(ch) != square_blocks[sudoku_block_index].end()) {
                    return false;
                }

                // 3. Mark it as a valid move, and then update all the sets we are maintaining.
                square_blocks[sudoku_block_index].insert(ch);
                rows[row].insert(ch);
                cols[col].insert(ch);
            }
        }

        return true;
    }
};
