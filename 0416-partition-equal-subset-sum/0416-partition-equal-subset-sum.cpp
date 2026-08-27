class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        //Find half.
        int sum = accumulate(nums.begin(), nums.end(), 0);

        //If its odd, then imposible.
        if (sum % 2 != 0)
        {
            return false;
        }

        //Target
        int target = sum / 2;

        //Memo
        vector<vector<int>> memo(nums.size() + 1, vector<int>(target + 1, -1));

        return canPartition(0, target, nums, memo);
    }
    
    bool canPartition(int i, int remainder, vector<int>& nums, vector<vector<int>>& memo)
    {
        
        //Base Case
        if (remainder == 0)
        {
            return true;
        }

        //Out of bounds OR remainder less then 0
        if (i >= nums.size() || remainder < 0)
        {
            return false;
        }

        //Check memo.
        if (memo[i][remainder] != -1)
        {
            return memo[i][remainder];
        }

        //Recursive case
        bool bool1 = canPartition(i + 1, remainder - nums[i], nums, memo);

        //Recrusive case. Dont subtract target.
        bool bool2 = canPartition(i + 1, remainder, nums, memo);

        memo[i][remainder] = bool1 || bool2;

        return memo[i][remainder];
    }

private:

};