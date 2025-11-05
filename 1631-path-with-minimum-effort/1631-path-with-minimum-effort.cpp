class Solution {
public:

    //DIJIKSTRAS SOLUTION...

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        //Hold distances
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        //Makes a min heap... IN PRIVATE SECTION
        //priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> pq;

        vector<pair<int, int>> directions {
            {0, -1},  // Up
            {0, 1},   // Down
            {1, 0},   // Right
            {-1, 0}   // Left
        };

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        return bfs(heights, rows, cols, directions, dist);
    }

    int bfs(vector<vector<int>>& heights, int& rows, int& cols, vector<pair<int, int>>& directions, vector<vector<int>>& dist)
    {   

        while (!pq.empty())
        {
            auto top = pq.top();
            int effort = top[0];
            int row = top[1];
            int col = top[2];
            pq.pop();

            if (row == rows - 1 && col == cols - 1)
            {
                return effort;
            }

            for (auto [dr, dc] : directions)
            {
                int newRow = dr + row;
                int newCol = dc + col;

                //Check the bounds..
                if (0 <= newRow && newRow < rows && 0 <= newCol && newCol < cols)
                {
                    int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));

                    if (newEffort < dist[newRow][newCol])
                    {
                        dist[newRow][newCol] = newEffort;
                        pq.push({newEffort, newRow, newCol});
                    }
                }
            }
        }

        return 0;
    }   

private:
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

};