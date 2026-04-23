class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        //Simple bfs
        int rows = grid.size();
        int cols = grid[0].size();

        std::vector<std::pair<int, int>> directions = {
            {-1, 0}, // up
            {0, -1}, // left
            {1, 0},  // down
            {0, 1}   // right
        };

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        std::queue<std::pair<int, int>> queue;

        for (size_t i{}; i < rows; i++)
        {
            for (size_t j{}; j < cols; j++)
            {
                if (visited[i][j] || grid[i][j] == '0')
                {
                    //If found.
                    continue;
                }
                else
                {
                    std::cout << i << j << std::endl;
                    bfs(i, j, directions, visited, grid, queue, rows, cols);
                    res += 1;
                }
            }
        }

        return res;
    }

    void bfs(int row, int col, vector<std::pair<int, int>>& directions, vector<vector<bool>>& visited, vector<vector<char>>& grid, std::queue<std::pair<int, int>>& queue, int rows, int cols)
    {
        //Append
        queue.push({row, col});
        visited[row][col] = true;

        while (!queue.empty())
        {
            //Do something
            std::pair<int, int> curr = queue.front();
            queue.pop();

            //We have the coords
            int x = curr.first;
            int y = curr.second;

            for (auto& [newRow, newCol] : directions)
            {
                int nRow = newRow + x;
                int nCol = newCol + y;

                //Check if valid
                if (nRow >= 0 && nRow <= rows - 1 && nCol >= 0 && nCol <= cols - 1 && grid[nRow][nCol] == '1' && !visited[nRow][nCol] )
                {
                    queue.push({nRow, nCol});
                    visited[nRow][nCol] = true;
                }
            }
        }
    }

private:
    int res = 0;
};