class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end());
        std::vector<vector<int>> res;

        for (int i = 1; i < intervals.size(); i++)
        {
            int a = intervals[i - 1][0];
            int b = intervals[i - 1][1];

            int c = intervals[i][0];
            int d = intervals[i][1];

            if (b >= c)
            {
                int min = std::min({a, b, c, d});
                int max = std::max({a, b, c, d});

                intervals[i] = {min, max};  
            }
            else
            {
                res.push_back(intervals[i - 1]);
            }
        }

        res.push_back(intervals.back());

        return res;
    }

private:

};