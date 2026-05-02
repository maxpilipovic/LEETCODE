class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        
        //Dp filled with 0's
        vector<vector<vector<int>>> dp(
            rows,
            vector<vector<int>>(cols, vector<int>(k + 1, -1))
        );

        //Start position
        dp[0][0][0] = grid[0][0];

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                for (int cost = 0; cost <= k; cost++)
                {
                    if (dp[row][col][cost] == -1)
                    {
                        continue;
                    }

                    // Move down
                    if (row + 1 < rows)
                    {
                        int value = grid[row + 1][col];
                        int extraCost = value == 0 ? 0 : 1;
                        int newCost = cost + extraCost;

                        if (newCost <= k)
                        {
                            dp[row + 1][col][newCost] = max(
                                dp[row + 1][col][newCost],
                                dp[row][col][cost] + value
                            );
                        }
                    }

                    // Move right
                    if (col + 1 < cols)
                    {
                        int value = grid[row][col + 1];
                        int extraCost = value == 0 ? 0 : 1;
                        int newCost = cost + extraCost;

                        if (newCost <= k)
                        {
                            dp[row][col + 1][newCost] = max(
                                dp[row][col + 1][newCost],
                                dp[row][col][cost] + value
                            );
                        }
                    }
                }
            }
        }

        int answer = -1;

        for (int cost = 0; cost <= k; cost++)
        {
            answer = max(answer, dp[rows - 1][cols - 1][cost]);
        }

        return answer;
    }

private:
    std::vector<std::pair<int, int>> directions = 
    {
        {0, 1},  // right
        {1, 0}   // down
    };

};