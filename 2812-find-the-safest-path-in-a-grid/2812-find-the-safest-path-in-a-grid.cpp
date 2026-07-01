class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> queue;

        //Find thiefs
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                if (grid[row][col] == 1)
                {
                    queue.push({row, col});
                }
            }
        }


        vector<vector<int>> grid2 = bfs(grid, queue, rows, cols);

        return safestPath(grid2, rows, cols);    
    }

    vector<vector<int>> bfs(vector<vector<int>>& grid, queue<pair<int, int>>& queue, int rows, int cols)
    {
        vector<vector<int>> grid2(rows, vector<int>(cols, -1));

        vector<vector<int>> directions =
        {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1}   // Right
        };

        //Make the thiefs 0
        auto temp = queue;

        while (!temp.empty())
        {
            auto [x, y] = temp.front();
            temp.pop();

            grid2[x][y] = 0;
        }

        //Pop from queue and run bfs.
        while (!queue.empty())
        {
            auto [x , y] = queue.front();
            queue.pop();


            for (auto& dir : directions)
            {
                int nr = dir[0];
                int nc = dir[1];

                int newX = x + nr;
                int newY = y + nc;

                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid2[newX][newY] == -1)
                {
                    grid2[newX][newY] = grid2[x][y] + 1;
                    queue.push({newX, newY});
                }
            }
        }

        return grid2;
    }

    int safestPath(vector<vector<int>>& grid2, int rows, int cols)
    {
        vector<vector<int>> visited(rows, vector<int>(cols, false));

        priority_queue<pair<int, pair<int, int>>> pq;

        pq.push({grid2[0][0], {0, 0}});

        vector<vector<int>> directions =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        while (!pq.empty())
        {
            auto [safe, cell] = pq.top();
            pq.pop();

            auto [x, y] = cell;

            if (visited[x][y])
            {
                continue;
            }

            visited[x][y] = true;

            if (x == rows - 1 && y == cols - 1)
            {
                return safe;
            }

            for (auto& dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                if (newX >= 0 && newX < rows &&
                    newY >= 0 && newY < cols &&
                    !visited[newX][newY])
                {
                    int newSafe = min(safe, grid2[newX][newY]);
                    pq.push({newSafe, {newX, newY}});
                }
            }
        }

        return 0;
    }

private:

};