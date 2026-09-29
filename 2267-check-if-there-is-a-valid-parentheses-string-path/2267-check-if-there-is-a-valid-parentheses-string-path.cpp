class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        //Quick wins
        if (grid[0][0] == ')')
        {
            return false;
        }

        //set. Don't think this is needed since we can only move right or down
        std::set<std::tuple<int, int, int>> hashy;

        //row, col, 'amount (', 'amount )'
        std::queue<std::tuple<int, int, int, int>> queue;

        std::vector<std::pair<int, int>> directions = 
        {
            {1, 0},  //Down
            {0, 1}   //Right
        };

        return bfs(0, 0, hashy, queue, grid, directions, rows, cols);
    }

    bool bfs(int row, int col, std::set<std::tuple<int, int, int>>& hashy, std::queue<std::tuple<int, int, int, int>>& q, vector<vector<char>>& grid, std::vector<std::pair<int, int>>& directions, int rows, int cols)
    {
        char c = grid[row][col];
        int open = 0;
        int close = 0;

        //Check OpenClose for inital value at 0, 0
        checkOpenClose(c, open, close);

        //Push first.
        q.push({row, col, open, close});
        hashy.insert({row, col, open - close});

        while (!q.empty())
        {
            auto tuple = q.front();
            q.pop();

            int nowRow = std::get<0>(tuple);
            int nowCol = std::get<1>(tuple);
            int open = std::get<2>(tuple);
            int close = std::get<3>(tuple);

            //Reached bottom right with everything closed
            if (nowRow == rows - 1 && nowCol == cols - 1 && open == close)
            {
                return true;
            }

            //Check if next is valid
            //Ask why this would be ref or no ref. Is this nessecary?
            for (auto& [newRow, newCol] : directions)
            {
                int xRow = nowRow + newRow;
                int yCol = nowCol + newCol;

                if (xRow >= 0 && xRow < rows && yCol >= 0 && yCol < cols)
                {

                    char next = grid[xRow][yCol];

                    int newOpen = open;
                    int newClose = close;
                    checkOpenClose(next, newOpen, newClose);

                    int balance = newOpen - newClose;

                    //More ')' than '(' so dead
                    if (balance < 0) 
                    {
                        continue;
                    }

                    //Not enough cells left to close everything
                    int stepsLeft = (rows - 1 - xRow) + (cols - 1 - yCol);

                    //Prune
                    if (balance > stepsLeft) 
                    {
                        continue;
                    }

                    //Checky hashy
                    if (hashy.count({xRow, yCol, balance})) 
                    {
                        continue;
                    }

                    //Add everything
                    hashy.insert({xRow, yCol, balance});
                    q.push({xRow, yCol, newOpen, newClose});
                }
            }

        }


        return false;
    }

    void checkOpenClose(char c, int& open, int& close)
    {
        if (c == '(')
        {
            open++;
        }
        else
        {
            close++;
        }
    }

private:

};