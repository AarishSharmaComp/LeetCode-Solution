class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        int count = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (board[i][j] != 'X')
                    continue;

                // If there is an X above or to the left,
                // this X belongs to an already counted ship.
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;

                if (j > 0 && board[i][j - 1] == 'X')
                    continue;

                count++;
            }
        }

        return count;
    }
};