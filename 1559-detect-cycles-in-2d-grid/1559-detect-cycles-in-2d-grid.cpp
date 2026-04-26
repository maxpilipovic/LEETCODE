class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) 
    {
        //1. Maybe do a global visited??

        int rows = grid.size();
        int cols = grid[0].size();

        vector<std::pair<int, int>> directions = 
        {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        for (int i{}; i < rows; i++)
        {
            for (int j{}; j < cols; j++)
            {
                if (!visited[i][j])
                {
                    if (dfs(i, j, -1, -1, rows, cols, grid, visited, directions))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(int row, int col, int parentRow, int parentCol, int rows, int cols, vector<vector<char>>& grid, std::vector<std::vector<bool>>& visited, vector<std::pair<int, int>>& directions)
    {
        //Recurrsive dfs.

        //Add to visited
        visited[row][col] = true;

        //dfs part.
        for (auto [xRow, xCol] : directions)
        {
            int newRow = xRow + row;
            int newCol = xCol + col;

            //If out of bounds
            if (newRow < 0 || newCol < 0 || newCol > cols - 1 || newRow > rows - 1)
            {
                //continue?
                continue;
            }

            if (grid[newRow][newCol] != grid[row][col])
            {
                continue;
            }

            if (parentRow == newRow && parentCol == newCol)
            {
                continue;
            }

            if (visited[newRow][newCol])
            {
                //If we can getback to the beginning
                return true;
            }

            if (dfs(newRow, newCol, row, col, rows, cols, grid, visited, directions))
            {
                return true;
            }
        }

        return false;
    }

private:
    
};