class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) 
    {
        //Res vector of size n and islands of size n 
        vector<bool> res;
        vector<int> islands(n);

        int numIslands = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] > maxDiff)
            {
                //New Island
                numIslands += 1;
            }

            islands[i] = numIslands;
        }

        for (auto& q : queries)
        {
            int x = q[0];
            int y = q[1];

            res.push_back(islands[x] == islands[y]);
        }
        
        return res;
    }
};