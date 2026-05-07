class Solution {
public:
    vector<int> maxValue(vector<int>& nums) 
    {
         int n = nums.size();

        vector<int> res = nums;

        //Build prefix maximums
        //res[i] = maximum value from nums[0..i]
        for (int i = 1; i < n; i++)
        {
            res[i] = max(res[i], res[i - 1]);
        }

        //Smallest value seen from the right
        int suffixMin = nums[n - 1];

        //Traverse from right to left
        for (int i = n - 2; i >= 0; i--)
        {
            //If left side has something bigger
            if (res[i] > suffixMin)
            {
                res[i] = res[i + 1];
            }

            //Update
            suffixMin = min(suffixMin, nums[i]);
        }

        return res;
    }

private:
    int x = 0;
};