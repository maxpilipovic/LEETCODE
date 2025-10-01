class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1] + 1)
            {
                streak += 1;
            }
            else if (nums[i] == nums[i - 1])
            {
                //Duplicate
                continue;
            }
            else {
                streak = 1;
            }

            if (streak > res)
            {
                res = streak;
            }
        }

        return res;
    }

private:
    int res = 1;
    int streak = 1;
};