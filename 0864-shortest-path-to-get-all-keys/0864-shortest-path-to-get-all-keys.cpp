class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) 
    {
        vector<pair<int,int>> directions = 
        {
            {-1, 0},  // up
            { 0, 1},  // right
            { 1, 0},  // down
            { 0,-1}   // left
        };
        bfs(grid, directions);
        
        return res;
    }

    int encode(int r, int c, int mask)
    {
        return (r << 12) | (c << 6) | mask;
    }

    void bfs(const vector<string>& grid, vector<pair<int,int>> directions)
    {
        int rows = (int)grid.size();
        int cols = (int)grid[0].size();

        int sr = -1, sc = -1;
        int allKeysMask = 0;

        //Find start + all keys
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                char ch = grid[r][c];

                if (ch == '@') 
                { 
                    sr = r; sc = c; 
                }
                if (ch >= 'a' && ch <= 'f')
                {
                    allKeysMask |= (1 << (ch - 'a'));
                }
            }
        }

        unordered_set<int> visited;
        queue<tuple<int,int,int>> queue; //r, c, mask

        queue.push({sr, sc, 0});
        visited.insert(encode(sr, sc, 0));
        int steps = 0;

        while (!queue.empty())
        {
            int size = queue.size();

            for (int i = 0; i < size; i++)
            {
                auto [row, col, mask] = queue.front();
                queue.pop();

                if (mask == allKeysMask)
                {
                    res = steps;
                    return;
                }

                for (auto [dr, dc] : directions)
                {
                    int newRow = row + dr;
                    int newCol = col + dc;

                    //Check bounds
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols)
                    {
                        char cell = grid[newRow][newCol];

                        if (cell == '#')
                        {
                            continue;
                        }

                        int newMask = mask;

                        //Key
                        if (cell >= 'a' && cell <= 'f')
                            newMask |= (1 << (cell - 'a'));

                        //Door
                        if (cell >= 'A' && cell <= 'F')
                            if (!(mask & (1 << (cell - 'A'))))
                                continue;

                        int state = encode(newRow, newCol, newMask);
                        if (visited.count(state)) continue;

                        visited.insert(state);
                        queue.push({newRow, newCol, newMask});

                    }
                }
            }
            steps++;
        }
        res -= 1;
    }

    void printVector(const std::vector<std::string>& v)
    {
        for (const std::string& s : v)
        {
            std::cout << s << " ";
        }
        std::cout << '\n';
    }

private:
    int res = 0;

};