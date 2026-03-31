class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        int rows = m;
        int cols = n;

        vector<vector<int>> board(rows, vector<int>(cols, 0));

        //Add guards
        for (int i = 0; i < guards.size(); i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];

            board[x][y] = 1;
        }

        //Add walls
        for (int i = 0; i < walls.size(); i++)
        {
            int x = walls[i][0];
            int y = walls[i][1];

            board[x][y] = 2;
        }

        //Loop through
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {   
                //Run from every guard
                if (board[i][j] == 1)
                {
                    //Run MOVE SIMULATION (left, right, up, down)
                    move(i, j, board);
                }
            }
        }

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 0)
                {
                    res += 1;
                } 
            }
        }

        return res;
        
    }

    void move(int i, int j, vector<vector<int>>& board)
    {

        for (auto [dr, dc] : directions)
        {
            int newRow = dr + i;
            int newCol = dc + j;

            while (newRow >= 0 && newRow < board.size() && newCol >= 0 && newCol < board[0].size())
            {
                if (board[newRow][newCol] == 1 || board[newRow][newCol] == 2)
                {
                    break;
                }

                board[newRow][newCol] = 3;
                newRow += dr;
                newCol += dc;
            }
        }
    }

private:
    vector<pair<int, int>> directions = {
        {0, 1},   // right
        {1, 0},   // down
        {-1, 0},  // up
        {0, -1}   // left
    };

    int res = 0;
};