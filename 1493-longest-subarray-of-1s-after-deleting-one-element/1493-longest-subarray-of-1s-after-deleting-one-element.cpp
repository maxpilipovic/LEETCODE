class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0;
        int zeroCount = 0;
        int res = 0;

        for (int right = 0; right < n; right++)
        {

            //Check 0's and 1's
            if (nums[right] == 0)
            {
                zeroCount++;
            }

            //Bounds check and checking 0's
            while (left < nums.size() && zeroCount > 1)
            {
                if (nums[left] == 0)
                {
                    zeroCount--;
                }

                left += 1;
            }

            //Check our max
            if (right - left + 1 > res)
            {
                res = right - left + 1;
            }
        }

        return res - 1;
    }
};