/*
Determine if a Sudoku is valid,
according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled,
where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable.
Only the filled cells need to be validated.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool hash[10];
        int raw, col;
        // valide each col
        for (col = 0; col < 9; col++) {
            memset(hash, 0, sizeof(hash));
            for (raw = 0; raw < 9; raw++) {
                if (board[col][raw] != '.') {
                    int num = board[col][raw] - '0';
                    if (hash[ num ]) return false;
                    hash[ num ] = true;
                }
            }
        }
        // valide each raw
        for (raw = 0; raw < 9; raw++) {
            memset(hash, 0, sizeof(hash));
            for (col = 0; col < 9; col++) {
                if (board[col][raw] != '.') {
                    int num = board[col][raw] - '0';
                    if (hash[num]) return false;
                    hash[ num ] = true;
                }
            }
        }
        // valide grid
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                // start is board[i][j]
                memset(hash, 0, sizeof(hash));
                for (col = i; col < i + 3; col++) {
                    for (raw = j; raw < j + 3; raw++) {
                        if (board[col][raw] != '.') {
                            int num = board[col][raw] - '0';
                            if (hash[ num ]) return false;
                            hash[ num] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};