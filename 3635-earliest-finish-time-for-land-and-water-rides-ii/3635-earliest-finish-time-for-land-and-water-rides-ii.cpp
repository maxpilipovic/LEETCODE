class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        int landThenWater = solve(landStartTime, landDuration, waterStartTime, waterDuration);

        int waterThenLand = solve(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(landThenWater, waterThenLand);    
    }

    int solve(vector<int>& firstStart, vector<int>& firstDuration, vector<int>& secondStart, vector<int>& secondDuration)
    {
        int firstFinish = INT_MAX;
        int n = firstStart.size();

        for (int i = 0; i < n; i++)
        {
           firstFinish = min(firstFinish, firstStart[i] + firstDuration[i]);
        }

        int m = secondStart.size();

        for (int i = 0; i < m; i++)
        {
            int startSecond = max(firstFinish, secondStart[i]);
            int finishSecond = startSecond + secondDuration[i];

            res = min(res, finishSecond);
        }

        return res;
    }
private:
    int res = INT_MAX;
};