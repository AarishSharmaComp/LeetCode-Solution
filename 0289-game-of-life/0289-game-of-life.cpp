class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int alive = 0;

                // Count live neighbors
                for (int k = 0; k < 8; k++) {
                    int ni = i + dr[k];
                    int nj = j + dc[k];

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        (board[ni][nj] == 1 || board[ni][nj] == 2)) {
                        alive++;
                    }
                }

                // Current cell is alive
                if (board[i][j] == 1) {
                    if (alive < 2 || alive > 3)
                        board[i][j] = 2;  // alive -> dead
                }

                // Current cell is dead
                else {
                    if (alive == 3)
                        board[i][j] = 3;  // dead -> alive
                }
            }
        }

        // Convert temporary states
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 2)
                    board[i][j] = 0;
                else if (board[i][j] == 3)
                    board[i][j] = 1;
            }
        }
    }
};