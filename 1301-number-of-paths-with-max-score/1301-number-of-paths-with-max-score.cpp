class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) 
    {
        
        //Turn the grid to something traversable easily. This is can be easily traversible since std::string supports indexing

        //dp vec's
        vector<vector<int>> dp(board.size(), vector<int>(board[0].size(), -1));
        vector<vector<int>> dp2(board.size(), vector<int>(board[0].size(), 0));

        //Rows and cols
        int rows = board.size();
        int cols = board[0].size();

        //DP
        dp[rows - 1][cols - 1] = 0;
        dp2[rows - 1][cols - 1] = 1;

        for (int row = rows - 1; row >= 0; row--)
        {
            for (int col = cols - 1; col >= 0; col--)
            {
                if (board[row][col] == 'X')
                {
                    continue;
                }

                if (row == rows - 1 && col == cols - 1)
                {
                    continue;
                }

                //Check down, right, diagonal right
                vector<pair<int, int>> dirs = {
                    {1, 0},   //Down
                    {0, 1},   //Right
                    {1, 1}    //Diagonal down-right
                };

                int best = -1;
                int count = 0;

                for (auto& [dr, dc] : dirs)
                {

                    int nr = row + dr;
                    int nc = col + dc;

                    if (nr >= rows || nc >= cols)
                    {
                        continue;
                    }

                    if (dp[nr][nc] == -1)
                    {
                        continue;
                    }

                    if (dp[nr][nc] > best)
                    {
                        //We only need the best
                        best = dp[nr][nc];
                        count = dp2[nr][nc];
                    }
                    else if (dp[nr][nc] == best)
                    {
                        //All optimal paths included
                        count = (count + dp2[nr][nc]) % MOD;
                    }
                }

                if (best == -1)
                {
                   continue; 
                }

                int val = 0;

                if (isdigit(board[row][col]))
                {
                    val = board[row][col] - '0';
                }

                dp[row][col] = best + val;
                dp2[row][col] = count;

            }
        }

        if (dp[0][0] == -1)
        {
            return {0, 0};
        }

        return {dp[0][0], dp2[0][0]};
    }


private:
    static constexpr int MOD = 1000000007;
};