class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) 
    {
        vector<vector<char>> classroom2;
        classroom2.reserve(classroom.size());
        vector<vector<int>> litterIndex;

        int litterCount = 0;
        int startRow = -1;
        int startCol = -1;

        //Find out how many litter items there are
        for (int i = 0; i < classroom.size(); i++)
        {
            vector<int> rowIndex(classroom[i].size(), -1);

            for (int j = 0; j < classroom[i].size(); j++)
            {
                char c = classroom[i][j];

                if (c == 'L')
                {
                    rowIndex[j] = litterCount;
                    litterCount += 1;
                }

                if (c == 'S') 
                { 
                    startRow = i; 
                    startCol = j; 
                }

            }

            litterIndex.push_back(rowIndex);
            classroom2.emplace_back(classroom[i].begin(), classroom[i].end());
        }

        vector<pair<int,int>> directions = {
            {-1, 0}, //up
            {1, 0},  //down
            {0, -1}, //left
            {0, 1}   //right
        };

        int rows = classroom2.size();
        int cols = classroom2[0].size();
        int fullMask = (1 << litterCount) - 1;

        if (fullMask == 0) return 0;

        std::queue<std::tuple<int, int, int, int, int>> q;

        return bfs(startRow, startCol, q, classroom2, litterIndex, directions, rows, cols, energy, fullMask);
    }

    int bfs(int i, int j, std::queue<std::tuple<int, int, int, int, int>>& q, vector<vector<char>>& classroom, vector<vector<int>>& litterIndex, vector<pair<int,int>>& directions, int rows, int cols, int energy, int fullMask)
    {
        //visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            rows, vector<vector<vector<bool>>>(
                cols, vector<vector<bool>>(
                    energy + 1, vector<bool>(fullMask + 1, false))));

        //Initial push and visit
        q.push({i, j, energy, 0, 0});
        visited[i][j][energy][0] = true;

        while (!q.empty())
        {
            auto [r, c, e, mask, moves] = q.front();

            //Pop
            q.pop();

            //Check directions. 
            for (auto& [row, col] : directions)
            {
                int newRow = row + r;
                int newCol = col + c;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols
                    && e > 0 && classroom[newRow][newCol] != 'X')
                {
                    int newEnergy = e - 1;

                    //Recharge station resets energy to max, regardless of current level
                    if (classroom[newRow][newCol] == 'R')
                    {
                        newEnergy = energy;
                    }

                    int newMask = mask;
                    if (classroom[newRow][newCol] == 'L')
                    {
                        newMask |= (1 << litterIndex[newRow][newCol]);
                    }

                    if (visited[newRow][newCol][newEnergy][newMask])
                    {
                        continue;
                    }
                    visited[newRow][newCol][newEnergy][newMask] = true;

                    //MADE IT
                    if (newMask == fullMask)
                    {
                        return moves + 1;
                    }

                    //Go to next cell
                    q.push({newRow, newCol, newEnergy, newMask, moves + 1});
                }
            }
        }

        //Could not find anything
        return -1;
    }

private:
};