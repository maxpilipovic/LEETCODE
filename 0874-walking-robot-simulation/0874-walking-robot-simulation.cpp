class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int size = commands.size();
        std::vector<std::pair<int, int>> directions = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        std::set<std::pair<int, int>> visited = getVisited(obstacles);
        int dir = 0;
        int x = 0, y= 0;

        for (int i = 0; i < size; i++)
        {
            if (commands[i] == -2)
            {
                //Turn left 90 degrees
                dir = (dir + 3) % 4;
            }
            else if (commands[i] == -1)
            {
                //Turn right 90 degrees
                dir = (dir + 1) % 4;
            }
            else
            {
                int steps = commands[i];

                for (int s = 0; s < steps; s++)
                {
                    int newX = x + directions[dir].first;
                    int newY = y + directions[dir].second;

                    //Check obstacle
                    if (visited.count({newX, newY}))
                    {
                        break; //Stop moving
                    }

                    // Move forward
                    x = newX;
                    y = newY;

                    //Update max distance
                    res = std::max(res, x * x + y * y);
                }
            }
        }

        return res;
    }

    std::set<std::pair<int, int>> getVisited(vector<vector<int>>& obstacles)
    {
        std::set<std::pair<int, int>> visited;

        for (const auto& obs : obstacles)
        {
            visited.insert({obs[0], obs[1]});
        }

        return visited;
    }

private:
    int res = 0;
};