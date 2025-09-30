class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        
        while (nums.size() != 1)
        {
            backtrack(nums);
        }

        return nums[0];
    }

    void backtrack(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> newNums;

        for (int i = 0; i < n; i++)
        {
            if (i + 1 >= n)
            {
                break;
            }
            newNums.push_back((nums[i] + nums[i + 1]) % 10);
        }

        nums = newNums;
    }

private:


};