class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check

        for (auto& r : board) {
            unordered_set<char> s;
            for (auto i : r) {
                if (s.contains(i)) return false;
                if (i == '.') continue;
                s.insert(i);
            }
        }

        // column check

        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;
            for (int j = 0; j < 9; j++) {
                if (s.contains(board[j][i])) return false;
                if (board[j][i] == '.') continue;
                s.insert(board[j][i]);
            }
        }

        // sub box check
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<char> s;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (s.contains(board[i * 3 + k][j * 3 + l])) return false;
                        if (board[i * 3 + k][j * 3 + l] == '.') continue;
                        s.insert(board[i * 3 + k][j * 3 + l]);
                    }
                }
            }
        }

        return true;
    }
};
