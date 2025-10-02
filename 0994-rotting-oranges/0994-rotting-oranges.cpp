class Solution {

private:
    int res = 0;
    std::set<pair<int, int>> visited; 

public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int freshOranges = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<tuple<int, int, int>> queue;

        vector<pair<int, int>> directions = {
            {0, 1},   
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        for (int row = 0; row < rows; row++)
        {
            for (int col = 0; col < cols; col++)
            {
                if (grid[row][col] == 2 && visited.find({row, col}) == visited.end())
                {
                    queue.push({row, col, 0});
                    visited.insert({row, col});
                }
                else if (grid[row][col] == 1)
                {
                    freshOranges++;
                }
            }
        }
        bfs(directions, rows, cols, grid, queue, freshOranges);

        if (freshOranges == 0)
        {
            return res;
        }

        return -1;
    }

    void bfs(vector<pair<int, int>>& directions, int rows, int cols, vector<vector<int>>& grid, queue<tuple<int, int, int>>& queue, int& freshOranges)
    {

        while (!queue.empty())
        {

            auto [row, col, count] = queue.front();
            queue.pop();

            //Update...
            res = std::max(res, count);
            
            for (auto [nRow, nCol] : directions)
            {
                int newRow = nRow + row;
                int newCol = nCol + col;

                //cout << "here" << endl;
                //Check bounds...
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && visited.find({newRow, newCol}) == visited.end() && grid[newRow][newCol] == 1)
                {
                    //This is a valid option...
                    queue.push({newRow, newCol, count + 1});
                    visited.insert({newRow, newCol});   
                    freshOranges -= 1;

                    cout << res << endl;
                }
            }
        }

    }

};