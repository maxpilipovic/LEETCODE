class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        for (int num : nums)
        {
            globalMax = max(globalMax, num);
            globalMin = min(globalMin, num);
        }

        long long ans = 1LL * (globalMax - globalMin) * k;

        return ans;
    }

private:
    int globalMax = INT_MIN;
    int globalMin = INT_MAX;
};