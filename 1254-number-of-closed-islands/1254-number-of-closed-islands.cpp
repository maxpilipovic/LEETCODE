class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        set<pair<int, int>> visited;
        vector<pair<int, int>> directions = 
        {
            {-1, 0},  // Up
            {1, 0},   // Down
            {0, -1},  // Left
            {0, 1}    // Right
        };

        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                if (grid[row][col] == 0 && !visited.count({row, col}) && bfs(row, col, rows, cols, visited, directions, grid))
                {
                    count += 1;
                }
            }
        }

        return count;
    }

    bool bfs(int row, int col, int rows, int cols, set<pair<int, int>>& visited, vector<pair<int, int>>& directions, vector<vector<int>>& grid)
    {
        std::queue<pair<int, int>> queue;
        bool isClosed = true;

        queue.push({row, col});
        visited.insert({row, col});

        while (!queue.empty())
        {

            auto [row, col] = queue.front();
            queue.pop();

            //Base Case
            if ((row == 0 || row == rows - 1 || col == 0 || col == cols - 1) && grid[row][col] == 0)
            {
                isClosed = false;
            }

            for (const auto& [nr, nc] : directions)
            {
                int newRow = row + nr;
                int newCol = col + nc;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 0 && !visited.count({newRow, newCol}))
                {
                    queue.push({newRow, newCol});
                    visited.insert({newRow, newCol});
                }
            }
        }

        return isClosed;
    }

private:
    int count = 0;
};