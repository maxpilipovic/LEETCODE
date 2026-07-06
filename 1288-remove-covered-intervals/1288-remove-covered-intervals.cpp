class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        for (int i{}; i < intervals.size(); i++)
        {
            //Grab first interval
            int a = intervals[i][0];
            int b = intervals[i][1];

            for (int j = 0; j < intervals.size(); j++)
            {
                if (i == j) 
                {
                    continue;
                }

                int c = intervals[j][0];
                int d = intervals[j][1];

                //CheckIntervals
                if (CompareInterval(a, b, c, d))
                {
                    count += 1;
                    break;
                }

            }
        }

        return intervals.size() - count;
    }

    int CompareInterval(int a, int b, int c, int d)
    {
        return c <= a && b <= d;
    }

private:
    int count = 0;
};