class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty())
        {
            return 0;
        }
        
        std::sort(nums.begin(), nums.end());
        
        int res = 1; //biggest val
        int streak = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                //Duplicate
                continue;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                streak += 1;
            }
            else {
                //Reset
                streak = 1;
            }
            
            //Update max.
            if (streak > res)
            {
                res = streak;
            }
            
        } 

        return res;
    }
};