class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        int rows = img1.size();
        int cols = img1[0].size();
        int n = img1.size();

        std::set<std::pair<int, int>> A;
        std::set<std::pair<int, int>> B;

        //Get everyhting in set's
        for (int row{}; row < rows; row++)
        {
            for (int col{}; col < cols; col++)
            {
                if (img1[row][col] == 1)
                {
                    A.insert({row, col});
                }

                if (img2[row][col] == 1)
                {
                    B.insert({row, col});
                }
            }
        }

        //If empty, nothing needs to be done
        if (A.empty() || B.empty())
        {
            return 0;
        }

        unordered_map<int, int> shiftCount;
        int best = 0;

        for (auto& a : A)
        {
            for (auto&b : B)
            {
                int dx = a.first - b.first;
                int dy = a.second - b.second;

                int key = (dx + n) * 200 + (dy + n);

                best = max(best, ++shiftCount[key]);
            }
        }

        return best;
    }
};