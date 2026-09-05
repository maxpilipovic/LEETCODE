class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> prefixMax(n);
        vector<int> suffixMin(n);

        prefixMax[0] = nums[0];
        //Prefix
        for (int i = 1; i < nums.size(); i++)
        {
            prefixMax[i] = max(nums[i], prefixMax[i - 1]);
        }
        
        suffixMin[n - 1] = nums[n - 1];
        //Sufix
        for (int i = n - 2; i < nums.size(); i--)
        {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }

        for (int i = n - 1; i < nums.size(); i--)
        {
            int x = abs(prefixMax[i] - suffixMin[i]);
            //Now compare.
            if (x <= k)
            {
                index = i;
            }
        }

        return index != INT_MAX ? index : -1;
    }

private:
    int index = INT_MAX;
};