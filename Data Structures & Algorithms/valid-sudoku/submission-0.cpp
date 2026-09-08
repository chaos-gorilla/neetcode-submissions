class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        map<pair<int, int>, unordered_set<char>> square_blocks;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                // check if we have seen the element in the rows before.
                char ch = board[row][col];

                if (ch == '.') {
                    continue;
                }

                if (rows[row].find(ch) != rows[row].end() or cols[col].find(ch) != cols[col].end()) {
                    return false;
                }
                
                // check the square_blocks.
                if (square_blocks[{row / 3, col / 3}].find(ch) != square_blocks[{row / 3, col / 3}].end()) {
                    return false;
                }

                // Update all the sets.
                square_blocks[{row / 3, col / 3}].insert(ch);
                rows[row].insert(ch);
                cols[col].insert(ch);
            }
        }

        return true;
    }
};
