class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        int rows = buildings.size();
        int cols = buildings[0].size();
        
        for (int row = 0; row < rows; row++)
        {
            int x = buildings[row][0];
            int y = buildings[row][1];
            hashy[x].push_back(y);
            hashy2[y].push_back(x);
        }

        for (const auto& building : buildings)
        {
            int x = building[0];
            int y = building[1];

            //Check up & down
            bool up = hasUp(hashy, hashy2, x, y);
            bool down = hasDown(hashy, hashy2, x, y);
            
            //Check right & left
            bool right = hasRight(hashy, hashy2, x, y);
            bool left = hasLeft(hashy, hashy2, x, y);

            if (up && down && right && left)
            {
                res += 1;
            }
        }
    
        return res;
    }

    bool hasUp(unordered_map<int, vector<int>>& hashy, unordered_map<int, vector<int>>& hashy2, int x, int y)
    {
        for (int above : hashy[x])
        {
            if (above >= y + 1)
            {
                return true;
            }
        }

        return false;
    }

    bool hasDown(unordered_map<int, vector<int>>& hashy, unordered_map<int, vector<int>>& hashy2, int x, int y)
    {
        for (int below : hashy[x])
        {
            if (below <= y - 1)
            {
                return true;
            }
        }

        return false;
    }

    bool hasRight(unordered_map<int, vector<int>>& hashy, unordered_map<int, vector<int>>& hashy2, int x, int y)
    {
        for (int right : hashy2[y])
        {
            if (right >= x + 1)
            {
                return true;
            }
        }

        return false;
    }

    bool hasLeft(unordered_map<int, vector<int>>& hashy, unordered_map<int, vector<int>>& hashy2, int x, int y)
    {

        for (int left : hashy2[y])
        {
            if (left <= x - 1)
            {
                return true;
            }
        }

        return false;
    }

private:
    int res = 0;
    unordered_map<int, vector<int>> hashy;
    unordered_map<int, vector<int>> hashy2;
};