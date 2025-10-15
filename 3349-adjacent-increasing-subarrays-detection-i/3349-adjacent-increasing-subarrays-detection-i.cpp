class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        //int left = 0;
        int streak = 1;

        for (int i = 0; i + 2 * k <= n; i++)
        {
            if (findSubArray(i, i + k, nums) && findSubArray(i + k, i + 2 * k, nums))
            {
                return true;
            }
        }

        return false;
         
    }

    bool findSubArray(int start, int end, vector<int>& nums)
    {
        //Helper function
        for (int i = start; i < end - 1; i++)
        {
            if (nums[i] >= nums[i + 1])
            {
                return false;
            }
        }

        return true;
    }


private:

};