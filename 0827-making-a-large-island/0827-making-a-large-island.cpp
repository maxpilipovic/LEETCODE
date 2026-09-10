class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int id = 0;
        unordered_map<int, int> islandLookup;

        //Key filled with -1.
        vector<vector<int>> grid2(rows, vector<int>(cols, -1));

        //First pass. Precompute islands.
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                if (grid[row][col] == 1 && grid2[row][col] == -1)
                {
                    //Start a bfs. And id this island with the next.
                    int islandCount = bfs(row, col, grid, grid2, id, rows, cols);

                    //Add the lookup here.
                    islandLookup[id] = islandCount;

                    //Increase the id.
                    id += 1;
                }
            }
        }   

        int res = INT_MIN;

        //Second pass. Lets loop through each zero. Pretend we have a 1. 
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                //Find a zero.

                if (grid[row][col] == 0)
                {
                    //Consider this zero a 1.
                    int islandCount = findLargestCount(row, col, grid2, islandLookup);

                    res = max(res, islandCount);
                }
            }
        }

        //Edge Case
        if (res == INT_MIN)
        {
            return rows * cols;
        }

        return res;
    }

    int bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& grid2, int id, int rows, int cols)
    {
        std::queue<pair<int, int>> q;
        q.push({row, col});
        grid2[row][col] = id;
        int localCount = 1;

        vector<pair<int,int>> directions = 
        {
            {-1,0}, 
            {1,0}, 
            {0,-1}, 
            {0,1}
        };

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto& [newR, newC] : directions)
            {
                int newRow = r + newR;
                int newCol = c + newC;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid2[newRow][newCol] == -1 && grid[newRow][newCol] == 1)
                {
                    grid2[newRow][newCol] = id;
                    q.push({newRow, newCol});
                    localCount += 1;
                }
            }
        }

        return localCount;
    }

    int findLargestCount(int row, int col, vector<vector<int>>& grid2, unordered_map<int, int>& islands)
    {

        unordered_set<int> hashy;
        int rows = grid2.size();
        int cols = grid2[0].size();

        vector<pair<int,int>> directions = 
        {
            {-1,0}, 
            {1,0}, 
            {0,-1}, 
            {0,1}
        };

        //Loop through adjacent boxes.
        for (auto& [r, c] : directions)
        {
            int newRow = row + r;
            int newCol = col + c;

            //Check connected islands.
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid2[newRow][newCol] >= 0 && !hashy.count(grid2[newRow][newCol]))
            {
                hashy.insert(grid2[newRow][newCol]);
            }
        }
        
        int res = 0;

        //Loop through visited.
        for (auto it = hashy.begin(); it != hashy.end(); ++it) 
        {
            res += islands[*it];
        }

        //Count for island itself (turning from 0 -> 1)
        return res + 1;
    }
};