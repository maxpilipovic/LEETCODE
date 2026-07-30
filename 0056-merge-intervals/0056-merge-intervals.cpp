class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());  //Sort by first element lowkey
        vector<vector<int>> res;

        for (auto& interval : intervals)
        {
            if (!res.empty() && interval[0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
            else
            {
                res.push_back(interval);
            }
        }

        return res;
    }
};