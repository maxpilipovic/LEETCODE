class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        
        vector<long long> minPrefix(k, LLONG_MAX); //Store minPrefix's filled with LONG_MAX.
        minPrefix[0] = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            //Locate bucket using modulo (groups)
            int r = (i + 1) % k;

            if (minPrefix[r] != LLONG_MAX) {
                maxVal = max(maxVal, prefixSum - minPrefix[r]);
            }

            minPrefix[r] = min(minPrefix[r], prefixSum);
        }

        return maxVal;
        
    }

private:
    long long maxVal = LLONG_MIN;
    long long prefixSum = 0;
};