class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {

        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::pair<int, int>> directions = 
        {
            {1, 0}, // Right
            {-1, 0}, // Left
            {0, 1}, // Up
            {0, -1} // Down
        };

        int total = 0;

        for (int i{}; i < rows; i++)
        {
            for (int j{}; j < cols; j++)
            {
                if (grid[i][j] == 1 && !visited.count({i, j}))
                {
                    int size = dfs(i, j, directions, grid, rows, cols);

                    if (size > 1)
                    {
                        total += size;
                    }
                }
            }
        }

        return total;
    }

    int dfs(int i, int j, vector<std::pair<int, int>>& directions, vector<vector<int>>& grid, int rows, int cols)
    {
        visited.insert({i, j});
        int count = 1;

        for (auto [dr, dc] : directions)
        {
            int newRow = i + dr;
            int newCol = j + dc;

            while (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
            {
                if (grid[newRow][newCol] == 1 && !visited.count({newRow, newCol}))
                {
                    count += dfs(newRow, newCol, directions, grid, rows, cols);
                }

                //Update moves.
                newRow += dr;
                newCol += dc;
            }
        }

        return count;
    }

private:
    std::set<pair<int, int>> visited;
};