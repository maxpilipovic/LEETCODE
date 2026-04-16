class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) 
    {
        unordered_map<int, vector<int>> map;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            //Add each value of nums[i]
            map[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int idx = queries[i];
            int value = nums[idx];

            vector<int>& positions = map[value];

            int dist = checkDistance(idx, positions, n);
            res.push_back(dist);

        }

        return res;
    }

    int checkDistance(int idx, vector<int>& positions, int n)
    {
        if (positions.size() == 1)
        {
            return -1;
        }

        auto it = lower_bound(positions.begin(), positions.end(), idx);
        int i = it - positions.begin();

        int prevIdx = (i - 1 + positions.size()) % positions.size();
        int nextIdx = (i + 1) % positions.size();

        int dist1 = abs(idx - positions[prevIdx]);
        dist1 = min(dist1, n - dist1);

        int dist2 = abs(idx - positions[nextIdx]);
        dist2 = min(dist2, n - dist2);

        return min(dist1, dist2);
    }

private:
    vector<int> res;
};