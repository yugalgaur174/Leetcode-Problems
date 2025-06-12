class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<char>> row(9);
        vector<set<char>> col(9);
        vector<set<char>> box(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    char a = board[i][j];

                    if (row[i].find(a) == row[i].end()) {
                        row[i].insert(a);
                    } else {
                        return false;
                    }

                    if (col[j].find(a) == col[j].end()) {
                        col[j].insert(a);
                    } else {
                        return false;
                    }

                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (box[boxIndex].find(a) == box[boxIndex].end()) {
                        box[boxIndex].insert(a);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
