class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) 
    {
        
        int rows = grid.size();
        int cols = grid[0].size();

        int minDamage = bfs(grid, 0, 0, rows, cols);
        
        return minDamage < health;
    }

    int bfs(vector<vector<int>>& grid, int row, int col, int rows, int cols)
    {
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        vector<pair<int, int>> directions = {
            {-1, 0}, // Up
            {1, 0},  // Down
            {0, -1}, // Left
            {0, 1}   // Right
        };

        //First element
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto [val, row, col] = pq.top();
            pq.pop();

            //If at rows - 1 and cols - 1. This is val we are looking for and the best we can find.
            if (row == rows - 1 && col == cols - 1)
            {
                return val;
            }

            //If val greater. Not needed skip.
            if (val > dist[row][col])
            {
                continue;
            }

            for (auto& [nRow, nCol] : directions)
            {
                int newRow = nRow + row;
                int newCol = nCol + col;

                //Check boundary
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
                {
                    int cost = val + grid[newRow][newCol];

                    if (cost < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = cost;
                        pq.push({cost, newRow, newCol});
                    }
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }


private:

};